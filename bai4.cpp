#include <iostream>
using namespace std;
int main(){
    int a=5;
    int *p=&a;
    int *q=p;
    *q=200;
    cout<<"a: "<<a<<endl;
    cout<<"*p: "<<*p<<endl;
    cout<<"*q: "<<*q;
    return 0;
}