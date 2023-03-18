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
HANDLE hSemaphore;

// Declare function prototypes
void WriteThread(void* pParam);
void ReadThread(void* pParam);

int main()
{
    char portName[8]; // declare variable to store port name entered by user
    printf("Enter COM port name (e.g. COM1): ");
    scanf("%s", portName); // read port name entered by user

    hCom = CreateFile(portName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);

    if (hCom == INVALID_HANDLE_VALUE)
    {
        printf("Failed to open COM port %s.\n", portName);
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

    hSemaphore = CreateSemaphore(NULL, 1, 1, NULL);

    HANDLE hThread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&WriteThread, NULL, 0, NULL);
    HANDLE hThread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&ReadThread, NULL, 0, NULL);

    // Wait for threads to finish
    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);

    CloseHandle(hThread1);
    CloseHandle(hThread2);
    CloseHandle(hCom);
    CloseHandle(hSemaphore);

    return 0;
}

void WriteThread(void* pParam)
{
    while (1)
    {
        // Read input from user
        printf("Enter message to send: ");
        fgets(szBuff, sizeof(szBuff), stdin);

        // Print "sending" message
        WaitForSingleObject(hSemaphore, INFINITE);
        printf("sending: %s", szBuff);
        ReleaseSemaphore(hSemaphore, 1, NULL);

        // Write message to serial port
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
            
            // Wait for the semaphore before reading
            WaitForSingleObject(hSemaphore, INFINITE);
            ReadFile(hCom, szBuff, sizeof(szBuff), &dwBytesRead, &olRead);
            fWaitingOnRead = TRUE;
            ReleaseSemaphore(hSemaphore, 1, NULL);
            
            WaitForSingleObject(olRead.hEvent, INFINITE);
            fWaitingOnRead = FALSE;
        }

        if (dwEventMask & EV_RXCHAR)
        {
            printf("Receiving: %s\n", szBuff);
        }
    }
}