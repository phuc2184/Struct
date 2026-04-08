#include <iostream>
using namespace std;
struct Node{
    Node* next;
    int data;
    
};
void nhap(int &n){
    cout<<"nhap vao so luong node";
    cin>>n;
}
void addHead(Node* &Head,int x){
    Head=new Node{Head,x};
}
void xuat(Node* Head){
    while(Head!=NULL){
        cout<<Head->data<<" ";
        Head=Head->next;
    }
}
int main(){
    int n,x;
    Node* Head=NULL;
    nhap(n);
    for(int i=0;i<n;i++){
        cout<<"Nhap vao Node "<<i+1<<": ";
        cin>>x;
        addHead(Head,x);
    }
    cout<<"\nDanh sach";
    xuat(Head);


    return 0;
}