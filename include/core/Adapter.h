#pragma once
#include <string>

class Adapter 
{
public:

    virtual ~Adapter() = default; 

    virtual Adapter* append(const std::string str_value) = 0;
    virtual Adapter* prepend(const std::string str_value) = 0;
    virtual Adapter* set(int index, std::string item) = 0;

    virtual std::string get(int index) const = 0;
    virtual std::string get_first() const = 0;
    virtual std::string get_last() const = 0;
    virtual std::string get_size() const = 0;
    virtual Adapter* get_subsequence(int start_index, int end_index) const = 0;
    virtual Adapter* map(double factor) = 0;

    virtual std::string to_string() const = 0; 


};
