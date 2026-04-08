#include <iostream>
using namespace std;
void thaydoi(int *x){
    cout<<"dai chi cua x : "<<x<<endl;
    *(x)+=10;
    cout<<"gia tri cua x"<<x;

}
int main(){
    int x=10;
    cout<<"dai chi cua x: "<<x<<endl;
    thaydoi(&x);
    cout<<"gia tri cua x sau khi thay doi: "<<x<<endl;
    
}