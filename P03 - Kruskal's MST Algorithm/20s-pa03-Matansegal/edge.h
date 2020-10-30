//
// Created by matan on 3/9/2020.
//

#ifndef INC_20S_PA02_MATANSEGAL_EDGE_H
#define INC_20S_PA02_MATANSEGAL_EDGE_H


using namespace std;

template <typename T>
class edge {
private:
    T elm1;
    T elm2;
    mutable int weight;

public:
    edge();
    edge(T,int,T);
    edge(const edge<T>&);
    edge<T>& operator=(const edge<T>&);
    bool operator==(const edge<T>&) const;
    bool operator<(const edge<T>&) const;
    int getWeight() const;
    T getIndex1() const;
    T getIndex2() const;

    // if it is in the edge
    bool contains(T) const;
    string print() const;

};

template<typename T>
edge<T>::edge(){
    weight = 0;
}

template<typename T>
edge<T>::edge(T a, int w, T b) {
    // keep elm1 smaller than elm2
    if (a < b){
        elm1 = a;
        elm2 = b;
    }
    else{
        elm1 = b;
        elm2 = a;
    }

    weight = w;
}

template<typename T>
edge<T>::edge(const edge<T> &e) {
    elm1 = e.elm1;
    elm2 = e.elm2;
    weight = e.weight;
}

template<typename T>
edge<T> &edge<T>::operator=(const edge<T> &e) {
    elm1 = e.elm1;
    elm2 = e.elm2;
    weight = e.weight;
    return *this;
}

template<typename T>
bool edge<T>::operator==(const edge<T> &e) const {
    if(elm1 == e.elm1 && elm2 == e.elm2){
        return true;
    }
    // or the opposite
    if(elm1 == e.elm2 && elm2 == e.elm1){
        return true;
    }
    return false;
}

// need for the set
template<typename T>
bool edge<T>::operator<(const edge<T> &e) const{
    return this->weight < e.weight;
}

template<typename T>
string edge<T>::print() const{
    return "(" + elm1 + "," + to_string(weight) + "," + elm2 + ") ";
}

template<typename T>
bool edge<T>::contains(T x) const{
    return elm1 == x || elm2 == x;
}

template<typename T>
int edge<T>::getWeight() const{
    return weight;
}

template<typename T>
T edge<T>::getIndex1() const{
    return  elm1;
}

template<typename T>
T edge<T>::getIndex2() const{
    return  elm2;
}

#endif //INC_20S_PA02_MATANSEGAL_EDGE_H
