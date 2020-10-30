#include <iostream>
#include <fstream>
#include <iomanip>
#include "dsvector.h"
#include "dsstring.h"
#include "word.h"
#include "readingfiles.h"
#include "readTest.h"
#include "porter2_stemmer.h"
#include "WordsFilter.h"

using namespace std;

void readingTestDataTarget(char* testDataFile,char* testTargetFile, DSvector<Word> valuedWords[], char* outputFile){

    int rightModeling = 0;

    ifstream testData;
    ifstream testTarget;

    testData.open(testDataFile);
    testTarget.open(testTargetFile);

    if(!testData.is_open() || !testTarget.is_open()){
        cout << "Could not open the file!" << endl;
    }

    char firstLineTrain[100];    // not important
    testData.getline(firstLineTrain, 100);
    char firstLineTarget[100];
    testTarget.getline(firstLineTarget,100);

    // from Train file
    char row[10];
    char id[11];
    char user[100];
    char twit[1000];

    //from Target file
    char rowTarget[10];
    char posNeg[2];
    char idTarget[11];

    int i =0 ;
    while(!testData.eof()){

        //from train
        testData.getline(row,10,',');
        testData.getline(id,11,',');
        testData.getline(user,100,',');
        testData.getline(twit,1000);

        //from target
        testTarget.getline(rowTarget,10,',');
        testTarget.getline(posNeg,2,',');
        testTarget.getline(idTarget,11);

        int posNegPoints = checkWordPoints(valuedWords, twit);

        int realSentimate;   // 0 for neg 1 for pos
        if (posNeg[0] == '0'){ realSentimate = 0;}
        else { realSentimate = 1;}

        int modelSentimate = -1;
        if ( posNegPoints < 0){ modelSentimate = 0; }
        else { modelSentimate = 1; }

        if(realSentimate == modelSentimate){
            rightModeling++;
        }
        i++;
    } // end for loop

    testData.close();
    testTarget.close();

    sendToOutput(outputFile, rightModeling, i-rightModeling);
}


int checkWordPoints(DSvector<Word> valuedWords[], char* twit){ // return the sum of points from the twit

    int posNegPoints = 0;

    int j = 0; // pointer counter in twit

    while(twit[j] != '\0'){
        char theWord[21];
        if (readingWord( j, twit, theWord)) { continue; } // if word too long skip it

        DSString wordDS = theWord;

        Porter2Stemmer::trim(wordDS); // removed added chars
        Porter2Stemmer::stem(wordDS); // change it to base word

        //if (isStopWord(wordDS,0,105)){ continue; }    // if it is a stop world it will skip this word
        int letterPlace = charToNumber(wordDS[0]);
        if(letterPlace < 0){ continue; }// if it is not a letter
        int location = isExcist(wordDS, valuedWords, letterPlace);      // check if the word excist

        if (location > -1){
            posNegPoints = valuedWords[letterPlace].at(location).getPosNegPoints();
        }

    } // end while word

    return posNegPoints;
}

void sendToOutput(char* fileName, int correct, int incorrect){

//    ofstream outputFile;
//    outputFile.open(fileName);

    double accuracy = (double)correct/(double)(correct + incorrect);
    cout << fixed << setprecision(3);
    cout << accuracy << endl;
    cout << correct << ",c" << endl;
    cout << incorrect << ",i" << endl;

//    outputFile.close();

}


