#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string stambuk, namaBarang;
    double hargaSatuan;
    int jumlahBarang;

    cout << "=== 5. Program Pembayaran dengan Formatting dan Percabangan ===\n";
    cout << "Masukkan stambuk: ";
    cin >> stambuk;
    cout << "Masukkan nama barang: ";
    cin >> namaBarang;
    cout << "Masukkan harga satuan: ";
    cin >> hargaSatuan;
    cout << "Masukkan jumlah barang: ";
    cin >> jumlahBarang;

    double totalBelanja = hargaSatuan * jumlahBarang;

    int duaDigitTerakhir = 0;
    if (stambuk.length() >= 2) {
        duaDigitTerakhir = (stambuk[stambuk.length() - 2] - '0') * 10 + (stambuk[stambuk.length() - 1] - '0');
    } else if (stambuk.length() == 1) {
        duaDigitTerakhir = stambuk[0] - '0';
    }

    double batasDiskon = 250000 + (duaDigitTerakhir * 2000);
    double diskon = 0;

    if (totalBelanja >= batasDiskon) {
        diskon = totalBelanja * 0.10;
    }

    double totalBayar = totalBelanja - diskon;

    cout << fixed << setprecision(2);
    cout << setw(20) << left << "Stambuk" << ": " << stambuk << endl;
    cout << setw(20) << left << "Nama Barang" << ": " << namaBarang << endl;
    cout << setw(20) << left << "Harga Satuan" << ": Rp" << hargaSatuan << endl;
    cout << setw(20) << left << "Jumlah Barang" << ": " << jumlahBarang << endl;
    cout << setw(20) << left << "Total Belanja" << ": Rp" << totalBelanja << endl;
    cout << setw(20) << left << "Batas Diskon" << ": Rp" << batasDiskon << endl;
    cout << setw(20) << left << "Diskon" << ": Rp" << diskon << endl;
    cout << setw(20) << left << "Total Bayar" << ": Rp" << totalBayar << endl;

    return 0;
}
