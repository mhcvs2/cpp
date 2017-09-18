#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

//int execl( const char *path, const char *arg, ...);
//int execle( const char *path, const char *arg , ..., char* const envp[]);
//int execv( const char *path, char *const argv[]);
//int execlp( const char *file, const char *arg, ...);   从PATH里找
//int execvp( const char *file, char *const argv[]);     从PATH里找

void t1() {
    cout << "Executing ls" << endl;
    execl("/bin/ls","ls","-l",NULL);
    perror("execl failed to run ls");
    exit(1);
}
/*覆盖掉原进程
Executing ls
总用量 84
-rw-r--r--. 1 root root 32211 9月  18 10:46 CMakeCache.txt
drwxr-xr-x. 5 root root  4096 9月  18 10:50 CMakeFiles
-rw-r--r--. 1 root root  1378 9月  18 10:46 cmake_install.cmake
-rwxr-xr-x. 1 root root 26360 9月  18 10:50 execl
-rw-r--r--. 1 root root  5309 9月  18 10:46 execl.cbp
-rw-r--r--. 1 root root  4886 9月  18 10:46 Makefile
 * */

void t2() {
    char* av[]={"ls","-l",NULL};
    execv("/bin/ls",av);
    perror("execv failed");
    exit(1);
}

void t3() {
    int pid;
/* fork 子进程 */
    pid=fork();
    switch(pid) {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            execl("/bin/ls","ls","-l","--color",NULL);
            perror("execl failed");
            exit(1);
        default:
            wait();
            printf("ls completed\n");
            exit(0);
    }
}

int docommand(char* command)
{
    int pid;
    switch(pid=fork())
    {
        case -1:
            return -1;
        case 0:
            execl("/bin/sh","sh","-c",command,NULL);
            exit(127);
        default:
            wait();
    }
    return 0;
}

int main() {
    t3();
    return 0;
}
