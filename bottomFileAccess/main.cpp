#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

using namespace std;

int is_begin_with(const char * str1,char *str2)
{
    if(str1 == NULL || str2 == NULL)
        return -1;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if((len1 < len2) || (len1 == 0 || len2 == 0))
        return -1;
    char *p = str2;
    int i = 0;
    while(*p != '\0')
    {
        if(*p != str1[i])
            return 0;
        p++;
        i++;
    }
    return 1;
}

int is_end_with(const char *str1, char *str2)
{
    if(str1 == NULL || str2 == NULL)
        return -1;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if((len1 < len2) || (len1 == 0 || len2 == 0))
        return -1;
    while(len2 >= 1)
    {
        if(str2[len2 - 1] != str1[len1 - 1])
            return 0;
        len2--;
        len1--;
    }
    return 1;
}

void printdir(char *dir, int depth){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if((dp = opendir(dir)) == NULL){
        fprintf(stderr, "can't open directory: %s\n", dir);
        return;
    }
    chdir(dir);
    while ((entry = readdir(dp)) != NULL){
        lstat(entry->d_name, &statbuf);
        if(S_ISDIR(statbuf.st_mode)){
            if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0 || is_begin_with(entry->d_name, ".") == 1){
                continue;
            }
            printf("%*s%s/\n", depth,"",entry->d_name);
            printdir(entry->d_name, depth+4);
        }else {
            if(is_begin_with(entry->d_name, ".") == 1){
                continue;
            }
            printf("%*s%s\n", depth,"",entry->d_name);
        }
    }
    chdir("..");
    closedir(dp);
}

void usage(){
    printf("Usage:\n");
    printf("%*sprintdir /path/to/dir_name\n", 5,"");
}

int main(int argc,char** argv) {
    if (argc < 2){
        usage();
        exit(1);
    }
    printf("Directory scan of %s:\n", argv[1]);
    printdir(argv[1], 0);
    printf("done.\n");
    exit(0);
}
