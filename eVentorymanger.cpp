/* eVentorymanger.cpp
 * Ronit Patel
 * 4/3/24
 * Helps with kepping track on which devices does company has.
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

class PersonalComputer {
private:
    string manufacturer;
    string formFactor;
    string serialNumber;
    string processor;
    int ram;
    string storageType;
    int storageSize;

public:
    PersonalComputer(const string& manufacturer, const string& formFactor,
                     const string& serialNumber, const string& processor,
                     int ram, const string& storageType, int storageSize)
            : manufacturer(manufacturer), formFactor(formFactor),
              serialNumber(serialNumber), processor(processor),
              ram(ram), storageType(storageType), storageSize(storageSize) {
        // Validate input values
        if (ram != 4 && ram != 6 && ram != 8 && ram != 16 && ram != 32 && ram != 64) {
            throw invalid_argument("Invalid RAM size.");
        }
        if (storageSize != 128 && storageSize != 256 && storageSize != 512 &&
            storageSize != 1024 && storageSize != 2048) {
            throw invalid_argument("Invalid storage size.");
        }
    }

    // Accessor methods
    string getManufacturer() const {
        return manufacturer;
    }

    string getFormFactor() const {
        return formFactor;
    }

    string getSerialNumber() const {
        return serialNumber;
    }

    string getProcessor() const {
        return processor;
    }

    int getRAM() const {
        return ram;
    }

    string getStorageType() const {
        return storageType;
    }

    int getStorageSize() const {
        return storageSize;
    }

    // Mutator methods
    void setRAM(int newRAM) {
        if (newRAM != 4 && newRAM != 6 && newRAM != 8 && newRAM != 16 && newRAM != 32 && newRAM != 64) {
            throw invalid_argument("Invalid RAM size.");
        }
        ram = newRAM;
    }

    void setStorage(const string& newStorageType, int newStorageSize) {
        if (newStorageSize != 128 && newStorageSize != 256 && newStorageSize != 512 &&
            newStorageSize != 1024 && newStorageSize != 2048) {
            throw invalid_argument("Invalid storage size.");
        }
        storageType = newStorageType;
        storageSize = newStorageSize;
    }

    // toString method
    string toString() const {
        ostringstream oss;
        oss << "Manufacturer: " << manufacturer << "\n"
            << "Form Factor: " << formFactor << "\n"
            << "Serial Number: " << serialNumber << "\n"
            << "Processor: " << processor << "\n"
            << "RAM: " << ram << "GB\n"
            << "Storage Type: " << storageType << "\n"
            << "Storage Size: " << storageSize << "GB\n";
        return oss.str();
    }
};

int main() {
    vector<PersonalComputer> inventory;
    char choice = 'y';

    while (tolower(choice) == 'y') {
        string manufacturer, formFactor, serialNumber, processor, storageType;
        int ram, storageSize;

        cout << "Enter Manufacturer: ";
        cin >> manufacturer;
        cout << "Enter Form Factor (laptop/desktop): ";
        cin >> formFactor;
        cout << "Enter Serial Number: ";
        cin >> serialNumber;
        cout << "Enter Processor: ";
        cin >> processor;
        cout << "Enter RAM (4, 6, 8, 16, 32, 64): ";
        cin >> ram;
        cout << "Enter Storage Type (UFS, SDD, HDD): ";
        cin >> storageType;
        cout << "Enter Storage Size (128, 256, 512, 1024, 2048): ";
        cin >> storageSize;

        try {
            PersonalComputer pc(manufacturer, formFactor, serialNumber, processor, ram, storageType, storageSize);
            inventory.push_back(pc);
            cout << "Added computer to inventory:\n" << pc.toString();
            cout << "Total computers in inventory: " << inventory.size() << "\n";

            cout << "Add another computer? (y/n): ";
            cin >> choice;
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << "\n";
            cout << "Try again? (y/n): ";
            cin >> choice;
        }
    }

    cout << "\nInventory List:\n";
    for (const auto& pc : inventory) {
        cout << pc.toString() << "\n";
    }

    return 0;
}
