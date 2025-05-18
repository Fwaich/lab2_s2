#pragma once
#include "core/Adapter.h"
#include "core/Sequence.h"

class DoubleAdapter : public Adapter 
{
private:
    Sequence<double>* sequence;

    double from_string(std::string str) {
        return std::stod(str);
    }

public:

    DoubleAdapter(Sequence<double>* seq){
        sequence = seq;
    }

    ~DoubleAdapter() override {
        delete sequence;
    }

    DoubleAdapter* append(const std::string str_value) override {
        sequence->append(from_string(str_value));
        return this;
    }

    DoubleAdapter* prepend(const std::string str_value) override {
        sequence->prepend(from_string(str_value));
        return this;
    }

    DoubleAdapter* set(int index, std::string item) override {
        sequence->set(index, from_string(item));
        return this;
    }

    std::string get(int index) const override {
        double value = sequence->get(index);
        return std::to_string(value);
    }

    std::string get_first() const override {
        double value = sequence->get_first();
        return std::to_string(value);
    }

    std::string get_last() const override {
        double value = sequence->get_last();
        return std::to_string(value);
    }

    std::string get_size() const override {
        int value = sequence->get_size();
        return std::to_string(value);
    }

    DoubleAdapter* get_subsequence(int start_index, int end_index) const override{
        DoubleAdapter* adapter = new DoubleAdapter(
            sequence->get_subsequence(start_index, end_index)
        );
        return adapter;
    } 

    std::string to_string() const {
        return sequence->to_string();
    } 

};