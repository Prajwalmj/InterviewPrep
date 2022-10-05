#include <iostream>

using namespace std;

class Parent
{
    public:
        void print()
        {
            cout << "Base class print" << endl;
        }

        virtual void show()
        {
            cout << "Virtual Base class shown" << endl;
        }
};

class Child: public Parent
{   
    public:
        void print()
        {
            cout << "Derived class print" << endl;
        }
        void show()
        {
            cout << "Derived class shown" << endl;
        }
};

int main()
{
    Parent *b;
    Child c;

    b = &c;

    b->print(); //Calls base class print
    //b->Child::print(); //Calls derived class print
    c.print();  //Calls derived class print
    b->Parent::show(); //Calls base class show
    b->show();  //Calls derived class show
    return 0;
}