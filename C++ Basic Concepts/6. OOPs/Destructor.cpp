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
        this->Age = Age;
    }

    void display()
    {
        cout << "RollNo: " << RollNo << " Age: " << Age << endl;
    }
    //* Destructor -> Deallocate our object's memory
    ~Student()
    {
        cout << "Destructor called" << endl;
    }
};
int main()
{
    Student s1(1, 20);
    s1.display();

    Student s2(s1);
    s2.display();

    Student *s3 = new Student(s1);
    s3->display();
    //! No Destructor will be called

    //* So we have to use delete to deallocate aur object in heap memory;
    //? After deleting the object destructor will be called
    delete s3;

    return 0;
}