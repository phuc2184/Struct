
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

// ================== MẢNG ==================
// Nhập mảng
void NhapMang(double *&SoThuc, int &n)
{
    do
    {
        cout << "Nhap so phan tu n (>0): ";
        cin >> n;
    } while (n <= 0);

    SoThuc = new double[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap SoThuc[" << i << "]: ";
        cin >> SoThuc[i];
    }
}

// Tổng số chẵn
double TongChan(double *SoThuc, int n)
{
    double tong = 0;
    for (int i = 0; i < n; i++)
        if (SoThuc[i] == (int)SoThuc[i] && (int)SoThuc[i] % 2 == 0)
            tong += SoThuc[i];
    return tong;
}

// Ghi file mảng
void GhiFile(double *SoThuc, int n)
{
    ofstream f("HotenSV.txt");
    f << n << endl;
    for (int i = 0; i < n; i++)
        f << SoThuc[i] << " ";
    f.close();
}

// ===== BÀI THÊM =====

// Số nguyên tố
bool LaSoNguyenTo(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}
int DemSoNguyenTo(double *a, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == (int)a[i] && LaSoNguyenTo((int)a[i]))
            dem++;
    return dem;
}

// Max - Min
double TimMax(double *a, int n)
{
    double m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m)
            m = a[i];
    return m;
}
double TimMin(double *a, int n)
{
    double m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < m)
            m = a[i];
    return m;
}

// Trung bình
double TBC(double *a, int n)
{
    double s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    return s / n;
}

// Đếm âm
int DemAm(double *a, int n)
{
    int d = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            d++;
    return d;
}

// Chính phương
bool LaCP(int x)
{
    int t = sqrt(x);
    return t * t == x;
}
int DemCP(double *a, int n)
{
    int d = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == (int)a[i] && LaCP((int)a[i]))
            d++;
    return d;
}

// Đảo mảng
void DaoMang(double *a, int n)
{
    for (int i = 0; i < n / 2; i++)
        swap(a[i], a[n - i - 1]);
}

// Bubble Sort
void BubbleSort(double *a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

// QuickSort
int Partition(double *a, int l, int r)
{
    double pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    swap(a[i + 1], a[r]);
    return i + 1;
}
void QuickSort(double *a, int l, int r)
{
    if (l < r)
    {
        int pi = Partition(a, l, r);
        QuickSort(a, l, pi - 1);
        QuickSort(a, pi + 1, r);
    }
}

// ================== DANH SÁCH ==================
struct SinhVien
{
    string HoTenSV;
    int NamSinh;
    SinhVien *next;
};

// Thêm cuối
void ThemSV(SinhVien *&head, string ten, int nam)
{
    SinhVien *sv = new SinhVien{ten, nam, nullptr};
    if (!head)
        head = sv;
    else
    {
        SinhVien *p = head;
        while (p->next)
            p = p->next;
        p->next = sv;
    }
}

// Nhập
void NhapDS(SinhVien *&head)
{
    string ten;
    int nam;
    cin.ignore();
    while (true)
    {
        cout << "Nhap ten (Thoat de dung): ";
        getline(cin, ten);
        if (ten == "Thoat")
            break;
        cout << "Nam sinh: ";
        cin >> nam;
        ThemSV(head, ten, nam);
        cin.ignore();
    }
}

// Xuất
void XuatDS(SinhVien *h)
{
    while (h)
    {
        cout << h->HoTenSV << " - " << h->NamSinh << endl;
        h = h->next;
    }
}

// Đảo list
void DaoDS(SinhVien *&h)
{
    SinhVien *p = nullptr, *c = h, *n;
    while (c)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    h = p;
}

// Xóa theo tên
void XoaSV(SinhVien *&h, string ten)
{
    while (h && h->HoTenSV == ten)
    {
        SinhVien *t = h;
        h = h->next;
        delete t;
    }
    SinhVien *p = h;
    while (p && p->next)
    {
        if (p->next->HoTenSV == ten)
        {
            SinhVien *t = p->next;
            p->next = t->next;
            delete t;
        }
        else
            p = p->next;
    }
}

// Ghi file SV
void GhiSV(SinhVien *h)
{
    ofstream f("SinhVien.txt");
    while (h)
    {
        f << h->HoTenSV << " " << h->NamSinh << endl;
        h = h->next;
    }
    f.close();
}

// Tìm gần đúng
void TimGanDung(SinhVien *h, string key)
{
    while (h)
    {
        if (h->HoTenSV.find(key) != string::npos)
            cout << h->HoTenSV << " - " << h->NamSinh << endl;
        h = h->next;
    }
}

// ================== MAIN ==================
int main()
{
    double *a = nullptr;
    int n = 0;
    SinhVien *ds = nullptr;
    string chon;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1.Nhap mang\n2.Tong chan\n3.Ghi file\n";
        cout << "4.Nhap SV\n5.Xuat SV\n";
        cout << "6.So nguyen to\n7.Max\n8.Min\n9.TBC\n10.So am\n";
        cout << "11.So CP\n12.Dao mang\n13.Bubble\n14.QuickSort\n";
        cout << "15.Dao DS\n16.Xoa SV\n17.Ghi SV\n18.Tim gan dung\n";
        cout << "Thoat de dung\nChon: ";
        cin >> chon;

        if (chon == "1")
            NhapMang(a, n);
        else if (chon == "2")
            cout << TongChan(a, n);
        else if (chon == "3")
            GhiFile(a, n);
        else if (chon == "4")
            NhapDS(ds);
        else if (chon == "5")
            XuatDS(ds);
        else if (chon == "6")
            cout << DemSoNguyenTo(a, n);
        else if (chon == "7")
            cout << TimMax(a, n);
        else if (chon == "8")
            cout << TimMin(a, n);
        else if (chon == "9")
            cout << TBC(a, n);
        else if (chon == "10")
            cout << DemAm(a, n);
        else if (chon == "11")
            cout << DemCP(a, n);
        else if (chon == "12")
            DaoMang(a, n);
        else if (chon == "13")
            BubbleSort(a, n);
        else if (chon == "14")
            QuickSort(a, 0, n - 1);
        else if (chon == "15")
            DaoDS(ds);
        else if (chon == "16")
        {
            string t;
            cin.ignore();
            getline(cin, t);
            XoaSV(ds, t);
        }
        else if (chon == "17")
            GhiSV(ds);
        else if (chon == "18")
        {
            string k;
            cin.ignore();
            getline(cin, k);
            TimGanDung(ds, k);
        }
    } while (chon != "Thoat");

    delete[] a;
}
