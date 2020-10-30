#ifndef WORDSFILTER_H
#define WORDSFILTER_H

#include <iostream>
#include "dsvector.h"
#include "dsstring.h"
#include "word.h"


int isExcist( DSString& , DSvector<Word>[], int&);
bool isStopWord( DSString& , int , int );
int charToNumber (char& );
int charToNumberBody (char& , int , int );



#endif // WORDSFILTER_H
