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
    mutable double betweenness;

public:
    edge();
    edge(T,T);
    edge(const edge<T>&);
    edge<T>& operator=(const edge<T>&);
    bool operator==(const edge<T>&) const;
    bool operator<(const edge<T>&) const;

    // if it is in the edge
    bool contains(T) const;
    string print() const;

};

template<typename T>
edge<T>::edge(){
    betweenness = 0;
}

template<typename T>
edge<T>::edge(T a, T b) {
    // keep elm1 smaller than elm2
    if (a < b){
        elm1 = a;
        elm2 = b;
    }
    else{
        elm1 = b;
        elm2 = a;
    }

    betweenness = 0;
}

template<typename T>
edge<T>::edge(const edge<T> &e) {
    elm1 = e.elm1;
    elm2 = e.elm2;
    betweenness = e.betweenness;
}

template<typename T>
edge<T> &edge<T>::operator=(const edge<T> &e) {
    elm1 = e.elm1;
    elm2 = e.elm2;
    betweenness = e.betweenness;
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
    if(this->elm1 < e.elm1){
        return true;
    }
    return this->elm1 == e.elm1 && elm2 < e.elm2;
}

template<typename T>
string edge<T>::print() const{
    return "(" + elm1 + "," + elm2 + ") ";
}

template<typename T>
bool edge<T>::contains(T x) const{
    return elm1 == x || elm2 == x;
}


#endif //INC_20S_PA02_MATANSEGAL_EDGE_H
