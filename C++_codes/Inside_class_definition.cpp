#include <iostream>

using namespace std;

class Test{
    private:
        int data;

    public:
        //inside class definition
        void displayData(int x){
            data = x;
            cout << "Data is :" << data << endl;
        }
};

int main(){
    Test t;
    t.displayData(100);
    return 0;
}