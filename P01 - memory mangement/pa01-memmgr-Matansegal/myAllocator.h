//
// Created by matan on 2/11/2020.
//

#ifndef INC_20S_3353_PA01_MYALLOCATOR_H
#define INC_20S_3353_PA01_MYALLOCATOR_H

#include <iostream>

using namespace std;

template <class T>
class myAllocator {
public:
    typedef T value_type;

    T* allocate(std::size_t n) {
        //cout << "Custom vector alloc" << endl;
        return static_cast<T*>(std::malloc(n*sizeof(T)));
    }

    void deallocate(T* p, std::size_t)noexcept {
        //cout << "Custom vector dealloc" << endl;
        std::free(p);
    }

};


#endif //INC_20S_3353_PA01_MYALLOCATOR_H
