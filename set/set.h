//
// Created by yons on 2017/10/17.
//

#ifndef SET_SET_H
#define SET_SET_H

class MySet
{
private:
    char *d[100];
    int maxl;

public:
    MySet(int l);

    void add(char x);

    void remove(char x);

    int size();

    bool contain(char x);

};

#endif //SET_SET_H
