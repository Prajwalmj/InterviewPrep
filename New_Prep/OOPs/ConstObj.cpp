#include <iostream>

class Example
{
    public:
        Example(int x, int y):
            Mx(x), 
            My(y)
        {}

        ~Example() = default;
    
        mutable int Mx;
        int My;
};

int main()
{
    const Example e(10, 20);
    e.Mx = 25;

    std::cout << "x is: " << e.Mx << std::endl;
    return 0;
}