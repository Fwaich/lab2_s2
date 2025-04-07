#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "ArraySequence.h"
//перегрузка операторов обязательно
//родителя убивать всегда

using namespace std;

int main()
{
   // int arr[] = {1, 2, 3, 4, 5};
   // double arr[] = {1.33, 2.4, 3.5, 4.6, 5.8};
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

   int arr[] = {1, 2, 3, 4, 5};
   ArraySequence<int> a(arr, 5);
   int num = a.get(3);
   int size = a.get_size();
   int first = a.get_first();
   int last = a.get_last();
   cout << num << endl;
   cout << first << endl;
   cout << last << endl;
   cout << size << endl;
   a.print();
   
   return 0;
}