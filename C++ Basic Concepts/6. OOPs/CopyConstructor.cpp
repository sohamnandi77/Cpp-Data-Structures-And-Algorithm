#include <iostream>
using namespace std;
class Student
{
public:
    int RollNo;

private:
    int Age;

public:
    Student(int RollNo, int Age)
    {
        cout << "Constructor 1 Called" << endl;
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
    cout << "Object s1: " << endl;
    Student s1(1, 25);
    s1.display();

    //* Copy Constructor -- Static object call static constructor
    cout << "Copy Constructor -> Static" << endl; //*  Notice Copy Constructor called, not Default
    cout << "Object s2: " << endl;
    Student s2(s1);
    s2.display();

    cout << "Object s3: " << endl;
    Student *s3 = new Student(3, 15);
    s3->display();

    //* Copy Constructor -- Dynamic object calls dynamic constructor
    cout << "Copy Constructor -> Dynamic" << endl;
    cout << "Object s4: " << endl;
    Student *s4 = new Student(*s3);
    s4->display();

    cout << "Object s5: " << endl;
    Student *s5 = new Student(s1);
    s5->display();

    //* Copy Assignment Operator(=) -- static
    cout << "Object s6: " << endl;
    Student s6(6, 30);
    s6.display();

    cout << "After using Copy Assignment Operator" << endl;
    s6 = s1;

    cout << "Object s6: " << endl;
    s6.display();

    //* Copy Assignment Operator(=)  -- dynamic
    cout << "Object s7: " << endl;
    Student *s7 = new Student(7, 18);
    s7->display();

    cout << "After using Copy Assignment Operator" << endl;
    *s7 = s1;
    cout << "Object s7: " << endl;
    s7->display();

    *s7 = *s3;
    cout << "Object s7: " << endl;
    s7->display();

    //? Here copy constructor used rather than copy assignment operator
    //* Student s8 = s1
    //* compiler interprets --> Student s8(s1);

    cout << "Object s8: " << endl;
    Student s8 = s1;
    s8.display();

    return 0;
}