#ifndef READINGFILES_H
#define READINGFILES_H

#include <iostream>
#include <fstream>
#include "dsvector.h"
#include "dsstring.h"
#include "word.h"

using namespace std;

void readingTrainData(char*,char*, DSvector<Word>[]);
void pushWord(DSvector<Word>[], char*, bool);
bool readingWord(int& , char*, char*);
void setValueWords(DSvector<Word>[], DSvector<Word>[]);


#endif // READINGFILES_H
