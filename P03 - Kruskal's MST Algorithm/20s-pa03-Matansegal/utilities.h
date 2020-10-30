//
// Created by matan on 3/1/2020.
//

#ifndef INC_20S_PA02_MATANSEGAL_UTILITIES_H
#define INC_20S_PA02_MATANSEGAL_UTILITIES_H

#include <fstream>
#include <string>
#include "edge.h"
#include "index.h"
#include <set>
#include "disjointListIndex.h"
#include "disjointTreeIndex.h"

class utilities {
private:
    multiset<edge<string>> mst;
    index* djli;
    string type;

public:
    utilities(string, int);
    ~utilities();
    void kruskals(multiset<edge<string>>&, string& );
    int getMSTweight();
};


#endif //INC_20S_PA02_MATANSEGAL_UTILITIES_H
