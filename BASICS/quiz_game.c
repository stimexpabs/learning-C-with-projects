#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
   int alarm_hour, alarm_min;
   bool alarm_triggered = false;
   clock_t start_time, end_time;
   double elapsed_time;
   
   printf("Press any key to start the stopwatch...\n");
   getchar();
   start_time = clock();
   
   while (!alarm_triggered) {
      time_t t = time(NULL);
      struct tm tm = *localtime(&t);
      printf("Current time: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
      
      if (!alarm_triggered) {
         printf("Enter alarm time (hh:mm) or press enter to skip: ");
         char input[6];
         fgets(input, sizeof(input), stdin);
         if (input[0] != '\n') {
            sscanf(input, "%d:%d", &alarm_hour, &alarm_min);
            printf("Alarm set for %02d:%02d\n", alarm_hour, alarm_min);
         }
      }
      
      if (tm.tm_hour == alarm_hour && tm.tm_min == alarm_min && !alarm_triggered) {
         printf("ALARM TRIGGERED!\n");
         alarm_triggered = true;
      }
      
      if (alarm_triggered) {
         end_time = clock();
         elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
         printf("Elapsed time: %f seconds\n", elapsed_time);
         break;
      }
   }
   
   return 0;
}
