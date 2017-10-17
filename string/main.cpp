#include <iostream>
#include <string>
using namespace std;

void t1(){
    string s = "123,456,789aaa";
    unsigned int iSize = s.size();
    cout<<iSize<<endl;
    cout<<s.length()<<endl;

    unsigned int i = 0;
    int iCount = 0;
    for(i=0; i<iSize; i++){
        cout<<s[i]<<endl;
        if(',' == s[i])
        {
            iCount++;
        }
    }
    cout<<iCount<<endl;
}

//11
//11
//2


int main() {
    t1();
    return 0;
}