#include <iostream>
using namespace std;

class Student
{
public:
    int rollNo;

private:
    int age;

public:
    int getSetAge(int a)
    {
        age = a;
        return age;
    }

    void setAge(int a)
    {
        age = a;
    }

    void display()
    {
        cout << "Age: " << age << " "
             << "RollNo: " << rollNo << endl;
    }
};

int main()
{
    // Object Created Statically
    Student s1;

    s1.rollNo = 1;

    s1.setAge(15);
    cout << s1.getSetAge(30) << endl;
    s1.display();

    // Object Created Dynamically
    Student *s2 = new Student;

    (*s2).rollNo = 2;
    s2->rollNo = 2;

    s2->setAge(20);
    s2->display();

    return 0;
}