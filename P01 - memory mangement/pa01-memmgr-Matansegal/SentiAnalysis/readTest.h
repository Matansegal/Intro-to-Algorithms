#ifndef READTEST_H
#define READTEST_H

#include <iostream>
#include <fstream>
#include "dsvector.h"
#include "dsstring.h"
#include "word.h"

using namespace std;

void readingTestDataTarget(char*,char*, DSvector<Word>[], char*);
int checkWordPoints(DSvector<Word>[] , char*);
void sendToOutput(char* , int, int);

#endif // READTEST_H
