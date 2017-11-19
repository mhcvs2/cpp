#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <time.h>

int main(int argc, char *argv[]) {
    int i;
    time_t the_time;
    for(i = 1; i <= 10; i++){
        the_time = time((time_t *)0);
        printf("The time is %1d\n", the_time);
        sleep(2);
    }

    exit(0);
}