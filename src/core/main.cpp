// #include <wx/wx.h>
#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "ArraySequence.h"
#include "LinkedList.h"
#include "ListSequence.h"
#include "Sequence.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"
// #include "stdafx.h"
//перегрузка операторов обязательно

using namespace std;

int main()
{
   int arr_int[] = {1, 2, 3, 4, 5};
   double arr_double[] = {1.33, 2.4, 3.5, 4.6, 5.8};


   // DynamicArray<double> a(arr, 5);
   // DynamicArray<double> a(5);
   // string arr[] = {"a","a","a","a","a"};
   // DynamicArray<string> a;
   // a.print();

   // // int num = a.get(2);
   // string num = a.get(2);
   // cout << num << endl;

   // int size = a.get_size();
   // cout << size << endl;

   // a.set(2, "Bob");

   // a.resize(10);
   // num = a.get_size();
   // cout << num << endl;
   // a.print();


   // ArraySequence<int> a(arr, 5);
   // int num = a.get(3);
   // int size = a.get_size();
   // int first = a.get_first();
   // int last = a.get_last();
   // cout << num << endl;
   // cout << first << endl;
   // cout << last << endl;
   // cout << size << endl;
   // a.print();
   // cout << endl;

   // ArraySequence<int>* sub = a.get_subsequence(0, 2);
   // cout << "Sub:" << endl;
   // sub->print();
   // delete sub;

   // LinkedList<int> a(arr, 5);
   // a.append(1);
   // a.append(2);


   // Sequence<int>* seq = new ArraySequence<int>(arr_int, 5);
   // Sequence<int>* sub = seq->get_subsequence(1, 3);
   // sub->prepend(100);
   // sub->print();

   // delete seq;
   // delete sub;


   // LinkedList<int> a(arr_int, 5);
   // a.prepend(0);
   // a.print();
   // int num_int = a.get_first();
   // cout << "num: " << num_int << endl;
   // LinkedList<int> b(a);
   // b.print();

   // LinkedList<int>* sub_list = a.get_sublist(1, 3);
   // cout << "a" << endl;
   // sub_list->set(0, 100);
   // sub_list->print();
   // delete sub_list;

   // ListSequence<int> a(arr_int, 5);
   // a.prepend(1000);
   // ListSequence<int> b(a);


   // Sequence<int>* seq = new ListSequence<int>(arr_int, 5);
   // seq->append(1000);
   // Sequence<int>* sub = seq->get_subsequence(1, 3);
   // sub->prepend(100);
   // sub->print();

   // delete seq;
   // delete sub;


   // Sequence<int>* a = new ListSequence<int>(arr_int, 5);
   // ArraySequence<int> c(*a);
   // a->append(1000);
   // c.print();
   // Sequence<int>* b = &c;
   // b->print();
   // delete a;
   // delete b;

   // ArraySequence<int> a(arr_int, 5);
   // a.set(1, 213);
   // ArraySequence<int> b = a;
   // b.print();

   // ConstArraySequence<int> a(arr_int, 5);
   // a.print();
   Sequence<int>* a = new ConstListSequence<int>(arr_int, 5);
   // a->append(1032);
   a->print();


   delete a;
   // delete b;

   return 0;
}