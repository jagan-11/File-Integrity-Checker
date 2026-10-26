#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

string readFile(const string& filename, bool& success) {
    ifstream file(filename.c_str(), ios::binary);
    string content;

    if (!file) {
        success = false;
        return "";
    }

    char ch;
    while (file.get(ch)) {
        content += ch;
    }

    success = file.eof();
    file.close();
    return content;
}

bool saveFile(const string& filename, const string& content) {
    ofstream file(filename.c_str(), ios::binary);

    if (!file) {
        return false;
    }

    file << content;
    file.close();
    return !file.fail();
}

void showContent(const string& title, const string& content) {
    cout << "\n--- " << title << " ---\n";

    if (content.empty()) {
        cout << "[Empty file]\n";
    } else {
        cout << content << "\n";
    }
}

int main() {
    int choice;
    string filename;
    const string baselineName = "baseline.txt";

    do {
        cout << "\n=================================\n";
        cout << "     FILE INTEGRITY CHECKER\n";
        cout << "=================================\n";
        cout << "1. Create or Update Baseline\n";
        cout << "2. Check File Integrity\n";
        cout << "3. View Current File\n";
        cout << "4. View Saved Baseline\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        if (choice >= 1 && choice <= 4) {
            cout << "Enter file name: ";
            cin >> filename;

            bool success = false;
            string current = readFile(filename, success);

            if (!success) {
                cout << "ERROR: Could not read the file.\n";
                continue;
            }

            if (choice == 1) {
                if (saveFile(baselineName, current)) {
                    cout << "Baseline saved successfully.\n";
                } else {
                    cout << "ERROR: Could not save the baseline.\n";
                }
            } else if (choice == 2) {
                bool baselineOK = false;
                string original = readFile(baselineName, baselineOK);

                if (!baselineOK) {
                    cout << "ERROR: Create a baseline first.\n";
                } else {
                    showContent("CURRENT FILE", current);

                    if (current == original) {
                        cout << "\nSTATUS: FILE IS SAFE\n";
                        cout << "No content changes detected.\n";
                    } else {
                        cout << "\nSTATUS: FILE MODIFIED!\n";
                        cout << "Current content differs from baseline.\n";
                        showContent("SAVED BASELINE", original);
                    }
                }
            } else if (choice == 3) {
                showContent("CURRENT FILE", current);
            } else if (choice == 4) {
                bool baselineOK = false;
                string original = readFile(baselineName, baselineOK);

                if (baselineOK) {
                    showContent("SAVED BASELINE", original);
                } else {
                    cout << "ERROR: No baseline found. Create one first.\n";
                }
            }
        } else if (choice == 5) {
            cout << "Thank you for using File Integrity Checker!\n";
        } else {
            cout << "Invalid choice. Select 1 to 5.\n";
        }

    } while (choice != 5);

    return 0;
}
