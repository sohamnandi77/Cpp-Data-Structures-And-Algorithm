#include <iostream>
using namespace std;
class Student
{
private:
public:
    int rollNo, age;
    //* static which belongs to class, the object doesn't create a copy of it.
    static int totalStudent;

    Student(int rollNo, int age)
    {
        this->rollNo = rollNo;
        this->age = age;
        totalStudent++;
    }

    // ? Static Member Fuction :
    // ? Only can use Static Properties
    // ? they don't have -> this pointer
    static int getTotalStudent()
    {
        return totalStudent;
    }
};

int Student::totalStudent = 0; // initialize static data members

int main()
{
    Student s1(1, 15);
    cout << s1.rollNo << " " << s1.age << endl;
    cout << Student::totalStudent << endl;
    //! Bad Practice -- cout<< s1.totalStudent;    return 0;

    cout << Student::getTotalStudent() << endl;
}