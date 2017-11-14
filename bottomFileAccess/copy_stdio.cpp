#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main() {
    char block[1024];
    int in, out;
    int nread=1;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    while ((nread = read(in, block, sizeof(block))) > 0){
        write(out, block, nread);
    }
    exit(0);
    return 1;
}
