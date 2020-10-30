#include <iostream>
#include <fstream>
#include "dsvector.h"
#include "dsstring.h"
#include "readingfiles.h"
#include "word.h"
#include "WordsFilter.h"
//#include "porter2_stemmer.h"

using namespace std;

void readingTrainData(char* trainDataFile, char* targetDataFile, DSvector<Word> valuedWords[]){

    DSvector<Word> words[26];  // 0 for a -- 25 for z
    ifstream trainData;
    ifstream targetData;


    trainData.open(trainDataFile);
    //trainData.open("dev-train-data.csv");
    targetData.open(targetDataFile);
    //targetData.open("dev-train-target.csv");

    if(!trainData.is_open() || !targetData.is_open()){
        cout << "\n\nCould not open the file!@!!@!@\n" << endl;
    }

    char firstLineTrain[100];    // not important
    trainData.getline(firstLineTrain, 100);
    char firstLineTarget[100];
    targetData.getline(firstLineTarget,100);

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
    // up to 5000
    while(i < 20){

        //from train
        trainData.getline(row,10,',');
        trainData.getline(id,11,',');
        trainData.getline(user,100,',');
        trainData.getline(twit,1000);

        //from target
        targetData.getline(rowTarget,10,',');
        targetData.getline(posNeg,2,',');
        targetData.getline(idTarget,11);

        bool positive;
        if (posNeg[0] == '0'){ positive = false;}
        else { positive = true;}

        pushWord(words, twit, positive);
        i++;

    } // end for loop along the twit

    trainData.close();
    targetData.close();

    setValueWords(valuedWords, words);

}


void pushWord(DSvector<Word> words[], char* twit, bool isPositive){

    int j = 0; // pointer cointer in twit

    while(twit[j] != '\0'){
        char theWord[21];  // if word is too long cut it.
        if (readingWord( j, twit, theWord)) { continue; } // if word is too long skip it

        DSString wordDS = theWord;
//        Porter2Stemmer::trim(wordDS); // removed added chars
//        Porter2Stemmer::stem(wordDS); // change it to base word

        //if (isStopWord(wordDS,0,105)){ continue; }    // if it is a stop world it will skip this word
        int letterPlace = charToNumber(wordDS[0]);
        if(letterPlace < 0){ continue; }              // if it is not a letter
        int location = isExcist(wordDS, words, letterPlace);      // check if the word excist


        if(location > -1){      // if excist, use location to incrament pos/neg
            if (isPositive){ words[letterPlace].at(location).incramentPositive(); }
            else { words[letterPlace].at(location).incramentNegative(); }
        } // end if excist

        else if(wordDS.size() < 20){                   // if not excist push the word
            Word s(wordDS);
            if (isPositive){ s.incramentPositive(); }
            else { s.incramentNegative();}
            words[letterPlace].push_back(s);
        }

    } // end while word
}

bool readingWord(int& j , char* twit, char* theWord){
    int k = 0; // pointer counter for the word in the vector
    bool longShortWord = false;

    while (twit[j] != ' ' && twit[j] != '\0' && twit[j] != '.' && twit[j] != '"' && k < 20){
        theWord[k] = twit[j];
        if ((theWord[0] == 'n' || theWord[0] == 'N') && theWord[1]=='o' && theWord[2] == 't' ){
            j++;
        } // if there is "not"
        k++;
        j++;
    }  // when finished to read a word

    if (k == 20){  // if the word too long
        longShortWord = true;
        while (twit[j] != ' ' && twit[j] != '\0'){  //skip on the rest of the word
            j++;
        }
    }

    if (k < 3){
        longShortWord = true;
    }

    theWord[k] = '\0';
    k = 0;   // start a new word

    while (twit[j] == ' ' || twit[j] == '.' || twit[j] == '"'){  // for not collecting spaces
        j++;
    }

    return longShortWord;
}


void setValueWords(DSvector<Word> valuedWords[], DSvector<Word> words[]){
    for (int i = 0 ; i < 26 ; i++){
        int bound = words[i].getSize();
        for (int l = 0 ; l < bound ; l++){
            if(words[i].at(l).getPosNegPoints() != 0){
                valuedWords[i].push_back(words[i].at(l));
            }
        }
    }
}

