#include <iostream>
#include <string>

using namespace std;


struct Pesanan {
    int id_pesanan;
    string nama_menu;
    int jumlah_pesanan;
    float harga_pesanan;
};


void tambahPesanan(Pesanan* pesananArray, int* jumlahPesanan) {
    cout << "Masukkan ID Pesanan: ";
    cin >> pesananArray[*jumlahPesanan].id_pesanan;

    cout << "Masukkan Nama Menu: ";
    cin.ignore();  
    getline(cin, pesananArray[*jumlahPesanan].nama_menu);

    cout << "Masukkan Jumlah Pesanan: ";
    cin >> pesananArray[*jumlahPesanan].jumlah_pesanan;

    cout << "Masukkan Harga: ";
    cin >> pesananArray[*jumlahPesanan].harga_pesanan;

    (*jumlahPesanan)++;
    cout << "Pesanan berhasil ditambahkan!" << endl;
}


void tampilkanPesanan(Pesanan* pesananArray, int jumlahPesanan) {
    if (jumlahPesanan == 0) {
        cout << "Belum ada pesanan." << endl;
        return;
    }

    cout << "Daftar Pesanan: " << endl;
    for (int i = 0; i < jumlahPesanan; i++) {
        cout << "ID: " << pesananArray[i].id_pesanan
             << ", Menu: " << pesananArray[i].nama_menu
             << ", Jumlah: " << pesananArray[i].jumlah_pesanan
             << ", Harga: " << pesananArray[i].harga_pesanan
             << endl;
    }
}


void editPesanan(Pesanan* pesananArray, int jumlahPesanan) {
    int id_pesanan;
    cout << "Masukkan ID pesanan yang ingin diedit: ";
    cin >> id_pesanan;

    for (int i = 0; i < jumlahPesanan; i++) {
        if (pesananArray[i].id_pesanan == id_pesanan) {
            cout << "Masukkan Nama Menu Baru: ";
            cin.ignore();
            getline(cin, pesananArray[i].nama_menu);

            cout << "Masukkan Jumlah Pesanan Baru: ";
            cin >> pesananArray[i].jumlah_pesanan;

            cout << "Masukkan Harga Baru: ";
            cin >> pesananArray[i].harga_pesanan;

            cout << "Pesanan berhasil diperbarui!" << endl;
            return;
        }
    }
    cout << "Pesanan dengan ID tersebut tidak ditemukan." << endl;
}


void hapusPesanan(Pesanan* pesananArray, int* jumlahPesanan) {
    int id_pesanan;
    cout << "Masukkan ID pesanan yang ingin dihapus: ";
    cin >> id_pesanan;

    for (int i = 0; i < *jumlahPesanan; i++) {
        if (pesananArray[i].id_pesanan == id_pesanan) {
            for (int j = i; j < *jumlahPesanan - 1; j++) {
                pesananArray[j] = pesananArray[j + 1];
            }
            (*jumlahPesanan)--;
            cout << "Pesanan berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Pesanan dengan ID tersebut tidak ditemukan." << endl;
}


int main() {
    int kapasitas = 100; 
    Pesanan pesananArray[kapasitas];
    int jumlahPesanan = 0;
    int pilihan;

    do {
        cout << "\nSistem Manajemen Pesanan Restoran" << endl;
        cout << "1. Tambah Pesanan" << endl;
        cout << "2. Tampilkan Pesanan" << endl;
        cout << "3. Edit Pesanan" << endl;
        cout << "4. Hapus Pesanan" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahPesanan(pesananArray, &jumlahPesanan);
            break;
        case 2:
            tampilkanPesanan(pesananArray, jumlahPesanan);
            break;
        case 3:
            editPesanan(pesananArray, jumlahPesanan);
            break;
        case 4:
            hapusPesanan(pesananArray, &jumlahPesanan);
            break;
        case 5:
            cout << "Keluar dari program..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
