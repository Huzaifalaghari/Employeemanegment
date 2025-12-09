#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "Testing file access...\n";
    
    ifstream file("login.txt");
    if (!file) {
        cout << "ERROR: Cannot open login.txt!\n";
        cout << "Current directory: ";
        system("cd");
        return 1;
    }
    
    string line;
    cout << "File contents:\n";
    while (getline(file, line)) {
        cout << "Line: '" << line << "'\n";
    }
    file.close();
    
    return 0;
}