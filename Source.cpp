#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

            // Class to track item frequencies
class ItemTracker {
private:
    // Map to store item names 
    map<string, int> frequencyMap;

public:
    // Loads item data from a file and counts occurrences
    void LoadData(const string& filename) {
        ifstream file(filename);
        string item;
        if (!file) {
            cout << "Error: Cannot open input file.\n";
            return;
        }
        while (file >> item) {
            frequencyMap[item]++;
        }
        file.close();
    }

    // Saves item frequencies to a file (backup)
    void SaveData(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cout << "Error: Cannot open output file.\n";
            return;
        }
        for (const auto& pair : frequencyMap) {
            file << pair.first << " " << pair.second << endl;
        }
        file.close();
    }

    // Prints each item and how many times it was purchased
    void PrintFrequencies() const {
        for (const auto& pair : frequencyMap) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Prints a histogram using asterisks to show item frequency
    void PrintHistogram() const {
        for (const auto& pair : frequencyMap) {
            cout << setw(12) << left << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) cout << "*";
            cout << endl;
        }
    }

    // Searches for a specific item and prints how many times it was purchased
    void SearchItem(const string& item) const {
        auto it = frequencyMap.find(item);
        if (it != frequencyMap.end()) {
            cout << item << " was purchased " << it->second << " times.\n";
        }
        else {
            cout << item << " was not found.\n";
        }
    }
};

// Prints the user menu
void PrintMenu() {
    cout << "\n===== Corner Grocer Menu =====\n";
    cout << "1. Search for item frequency\n";
    cout << "2. Display all item frequencies\n";
    cout << "3. Display histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Main function to run the program
int main() {
    ItemTracker tracker;

    // Load item data from file and save it to backup file
    tracker.LoadData("CS210_Project_Three_Input_File.txt");
    tracker.SaveData("frequency.dat");

    int choice = 0;
    string userItem;

    // Menu loop
    while (choice != 4) {
        PrintMenu();
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard bad input
            cout << "Invalid input. Try again.\n";
            continue;
        }

        // Respond to user menu choice
        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            cin >> userItem;
            tracker.SearchItem(userItem);
            break;
        case 2:
            tracker.PrintFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
