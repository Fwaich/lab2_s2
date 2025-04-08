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
    ArraySequence<T>* get_subsequence(int start_index, int end_index);


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

template <typename T>
ArraySequence<T>* ArraySequence<T>::get_subsequence(int start_index, int end_index){
    if (!items) throw logic_error("Array data is null");

    if (start_index < 0 || start_index >= items->get_size() ||
        end_index < 0 || end_index >= items->get_size()) {
        throw out_of_range("start||end out of bounds");
    }

    if (start_index > end_index){
        int tmp = end_index;
        end_index = start_index;
        start_index = tmp;
    }

    int sub_size = end_index - start_index + 1;
    T* sub_data = new T[sub_size];

    int j = 0;
    for (int i = start_index; i < end_index + 1; i++) {
        sub_data[j++] = items->get(i);
    }

    ArraySequence<T>* sub_array = new ArraySequence<T>(sub_data, sub_size);
    delete[] sub_data;
    return sub_array;
}