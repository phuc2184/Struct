#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"nhap vao do dai phan tu: ";
    cin>>n;
    int tong=0;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<"["<<i<<"]"<<":"<<arr[i];
        
    }cout<<"cac so chan la: ";
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            cout<<arr[i]<<" ";
        }
        tong+=arr[i];
    }
    cout<<"tong mang la: "<<tong;
    return 0;
}