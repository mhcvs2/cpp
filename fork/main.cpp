#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main() {
    pid_t pid;
    cout << "Now only one process" << endl;
    cout << "Calling fork..." <<endl;
    pid=fork();
    if(!pid) {    //pid = 0
        cout << "I’m the child" << endl;
    } else if(pid > 0) {
        cout << "I’m the parent, child has pid " << pid << endl;
    } else {   //pid = -1
        cout << "fork failed" << endl;
    }
    return 0;
}

/*
Now only one process
Calling fork...
I’m the parent, child has pid 15444
I’m the child
 * */