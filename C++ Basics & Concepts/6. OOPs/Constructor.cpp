#include <iostream>
using namespace std;

class Student
{
public:
    int RollNo;

private:
    int Age;

public:
    // Default Constructor
    Student()
    {
        cout << "Constructor Called" << endl;
    }

    // Parameterized Constructor
    Student(int r)
    {
        cout << "Constructor 2 Called" << endl;
        RollNo = r;
    }

    //* this keyword -> is a Pointer holds the address of current object
    Student(int RollNo, int Age)
    {
        cout << "Constructor 3 Called" << endl;
        cout << "This: " << this << endl;
        this->RollNo = RollNo;
        this->Age = Age;
    }

    void display()
    {
        cout << "RollNo: " << RollNo << " Age: " << Age << endl;
    }
};

int main()
{
    //* Default Constructor
    Student s1;
    s1.display();

    Student *s2 = new Student;
    s2->display();

    //* Parameterized Constructor
    Student s3(3);
    s3.display();

    Student *s4 = new Student(4);
    s4->display();

    //* this Keyword
    Student s5(5, 25);
    cout << "Address of s5: " << &s5 << endl;
    s5.display();
    return 0;
}