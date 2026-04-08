//🎯 Mục tiêu: Tạo chương trình quản lý dataset sinh viên:
//name | age | ml_score | python_score
//yeu cau bai: 1. Nhập dữ liệu
//2. In dữ liệu
//3. Tính average ML
//4. Tìm sinh viên điểm cao nhất
//5. Sắp xếp theo ML
//6. Lưu file
//7. Đọc file
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct student{
    string name;
    int age;
    string line;
    float ml_score;
    float python_score;

};
void nhap(student s[],int &n){
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Sinh vien thu "<<i+1<<endl;
        cout<<"Ten : ";
        getline(cin,s[i].name);
        cout<<"Nam sinh : ";
        cin>>s[i].age;
        cout<<"Diem ml : ";
        cin>>s[i].ml_score;
        cout<<"Diem python : ";
        cin>>s[i].python_score;
        cin.ignore();
    }
}
void xuat(student s[],int &n){
    for(int i=0;i<n;i++){
        cout<<"sinh vien thu "<<i+1<<endl;
        cout<<"Ten : "<<s[i].name<<endl;
        cout<<"Nam sinh : "<<s[i].age<<endl;
        cout<<"Diem ml : "<<s[i].ml_score<<endl;
        cout<<"Diem python : "<<s[i].python_score<<endl;
    }
}
float avg(student s[],int &n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=s[i].ml_score;
    }
    return sum/n;
}
void maxml(student s[],int &n){
    int max=0;
    for(int i=0;i<n;i++){
        if(s[i].ml_score > s[max].ml_score){
            max=i;
        }
    }
    cout<<"sinh vien co diem cao nhat la : "<<endl;
    cout<<"Ten : "<<s[max].name<<endl;
    cout<<"Nam sinh : "<<s[max].age<<endl;
    cout<<"Diem ml : "<<s[max].ml_score<<endl;
    cout<<"Diem python : "<<s[max].python_score<<endl;
}
void sx(student s[],int &n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i].ml_score < s[j].ml_score){
                swap(s[i],s[j]);
            }
        }
    }
    cout<<"\nDanh sach sinh vien da sap xep\n";
    for(int i=0;i<n;i++){
        cout<<"sinh vien thu "<<i+1<<endl;
        cout<<"Ten : "<<s[i].name<<endl;
        cout<<"Nam sinh : "<<s[i].age<<endl;
        cout<<"Diem ml : "<<s[i].ml_score<<endl;
        cout<<"Diem python : "<<s[i].python_score<<endl;
    }
}
void save(student s[],int &n){
    ofstream file("date.txt");
    for(int i=0;i<n;i++){
        file<<"sinh vien thu "<<i+1<<endl;
        file<<"Ten : "<<s[i].name<<endl;
        file<<"Nam sinh : "<<s[i].age<<endl;
        file<<"Diem ml : "<<s[i].ml_score<<endl;
        file<<"Diem python : "<<s[i].python_score<<endl;
    }
    file.close();
}
void doc(student s[],int &n){
    string line;
    ifstream file("date.txt");
    while(!file.eof()){
        getline(file,line);
        cout<< line <<endl;
    }
    file.close();
}
int main(){
    int n,x;
    cout<<"nhap vao so luong sinh vien: ";
    cin>>n;
    student s[n];
    cin.ignore();
    cout<<"\nvui long chon chuc nang\n";
    cout<<"\n1. Nhập dữ liệu\n"
        <<"\n2. In dữ liệu\n"
        <<"\n3. Tính average ML\n"
        <<"\n4. Tìm sinh viên điểm cao nhất\n"
        <<"\n5. Sắp xếp theo ML\n"
        <<"\n6. Lưu file\n"
        <<"\n7. Đọc file\n";
    while(true){
        cout<<"nhap so de chon chuc nang";
        cin>>x;
        switch (x){
            case 1:
            nhap(s,n);
            break;
        case 2:
            xuat(s,n);
            break;
        case 3:
            avg(s,n);
            break;
        case 4:
            maxml(s,n);
            break;
        case 5:
            sx(s,n);
            break;
        case 6:
            save(s,n);
            break;
        case 7:
            doc(s,n);
            break;
        default:
            cout<<"so ban nhap khong hop le";
            break;
        }


    }
    return 0;
}