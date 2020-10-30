#include <iostream>
#include "AloMemory.h"
#include "test1.h"
#include "test2.h"
#include "test3.h"
#include "test4.h"
#include "SentiAnalysis/SentAnal.h"

using namespace std;

int main(int argc, char *argv[]) {
    for(int i=0; i<argc; i++){
        cout<<argv[i]<<endl;
    }
    long runTime;
    string testKind = argv[2];
    // argv[1] = '-m' for MyFit, '-b' for BestFit, '-f' for FirstFit
    Allocator* AS = AllocatorSingleton::initMemory(256 * pow(2,20), argv[1]); // 1 Mb = pow(2,20)
    //argv[2] = test || argv[3] = data size
    if (testKind == "t1"){
        test1 t1;
        runTime = t1.runTest(argv[3]);
    }
    else if (testKind == "t2"){
        test2 t2;
        runTime = t2.runTest(argv[3]);
    }

    else if (testKind == "t3"){
        test3 t3;
        runTime = t3.runTest(argv[3]);
    }

    else if (testKind == "t4"){
        test4 t4(argv[3]);
        runTime = t4.runTest();
    }


    else if (testKind == "sa"){
        SentAnal tSA;
        runTime = tSA.runTest();
    }



    cout << "Test " << argv[2] << " took " << runTime << " microseconds" << endl;
    cout << "Memory pointer is at: " << AS->getNext() << endl;

    AS->releaseMemory();
    return 0;
}


