//
// Created by matan on 1/29/2020.
//

#ifndef PROJECT1_CS3353_ALLOCATORSINGLETON_H
#define PROJECT1_CS3353_ALLOCATORSINGLETON_H

#include "Allocator.h"
#include "MyFit.h"
#include "FirstFit.h"
#include "BestFit.h"

class AllocatorSingleton {
private:
    AllocatorSingleton() = default;
    static Allocator* alloc;

public:
    // argv[1] = '-m' for MyFit, '-b' for BestFit, '-f' for FirstFit
    static Allocator* initMemory(size_t numOfMem = 0, string fitKind = ""){
        // initialize in the global file - AloMemory
        if (alloc == nullptr) {
            // CANNOT DO THIS BECAUSE SEND TO ITSELF!!
            alloc = (Allocator *) malloc(sizeof(Allocator));
        }
        // when called in main
        else {
            if(fitKind == "-m"){
                new(alloc) MyFit(numOfMem);
            }
            else if(fitKind == "-b"){
                new(alloc) BestFit(numOfMem);
            }
            else if(fitKind == "-f"){
                new(alloc) FirstFit(numOfMem);
            }
        }
        return alloc;
    }


};



#endif //PROJECT1_CS3353_ALLOCATORSINGLETON_H
