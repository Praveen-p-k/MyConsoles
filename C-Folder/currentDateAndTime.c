#include <stdio.h>
#include <time.h>

int main()
{
    // Get the current time
    time_t now = time(NULL);

    // Convert to local time
    struct tm *local_time = localtime(&now);

    // Print the date and time
    printf("Current date and time: %04d-%02d-%02d %02d:%02d:%02d\n",
           local_time->tm_year + 1900,
           local_time->tm_mon + 1,
           local_time->tm_mday,
           local_time->tm_hour,
           local_time->tm_min,
           local_time->tm_sec);

    return 0;
}
