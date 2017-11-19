#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <time.h>

int main(int argc, char *argv[]) {

    struct tm *tm_ptr;
    time_t  the_time;

    (void) time(&the_time);
    tm_ptr = gmtime(&the_time);

    printf("Raw time is %1d\n", the_time);
    printf("gmtime gives:\n");
    printf("date: %02d/%02d/%02d\n",
        tm_ptr->tm_year, tm_ptr->tm_mon+1, tm_ptr->tm_mday);
    printf("date: %02d/%02d/%02d\n",
           tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
    exit(0);
}