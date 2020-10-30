#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"
#include "utilities.h"

using namespace std;

int main(int argc, char** argv) {

    utilities util;
    util.readCommands(argv[1]);
    return 0;
}
