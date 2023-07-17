#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	//isi disini
	int jumlahProduk;
	string namaProduk;
	string tipeProduk;
	Node* next;


};
class ManajemenProduk {
private:
	Node* head;
public:
	ManajemenProduk() {
		head = NULL;
	}
	void tambahProduk() {
		string nama;
		int jumlah;
		string tipe;
		cout << "========== TAMBAH PRODUK ==========" << endl;
		cout << "Nama Produk : ";
		getline(cin, nama);
		cout << "Jumlah Produk : ";
		cin >> jumlah;
		cin.ignore(); // Membersihkan buffer input
		cout << "Tipe Produk : ";
		getline(cin, tipe);
		//isi disini
		Node* newNode = new Node();
		newNode->jumlahProduk = jumlah;
		newNode->namaProduk = nama;
		newNode->tipeProduk = tipe;
		// begining of list
		if (head == NULL) {
			newNode->next = newNode;
			head = newNode;
			return;
		}
		//end of list
		if (nama <= head->next->namaProduk) {
			if (nama == head->next->namaProduk) {
				cout << "\nProduk sudah ada" << endl;
				return;
			}
			newNode->next = head->next;
			head->next = newNode;

			return;
		}

		Node* current = head->next;
		Node* previous = head;
		while (current->next != head->next && current->next->namaProduk < nama) {
			previous = current;
			current = current->next;
		}

		if (current->next != head->next && nama == current->next->namaProduk) {
			cout << "\nProduk sudah ada" << endl;
			return;
		}

		newNode->next = current->next;
		current->next = newNode;


		cout << "Produk berhasil ditambahkan!" << endl;
	}
	void tampilkanSemuaProduk() {
		cout << "========== SEMUA DATA PRODUK ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;

		}
		else {
			Node* currentNode = head;
			while (true) {
				cout << "Nama Produk	: " << currentNode->namaProduk << endl;
				cout << "Jumlah Produk	: " << currentNode->jumlahProduk << endl;
				cout << "Tipe Produk	: " << currentNode->tipeProduk << endl;
				if (currentNode->next == head) {
					break;
				}
				currentNode = currentNode->next;
			}
		}
	}



	void cariProdukByNama() {
		cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			string targetNama;
			cout << "Nama Produk yang dicari: ";
			getline(cin, targetNama);
			Node* current = head;
			int posisi = 0;
			while (current != NULL) {
				posisi++;
				//isi disini
				if (current->namaProduk == targetNama) {
					cout << "Produk ditemukan pada posisi " << posisi << endl;
					cout << "Nama Produk	: " << current->namaProduk << endl;
					cout << "Jumlah Produk	: " << current->jumlahProduk << endl;
					cout << "Tipe Produk	: " << current->tipeProduk << endl;
					break;
				}
				current = current->next;
			}
			if (current == NULL) {
				cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" <<
					endl;
			}
		}
	}
	void algorithmaSortByJumlahProduk() {
		if (head == NULL || head->next == NULL) {
			return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
		}
		Node* current;
		Node* last = NULL;
		current = head;
		//isi disini
	}
};
int main() {
	ManajemenProduk manajemenProduk;
	int pilihan;
	do {
		cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
		cout << "1. Tambah Produk" << endl;
		cout << "2. Tampilkan Semua Produk" << endl;
		cout << "3. Cari Produk berdasarkan Nama" << endl;
		cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			manajemenProduk.tambahProduk();
			break;
		case 2:
			manajemenProduk.tampilkanSemuaProduk();
			break;
		case 3:
			manajemenProduk.cariProdukByNama();
			break;
		case 4:
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}



//2. circuler linkedlist,singlelinkedlist 
//3. memasukan data pada daftar(array) awal dan akan di keluarkan diawal juga (FIFO)
//4. algoritma stack digunakan saat ada tumpukan data maka data yang akan diambil atau dibuang terlebih dahulu adalaha data yang paling atas
//5.a. 5
//  b.inoder = 15,20,30,48,31,32,25,35, 50, 99,98,90,70,69,67,65,94,,66s