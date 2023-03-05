#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt"); // membuka file input.txt
    string line;
    int i = 1;

    while (getline(inputFile, line)) {
        stringstream ss;
        ss << "File_Bot/Bot" << i << ".txt"; // membuat nama file baru di dalam folder "Output"
        ofstream outputFile(ss.str().c_str()); // membuka file baru
        outputFile << line; // menuliskan baris ke dalam file baru
        outputFile.close(); // menutup file baru
        i++; // menambah indeks file
    }

    inputFile.close(); // menutup file input
    return 0;
}

