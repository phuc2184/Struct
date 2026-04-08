//Tên bài: Student Dataset Processing (Mini ML Pipeline)

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct student{
    string name;
    int age;
    float ml_score;
    float python_score;
};
void nhap(student s[],int n){
    for(int i=0;i<n;i++){
        cout<<"Nhap ten : ";
        cin>>s[i].name;
        cout<<"Nhap tuoi : ";
        cin>>s[i].age;
        cout<<"Nhap diem ml : ";
        cin>>s[i].ml_score;
        cout<<"Nhap diem python : ";
        cin>>s[i].python_score;
        cin.ignore();
    }
}
void xuat(student s[],int n){
    for(int i=0;i<n;i++){
        cout<<"Ten: "<<s[i].name<<endl
            <<"Tuoi: "<<s[i].age<<endl
            <<"Diem ml: "<<s[i].ml_score<<endl
            <<"Diem python: "<<s[i].python_score<<endl;
    }

}
float avg(student s[],int n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=s[i].ml_score;
    }
    return sum/n;
}
void  Filter(student s[],int n){
    cout<<"\nCac sinh vien duoc xep loai gioi\n";
    for(int i=0;i<n;i++){
        if(s[i].ml_score >= 8){
            cout<<s[i].name<<" "<<s[i].ml_score;
        }
    }
}
void Top(student s[],int n){
    cout<<"\nCac sinh vien Top 3 diem cao\n";
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i].ml_score < s[j].ml_score){
                swap(s[i],s[j]);
            }
        }
    }
    for(int i=0;i<3;i++){
        cout<<"Ten: "<<s[i].name
            <<"Tuoi: "<<s[i].age
            <<"Diem ml: "<<s[i].ml_score
            <<"Diem python: "<<s[i].python_score;
    }
}
// Chuẩn hoá điểm ML
void chuanhoa(student s[],int n){
    float max=s[0].ml_score;
    float min=s[0].ml_score;
    for(int i=0;i<n;i++){
        
        if(max < s[i].ml_score) max=s[i].ml_score;
        if(min > s[i].ml_score) min=s[i].ml_score;
    }if(max==min) return ;
    cout<<"\ndanh sach du lieu chuan hoa diem ml\n ";
    for(int i=0;i<n;i++){
        s[i].ml_score=(s[i].ml_score-min)/(max-min);
        cout<<"Ten: "<<s[i].name<<endl
            <<"Tuoi: "<<s[i].age<<endl
            <<"Diem ml: "<<s[i].ml_score<<endl
            <<"Diem python: "<<s[i].python_score;
    }
}
void luufile(student s[],int n){
    ofstream file("dataset.txt");
    for(int i=0;i<n;i++){
        file<<"Ten "<<s[i].name<<" "
            <<s[i].age<<" "
            <<s[i].ml_score<<" "
            <<s[i].python_score;
    }
    file.close();

}
void doc(student s[],int n){
    string line;
    ifstream file("dataset.txt");
    while(getline(file,line)){
        cout<<line<<endl;
    }
    file.close();
}
// train 
void train(student s[],int n){
    int test_train=n*0.7;
    cout<<"\ntrain\n";
    for(int i=0;i<test_train;i++){
        cout<<s[i].name<<" "<<s[i].python_score<<endl;
    }
    cout<<"\ntest\n";
    for(int i=test_train;i<n;i++){
        cout<<s[i].name<<" "<<s[i].ml_score<<endl;
    }
}
int main(){
    int n,x;
    cout<<"nhap vao so luong sinh vien: ";
    cin>>n;
    student s[100];
    cin.ignore();
    cout<<"\n===== MENU =====\n";
    cout<<"1. Nhap du lieu\n";
    cout<<"2. Xuat du lieu\n";
    cout<<"3. Tinh trung binh ML\n";
    cout<<"4. Loc sinh vien ML >= 8\n";
    cout<<"5. Top 3 sinh vien ML cao nhat\n";
    cout<<"6. Chuan hoa diem ML\n";
    cout<<"7. Luu file\n";
    cout<<"8. Doc file\n";
    cout<<"9. Train/Test split\n";
    cout<<"0. Thoat\n";
    while(true){
        cout<<"nhap vao chuc nang";
        cin>>x;
        switch (x){
    case 1: 
        nhap(s,n);
        break;
    case 2 :
        xuat(s,n);
        break;
    case 3:
        avg(s,n);
        cout<<"Average ML = "<<avg(s,n)<<endl;
        break;
    case 4:
        Filter(s,n);
        break;
    case 5:
        Top(s,n);
        break;
    case 6:
        chuanhoa(s,n);
        break;
    case 7:
        luufile(s,n);
        break;
    case 8:
        doc(s,n);
        break;
    case 9:
        train(s,n);
        break;
    case 0:
        cout<<"thoat";
        return 0;
    default:
        cout<<"So khong hop le";
        break;
    }
    }
    
    return 0;
}