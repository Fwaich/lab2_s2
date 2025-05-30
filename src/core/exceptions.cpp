#include "core/exceptions.h"

const char* array_out_of_range::what() const noexcept{
    return "index out of array";
}

const char* list_out_of_range::what() const noexcept{
    return "index out of list";
}

const char* data_is_null::what() const noexcept{
    return "data isn't intialized";
}

const char* wrong_type::what() const noexcept{
    return "invalid type entered";
}