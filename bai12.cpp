//2️⃣ Bài: Struct + Searching (Tìm max)




#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct student{
    string name;
    string class1;
    int ml_score;
    void nhap(){
        cout<<"Nhap ten : ";
        getline(cin,name);
        cout<<"Nhap lop : ";
        cin>>class1;
        cout<<"Nhap diem : ";
        cin>>ml_score;
        cin.ignore();
    }
    void xuat(){
        cout<<"Ten : "<<name<<endl;
        cout<<"Lop : "<<class1<<endl;
        cout<<"diem ml : "<<ml_score<<endl;
    }
};
int main(){
    int n,max=0;
    cin>>n;
    student s[n];
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"sinh thu "<<i+1<<endl;
        s[i].nhap();
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i].ml_score > s[j].ml_score){
                max=i;
            }
        }

    }
    cout<<"\nDanh sach lop\n";
    for(int i=0;i<n;i++){
        cout<<"Sinh vien thu "<<i+1<<endl;
        s[i].xuat();
    }
    cout<<" Nguoi co diem lon nhat la sinh vien : ";
    for(int i=0;i<n;i++){
        s[max].xuat();
    }
    return 0;
}