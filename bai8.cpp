//Ta có thể tính average score cho bai 1


#include <iostream>
#include <string>
using namespace std;

struct student{
    string name;
    int age;
    float ml_score;
    float python_score;
};


int main(){
    student s;
    cout<<"Nhap ten : ";
    getline(cin,s.name);

    cout<<"Nhap tuoi : ";
    cin>>s.age;
    
    cout<<"Nhap diem ML : ";
    cin>>s.ml_score;

    cout<<"nhap diem python : ";
    cin>>s.python_score;
    float avg = (s.ml_score + s.python_score)/2;

    cout<<"\nThong tin sinh vien :\n";
    cout<<" Ten     : "<<s.name<<endl;
    cout<<" Tuoi    : "<<s.age<<endl;
    cout<<" ML      :"<<s.ml_score<<endl;
    cout<<" Python  : "<<s.python_score<<endl;
    cout<<" Average : "<<avg<<endl;

    return 0;
}