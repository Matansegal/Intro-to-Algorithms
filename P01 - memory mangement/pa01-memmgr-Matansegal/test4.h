//
// Created by matan on 2/13/2020.
//

#ifndef INC_20S_3353_PA01_TEST4_H
#define INC_20S_3353_PA01_TEST4_H

#include <string>
#include "test1.h"
#include "test2.h"

using namespace std;

class test4 {
private:
    test1 t1;
    test2 t2;
    long runTime;
    string t1size;
    string t2size;
public:
    test4(string s);
    long runTest();
};


#endif //INC_20S_3353_PA01_TEST4_H
