#include <iostream>
#include <set>
#include "set.h"

using namespace std;

void t1(){
    int i;
    int arr[5] = {0,1,2,3,4};
    set<int> iset(arr, arr+5);

    iset.insert(5);
    cout << "size:" << iset.size() << endl;
    cout << "3 count="<< iset.count(3)<<endl;
    iset.erase(1);

    set<int>::iterator itel = iset.begin();
    set<int>::iterator itel2 = iset.end();
    for(;itel!=itel2;itel++){
        cout<<*itel;
    }
    cout<<endl;
    itel = iset.find(3);
    if(itel!=iset.end())
        cout<<"3 found"<<endl;
    itel = iset.find(1);
    if(itel==iset.end())
        cout<<"1 not found"<<endl;
}

void t2(){
    int i;
    string arr[5] = {"a","b","c","d","e"};
    set<string> iset(arr, arr+31000);

    iset.insert("f");
    cout << "size:" << iset.size() << endl;
    cout << "a count="<< iset.count("a")<<endl;
    iset.erase("b");

    set<string>::iterator itel = iset.begin();
    set<string>::iterator itel2 = iset.end();
    for(;itel!=itel2;itel++){
        cout<<*itel;
    }
    cout<<endl;
    itel = iset.find("e");
    if(itel!=iset.end())
        cout<<"e found"<<endl;
    itel = iset.find("b");
    if(itel==iset.end())
        cout<<"b not found"<<endl;
}

void t3(){
    int i;
    set<string> iset;

    iset.insert("f");
    cout << "size:" << iset.size() << endl;
    cout << "a count="<< iset.count("a")<<endl;
    iset.erase("b");

    set<string>::iterator itel = iset.begin();
    set<string>::iterator itel2 = iset.end();
    for(;itel!=itel2;itel++){
        cout<<*itel;
    }
    cout<<endl;
    itel = iset.find("e");
    if(itel!=iset.end())
        cout<<"e found"<<endl;
    itel = iset.find("b");
    if(itel==iset.end())
        cout<<"b not found"<<endl;
}

void t4(){
    MySet *s = new MySet(100);
    string ss = "abdsdfsdf";
    for (int i = 0; i < ss.size(); i++) {
        s->add(ss[i]);
    }
    cout<<s->size()<<endl;
}

int main() {
    t4();
    return 0;
}