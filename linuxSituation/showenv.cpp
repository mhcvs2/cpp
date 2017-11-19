#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>

extern char **environ;

int main(int argc, char *argv[]) {
    char **env = environ;
    while(*env){
        printf("%s\n", *env);
        env++;
    }

    exit(0);
}