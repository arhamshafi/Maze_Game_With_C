#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{

    int id;
    string name;

    // -------------------------
    // FILE SE DATA READ
    // -------------------------

    ifstream readFile("atd.txt");

    readFile >> id;
    readFile >> name;

    readFile.close();

    cout << "Old Data:\n";
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;

    // -------------------------
    // DATA CHANGE
    // -------------------------

    cout << "\nEnter new name: ";
    cin >> name;

    // -------------------------
    // UPDATED DATA FILE MEIN SAVE
    // -------------------------

    ofstream writeFile("atd.txt");

    writeFile << id << endl;
    writeFile << name << endl;

    writeFile.close();

    cout << "\nData updated successfully.\n";

    return 0;
}