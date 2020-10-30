#include <iostream>
#include <cstring>
#include "dsstring.h"
#include "word.h"

using namespace std;

Word::Word(){
    theWord ="";
    positiveCounter = 0;
    negativeCounter = 0;
    posNegPoints = 0;
}

Word::Word(const char* newWord){
    theWord =newWord;
    positiveCounter = 0;
    negativeCounter = 0;
    posNegPoints = 0;
}

Word::Word(const DSString& newWord){
    theWord = newWord;
    positiveCounter = 0;
    negativeCounter = 0;
    posNegPoints = 0;
}

void Word::incramentPositive(){
    positiveCounter++;
}

void Word::incramentNegative(){
    negativeCounter++;
}

int Word::getPositive(){
    return positiveCounter;
}

int Word::getNegative(){
    return negativeCounter;
}

char* Word::getWord(){
    return theWord.c_str();
}


int Word::getPosNegPoints(){ // a way to deside if pos or neg



    if (positiveCounter > negativeCounter + 5){
        if(negativeCounter == 0 ){
            posNegPoints = 10;
        }
        else if ((double)negativeCounter/(double)positiveCounter < 0.1){
             posNegPoints = 10;
        }
        else if ((double)negativeCounter/(double)positiveCounter < 0.2){
            posNegPoints = 8;
        }
        else if ((double)negativeCounter/(double)positiveCounter < 0.3){
            posNegPoints = 6;
        }
        else if ((double)negativeCounter/(double)positiveCounter < 0.4){
            posNegPoints = 4;
        }
        else if ((double)negativeCounter/(double)positiveCounter < 0.5){
            posNegPoints = 2;
        }
        else{
            posNegPoints =0;
        }

    } // end if pos > neg

    else if(negativeCounter > positiveCounter + 5){
        if(positiveCounter == 0 ){
            posNegPoints = -10;
        }
        else if ((double)positiveCounter/(double)negativeCounter < 0.1){
             posNegPoints = -10;
        }
        else if ((double)positiveCounter/(double)negativeCounter < 0.2){
            posNegPoints = -8;
        }
        else if ((double)positiveCounter/(double)negativeCounter < 0.3){
            posNegPoints = -6;
        }
        else if ((double)positiveCounter/(double)negativeCounter < 0.4){
            posNegPoints = -4;
        }
        else if ((double)positiveCounter/(double)negativeCounter < 0.5){
            posNegPoints = -2;
        }
        else{
            posNegPoints =0;
        }

    }

    else{
        posNegPoints = 0;
    }

    return posNegPoints;
}
