#include <iostream>
#include <cassert>
#include "core/Sequence.h"
#include "core/ArraySequence.h"
#include "core/ListSequence.h"

int arr_int[] = {1, 2, 3, 4, 5};

void test_constructors() 
{
    std::cout << "test_constructors(): ";
    Sequence<int>* a;
    a = new ArraySequence<int>;
    assert(a->get_size() == 0);
    delete a;

    a = new ArraySequence<int>(arr_int, 5);
    assert(a->get_size() == 5);
    assert(a->get_first() == 1);
    assert(a->get_last() == 5);
    delete a;

    Sequence<int>* l;
    l = new ListSequence<int>;
    assert(l->get_size() == 0);
    delete l;

    l = new ListSequence<int>(arr_int, 5);
    assert(l->get_size() == 5);
    assert(l->get_first() == 1);
    assert(l->get_last() == 5);
    delete l;

    std::cout << "Succesfull" << std::endl;
}

void test_get_first()
{
    std::cout << "test_get_first(): ";
    Sequence<int>* a;
    a = new ArraySequence<int>(arr_int, 5);
    assert(a->get_first() == 1);

    Sequence<int>* l;
    l = new ListSequence<int>(arr_int, 5);
    assert(l->get_first() == 1);

    std::cout << "Succesfull" << std::endl;
    delete a;
    delete l;
}

void test_get_last()
{
    std::cout << "test_get_last(): ";
    Sequence<int>* a;
    a = new ArraySequence<int>(arr_int, 5);
    assert(a->get_last() == 5);

    Sequence<int>* l;
    l = new ListSequence<int>(arr_int, 5);
    assert(l->get_last() == 5);

    std::cout << "Succesfull" << std::endl;
    delete a;
    delete l;
}

void test_get()
{
    std::cout << "test_get(): ";
    Sequence<int>* a;
    a = new ArraySequence<int>(arr_int, 5);
    assert(a->get(2) == 3);

    Sequence<int>* l;
    l = new ListSequence<int>(arr_int, 5);
    assert(l->get(3) == 4);

    std::cout << "Succesfull" << std::endl;
    delete a;
    delete l;
}

void test_append() 
{
    std::cout << "test_append(): ";
    Sequence<int>* a;
    a = new ArraySequence<int>(arr_int, 5);
    a->append(3);
    assert(a->get_last() == 3);

    Sequence<int>* l;
    l = new ListSequence<int>(arr_int, 5);
    l->append(4);
    assert(l->get_last() == 4);
    
    std::cout << "Succesfull" << std::endl;
    delete a;
    delete l;
}

void test_prepend() 
{
    std::cout << "test_prepend(): ";
    Sequence<int>* a;
    a = new ArraySequence<int>(arr_int, 5);
    a->prepend(3);
    assert(a->get_first() == 3);

    Sequence<int>* l;
    l = new ListSequence<int>(arr_int, 5);
    l->prepend(4);
    assert(l->get_first() == 4);

    std::cout << "Succesfull" << std::endl;
    delete a;
    delete l;
}

void test_set() 
{
    std::cout << "test_set(): ";
    Sequence<int>* a;
    a = new ArraySequence<int>(arr_int, 5);
    a->set(2, 10);
    assert(a->get(2) == 10);

    Sequence<int>* l;
    l = new ListSequence<int>(arr_int, 5);
    l->set(3, 11);
    assert(l->get(3) == 11);
    std::cout << "Succesfull" << std::endl;

    delete a;
    delete l;
}

void test_to_string() 
{
    std::cout << "test_to_string(): ";
    Sequence<int>* a;
    a = new ArraySequence<int>(arr_int, 5);
    assert(a->to_string() == "[1, 2, 3, 4, 5]");

    Sequence<int>* l;
    l = new ListSequence<int>(arr_int, 5);
    assert(l->to_string() == "{1, 2, 3, 4, 5}");

    std::cout << "Succesfull" << std::endl;
    delete a;
    delete l;
}

void test_get_subsequence()
{
    std::cout << "test_get_subsequence(): ";
    Sequence<int>* a;
    a = new ArraySequence<int>(arr_int, 5);
    Sequence<int>* sub_a = a->get_subsequence(1,3);
    assert(sub_a->to_string() == "[2, 3, 4]");

    Sequence<int>* l;
    l = new ListSequence<int>(arr_int, 5);
    Sequence<int>* sub_l = l->get_subsequence(1,3);
    assert(sub_l->to_string() == "{2, 3, 4}");

    std::cout << "Succesfull" << std::endl;
    delete a;
    delete l;
}

void test_map()
{
    std::cout << "test_map(): ";
    Sequence<int>* a;
    a = new ArraySequence<int>(arr_int, 5);
    a->map(2);
    assert(a->to_string() == "[2, 4, 6, 8, 10]");

    // Sequence<int>* l;
    // l = new ListSequence<int>(arr_int, 5);
    // l->map(2);
    // assert(l->to_string() == "{2, 4, 6, 8, 10}");

    Sequence<std::string>* l;
    l = new ListSequence<std::string>;
    l->append("aaa");
    l->append("BbB");
    l->map(0);
    assert(l->to_string() == "{AAA, BBB}");

    std::cout << "Succesfull" << std::endl;
    delete a;
    delete l;
}

int main() 
{ 
    test_constructors();
    test_get_first();
    test_get_last();
    test_get();
    test_append();
    test_prepend();
    test_set();
    test_to_string();
    test_get_subsequence();
    test_map();
    return 0;
}