#include <iostream>
#include "dsstring.h"

using namespace std;

DSString::DSString(){
    data = new char[1];
    data[0] = '\0';
}


DSString::DSString(const char* newData){
    data = new char[strlen(newData)+1];
    int i = 0;
    while (newData[i]){
        data[i] = newData[i];
        i++;
    }
    data[i]='\0';
}


DSString::DSString(const DSString& newData){
    data = new char[strlen(newData.data)+1];
    int i = 0;
    while (newData.data[i]){
        data[i] = newData.data[i];
        i++;
    }
    data[i]='\0';

}


DSString::~DSString(){
    delete [] data;
}


DSString& DSString:: operator=(const char * newData){
    delete [] data;
    data = new char[strlen(newData)+1];
    int i = 0;
    while (newData[i]){
        data[i] = newData[i];
        i++;
    }
    data[i]='\0';

    return *this;
}


DSString& DSString:: operator=(const DSString& newData){
    delete [] data;
    data = new char[strlen(newData.data)+1];
    int i = 0;
    while (newData.data[i] && i < 30){
        data[i] = newData.data[i];
        i++;
    }
    data[i]='\0';

    return *this;
}

DSString DSString:: operator+(const DSString& newData){
    char* temp = data;
    this->data = new char[strlen(temp)+strlen(newData.data)+1];
    strcpy(this->data,temp);
    strcat(this->data,newData.data);

    delete [] temp;
    return *this;

}


DSString& DSString:: operator+=(const DSString& newData){
    char* temp = this->data;
    this->data = new char[strlen(temp)+strlen(newData.data)+1];
    strcpy(this->data,temp);
    strcat(this->data,newData.data);

    delete [] temp;
    return *this;

}

DSString& DSString:: operator+=(const char* newData){
    char* temp = this->data;
    this->data = new char[strlen(temp)+strlen(newData)+1];
    strcpy(this->data,temp);
    strcat(this->data,newData);

    delete [] temp;
    return *this;

}


bool DSString:: operator==(const char* newData) const{
    if ( newData != nullptr && strlen(newData) != strlen(data)){
        return false;
    }
    for(unsigned int i = 0; i < strlen(newData); i++){
        if (this->data[i] != newData[i]){
            return false;
        }
    }
    return true;
}


bool DSString:: operator==(const DSString& newData) const{
    if ( strlen(newData.data) != strlen(data)){
        return false;
    }
    for(unsigned int i = 0; i < strlen(newData.data); i++){
        if (this->data[i] != newData.data[i]){
            return false;
        }
    }
    return true;
}


bool DSString:: operator<(const char* newData){

    int i = 0;
    while (data[i]==newData[i]){
        i++;
    }
    if (data[i] < newData[i])
        return true;
    return false;
}


bool DSString:: operator<(const DSString& newData){

    int i = 0;
    while (data[i]==newData.data[i]){
        i++;
    }
    if (data[i] < newData.data[i]){
        return true;
    }
    return false;
}


char& DSString:: operator[](const int index){
    return data[index];
}


int DSString:: size(){
    return strlen(data);
}


DSString DSString:: substring(int a ,int b){
    char* newString = new char[abs(b)+1];

    int i = 0;
    while (i < abs(b)){
        if (b > 0){
            newString[i] = data[a+i];
        }
        else if (b < 0){               // if b negative go backword
            newString[abs(b)-1-i] = data[a-i];
        }
        i++;
    }

    newString[i] = '\0';

    return newString;
}


char* DSString::c_str(){
    return data;
}


ostream& operator<<(ostream& output, const DSString& newData){
    output << newData.data;
    return output;
}


istream& operator>> (istream& input, DSString& myString){
    input >> myString.data;
    return input;
}



/*
void DSString::getline(std::istream& file, char* inVar, char delimiter = '\n'){
    int i = 0;
    //char ch;
    while (file.get() != delimiter){
        inVar[i] = file.get();
        i++;
    }

}

*/










