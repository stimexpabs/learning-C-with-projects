
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>

// Struct to store the Pomodoro template
typedef struct {
    int work_time;
    int break_time;
} Pomodoro;

// Function to display the main menu
void show_menu() {
    printf("\n\n\t\t\t\tPOMODORO TIMER\n\n");
    printf("\t\t\t\t1. Start Timer\n");
    printf("\t\t\t\t2. Choose Template\n");
    printf("\t\t\t\t3. Exit\n\n");
    printf("\t\t\t\tEnter your choice: ");
}

// Function to display the template menu
void show_template_menu() {
    printf("\n\n\t\t\t\tPOMODORO TEMPLATES\n\n");
    printf("\t\t\t\t1. 25 minutes work, 5 minutes break\n");
    printf("\t\t\t\t2. 30 minutes work, 10 minutes break\n");
    printf("\t\t\t\t3. 45 minutes work, 15 minutes break\n");
    printf("\t\t\t\t4. 60 minutes work, 15 minutes break\n\n");
    printf("\t\t\t\tEnter your choice: ");
}

// Function to start the timer
void start_timer(Pomodoro *pomodoro) {
    int work_time = pomodoro->work_time;
    int break_time = pomodoro->break_time;
    int time_left = work_time;
    int i;

    printf("\n\n\t\t\t\tWORK TIME\n\n");

    for (i = 0; i < work_time; i++) {
        printf("\t\t\t\tTime left: %d seconds\n", time_left);
        time_left--;
        Sleep(1000);
        system("cls");
    }

    printf("\n\n\t\t\t\tBREAK TIME\n\n");
    time_left = break_time;

    for (i = 0; i < break_time; i++) {
        printf("\t\t\t\tTime left: %d seconds\n", time_left);
        time_left--;
        Sleep(1000);
        system("cls");
    }

    // Sound and popup window alert when the work interval and break interval are finished
    MessageBeep(MB_ICONEXCLAMATION);
    MessageBox(NULL, "Time is up!", "Pomodoro Timer", MB_OK);
}

// Main function
int main() {
    int choice;
    Pomodoro pomodoro;

    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start_timer(&pomodoro);
                break;
            case 2:
                show_template_menu();
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        pomodoro.work_time = 25 * 60;
                        pomodoro.break_time = 5 * 60;
                        break;
                    case 2:
                        pomodoro.work_time = 30 * 60;
                        pomodoro.break_time = 10 * 60;
                        break;
                    case 3:
                        pomodoro.work_time = 45 * 60;
                        pomodoro.break_time = 15 * 60;
                        break;
                    case 4:
                        pomodoro.work_time = 60 * 60;
                        pomodoro.break_time = 15 * 60;
                        break;
                    default:
                        printf("\n\n\t\t\t\tInvalid choice!\n");
                        break;
                }
                break;
            case 3:
                exit(0);
            default:
                printf("\n\n\t\t\t\tInvalid choice!\n");
                break;
        }
    }

    return 0;
}