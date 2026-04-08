#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
// Cau 1
void NhapMang(double *&SoThuc, int &n) 
{
    do 
	{
        cout << "Nhap so phan tu n (>0): ";
        cin >> n;
        if (n <= 0) cout << "Nhap sai, vui long nhap lai!\n";
    } while (n <= 0);

    SoThuc = new double[n];
    for (int i = 0; i < n; i++) 
	{
        cout << "Nhap phan tu SoThuc[" << i << "]: ";
        cin >> SoThuc[i];  
    }
} 
//CAu 2
double TongChan(double *SoThuc, int n) 
{
    double tong = 0.0;
    for(int i = 0; i < n; i++) 
        if (SoThuc[i] == floor(SoThuc[i]) && ((int)SoThuc[i] % 2 == 0)) 
			tong += SoThuc[i];
    return tong;
}
// Cau 3
void GhiFile(double *SoThuc, int n) 
{
    ofstream ghi("HotenSV.txt");
    if (!ghi) 
	{
        cout << "Khong mo duoc file!\n";
        return;
    }
    ghi << n << endl;
    for (int i = 0; i < n; i++) 
        ghi << SoThuc[i] << "\t";
    ghi.close();
    cout << "Da ghi mang vao file HotenSV.txt\n";
}
// Cau 4
struct SinhVien 
{
    string HoTenSV;
    int NamSinh;
    SinhVien *next;
};
//THEM CUOI
void ThemSinhVien(SinhVien *&head, string ten, int nam) 
{
    SinhVien *sv = new SinhVien;
    sv->HoTenSV = ten;
    sv->NamSinh = nam;
    sv->next = nullptr;
    if (head == nullptr) 
        head = sv;
    else 
	{
        SinhVien *p = head;
        while (p->next != nullptr) 
			p = p->next;
        p->next = sv;
    }
}
void NhapDanhSach(SinhVien *&head) 
{
    string ten;
    int nam;
    cout << "Nhap ho ten (nhap 'Thoat' de dung): ";
    getline(cin, ten);
    while (ten != "Thoat") 
	{
        cout << "Nhap nam sinh: ";
        cin >> nam;
        cin.ignore();
        ThemSinhVien(head, ten, nam);
        cout << "Nhap ho ten (nhap 'Thoat' de dung): ";
        getline(cin, ten);
    }
}
//Câu 5
void XuatDanhSach(SinhVien *head) 
{
    cout << "\nDanh sach sinh vien:\n";
    SinhVien *p = head;
    while (p != nullptr) 
	{
        cout << "Ho ten: " << p->HoTenSV << ", Nam sinh: " << p->NamSinh << endl;
        p = p->next;
    }
}
// menu
int main() 
{
    double *SoThuc = nullptr;
    int n = 0;
    SinhVien *ds = nullptr;
    string chon;
    do {
        cout << "\nDAY LA MENU BAI KIEM TRA\n";
        cout << "1. Nhap mang SoThuc\n";
        cout << "2. Tinh tong cac phan tu chan\n";
        cout << "3. Ghi mang vao file HotenSV.txt\n";
        cout << "4. Nhap danh sach sinh vien\n";
        cout << "5. Xuat danh sach sinh vien\n";
        cout << "Nhap 'Thoat' de ket thuc\n";
        cout << "Lua chon: ";
        cin >> chon;
        cin.ignore();//bo qua ky tu trong bo dem

        if (chon == "1") 
            NhapMang(SoThuc, n);
        else if (chon == "2") 
		{
            if (SoThuc != nullptr)
                cout << "Tong cac phan tu chan = " << TongChan(SoThuc, n) << endl;
            else cout << "Chua nhap mang!\n";
        } else if (chon == "3") 
		{
            if (SoThuc != nullptr) 
				GhiFile(SoThuc, n);
            else cout << "Chua nhap mang!\n";
        } else if (chon == "4") 
            NhapDanhSach(ds);
          else if (chon == "5") 
            XuatDanhSach(ds);
    } while (chon != "Thoat");
    delete[] SoThuc;
    return 0;
}

