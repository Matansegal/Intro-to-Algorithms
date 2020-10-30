#ifndef DSVECTOR_H
#define DSVECTOR_H

#include <iostream>
#include <cstring>
#include "dsstring.h"

template <typename T>
class DSvector
{
    private:
        T* data;
        int capacity; // start capacity 10 , when resize it multiply by 2 each time
        int size;
        void resize();

    public:
        DSvector();
        DSvector(int);   // asssign the length of the vector
        DSvector<T>& operator=(const DSvector<T>&);
        ~DSvector();
        T& operator[] (const int);
        T& at(const int);
        void push_back(const T&);
        int getSize();
        int getCapacity();
        T& front();        // need to write the functions below
        T& back();
        T* cbegin();     // return pointer to the first element
        T* cend();
        T pop_back();  // pop -  return last element and decreading size
        void swap(int, int); // swap - get n and k switch
        void insert(T&, const int&); // insert in the given position

};


template <typename T>
DSvector<T>::DSvector(){
    capacity = 10;
    size = 0;
    data = new T[capacity];
}

template <typename T>
DSvector<T>::DSvector(int x){
    capacity = x;
    size = 0;
    data = new T[capacity];
}

template <typename T>
DSvector<T>& DSvector<T>::operator=(const DSvector<T>& v){
    delete [] data;
    capacity = v.capacity;
    size = v.size;
    data = new T[capacity];

    for (int i = 0 ; i < v.size ; i++){
        data[i] = v.data[i];
    }
    return *this;
}

template <typename T>
DSvector<T>::~DSvector(){
    //delete [] data;
}


template <typename T>
T& DSvector<T>::operator[](const int index){
    return data[index];
}

template <typename T>
T& DSvector<T>::at(const int index){
    return data[index];
}

template <typename T>
void DSvector<T>::push_back(const T& newData){
    data[size] = newData;
    size++;

    if (size == capacity){
        resize();
    }
}


template <typename T>
void DSvector<T>::resize(){
    capacity = 2*capacity;
    T* temp = data;
    data = new T[capacity];
    for(int i = 0 ; i < size ; i++){
        data[i] = temp[i];
    }
    delete [] temp;
}


template <typename T>
int DSvector<T>::getSize(){
    return size;
}


template <typename T>
int DSvector<T>::getCapacity(){
    return capacity;
}

template <typename T>
T& DSvector<T>::front(){
    return data[0];
}

template <typename T>
T& DSvector<T>::back(){
    return data[size-1];
}

template <typename T>
T* DSvector<T>::cbegin(){
    return &(data[0]);
}

template <typename T>
T* DSvector<T>::cend(){
    return &(data[size-1]);
}

template <typename T>
T DSvector<T>::pop_back(){
    T element = data[size-1];
    size--;
    return element;
}

template <typename T>
void DSvector<T>::swap(int index1, int index2){
    T temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
}


template <typename T>
void DSvector<T>::insert(T& element, const int& location){

    T* temp = data;
    capacity++;      // just in case pass the capacity
    size++;
    data = new T[capacity];
    for (int i = 0 ; i < location ; i++){
        data[i] = temp[i];
    }
    data[location] = element;
    for (int i = location + 1 ; i < size ; i++){
        data[i] = temp[i-1];
    }
    delete [] temp;

}

#endif // DSVECTOR_H
