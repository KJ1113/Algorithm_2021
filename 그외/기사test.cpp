#include <iostream>

using namespace std;
int main(){

    struct Mys{
        char name[10];
        int age;

    } a[] ={"Kinm" , 1 , "Lee" , 2};

    Mys *p;
    p = a;

    cout << p->name <<endl;

    char B = '1';
    cout << B << endl;
    cout << B - '0' <<endl;
    
}