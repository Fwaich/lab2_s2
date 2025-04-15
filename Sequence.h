#pragma once

template <typename T>
class Sequence
{
public:

    virtual ~Sequence() = 0;
    virtual T get(int index) = 0;
    virtual T get_first() = 0;
    virtual T get_last() = 0;
    virtual int get_size() = 0;
    virtual Sequence<T>* get_subsequence(int start_index, int end_index) = 0;

    virtual void print() = 0;
};

template <typename T>
Sequence<T>::~Sequence() {}