//
// Created by matan on 1/29/2020.
//

#ifndef PROJECT1_CS3353_ALLOCATOR_H
#define PROJECT1_CS3353_ALLOCATOR_H

#include <cstdlib>
#include <iostream>
#include "BookKeepingNode.h"
#include "myAllocator.h"
#include <iterator>
#include <map>

using namespace std;

class Allocator {
protected:
    int totalMem;
    void* pool;
    int poolAddress;
    int next;
    //buffer for tracking memory used by arrays
    BookKeepingNode* BookKeep[100000][671]; // 2D array ,map of bookkeeping node list, which each key - the index of the first dimention
                                // is the last start address divide by 2684 || 100,000, each contains 2684 bytes.
                                // the second dimension contains 2684/4 = 671 indexes
                                // last address = (index +1)*2684 + poolAddress || index = (address - poolAddress)/2684

    BookKeepingNode* freeList[10000][1000];
                                        // there will be jumps of 100. each group will represent a group of memory:
                                        // dimension 1 index 0-99 will represent up to 399 bytes.
                                        // index 100 to 199 are 401 to 800 bytes
                                        // means the location starts at: index = (bytes/400)*100 since all are int
                                        // the first node set the length of the other nodes in the second dimension
                                        // and inside of a group of 100 indexes it will not be in order
                                        // if we get index larger than the last group, store in last group

    map<int, int, std::less<int>, myAllocator<pair<int,int>> > freeAddresses[100000]; // follow continuoes address
    map<int, int>::iterator itr;                                            // first address second size, organize like the bookKeep
    bool addedToFreeAdd;

public:
    Allocator(const size_t);
    virtual ~Allocator();
    void releaseMemory();
    // for new operator
    virtual void* addToMemory(size_t bytes, bool isArray = false) = 0;
    // for delete
    void freeMemory(void* p, bool isArray = false, int s = 0);
    void updateFreeAdds(BookKeepingNode*&);
    BookKeepingNode* findFreelistItem(int, void* startAdd= nullptr);
    void addToFreeList(BookKeepingNode*&);
    int getNext();


};


#endif //PROJECT1_CS3353_ALLOCATOR_H
