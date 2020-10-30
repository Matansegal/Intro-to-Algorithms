//
// Created by matan on 4/10/2020.
//

#ifndef INC_20S_PA03_MATANSEGAL_PREPROCESS_H
#define INC_20S_PA03_MATANSEGAL_PREPROCESS_H

#include <string>
#include "utilities.h"
#include <fstream>

using namespace std;

class preprocess {
private:
    multiset<edge<string>> edgesList;
    set<string> indexList;
    int numOfelm;
public:
    preprocess(string);
};


#endif //INC_20S_PA03_MATANSEGAL_PREPROCESS_H
