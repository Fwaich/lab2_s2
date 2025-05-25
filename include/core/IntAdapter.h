#pragma once
#include "core/Adapter.h"
#include "core/Sequence.h"
#include "core/exceptions.h"

class IntAdapter : public Adapter 
{
private:
    Sequence<int>* sequence;

    int from_string(std::string str) {
        try {
            size_t pos;
            int val = std::stoi(str, &pos);
    
            if (pos != str.length()) {
                throw wrong_type();
            }
    
            return val;
    
        } catch (const std::exception&) {
            throw wrong_type();
        }
    }

public:

    IntAdapter(Sequence<int>* seq){
        sequence = seq;
    }

    ~IntAdapter() override {
        delete sequence;
    }

    IntAdapter* append(const std::string str_value) override {
        sequence->append(from_string(str_value));
        return this;
    }

    IntAdapter* prepend(const std::string str_value) override {
        sequence->prepend(from_string(str_value));
        return this;
    }

    IntAdapter* set(int index, std::string item) override {
        sequence->set(index, from_string(item));
        return this;
    }

    std::string get(int index) const override {
        int value = sequence->get(index);
        return std::to_string(value);
    }

    std::string get_first() const override {
        int value = sequence->get_first();
        return std::to_string(value);
    }

    std::string get_last() const override {
        int value = sequence->get_last();
        return std::to_string(value);
    }

    std::string get_size() const override {
        int value = sequence->get_size();
        return std::to_string(value);
    }

    IntAdapter* get_subsequence(int start_index, int end_index) const override{
        IntAdapter* adapter = new IntAdapter(
            sequence->get_subsequence(start_index, end_index)
        );
        return adapter;
    } 

    std::string to_string() const {
        return sequence->to_string();
    } 

};