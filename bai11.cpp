//Bài: Struct + Sorting (Sắp xếp)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


struct student{
    string name;
    string class1;
    int id;
    float ml_score;
    void nhap(){
        cout<<"Nhap ten : ";
        getline(cin,name);
        cout<<"Nhap lop : ";
        cin>>class1;
        cout<<"nhap mssv : ";
        cin>>id;
        cout<<"nhap diem ml : ";
        cin>>ml_score;
        cin.ignore();
    }
    void xuat(){
        cout<<"Ten : "<<name<<endl;
        cout<<"Lop : "<<class1<<endl;
        cout<<"MSSV : "<<id<<endl;
        cout<<"Diem ml : "<<ml_score<<endl;
    }
};

int main(){
    int n;
    cin>>n;
    cin.ignore();
    student s[n+1];
    for(int i=0;i<n;i++){
        cout<<"\nSinh vien "<<i+1<<endl;
        s[i].nhap();
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i].ml_score < s[j].ml_score){
                swap(s[i],s[j]);
            }
        }
    }
    cout<<"\nDanh sach cac sinh vien\n";
    for(int i=0;i<n;i++){
        s[i].xuat();
    }


    

    return 0;
}