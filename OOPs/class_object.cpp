#include <iostream>
using namespace std;

class student
{
    string name;

    public:
    int age;
    bool sex;

    student()
    {
        // Default Constructor
    }

    student(string str, int a, int s)
    {
        // Parameterised Constructor

        name = str;
        age = a;
        sex = s;
    }

    student(student &a)
    {
        // Copy Constructor

        name = a.name;
        age = a.age;
        sex = a.sex;
    }

    ~student(){}

    void access_private(string str)
    {
        name = str;
    }

    void print_info()
    {
        cout << "name -> " << name << endl;
        cout << "age -> " << age << endl;
        cout << "sex -> " << sex << endl;
    }

    bool operator == (student &a)
    {
        if (a.name==name && a.age==age && a.sex==sex)
            return true;

        else
            return false;
    }
};

int main()
{
    student a;

    string str = "dhar";
    a.access_private(str);
    //a.name = "dharmani";
    a.age = 6;
    a.sex = 1;

    a.print_info();

    student b("jai_ho", 69, 0);
    b.print_info();

    student c = a;
    c.print_info();

    if (c==a)
        cout << "Same";

    else
        cout << "Not Same";
}