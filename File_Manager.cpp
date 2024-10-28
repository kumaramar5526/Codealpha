#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>   // Use this for _mkdir on Windows
#include <limits>

using namespace std;

void createDirectory(const string& dirPath) {
    // Attempt to create the directory using _mkdir
    if (_mkdir(dirPath.c_str()) == 0) { // 0 indicates success
        cout << "Directory created: " << dirPath << endl;
    } else {
        cout << "Directory could not be created or already exists: " << dirPath << endl;
    }
}

void copyFile(const string& sourcePath, const string& destPath) {
    ifstream src(sourcePath, ios::binary);
    ofstream dest(destPath, ios::binary);
    
    if (src && dest) {
        dest << src.rdbuf(); // Copy content
        cout << "File copied successfully to: " << destPath << endl;
    } else {
        cout << "Error copying file. Please check the paths." << endl;
    }
}

int main() {
    int choice;
    string dirPath, sourceFile, destFile;

    do {
        cout << "File Manager Options:" << endl;
        cout << "1. Create Directory" << endl;
        cout << "2. Copy File" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        while (!(cin >> choice)) { // Input validation for choice
            cout << "Invalid input. Please enter a number (1-3): ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        switch (choice) {
            case 1:
                cout << "Enter directory path to create: ";
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, dirPath);
                createDirectory(dirPath);
                break;
            case 2:
                cout << "Enter source file path: ";
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, sourceFile);
                cout << "Enter destination file path: ";
                getline(cin, destFile);
                copyFile(sourceFile, destFile);
                break;
            case 3:
                cout << "Exiting File Manager." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 3);

    return 0;
}
