#include <iostream>
using namespace std;
class Student
{
public:
    int age;
    const int rollNo;
    int &x; // Age reference Variable

    //* Initialsation List
    Student(int rollNo, int age) : rollNo(rollNo), age(age), x(this->age) {}
};
int main()
{
    Student s1(1, 20);
    return 0;
}