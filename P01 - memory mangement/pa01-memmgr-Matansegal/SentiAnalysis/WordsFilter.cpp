#include <iostream>
#include "dsvector.h"
#include "dsstring.h"
#include "readingfiles.h"
#include "word.h"
#include "WordsFilter.h"

using namespace std;

//const DSString stopWords[106] = {"a","about","after","all","also","am","an","and","any","are","as","at",
//                                 "back", "be","because","but", "by",
//                                 "can","come","could","day","do","even","first","for","from",
//                                 "get","give","go","has","have","he","her","him","his","how",
//                                 "i","i'm","if","in","into","is","it","its","just","know",
//                                 "like","look", "make","me","most","my","new","no","not","now",
//                                 "of","on","one","only","or","other","our","out","over",
//                                 "people","say","see","she","so","some",
//                                 "take","than","that","the","their","them","then","there","these","they",
//                                 "think","this","time","to","too","two","up","us","use",
//                                 "want","was","way","we","well", "what", "when", "which","who","will",
//                                 "with", "would","year","you","you'r","your"};


int isExcist( DSString& checkWord, DSvector<Word> words[], int& letterPlace){
                                               // check if the word already in the vector
                                               // return the location or -1 if do not excist

    int limit = words[letterPlace].getSize();
    for(int i = 0 ; i < limit ; i++){
        if(checkWord == words[letterPlace].at(i).getWord()){
            return i;
        }
    }
    return -1;
}


//bool isStopWord( DSString& theWord, int begin, int end){  // binary search
//    int middle = (begin+end)/2;
//    if (theWord == stopWords[middle]){
//        return true;
//    }
//    else if (end <= begin){
//        return false;
//    }
//    else if ( theWord < stopWords[middle]){
//        isStopWord(theWord, begin, middle);
//    }
//    else{
//        isStopWord(theWord, middle + 1, end);
//    }
//}

int charToNumber(char& c){  // return the value 0 to 25 of the first letter

    return -97 + charToNumberBody(c,97,122); // ascii values of a and z
}

int charToNumberBody (char& c , int begin, int end){
    int middle = (begin+end)/2;
    if (c == middle){
        return middle;
    }
    else if (end <= begin){
        return -1;
    }
    else if (c > middle){
        charToNumberBody (c , middle+1, end);
    }
    else {
        charToNumberBody (c , begin, middle);
    }
}


// do a negative word function no not
