//struct là kiểu dữ liệu do người lập trình tạo ra để lưu nhiều thông tin liên quan với nhau


#include <iostream>
#include <string>
using namespace std;
struct student{
    string name;
    int age;
    float ml_score;
    float python_score;

};
//Struct giống một record trong dataset.

int main(){
    student s;
    cout<<"nhap ten: ";
    getline(cin,s.name);

    cout<<"nhap tuoi: ";
    cin>>s.age;

    cout<<"nhap diem machine learning: ";
    cin>>s.ml_score;

    cout<<"nhap diem python: ";
    cin>>s.python_score;
    cout<<"\nthong tin sinh vien :\n";
    cout<<" ten : "<<s.name<<endl;
    cout<<" tuoi : "<<s.age<<endl;
    cout<<" diem ML : "<<s.ml_score<<endl;
    cout<<" diem Python : "<<s.python_score<<endl;


    return 0;
}