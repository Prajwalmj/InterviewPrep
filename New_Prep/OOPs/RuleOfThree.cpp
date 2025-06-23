#include <iostream>

class Test
{
    public:
        Test()
        {
            Data = 5;
            Ptr = new int(10);
        };

        Test(const Test& other)
        {
            Data = other.Data;
            Ptr = new int(*(other.Ptr));
        }

        Test& operator=(const Test& other)
        {
            if(this != &other)
            {
                this->Data = other.Data;
                this->Ptr = new int(*(other.Ptr));
            }
            return (*this);
        }

        void Print()
        {
            std::cout << "Data is: " << Data << std::endl;
            std::cout << "Ptr pointing to: " << *Ptr << std::endl;
            std::cout << "Address is: " << Ptr << std::endl;
        }

        ~Test()
        {
            delete Ptr;
        };

    private:
        int Data;
        int* Ptr;
};

int main()
{
    Test t1;
    t1.Print();

    Test t2(t1);
    t2.Print();

    Test t3;
    t3 = t1;
    t3.Print();
    return 0;
}