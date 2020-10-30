//
// Created by matan on 2/11/2020.
//

#ifndef INC_20S_3353_PA01_SENTANAL_H
#define INC_20S_3353_PA01_SENTANAL_H

#include <iostream>
#include <fstream>
#include "dsvector.h"
#include "dsstring.h"
#include "readingfiles.h"
#include "readTest.h"
#include "word.h"
#include <chrono>

using namespace std;

class SentAnal {
public:
    SentAnal();
    long runTest();


private:
    char argv1[50];
    char argv2[50];
    char argv3[50];
    char argv4[50];
    char argv5[50];
    long runTime;
};


#endif //INC_20S_3353_PA01_SENTANAL_H
