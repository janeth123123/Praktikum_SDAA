#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

    vector<Node> toVector() {
        vector<Node> result;
        Node* temp = top;
        while (temp != nullptr) {
            result.push_back(*temp);
            temp = temp->next;
        }
        return result;
    }

    void fromVector(const vector<Node>& nodes) {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }

        for (auto it = nodes.rbegin(); it != nodes.rend(); ++it) {
            Node* newNode = new Node(*it);
            newNode->next = top;
            top = newNode;
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

    vector<Node> toVector() {
        vector<Node> result;
        Node* temp = front;
        while (temp != nullptr) {
            result.push_back(*temp);
            temp = temp->next;
        }
        return result;
    }

    void fromVector(const vector<Node>& nodes) {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        for (const auto& node : nodes) {
            Node* newNode = new Node(node);
            newNode->next = nullptr;

            if (rear == nullptr) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }
    }
};

// Merge sort (ascending)
void merge(vector<Node>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Node> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].harga_pesanan <= R[j].harga_pesanan) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Node>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Quick sort (descending)
int partition(vector<Node>& arr, int low, int high) {
    float pivot = arr[high].harga_pesanan;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].harga_pesanan >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<Node>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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
        cout << "7. Sort Stack (Merge Sort - Ascending)" << endl;
        cout << "8. Sort Queue (Quick Sort - Descending)" << endl;
        cout << "9. Keluar" << endl;
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
        case 7: {
            vector<Node> stackVector = pesananStack.toVector();
            mergeSort(stackVector, 0, stackVector.size() - 1);
            pesananStack.fromVector(stackVector);
            cout << "Stack telah diurutkan secara ascending menggunakan Merge Sort." << endl;
            break;
        }
        case 8: {
            vector<Node> queueVector = pesananQueue.toVector();
            quickSort(queueVector, 0, queueVector.size() - 1);
            pesananQueue.fromVector(queueVector);
            cout << "Queue telah diurutkan secara descending menggunakan Quick Sort." << endl;
            break;
        }
        case 9:
            cout << "Keluar dari program..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 9);

    return 0;
}