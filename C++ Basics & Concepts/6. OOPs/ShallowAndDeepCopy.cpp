#include <iostream>
#include <cstring>
using namespace std;
class Student
{
public:
    int age;
    char *name;

    Student(int age, char *name)
    {
        this->age = age;

        //! Shallow Copy (should be avoided)
        //! this->name = name;

        //* Deep Copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // copy constructor
    //! Student(Student s){} --> creates a infinite loop as it agains calls the copy constructor

    Student(Student const &s)
    {
        this->age = s.age;
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << "Name: " << name << " Age: " << age << endl;
    }
};
int main()
{
    char name[] = "abcd";
    Student s1(20, name);
    s1.display();

    Student s2(s1); //! Copy Constructor should be avoided in case of char array as it does shallow copy
    s2.name[3] = 'e';
    s2.display();
    s1.display();

    return 0;
}