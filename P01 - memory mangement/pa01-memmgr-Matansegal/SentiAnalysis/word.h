#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <cstring>
#include "dsstring.h"

class Word{
    private:
        DSString theWord;
        int positiveCounter;
        int negativeCounter;
        int posNegPoints;

    public:
        Word();
        Word(const char*);
        Word(const DSString&);
        void incramentPositive();
        void incramentNegative();
        int getPositive();
        int getNegative();
        char* getWord();
        int getPosNegPoints();

};

#endif // WORD_H
