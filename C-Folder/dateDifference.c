#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert a date string in the format "dd/mm/yyyy" to a Unix timestamp
time_t date_to_timestamp(char *date_str)
{
    struct tm tm = {0};
    strptime(date_str, "%d/%m/%Y", &tm);
    time_t timestamp = mktime(&tm);
    return timestamp;
}

// Function to calculate the difference between two dates in days
int date_difference(char *date_str1, char *date_str2)
{
    time_t timestamp1 = date_to_timestamp(date_str1);
    time_t timestamp2 = date_to_timestamp(date_str2);
    int difference = difftime(timestamp2, timestamp1) / (60 * 60 * 24);
    return difference;
}

int main()
{
    char date_str1[] = "12/03/2022";
    char date_str2[] = "11/01/2020";

    int difference = date_difference(date_str1, date_str2);

    printf("The difference between %s and %s is %d days.\n", date_str1, date_str2, difference);

    return 0;
}
