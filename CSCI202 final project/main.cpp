/* Program name: rms.cpp
*  Author: Ronit Patel
*  Date last updated: 5/6/2024
* Purpose: Opens A restaurent managemnt system.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_RESERVATIONS = 50;
const int MAX_TABLES = 20;
const int MAX_ORDERS = 50;
const double TAX_RATE = 0.10;
const double TIP_RATE = 0.20;

enum MenuItem {
    Panner_Burger = 1,
    Chips_Salsa,
    Fried_Chicken_Sliders,
    Hamburger_Sliders,
    Veggie_Sliders,
    Haddock_Sandwich,
    BLT,
    Butter_Chicken,
    Chicken_Burrito,
    Falafel_Wrap,
    Cheese_Pizza,
    Pepperoni_Pizza,
    Bean_Burrito,
    Fish_and_chips
};


string menuItemToString(MenuItem item) {
    switch (item) {
        case Panner_Burger:
            return "Panner Burger";
        case Chips_Salsa:
            return "Chips_Salsa";
        case Fried_Chicken_Sliders:
            return "Fried Chicken Sliders";
        case Hamburger_Sliders:
            return "Hamburger Sliders";
        case Veggie_Sliders:
            return "Veggie Sliders";
        case Haddock_Sandwich:
            return "Haddock Sandwich";
        case BLT:
            return "BLT";
        case Butter_Chicken:
            return "Butter Chicken";
        case Chicken_Burrito:
            return "Chicken Burrito";
        case Falafel_Wrap:
            return "Falafel Wrap";
        case Cheese_Pizza:
            return "Cheese Pizza";
        case Pepperoni_Pizza:
            return "Pepperoni Pizza";
        case Bean_Burrito:
            return "Bean Wrap";
        case Fish_and_chips:
            return "Fish and Chips";
        default:
            return "Unknown Item";
    }
}

struct Reservation {
    string name;
    int partySize{};
    string time;
    bool checkedIn{};
};

struct Table {
    int tableNumber;
    int capacity;
    int currentOccupancy;
    bool occupied;
};

struct Order {
    Reservation reservation;
    MenuItem itemsOrdered[10]{};
    int numItems{};
    bool completed{};
    bool paid{};
    int tableNumber{};
};

Reservation reservations[MAX_RESERVATIONS];
Table tables[MAX_TABLES];
Order orders[MAX_ORDERS];
int numReservations = 0;
int numTables = 0;
int numOrders = 0;

bool hasPendingReservations() {
    for (int i = 0; i < numReservations; ++i) {
        if (!reservations[i].checkedIn) {
            return true;
        }
    }
    return false;
}

bool hasOutstandingOrders() {
    for (int i = 0; i < numOrders; ++i) {
        if (!orders[i].completed || !orders[i].paid) {
            return true;
        }
    }
    return false;
}

bool allTablesEmpty() {
    for (int i = 0; i < numTables; ++i) {
        if (tables[i].occupied) {
            return false; // If any table is occupied, return false
        }
    }
    return true; // If all tables are empty, return true
}

void makeReservation() {
    cout << "-----*---------------*--------------*--------------*-------------*--------------*-----" << endl;
    if (numReservations >= MAX_RESERVATIONS) {
        cout << "Cannot make more reservations. Maximum capacity reached." << endl;
        return;
    }

    string name;
    int partySize;
    string time;
    char choice;

    do {
        cout << "Enter a name for the reservation: ";
        getline(cin, name);
        cout << "Enter the number of people in the party: ";
        while (true) {
            cin >> partySize;
            cin.ignore(); // Clear input buffer

            // Check if the number of people exceeds 10 or is less than or equal to 0
            if (partySize > 10 || partySize <= 0) {
                cout << "Warning: Parties must have 1 to 10 people. Please enter a valid number." << endl;
            } else {
                break;
            }
        }
        cout << "Enter the time for the reservation in HH::MM AM/PM: ";
        getline(cin, time);

        // Display the entered information for confirmation
        cout << "Reservation Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Party Size: " << partySize << endl;
        cout << "Time: " << time << endl;

        // Prompt for confirmation
        cout << "Is this information correct [Y]es, [N]o (make changes), [C]ancel? ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 'Y':
            case 'y':
                // Information confirmed, proceed with reservation
                reservations[numReservations].name = name;
                reservations[numReservations].partySize = partySize;
                reservations[numReservations].time = time;
                reservations[numReservations].checkedIn = false;
                numReservations++;
                cout << "Reservation successfully made." << endl;
                break;
            case 'N':
            case 'n':
                // User wants to make changes
                int changeOption;
                do {
                    cout << "What do you want to change?" << endl;
                    cout << "1. Name" << endl;
                    cout << "2. Number of People" << endl;
                    cout << "3. Time" << endl;
                    cout << "4. Cancel" << endl;
                    cout << "Enter your choice: ";
                    cin >> changeOption;
                    cin.ignore(); // Clear input buffer

                    switch (changeOption) {
                        case 1:
                            cout << "Enter new name: ";
                            getline(cin, name);
                            break;
                        case 2:
                            cout << "Enter the number of people in the party: ";
                            while (true) {
                                cin >> partySize;
                                cin.ignore(); // Clear input buffer

                                // Check if the number of people exceeds 10 or is less than or equal to 0
                                if (partySize > 10 || partySize <= 0) {
                                    cout << "Warning: Parties must have 1 to 10 people. Please enter a valid number." << endl;
                                } else {
                                    break;
                                }
                            }
                            break;
                        case 3:
                            cout << "Enter new time: ";
                            getline(cin, time);
                            break;
                        case 4:
                            cout << "Reservation canceled." << endl;
                            return;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                    }

                    // Display updated information for confirmation
                    cout << "Updated Reservation Details:" << endl;
                    cout << "Name: " << name << endl;
                    cout << "Party Size: " << partySize << endl;
                    cout << "Time: " << time << endl;

                    // Prompt for confirmation again
                    cout << "Is this information correct [Y]es, [N]o (make changes), [C]ancel? ";
                    cin >> choice;
                    cin.ignore(); // Clear input buffer

                } while (choice == 'N' || choice == 'n');
                break;
            case 'C':
            case 'c':
                // User cancels the reservation
                cout << "Reservation canceled." << endl;
                break;
            default:
                cout << "Invalid choice. Reservation canceled." << endl;
        }
    } while (choice == 'N' || choice == 'n');
}

void checkInReservation() {
    cout << "-----*---------------*--------------*--------------*-------------*--------------*-----" << endl;

    // Check if there are any reservations available
    bool foundReservation = false;
    for (int i = 0; i < numReservations; ++i) {
        if (!reservations[i].checkedIn) {
            foundReservation = true;
            break;
        }
    }

    if (!foundReservation) {
        cout << "No reservations available to check in. Please make a reservation first." << endl;
        return;
    }

    cout << "Choose the reservation to check in" << endl;
    for (int i = 0; i < numReservations; ++i) {
        if (!reservations[i].checkedIn) {
            cout << i+1 << ": " << reservations[i].name << " - " << reservations[i].time << ", " << reservations[i].partySize << " people" << endl;
        }
    }
    int choice;
    cin >> choice;
    choice--; // Adjust for 0-based indexing

    // Display available tables based on party size
    cout << "Please assign a table:" << endl;
    bool tableFound = false;
    for (int i = 0; i < numTables; ++i) {
        if (!tables[i].occupied && tables[i].capacity >= reservations[choice].partySize) {
            cout << tables[i].tableNumber << ": " << tables[i].capacity << " people" << endl;
            tableFound = true;
        }
    }

    if (!tableFound) {
        cout << "There are no open tables that will fit the party. Please complete some orders and have the customers pay their bills to free up tables." << endl;
        // Loop back to the main menu
        return;
    }

    int tableChoice;
    cin >> tableChoice;
    tableChoice--; // Adjust for 0-based indexing


    tables[tableChoice].occupied = true;
    tables[tableChoice].currentOccupancy = reservations[choice].partySize; // Update current occupancy
    reservations[choice].checkedIn = true;
}

void enterOrder() {
    cout << "-----*---------------*--------------*--------------*-------------*--------------*-----" << endl;

    cout << "Please choose the table for the order:" << endl;
    bool validTableFound = false;
    for (int i = 0; i < numTables; ++i) {
        if (tables[i].occupied && tables[i].currentOccupancy > 0) {
            cout << i + 1 << ": Table " << tables[i].tableNumber << " (" << tables[i].currentOccupancy << " people)" << endl;
            validTableFound = true;
        }
    }
    if (!validTableFound) {
        cout << "No available table for the party size." << endl;
        return;
    }

    int tableChoice;
    cin >> tableChoice;
    cin.ignore();
    tableChoice--; // Adjust for 0-based indexing

    // Find the index of the selected table
    int tableIndex = -1;
    for (int i = 0; i < numTables; ++i) {
        if (tables[i].occupied && tables[i].tableNumber == tableChoice + 1) {
            tableIndex = i;
            break;
        }
    }

    if (tableIndex == -1) {
        cout << "Invalid table selection." << endl;
        return;
    }

    // Check if there's already an incomplete order for this table
    for (int i = 0; i < numOrders; ++i) {
        if (orders[i].tableNumber == tableChoice + 1 && !orders[i].completed) {
            cout << "There is already an incomplete order for this table." << endl;
            return;
        }
    }

    orders[numOrders].reservation = reservations[numReservations - 1];
    cout << "Please choose entree numbers (up to " << tables[tableIndex].currentOccupancy << " items, 1 per person):" << endl;
    for (int i = 0; i < tables[tableIndex].currentOccupancy; ++i) {
        cout << "For person " << i + 1 << ":" << endl;
        for (int j = 0; j < 14; ++j) {
            cout << j + 1 << ": " << menuItemToString(static_cast<MenuItem>(j + 1)) << endl;
        }
        int choice;
        cout << "Input: ";
        cin >> choice;
        orders[numOrders].itemsOrdered[i] = static_cast<MenuItem>(choice);
    }

    orders[numOrders].numItems = tables[tableIndex].currentOccupancy;
    orders[numOrders].completed = false;
    orders[numOrders].paid = false;
    orders[numOrders].tableNumber = ++tableChoice;
    numOrders++;

    cout << "Welcome to Messijoes" << endl;
}

void completeOrder() {
    cout << "-----*---------------*--------------*--------------*-------------*--------------*-----" << endl;

    bool presentOrdersExist = false;
    for (int i = 0; i < numOrders; ++i) {
        if (!orders[i].completed && !orders[i].paid) {
            presentOrdersExist = true;
            break;
        }
    }
    if (!presentOrdersExist) {
        cout << "There are no present orders to complete." << endl;
        return;
    }
    cout << "Choose the order to complete:" << endl;
    for (int i = 0; i < numOrders; ++i) {
        if (!orders[i].completed && !orders[i].paid) {
            cout << i + 1 << ": Table no " << orders[i].tableNumber << endl;
        }
    }
    int choice;
    cin >> choice;
    choice--; // Adjust for 0-based indexing
    orders[choice].completed = true;

}

void calculateAndPayBill() {
    cout << "-----*---------------*--------------*--------------*-------------*--------------*-----" << endl;

    bool ordersReadyForPayment = false;
    for (int i = 0; i < numOrders; ++i) {
        if (orders[i].completed && !orders[i].paid) {
            ordersReadyForPayment = true;
            break;
        }
    }
    if (!ordersReadyForPayment) {
        cout << "There are no orders ready for payment." << endl;
        return;
    }
    cout << "Choose the order to calculate the bill:" << endl;
    for (int i = 0; i < numOrders; ++i) {
        if (orders[i].completed && !orders[i].paid) {
            cout << i+1 << ": Table " << orders[i].tableNumber << endl;
        }
    }
    int choice;
    cin >> choice;
    choice = choice - 1; // Adjust for 0-based indexing

    orders[choice].paid = true;
    // tables[choice].occupied = false; // Free the
    // Find the index of the table associated with the order
    int tableIndex = -1;
    for (int i = 0; i < numTables; ++i) {
        if (tables[i].tableNumber == orders[choice].tableNumber) {
            tableIndex = i;
            break;
        }
    }

    if (tableIndex != -1) {
        // Update the occupancy status of the table
        tables[tableIndex].occupied = false;
    } else {
        cerr << "Error: Could not find the associated table for the order." << endl;
    }

    double subtotal = 0;
    for (int i = 0; i < orders[choice].numItems; ++i) {
        switch(orders[choice].itemsOrdered[i]) {
            case Panner_Burger:
                subtotal += 35;
                break;
            case Chips_Salsa:
            case Fried_Chicken_Sliders:
            case Hamburger_Sliders:
            case Veggie_Sliders:
            case Haddock_Sandwich:
            case BLT:
            case Butter_Chicken:
            case Chicken_Burrito:
            case Falafel_Wrap:
                subtotal += 42;
                break;
            case Cheese_Pizza:
            case Pepperoni_Pizza:
                subtotal += 59;
                break;
            case Bean_Burrito:
            case Fish_and_chips:
                subtotal += 77;
                break;
            default:
                break;
        }
    }

    double tax = subtotal * 0.10;
    double totalWithoutTax = subtotal + tax;
    double tip = totalWithoutTax * 0.20;
    double total = totalWithoutTax + tip;

    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Tax (10%): $" << tax << endl;
    cout << "Total (with tax): $" << totalWithoutTax << endl;
    cout << "Tip (20% on subtotal without tax): $" << tip << endl;
    cout << "Total (with tax and tip): $" << total << endl;


}

int main() {
    // Initialize tables
    tables[0] = {1, 2, 0, false};
    tables[1] = {2, 2, 0, false};
    tables[2] = {3, 2, 0, false};
    tables[3] = {4, 2, 0, false};
    tables[4] = {5, 2, 0, false};
    tables[5] = {6, 2, 0, false};
    tables[6] = {7, 2, 0, false};
    tables[7] = {8, 2, 0, false};
    tables[8] = {9, 10, 0, false};
    tables[9] = {10, 10, 0, false};
    tables[10] = {11, 4, 0, false};
    tables[11] = {12, 4, 0, false};
    tables[12] = {13, 4, 0, false};
    tables[13] = {14, 4, 0, false};
    tables[14] = {15, 4, 0, false};
    tables[15] = {16, 4, 0, false};
    tables[16] = {17, 6, 0, false};
    tables[17] = {18, 6, 0, false};
    tables[18] = {19, 6, 0, false};
    tables[19] = {20, 6, 0, false};

    numTables = 20; // Update the number of tables

    bool done = false;
    while (!done) {
        cout << "-----*---------------*--------------*--------------*-------------*--------------*-----" << endl;

        cout << "1. Make reservation" << endl;
        cout << "2. Check in reservation" << endl;
        cout << "3. Enter order" << endl;
        cout << "4. Complete order" << endl;
        cout << "5. Calculate and pay bill" << endl;
        if (!hasPendingReservations() && !hasOutstandingOrders() && allTablesEmpty()) {
            cout << "6. Exit" << endl; // Modified option

        }
        cout << "Choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Clear input buffer
        switch (choice) {
            case 1:
                makeReservation();
                break;
            case 2:
                checkInReservation();
                break;
            case 3:
                enterOrder();
                break;
            case 4:
                completeOrder();
                break;
            case 5:
                calculateAndPayBill();
                break;
            case 6:
                done = true;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

