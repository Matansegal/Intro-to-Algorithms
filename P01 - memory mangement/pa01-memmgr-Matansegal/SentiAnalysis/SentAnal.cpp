//
// Created by matan on 2/11/2020.
//

#include "SentAnal.h"

using namespace std;


SentAnal::SentAnal() {
    strncpy(argv1, "PA02Files/train-data.csv", 50);
    strncpy(argv2, "PA02Files/train-target.csv", 50);
    strncpy(argv3, "PA02Files/test-data.csv", 50);
    strncpy(argv4, "PA02Files/test-target.csv", 50);

}

long SentAnal::runTest() {
    DSvector<Word> valuedWords[26];
    auto t1 = chrono::high_resolution_clock::now();
    readingTrainData(argv1, argv2, valuedWords);

//    readingTestDataTarget(argv3, argv4, valuedWords, argv5);
    auto t2 = chrono::high_resolution_clock::now();
    runTime=chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    cout << "done!" << endl;
    return runTime;
}
