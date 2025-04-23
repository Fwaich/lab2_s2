#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
#include "LinkedList.h"
#include "Sequence.h"

template <typename T>
class ListSequence: public Sequence<T>
{
private:
    LinkedList<T>* items;
public:

    ListSequence();
    ListSequence(T* arr, int count);
    ListSequence(Sequence<T>& seq);
    ListSequence(const LinkedList<T>& list);
    ~ListSequence() override;

    void append(T item) override;
    void prepend(T item) override;
    void set(int index, T item) override;
    T get(int index) override;
    T get_first() override;
    T get_last() override;
    int get_size() override;
    ListSequence<T>* get_subsequence(int start_index, int end_index) override;

    void print() override{
        items->print();
    }

};

template <typename T>
ListSequence<T>::ListSequence(){
    items = new LinkedList<T>;
};

template <typename T>
ListSequence<T>::ListSequence(T* arr, int count){
    items = new LinkedList<T>(arr, count);
};

template <typename T>
ListSequence<T>::ListSequence(Sequence<T>& seq){
    items = new LinkedList<T>();

    for (int i = 0; i < seq.get_size(); i++){
        items->append(seq.get(i));
    }
}

template <typename T>
ListSequence<T>::ListSequence(const LinkedList<T>& list){
    items = new LinkedList<T>(list);
}

template <typename T>
ListSequence<T>::~ListSequence(){
    delete items;
};

template <typename T>
void ListSequence<T>::append(T item){
    items->append(item);
};

template <typename T>
void ListSequence<T>::prepend(T item){
    items->prepend(item);
};

template <typename T>
void ListSequence<T>::set(int index, T value){
    items->set(index, value);
};

template <typename T>
T ListSequence<T>::get(int index){
    return items->get(index);
};

template <typename T>
T ListSequence<T>::get_first(){
    if (items->get_length() == 0)  throw out_of_range("get_first: list not initialized");
    return items->get_first();
};

template <typename T>
T ListSequence<T>::get_last(){
    if (items->get_length() == 0)  throw out_of_range("get_last: list not initialized");
    return items->get_last();
};

template <typename T>
int ListSequence<T>::get_size(){
    return items->get_length();
};

template <typename T>
ListSequence<T>* ListSequence<T>::get_subsequence(int start_index, int end_index){
    LinkedList<T>* sublist = items->get_sublist(start_index, end_index);
    ListSequence<T>* sublist_sequence = new ListSequence<T>(*sublist);
    delete sublist;
    return sublist_sequence;
};
