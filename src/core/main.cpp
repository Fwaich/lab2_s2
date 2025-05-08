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
#include "exceptions.h"
// #include "stdafx.h"
//перегрузка операторов обязательно

using namespace std;

int main()
{
   int arr_int[] = {1, 2, 3, 4, 5};
   double arr_double[] = {1.33, 2.4, 3.5, 4.6, 5.8};


   int a = 0;
   cin >> a;
   try {
      ArraySequence<int> b(arr_int, 5);
      b.set(1, a);
      b.print();
   } catch(array_out_of_range& e){
      cout << e.what() << endl;
   } catch(list_out_of_range& e){
      cout << e.what() << endl;
   } catch(data_is_null& e){
      cout << e.what() << endl;
   }

   

   return 0;
}