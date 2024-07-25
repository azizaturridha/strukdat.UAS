#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    int id;
    string category;
    string author;
};

vector<Book> libarary;

void tambahBuku() {
    Book book;
    cout << "Masukkan ID buku: ";
    cin >> book.id;
    cout << "Masukkan kategori buku: ";
    cin.ignore();
    getline(cin, book.category);
    cout << "Masukkan author buku: ";
    getline(cin, book.author);

    libarary.push_back(book);
    cout << "Buku berhasil ditambahkan!" << endl;
}

void tampilkanBuku() {
    if (libarary.empty()) {
        cout << "Perpustakaan kosong." << endl;
        return;
    }

    cout << "Daftar buku:" << endl;
    for (const auto& book : libarary) {
        cout << "ID: " << book.id << ", kategori: " << book.category << ", author: " << book.author << endl;
    }
}

void updateBuku() {
    int id;
    cout << "Masukkan ID buku yang ingin diupdate: ";
    cin >> id;

    for (auto& book : libarary) {
        if (book.id == id) {
            cout << "Masukkan kategori buku baru: ";
            cin.ignore();
            getline(cin, book.category);
            cout << "Masukkan author buku baru: ";
            getline(cin, book.author);
            cout << "Buku berhasil diupdate!" << endl;
            return;
        }
    }

    cout << "Buku dengan ID tersebut tidak ditemukan." << endl;
}

void hapusBuku() {
    int id;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin >> id;

    for (auto it = libarary.begin(); it != libarary.end(); ++it) {
        if (it->id == id) {
            libarary.erase(it);
            cout << "Buku berhasil dihapus!" << endl;
            return;
        }
    }

    cout << "Buku dengan ID tersebut tidak ditemukan." << endl;
}

int main() {
    int choice;
    string role;

    do {
		cout << "\n 1. Admin atau User\n ";
		cout << "2. Exit\n ";
		cout << "Enter choice: ";
		cin >> role;

        if (role == "admin") {
            do {
                cout << "Menu Perpustakaan (Admin)" << endl;
                cout << "1. Tambahkan Buku" << endl;
                cout << "2. Tampilkan Buku" << endl;
                cout << "3. Update Buku" << endl;
                cout << "4. Hapus Buku" << endl;
                cout << "0. Exit" << endl;
                cout << "Pilihan Anda: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        tambahBuku();
                        break;
                    case 2:
                        tampilkanBuku();
                        break;
                    case 3:
                        updateBuku();
                        break;
                    case 4:
                        hapusBuku();
                        break;
                    case 0:
                        cout << "Thax you!" << endl;
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                        break;
                }

                cout << endl;
            } while (choice != 0);
        } else if (role == "user") {
            do {
                cout << "Menu Perpustakaan (User)" << endl;
                cout << "1. Tampilkan Buku" << endl;
                cout << "0. Keluar" << endl;
                cout << "Pilihan Anda: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        tampilkanBuku();
                        break;
                    case 0:
                        cout << "Terima kasih!" << endl;
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                        break;
                }

                cout << endl;
            } while (choice != 0);
        } else if (role != "0") {
            cout << "Peran tidak valid." << endl;
        }
    } while (role != "0");
    return 0;
}
