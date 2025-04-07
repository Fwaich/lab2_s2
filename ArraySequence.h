#pragma once
#include <iostream>
#include "DynamicArray.h"

template <typename T>
class ArraySequence 
{
private:
    DynamicArray<T>* items;
public:

    ArraySequence();
    ArraySequence(T* arr, int count);
    ~ArraySequence();

    T get(int index);
    T get_first();
    T get_last();
    int get_size();


    void print() {
        items->print();
    }
};

template <typename T>
ArraySequence<T>::ArraySequence(){
    items = new DynamicArray<T>;
}

template <typename T>
ArraySequence<T>::ArraySequence(T* arr, int count){
    items = new DynamicArray<T>(arr, count);
}

template <typename T>
ArraySequence<T>::~ArraySequence(){
    delete items;
}

template <typename T>
T ArraySequence<T>::get(int index){
    return items->get(index);
}

template <typename T>
int ArraySequence<T>::get_size(){
    return items->get_size();
}

template <typename T>
T ArraySequence<T>::get_first(){
    if (items->get_size() == 0) throw out_of_range("Array not initialized");
    return items->get(0);
}

template <typename T>
T ArraySequence<T>::get_last(){
    int size_of_array = items->get_size();
    if (size_of_array == 0) throw out_of_range("Array not initialized");
    return items->get(size_of_array - 1);
}