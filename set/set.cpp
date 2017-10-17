//
// Created by yons on 2017/10/17.
//
#include "set.h"

MySet::MySet(int l) {
    maxl = l;
//    d = new char[maxl];
    for(int i=0; i<maxl; i++){
        *d[i] = '\0';
    }
}

int MySet::size() {
    for(int i=0; i<maxl; i++){
        if(*d[i] == '\0'){
            return i;
        }
    }
    return maxl;
}

bool MySet::contain(char x) {
    for(int i=0; i<maxl; i++){
        if(*d[i] == x){
            return true;
        } else if(*d[i]=='\0'){
            break;
        }
    }
    return false;
}

void MySet::add(char x) {
    if(!contain(x)){
        *d[size()] = x;
    }
}

void MySet::remove(char x) {
    for(int i=0; i<maxl; i++){
        if(*d[i] == x){
            for(int j=i;j<maxl;j++){
                if(*d[j]=='\0'){ break; }
                d[j] = d[j+1];
            }
        }
    }
}
