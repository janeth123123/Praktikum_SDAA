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


struct Stack {
    Node* top = nullptr;

    void push() {
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

        newNode->next = top;
        top = newNode;

        cout << "Pesanan berhasil ditambahkan ke Stack!" << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack kosong." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;

        cout << "Pesanan berhasil dihapus dari Stack!" << endl;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack kosong." << endl;
            return;
        }

        Node* temp = top;
        cout << "Daftar Pesanan di Stack: " << endl;
        while (temp != nullptr) {
            cout << "ID: " << temp->id_pesanan
                << ", Menu: " << temp->nama_menu
                << ", Jumlah: " << temp->jumlah_pesanan
                << ", Harga: " << temp->harga_pesanan
                << endl;
            temp = temp->next;
        }
    }
};


struct Queue {
    Node* front = nullptr;
    Node* rear = nullptr;

    void enqueue() {
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

        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Pesanan berhasil ditambahkan ke Queue!" << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue kosong." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;

        cout << "Pesanan berhasil dihapus dari Queue!" << endl;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue kosong." << endl;
            return;
        }

        Node* temp = front;
        cout << "Daftar Pesanan di Queue: " << endl;
        while (temp != nullptr) {
            cout << "ID: " << temp->id_pesanan
                << ", Menu: " << temp->nama_menu
                << ", Jumlah: " << temp->jumlah_pesanan
                << ", Harga: " << temp->harga_pesanan
                << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Stack pesananStack;
    Queue pesananQueue;
    int pilihan;

    do {
        cout << "\nSistem Manajemen Pesanan Restoran" << endl;
        cout << "1. Tambah Pesanan ke Stack" << endl;
        cout << "2. Hapus Pesanan dari Stack" << endl;
        cout << "3. Tampilkan Pesanan di Stack" << endl;
        cout << "4. Tambah Pesanan ke Queue" << endl;
        cout << "5. Hapus Pesanan dari Queue" << endl;
        cout << "6. Tampilkan Pesanan di Queue" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            pesananStack.push();
            break;
        case 2:
            pesananStack.pop();
            break;
        case 3:
            pesananStack.display();
            break;
        case 4:
            pesananQueue.enqueue();
            break;
        case 5:
            pesananQueue.dequeue();
            break;
        case 6:
            pesananQueue.display();
            break;
        case 7:
            cout << "Keluar dari program..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 7);

    return 0;
}
