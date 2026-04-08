#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void nhap(int &n){
    cout<<"nhap so luong node: ";
    cin>>n;
}

void addhead(Node* &Head,int x){
    Head = new Node{x, Head};
}

void xuat(Node* Head){
    while(Head != NULL){
        cout << Head->data << " ";
        Head = Head->next;
    }
}

int main(){
    int n;
    nhap(n);

    Node* Head = NULL;

    for(int i = 0; i < n; i++){
        int x;
        cout<<"nhap gia tri: ";
        cin>>x;
        addhead(Head, x);
    }

    cout<<"\nDanh sach: ";
    xuat(Head);

    return 0;
}