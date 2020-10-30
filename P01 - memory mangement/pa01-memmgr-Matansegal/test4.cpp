//
// Created by matan on 2/13/2020.
//

#include "test4.h"

test4::test4(string s) {
    if(s == "small"){
        t1size = s;
        t2size = s;
    }
    else if (s == "med"){
        t1size = "med";
        t2size = s;
    }
    else if ( s =="large"){
        t1size = "med";
        t2size = "med";
    }
}

long test4::runTest() {
    auto time1 = chrono::high_resolution_clock::now();

    t1.runTest(t1size);
    t2.runTest(t2size);

    auto time2 = chrono::high_resolution_clock::now();
    runTime=chrono::duration_cast<std::chrono::microseconds>(time2 - time1).count();
    return runTime;
}

