#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;
#define MAX 10
#define GARIS "-----------------------------"

string data_stack[MAX];
int top_stack = 0;

bool isStackEmpty() {
    return top_stack == 0;
}

bool isStackFull() {
    return top_stack >= MAX;
}

void tampilStack() {
    if (!isStackEmpty()) {
        cout << "data yang tersimpan : " << endl;
        for (int i = 0; i < top_stack; i++) {
            cout << i + 1 << ". " << data_stack[i] << endl;
        }
    } else {
        cout << "data tidak tersedia : " << endl;
    }
    if (isStackFull()) {
        cout << "data sudah penuh !" << endl;
    }
}

void push() {
    if (!isStackFull()) {
        cout << "masukkan data : ";
        cin >> data_stack[top_stack];
        top_stack++;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void pop() {
    if (!isStackEmpty()) {
        top_stack--;
        cout << "Data teratas berhasil dihapus (Pop)." << endl;
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void clearStack() {
    top_stack = 0;
    cout << "Stack berhasil dikosongkan." << endl;
}

void cariStack() {
    if (isStackEmpty()) {
        cout << "Data kosong, tidak dapat melakukan pencarian!" << endl;
        return;
    }

    for (int i = 0; i < top_stack - 1; i++) {
        for (int j = 0; j < top_stack - i - 1; j++) {
            if (data_stack[j] > data_stack[j + 1]) {
                string temp = data_stack[j];
                data_stack[j] = data_stack[j + 1];
                data_stack[j + 1] = temp;
            }
        }
    }

    string target;
    cout << "Data Sudah Diurutkan" << endl;
    cout << "Masukkan data yang dicari : ";
    cin >> target;

    int awal = 0;
    int akhir = top_stack - 1;
    int tengah;
    bool ditemukan = false;

    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;

        if (data_stack[tengah] == target) {
            ditemukan = true;
            break;
        }
        else if (data_stack[tengah] < target) {
            awal = tengah + 1;
        } 
        else {
            akhir = tengah - 1;
        }
    }

    if (ditemukan) {
        cout << "Data Ditemukan!!!" << endl;
    } else {
        cout << "Data Tidak Ditemukan!!!" << endl;
    }
}

string data_queue[MAX];
int top_queue = 0;

bool isQueueEmpty() {
    return top_queue == 0;
}

bool isQueueFull() {
    return top_queue >= MAX;
}

void tampilQueue() {
    if (!isQueueEmpty()) {
        cout << "Antrian Data" << endl;
        for (int i = top_queue - 1; i >= 0; i--) {
            cout << i + 1 << ". " << data_queue[i] << endl;
        }
    } else {
        cout << "Antrian kosong" << endl;
    }
    if (isQueueFull()) {
        cout << "Antrian Penuh" << endl;
    }
}

void enqueue() {
    if (!isQueueFull()) {
        cout << "Masukkan data ... ";
        cin >> data_queue[top_queue];
        top_queue++;
    } else {
        cout << "Queue penuh!" << endl;
    }
}

void dequeue() {
    if (!isQueueEmpty()) {
        for (int i = 0; i < top_queue - 1; i++) {
            data_queue[i] = data_queue[i + 1];
        }
        top_queue--;
        cout << "Data terdepan telah dihapus (Dequeue)." << endl;
    } else {
        cout << "Queue kosong!" << endl;
    }
}

void clearQueue() {
    top_queue = 0;
    cout << "Queue berhasil dikosongkan." << endl;
}

void cariQueue() {
    if (isQueueEmpty()) {
        cout << "Data kosong, tidak dapat melakukan pencarian!" << endl;
        return;
    }

    for (int i = 0; i < top_queue - 1; i++) {
        for (int j = 0; j < top_queue - i - 1; j++) {
            if (data_queue[j] > data_queue[j + 1]) {
                string temp = data_queue[j];
                data_queue[j] = data_queue[j + 1];
                data_queue[j + 1] = temp;
            }
        }
    }

    string target;
    cout << "Data Sudah Diurutkan" << endl;
    cout << "masukkan data yang dicari : ";
    cin >> target;

    int awal = 0;
    int akhir = top_queue - 1;
    int tengah;
    bool ditemukan = false;

    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;

        if (data_queue[tengah] == target) {
            ditemukan = true;
            break;
        }
        else if (data_queue[tengah] < target) {
            awal = tengah + 1;
        } 
        else {
            akhir = tengah - 1;
        }
    }

    if (ditemukan) {
        cout << "data ditemukan!!!" << endl;
    } else {
        cout << "data tidak ditemukan!!!" << endl;
    }
}

int main() {
    int pUtama, pil;

    menu_utama:
    system("cls");
    cout << "++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Menu Pilihan  \n 1. Stack \n 2. Queue \n 3. Keluar" << endl;
    cout << "pilih ... ";
    cin >> pUtama;
    cout << "++++++++++++++++++++++++++++++++++++" << endl;

    if (pUtama == 1) {
        menu_stack:
        system("cls");
        cout << "+++++++++ stack +++++++++" << endl;
        tampilStack();
        cout << "\nmenu pilihan : \n 1. Push \n 2. Pop \n 3. Clear \n 4. Pencarian \n 5. Kembali" << endl;
        cout << "\npilih .... ";
        cin >> pil;

        if (pil == 1) {
            push();
            goto menu_stack;
        } else if (pil == 2) {
            pop();
            goto menu_stack;
        } else if (pil == 3) {
            clearStack();
            goto menu_stack;
        } else if (pil == 4) {
            cariStack();
            system("pause");
            goto menu_stack;
        } else if (pil == 5) {
            goto menu_utama;
        } else {
            cout << "Pilihan tidak sesuai perintah!" << endl;                                                                                                            
        }
    } else if (pUtama == 2) {
        menu_queue:
        system("cls");
        cout << "+++++++++ queue +++++++++" << endl;
        tampilQueue();
        cout << "\nmenu pilihan : \n 1. Enqueue \n 2. Dequeue \n 3. Clear \n 4. Pencarian \n 5. Kembali" << endl;
        cout << "\npilih .... ";
        cin >> pil;

        if (pil == 1) {
            enqueue();
            goto menu_queue;
        } else if (pil == 2) {
            dequeue();
            goto menu_queue;
        } else if (pil == 3) {
            clearQueue();
            goto menu_queue;
        } else if (pil == 4) {
            cariQueue();
            system("pause");
            goto menu_queue;
        } else if (pil == 5) {
            goto menu_utama;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    } else if (pUtama == 3) {
        exit(0);
    } 

    return 0;
}
