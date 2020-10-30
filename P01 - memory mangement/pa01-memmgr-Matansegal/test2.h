//
// Created by matan on 2/10/2020.
//

#ifndef INC_20S_3353_PA01_TEST2_H
#define INC_20S_3353_PA01_TEST2_H

#include <iostream>
#include <chrono>

using namespace std;

class foo{
private:
    int a;
    long b;
    char c;
    string d;
    double e;
    long long f;
public:
    foo(){

    }
    ~foo(){

    }
};

class test2 {
private:
    long runTime;
    foo** ptrArray[100000];
    int dataSize;
    void setDataSize(string);
public:
    test2();
    long runTest(string);
};


#endif //INC_20S_3353_PA01_TEST2_H
