#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // membuka file input.txt untuk dibaca
    ifstream inputFile("input.txt");

    // memeriksa apakah file berhasil dibuka
    if (!inputFile.is_open()) {
        cout << "Gagal membuka file input.txt!" << endl;
        return 1;
    }

    // membaca teks dari file input.txt dan menyimpannya ke dalam string
    string text;
    string line;
    while (getline(inputFile, line)) {
        if (line.find(":Password.") != string::npos) {
            // hapus kata ":1sampai8." dari baris yang mengandungnya
            line.erase(line.find(":Password."), 10);
        }
        // konversi teks menjadi huruf kapital
        transform(line.begin(), line.end(), line.begin(), ::toupper);
        text += line + "\n";
    }
    inputFile.close();

    // menulis teks yang sudah diubah kembali ke file input.txt
    ofstream outputFile("input.txt");
    outputFile << text;
    outputFile.close();

    cout << "Teks di file input.txt telah diubah menjadi huruf kapital dan kata ':1sampai8.' dihapus dari baris yang mengandungnya." << endl;

    return 0;
}

