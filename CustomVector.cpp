//
// Created by misho on 2/19/2022.
//
#include "CustomVector.h"
#include <iostream>

using namespace std;

template <typename T>
CustomVector<T>::CustomVector(){
    vsize = 0;
    v = new T[vsize];
}
template <typename T>
CustomVector<T>::CustomVector(int size){
    vsize = size;
    v = new T[vsize];
    for(int i = 0;i<vsize;i++){
        v[i] = 0;
    }
}
template <typename T>
CustomVector<T>::CustomVector(const CustomVector& x){
    vsize = x.vsize;
    v = new T[vsize];
    for(int i = 0;i<vsize;i++){
        v[i] = x.v[i];
    }
}
template <typename T>
CustomVector<T>::~CustomVector(){
    delete[] v;
}
template <typename T>
T CustomVector<T>::at(int IND){
    return v[IND];
}
template <typename T>
CustomVector<T>::operator= (const CustomVector& x){
    delete[] v;
    vsize = x.vsize;
    v = new T[vsize];
    for(int i = 0;i<vsize;i++){
        v[i] = x.v[i];
    }
}
template <typename T>
void CustomVector<T>::print(){
    cout<<"size = "<<vsize<<endl;
    for(int i = 0;i<vsize;i++){
        cout<< v[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
bool CustomVector<T>::Empty(){
    return(vsize==0);
}

template <typename T>
void CustomVector<T>::Clear(){
    delete[] v;
    vsize = 0;
    v = new T[vsize];
}
template <typename T>
bool CustomVector<T>::valid_position(int pos){
    return(pos>=0&&pos<vsize);
}
template <typename T>
void CustomVector<T>::Push_back(T x){
    T *temp;
    temp = new T[vsize];
    for(int i = 0;i<vsize;i++){
        temp[i]=v[i];
    }
    vsize+=1;
    delete[] v;
    v = new T[vsize];
    for(int i = 0;i<vsize-1;i++){
        v[i]=temp[i];
    }
    delete[] temp;
    v[vsize-1]=x;
}
template <typename T>
void CustomVector<T>::Pop_back(){
    T *temp;
    temp = new T[vsize];
    for(int i = 0;i<vsize;i++){
        temp[i]=v[i];
    }
    vsize-=1;
    delete[] v;
    v = new T[vsize];
    for(int i = 0;i<vsize;i++){
        v[i]=temp[i];
    }
    delete[] temp;
}

template <typename T>
void CustomVector<T>::Insert(int position, const T element){

    if(vsize>position){
        vsize+=1;
        T *temp;
        temp = new T[vsize];
        for(int i = 0;i<position;i++){
            temp[i]=v[i];
        }
        temp[position]=element;
        for(int i = position;i<vsize;i++){
            temp[i+1]=v[i];
        }
        delete[] v;
        v = new T[vsize];
        for(int i = 0;i<vsize;i++){
            v[i]=temp[i];
        }
        delete[] temp;
    }else if( vsize == position){
        Push_back(element);
    }else{
        cout<<"no such index"<<endl;
    }
}

template <typename T>
void CustomVector<T>::Erase(int position){

    if(vsize>position){
        T *temp;
        temp = new T[vsize-1];
        for(int i = 0;i<position;i++){
            temp[i]=v[i];
        }
        for(int i = position+1;i<vsize;i++){
            temp[i-1]=v[i];
        }
        vsize-=1;
        delete[] v;
        v = new T[vsize];
        for(int i = 0;i<vsize;i++){
            v[i]=temp[i];
        }
        delete[] temp;
    }else{
        cout<<"no such index"<<endl;
    }
}

template <typename T>
void CustomVector<T>::Resize(int Size){

    if(Size>vsize){
        T *temp;
        temp = new T[Size];
        for(int i = 0;i<vsize;i++){
            temp[i]=v[i];
        }
        for(int i = vsize;i<Size;i++){
            temp[i]=0;
        }
        delete[] v;
        vsize = Size;
        v = new T[vsize];
        for(int i = 0;i<vsize;i++){
            v[i]=temp[i];
        }
        delete[] temp;
    }else{
        T *temp;
        temp = new T[Size];
        for(int i = 0;i<Size;i++){
            temp[i]=v[i];
        }
        delete[] v;
        vsize = Size;
        v = new T[vsize];
        for(int i = 0;i<vsize;i++){
            v[i]=temp[i];
        }
        delete[] temp;
    }
}

template <typename T>
int CustomVector<T>::Find(T element){
    int index = -1;
    for(int i =0;i<vsize;i++){
        if(v[i]==element){
            index = i;
        }
    }
    return index;
}