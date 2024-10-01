#include <iostream>
#include <string>

using namespace std;

struct Node {
    int id_pesanan;
    string nama_menu;
    int jumlah_pesanan;
    float harga_pesanan;
    Node* next;
};

void tambahPesanan(Node** head) {
    Node* newNode = new Node();
    cout << "Masukkan ID Pesanan: ";
    cin >> newNode->id_pesanan;

    cout << "Masukkan Nama Menu: ";
    cin.ignore();
    getline(cin, newNode->nama_menu);

    cout << "Masukkan Jumlah Pesanan: ";
    cin >> newNode->jumlah_pesanan;

    cout << "Masukkan Harga: ";
    cin >> newNode->harga_pesanan;

    newNode->next = *head; 
    *head = newNode;

    cout << "Pesanan berhasil ditambahkan!" << endl;
}

void tampilkanPesanan(Node* head) {
    if (head == nullptr) {
        cout << "Belum ada pesanan." << endl;
        return;
    }

    Node* temp = head;
    cout << "Daftar Pesanan: " << endl;
    while (temp != nullptr) {
        cout << "ID: " << temp->id_pesanan
             << ", Menu: " << temp->nama_menu
             << ", Jumlah: " << temp->jumlah_pesanan
             << ", Harga: " << temp->harga_pesanan
             << endl;
        temp = temp->next;
    }
}

void editPesanan(Node* head) {
    int id_pesanan;
    cout << "Masukkan ID pesanan yang ingin diedit: ";
    cin >> id_pesanan;

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->id_pesanan == id_pesanan) {
            cout << "Masukkan Nama Menu Baru: ";
            cin.ignore();
            getline(cin, temp->nama_menu);

            cout << "Masukkan Jumlah Pesanan Baru: ";
            cin >> temp->jumlah_pesanan;

            cout << "Masukkan Harga Baru: ";
            cin >> temp->harga_pesanan;

            cout << "Pesanan berhasil diperbarui!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Pesanan dengan ID tersebut tidak ditemukan." << endl;
}

void hapusPesanan(Node** head) {
    int id_pesanan;
    cout << "Masukkan ID pesanan yang ingin dihapus: ";
    cin >> id_pesanan;

    Node* temp = *head;
    Node* prev = nullptr;
  
    if (temp != nullptr && temp->id_pesanan == id_pesanan) {
        *head = temp->next;
        delete temp;
        cout << "Pesanan berhasil dihapus!" << endl;
        return;
    }
  
    while (temp != nullptr && temp->id_pesanan != id_pesanan) {
        prev = temp;
        temp = temp->next;
    }

   
    if (temp == nullptr) {
        cout << "Pesanan dengan ID tersebut tidak ditemukan." << endl;
        return;
    }
    
    prev->next = temp->next;
    delete temp;
    cout << "Pesanan berhasil dihapus!" << endl;
}

int main() {
    Node* head = nullptr;
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
            tambahPesanan(&head);
            break;
        case 2:
            tampilkanPesanan(head);
            break;
        case 3:
            editPesanan(head);
            break;
        case 4:
            hapusPesanan(&head);
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
