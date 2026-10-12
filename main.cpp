#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int pilihan;

    cout << "===============================================" << endl;
    cout << "PROGRAM LATIHAN PERCABANGAN DAN FORMAT OUTPUT" << endl;
    cout << "===============================================" << endl;
    cout << "1. Pengolahan Nilai Akhir Mahasiswa" << endl;
    cout << "2. Validasi Nilai, Kelulusan, dan Grade" << endl;
    cout << "3. Nested If - Potongan Biaya Berdasarkan Transaksi dan Status Member" << endl;
    cout << "4. Kategori Biaya Praktikum Berdasarkan Stambuk dan Nilai" << endl;
    cout << "5. Program Pembayaran dengan Formatting dan Percabangan" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih program: ";
    cin >> pilihan;

    if (pilihan == 1) {
        cout << "\n=== 1. Pengolahan Nilai Akhir Mahasiswa ===\n";
        string stambuk;
        double tugas, uts, uas;

        cout << "Masukkan stambuk: ";
        cin >> stambuk;
        cout << "Masukkan nilai Tugas: ";
        cin >> tugas;
        cout << "Masukkan nilai UTS: ";
        cin >> uts;
        cout << "Masukkan nilai UAS: ";
        cin >> uas;

        double nilaiSebelumBonus = (tugas * 0.30) + (uts * 0.30) + (uas * 0.40);
        int digitTerakhir = stambuk.back() - '0';
        double bonus = digitTerakhir % 5;
        double nilaiAkhir = nilaiSebelumBonus + bonus;

        if (nilaiAkhir > 100) {
            nilaiAkhir = 100;
        }

        cout << fixed << setprecision(2);
        cout << "Stambuk: " << stambuk << endl;
        cout << "Nilai sebelum bonus: " << nilaiSebelumBonus << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Nilai akhir: " << nilaiAkhir << endl;
    }
    else if (pilihan == 2) {
        cout << "\n=== 2. Validasi Nilai, Kelulusan, dan Grade ===\n";
        double nilai;
        cout << "Masukkan nilai akhir mahasiswa: ";
        cin >> nilai;

        if (nilai < 0 || nilai > 100) {
            cout << "Nilai tidak valid" << endl;
        } else {
            string status;
            if (nilai >= 60) {
                status = "Lulus";
            } else {
                status = "Tidak Lulus";
            }

            char grade;
            if (nilai >= 80) {
                grade = 'A';
            } else if (nilai >= 70) {
                grade = 'B';
            } else if (nilai >= 60) {
                grade = 'C';
            } else if (nilai >= 50) {
                grade = 'D';
            } else {
                grade = 'E';
            }

            cout << fixed << setprecision(2);
            cout << "Nilai: " << nilai << endl;
            cout << "Status Kelulusan: " << status << endl;
            cout << "Grade: " << grade << endl;
        }
    }
    else if (pilihan == 3) {
        cout << "\n=== 3. Nested If - Potongan Biaya Berdasarkan Transaksi dan Status Member ===\n";
        double totalTransaksi;
        int statusMember;
        string stambuk;

        cout << "Masukkan total transaksi: ";
        cin >> totalTransaksi;
        cout << "Status member (1 = member, 0 = bukan member): ";
        cin >> statusMember;
        cout << "Masukkan dua digit terakhir stambuk: ";
        cin >> stambuk;

        int duaDigitTerakhir = 0;
        if (stambuk.length() >= 2) {
            duaDigitTerakhir = (stambuk[stambuk.length() - 2] - '0') * 10 + (stambuk[stambuk.length() - 1] - '0');
        } else if (stambuk.length() == 1) {
            duaDigitTerakhir = stambuk[0] - '0';
        }

        double batasTransaksi = 400000 + (duaDigitTerakhir * 1000);
        double diskon = 0;
        double persenDiskon = 0;

        if (totalTransaksi < batasTransaksi) {
            diskon = 0;
            persenDiskon = 0;
        } else if (totalTransaksi >= batasTransaksi) {
            diskon = totalTransaksi * 0.10;
            persenDiskon = 10;

            if (statusMember == 1) {
                diskon += totalTransaksi * 0.05;
                persenDiskon = 15;
            }
        }

        double totalBayar = totalTransaksi - diskon;

        cout << fixed << setprecision(2);
        cout << "Batas transaksi: Rp" << batasTransaksi << endl;
        cout << "Total transaksi: Rp" << totalTransaksi << endl;
        cout << "Persentase diskon: " << persenDiskon << "%" << endl;
        cout << "Nominal diskon: Rp" << diskon << endl;
        cout << "Total yang harus dibayar: Rp" << totalBayar << endl;

        cout << "\nUrutan keputusan:" << endl;
        cout << "1. Cek apakah total transaksi belum mencapai batas." << endl;
        cout << "2. Jika sudah mencapai batas, beri diskon 10%." << endl;
        cout << "3. Jika status member adalah 1, tambah diskon 5% lagi." << endl;
        cout << "4. Hitung total yang harus dibayar = total transaksi - diskon." << endl;
    }
    else if (pilihan == 4) {
        cout << "\n=== 4. Kategori Biaya Praktikum Berdasarkan Stambuk dan Nilai ===\n";
        string stambuk;
        double nilaiPraktikum;

        cout << "Masukkan stambuk: ";
        cin >> stambuk;
        cout << "Masukkan nilai praktikum: ";
        cin >> nilaiPraktikum;

        if (nilaiPraktikum < 0 || nilaiPraktikum > 100) {
            cout << "Nilai tidak valid" << endl;
        } else {
            int digitTerakhir = stambuk.back() - '0';
            string kelompok;

            if (digitTerakhir % 2 == 0) {
                kelompok = "Kelompok A";
            } else {
                kelompok = "Kelompok B";
            }

            string kategori;
            if (nilaiPraktikum >= 85 && nilaiPraktikum <= 100) {
                kategori = "Sangat Baik";
            } else if (nilaiPraktikum >= 70 && nilaiPraktikum <= 84) {
                kategori = "Baik";
            } else if (nilaiPraktikum >= 60 && nilaiPraktikum <= 69) {
                kategori = "Cukup";
            } else {
                kategori = "Perlu Perbaikan";
            }

            cout << fixed << setprecision(2);
            cout << "Stambuk: " << stambuk << endl;
            cout << "Kelompok mahasiswa: " << kelompok << endl;
            cout << "Nilai: " << nilaiPraktikum << endl;
            cout << "Kategori hasil praktikum: " << kategori << endl;
        }
    }
    else if (pilihan == 5) {
        cout << "\n=== 5. Program Pembayaran dengan Formatting dan Percabangan ===\n";
        string stambuk, namaBarang;
        double hargaSatuan, totalBelanja, batasDiskon, diskon, totalBayar;
        int jumlahBarang;

        cout << "Masukkan stambuk: ";
        cin >> stambuk;
        cout << "Masukkan nama barang: ";
        cin >> namaBarang;
        cout << "Masukkan harga satuan: ";
        cin >> hargaSatuan;
        cout << "Masukkan jumlah barang: ";
        cin >> jumlahBarang;

        totalBelanja = hargaSatuan * jumlahBarang;

        int duaDigitTerakhir = 0;
        if (stambuk.length() >= 2) {
            duaDigitTerakhir = (stambuk[stambuk.length() - 2] - '0') * 10 + (stambuk[stambuk.length() - 1] - '0');
        } else if (stambuk.length() == 1) {
            duaDigitTerakhir = stambuk[0] - '0';
        }

        batasDiskon = 250000 + (duaDigitTerakhir * 2000);

        if (totalBelanja >= batasDiskon) {
            diskon = totalBelanja * 0.10;
        } else {
            diskon = 0;
        }

        totalBayar = totalBelanja - diskon;

        cout << fixed << setprecision(2);
        cout << setw(20) << left << "Stambuk" << ": " << stambuk << endl;
        cout << setw(20) << left << "Nama Barang" << ": " << namaBarang << endl;
        cout << setw(20) << left << "Harga Satuan" << ": Rp" << hargaSatuan << endl;
        cout << setw(20) << left << "Jumlah Barang" << ": " << jumlahBarang << endl;
        cout << setw(20) << left << "Total Belanja" << ": Rp" << totalBelanja << endl;
        cout << setw(20) << left << "Batas Diskon" << ": Rp" << batasDiskon << endl;
        cout << setw(20) << left << "Diskon" << ": Rp" << diskon << endl;
        cout << setw(20) << left << "Total Bayar" << ": Rp" << totalBayar << endl;
    }
    else if (pilihan == 0) {
        cout << "Program selesai." << endl;
    }
    else {
        cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}

