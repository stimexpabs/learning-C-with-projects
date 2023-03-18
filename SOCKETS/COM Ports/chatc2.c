#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Declare global variables
HANDLE hCom;
OVERLAPPED olRead, olWrite;
DWORD dwEventMask, dwBytesRead, dwBytesWritten;
CHAR szBuff[512];
BOOL fWaitingOnRead = FALSE, fWaitingOnWrite = FALSE;

// Declare function prototypes
void WriteThread(void* pParam);
void ReadThread(void* pParam);

int main()
{
    char portName[4]; // declare variable to store port name entered by user
    printf("Enter COM port name: ");
    scanf("%s", portName); // read port name entered by user

    DWORD dwThreadID1, dwThreadID2;
    HANDLE hThread1, hThread2;

    hCom = CreateFile(portName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);

    if (hCom == INVALID_HANDLE_VALUE)
    {
        printf("Failed to open COM port.\n");
        exit(1);
    }

    DCB dcb;
    dcb.DCBlength = sizeof(DCB);
    GetCommState(hCom, &dcb);
    dcb.BaudRate = CBR_9600;
    dcb.ByteSize = 8;
    dcb.StopBits = ONESTOPBIT;
    dcb.Parity = NOPARITY;
    SetCommState(hCom, &dcb);

    memset(&olRead, 0, sizeof(olRead));
    memset(&olWrite, 0, sizeof(olWrite));
    olRead.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    olWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

    hThread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&WriteThread, NULL, 0, &dwThreadID1);
    hThread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&ReadThread, NULL, 0, &dwThreadID2);

    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);

    CloseHandle(hThread1);
    CloseHandle(hThread2);

    CloseHandle(hCom);

    return 0;
}

void WriteThread(void* pParam)
{
    while (1)
    {
        fgets(szBuff, sizeof(szBuff), stdin);
        WriteFile(hCom, szBuff, strlen(szBuff), &dwBytesWritten, &olWrite);
        fWaitingOnWrite = TRUE;
        WaitForSingleObject(olWrite.hEvent, INFINITE);
        fWaitingOnWrite = FALSE;
    }
}

void ReadThread(void* pParam)
{
    dwEventMask = EV_RXCHAR | EV_ERR;

    while (1)
    {
        if (!fWaitingOnRead)
        {
            memset(szBuff, 0, sizeof(szBuff));
            ReadFile(hCom, szBuff, sizeof(szBuff), &dwBytesRead, &olRead);
            fWaitingOnRead = TRUE;
            WaitForSingleObject(olRead.hEvent, INFINITE);
            fWaitingOnRead = FALSE;
        }

        if (dwEventMask & EV_RXCHAR)
        {
            printf("r: %s", szBuff);
        }
    }
}