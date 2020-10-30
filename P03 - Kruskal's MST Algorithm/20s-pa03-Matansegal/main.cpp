#include <iostream>
#include "preprocess.h"

int main() {
    preprocess graph10low("inputFiles/graph10low.txt");
    preprocess graph10dens("inputFiles/graph10dens.txt");

    preprocess graph50low("inputFiles/graph50low.txt");
    preprocess graph50dens("inputFiles/graph50dens.txt");

    preprocess graph100low("inputFiles/graph100low.txt");
    preprocess graph100dens("inputFiles/graph100dens.txt");

    preprocess graph200low("inputFiles/graph200low.txt");
    preprocess graph200dens("inputFiles/graph200dens.txt");

    preprocess graph500low("inputFiles/graph500low.txt");
    preprocess graph500dens("inputFiles/graph500dens.txt");

    return 0;
}
