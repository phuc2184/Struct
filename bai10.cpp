//Bài 2 (giống xử lý dataset)
//Nhập 5 sinh viên, Tính: average ML score của cả lớp


#include <iostream>
#include <string>
using namespace std ;

struct student{
    string name;
    int mssv;
    float ml_score;

    void nhap(){
        cout<<"Nhap ten : ";
        getline(cin,name);

        cout<<"Nhap ma so sinh vien : ";
        cin>>mssv;

        cout<<"Nhap diem ml : ";
        cin>>ml_score;
        cin.ignore();
        
    }
    void xuat(){
        cout<<"Ten : "<<name<<endl;
        cout<<"MSSV : "<<mssv<<endl;
        cout<<"Diem ml :"<<ml_score<<endl;
    }
};

int main(){
    int n;
    cin>>n;
    float sum=0;
    cin.ignore();
    student s[100];
    
    for(int i=0;i<n;i++){
        cout<<"\nSinh vien "<<i+1<<endl;
        s[i].nhap();
    }

    cout<<"\nThong tin cac sinh vien\n";
    for(int i=0;i<n;i++){
        cout<<"STT: "<<i+1<<endl;
        s[i].xuat();
        sum += s[i].ml_score;
    }
    float avg =sum/n;
    cout<<"\nAverage ML score cua lop: "<<avg;
    return 0;
}