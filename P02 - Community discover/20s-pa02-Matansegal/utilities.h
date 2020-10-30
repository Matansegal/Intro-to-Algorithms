//
// Created by matan on 3/1/2020.
//

#ifndef INC_20S_PA02_MATANSEGAL_UTILITIES_H
#define INC_20S_PA02_MATANSEGAL_UTILITIES_H

#include <fstream>
#include "graph.h"

class utilities {
private:
    graph<string> g;
public:
    utilities();
    ~utilities();
    void readCommands(string);
    void makeGraph(string);

};


#endif //INC_20S_PA02_MATANSEGAL_UTILITIES_H
