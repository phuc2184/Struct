#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
struct student{
    string name;
    string class1;
    string id;
    float ml_score;
    void nhap(){
        cout<<"Nhap ten : ";
        cin>>name;
        cout<<"Nhap lop : ";
        cin>>class1;
        cout<<"Nhap mssv : ";
        cin>>id;
        cout<<"Nhap diem : ";
        cin>>ml_score;
        cin.ignore();
    }
    void xuat(){
        cout<<"Ten : "<<name<<endl;
        cout<<"Lop : "<<class1<<endl;
        cout<<"MSSV : "<<id<<endl;
        cout<<"Diem : "<<ml_score<<endl;
    }

};

int main(){
    int n;
    cin>>n;
    student s[n];
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"sinh vien thu "<<i+1<<endl;
        s[i].nhap();
    }
    cout<<"\nDanh sach sinh vien\n";
    for(int i=0;i<n;i++){
        cout<<"sinh vien thu "<<i+1<<endl;
        s[i].xuat();
    }

    ofstream file;
    file.open("danh sach sinh vien.txt");
    for(int i=0;i<n;i++){
        file << s[i].name;
        file << s[i].class1;
        file << s[i].ml_score;
    }
    file.close();
    return 0;
}