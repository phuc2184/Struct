#include <iostream>
using namespace std;

int main() {
    int n = 3;

    // Mảng động số nguyên
    int* mangInt = new int[n];
    mangInt[0] = 5 / 2; // Kết quả sẽ là 2 (bị mất phần thập phân)

    // Mảng động số thực
    float* mangFloat = new float[n];
    mangFloat[0] = 5.0 / 2.0; // Kết quả sẽ là 2.5 (giữ được phần thập phân)

    cout << "Mang int: " << mangInt[0] << endl;
    cout << "Mang float: " << mangFloat[0] << endl;

    delete[] mangInt;
    delete[] mangFloat;
    return 0;
}