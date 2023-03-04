#include<stdio.h>

int main(void) {
    int i;
    char ans;
    signed int point = 0;
    printf("\t\t\tWelcome to the Game!\n\n");
    printf("\t\t\tpress 7 to start the game!\n");
    printf("\t\t\tpress 0 to quit the game.\n");
    scanf("%d", &i);
    if (i == 7) printf("The game started!\n\n");
    else if (i == 0) printf("The game has ended.\n\n");
    else printf("Invalid Input..\n\n");
    if (i == 7) {
        printf("1) Which one is the first search engine in Internet?\n");
        printf("\ta) Google\n");
        printf("\tb) Archie\n");
        printf("\tc) Wais\n");
        printf("\td) Altavista\n\n");

        printf("Enter your answer: ");
        scanf("\n%c", &ans);

        if (ans == 'a') {
            printf("Correct answer!!\n");
            point += 5;
            printf("Scored!! 5 points!!\n\n");
        } else {
            printf("Wrong answer.\n");
            point -= 3;
            printf("punished..\n\n");
        }
        printf("2) Which one is the first web browser invented in 1990?\n");
        printf("\ta) Internet Explorer\n");
        printf("\tb) Mosaic\n");
        printf("\tc) Mozilla\n");
        printf("\td) Nexus\n\n");
        printf("Enter your answer: ");
        scanf("\n%c", &ans);
        if (ans == 'd') {
            printf("Correct answer!!\n");
            point += 5;
            printf("Scored!! 5 points!!\n\n");
        } else {
            printf("Wrong answer.\n");
            point -= 3;
            printf("punished..\n\n");
        }
        printf("3) First computer virus is known as?\n");
        printf("\ta) Rabbit\n");
        printf("\tb) Creeper\n");
        printf("\tc) Elk Cloner\n");
        printf("\td) SCA Virus\n\n");
        printf("Enter your answer: ");
        scanf("\n%c", &ans);

        if (ans == 'b') {
            printf("Correct answer!!\n");
            point += 5;
            printf("Scored!! 5 points!!\n\n");
        } else {
            printf("Wrong answer.\n");
            point -= 3;
            printf("punished..\n\n");
        }
        printf("4) Firewall in coumputer is used for?\n");
        printf("\ta) Security\n");
        printf("\tb) Data Transmission\n");
        printf("\tc) Monitoring\n");
        printf("\td) Authentication\n\n");
        printf("Enter your answer: ");
        scanf("\n%c", &ans);
        if (ans == 'a') {
            printf("Correct answer!!\n");
            point += 5;
            printf("Scored!! 5 points!!\n\n");
        } else {
            printf("Wrong answer.\n");
            point -= 3;
            printf("punished..\n\n");
        }
        printf("5) Which of the following is not a database managent software?\n");
        printf("\ta) MySQL\n");
        printf("\tb) Oracle\n");
        printf("\tc) COBAL\n");
        printf("\td) Sybase\n\n");
        printf("Enter your answer: ");
        scanf("\n%c", &ans);
        if (ans == 'c') {
            printf("Correct answer!!\n");
            point += 5;
            printf("Scored!! 5 points!!\n\n");
        } else {
            printf("Wrong answer.\n");
            point -= 3;
            printf("punished..\n\n");
        }
    }
    printf("\t\t\tYour Score: %d.\n\n\n", point);
    if (point > 15) printf("Good Score!");
    else printf("Result can be better.");// two grading system.
    return 0;
} 
