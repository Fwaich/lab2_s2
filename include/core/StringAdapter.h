#pragma once
#include "core/Adapter.h"
#include "core/Sequence.h"

class StringAdapter : public Adapter 
{
private:
    Sequence<std::string>* sequence;

public:

    StringAdapter(Sequence<std::string>* seq){
        sequence = seq;
    }

    ~StringAdapter() override {
        delete sequence;
    }

    StringAdapter* append(const std::string str_value) override {
        sequence->append(str_value);
        return this;
    }

    StringAdapter* prepend(const std::string str_value) override {
        sequence->prepend(str_value);
        return this;
    }

    StringAdapter* set(int index, std::string item) override {
        sequence->set(index, item);
        return this;
    }

    std::string get(int index) const override {
        return sequence->get(index);
    }

    std::string get_first() const override {
        return sequence->get_first();
    }

    std::string get_last() const override {
        return sequence->get_last();
    }

    std::string get_size() const override {
        int value = sequence->get_size();
        return std::to_string(value);
    }

    StringAdapter* get_subsequence(int start_index, int end_index) const override{
        StringAdapter* adapter = new StringAdapter(
            sequence->get_subsequence(start_index, end_index)
        );
        return adapter;
    } 

    StringAdapter* map(double factor) override{
        sequence->map(0);
        return this;
    }

    std::string to_string() const {
        return sequence->to_string();
    } 

};