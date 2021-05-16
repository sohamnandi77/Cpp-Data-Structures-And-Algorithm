#include <iostream>
using namespace std;
int main()
{
  int j = 10;
  void *ptr = &j; // Pointer can be void*

  // ? why can't we jsut use:  pointer c = &i; why we have to mention the datatype of the pointer
  // * We have to mention the datatype as when dereferencing the pointer then we don't be able to
  // -> read how much byte it will take
  // -> which type of value is that as it can be anything say 0 -> it can be int, bool, double, float anything so, it's necessary to mention the datatype

  int i = 65;
  char c = i; //* Implicit Type casting
  cout << c << endl;

  int *p = &i;
  //! char *pc = p; //* Implicit Type casting is not possible in case of pointers

  char *pc = (char *)p; //* Explicit Type casting

  cout << p << endl;  //* address
  cout << pc << endl; //* keeps printing till gets a null character

  cout << *p << endl;
  cout << *pc << endl; //* Follows Little Endian
  cout << *(pc + 1) << endl;
  cout << *(pc + 2) << endl;
  cout << *(pc + 3) << endl;
  return 0;
}