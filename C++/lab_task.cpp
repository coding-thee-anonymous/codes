#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Enum to track which member of the union is active
enum StatusType {
    ROOM_NUMBER,
    IS_AVAILABLE
};

// Union to store either room number or availability status
union Status {
    int roomNumber;
    bool isAvailable;
};

// Component struct with union for status
struct Component {
    int id;
    char name[50];
    double powerConsumption;
    Status status;
    StatusType statusType;  // Track which member is active
};

// Global variables
Component inventory[10];
int componentCount = 0;
const char* FILENAME = "inventory.dat";

// Function prototypes
void addComponent();
void displayAllComponents();
void saveToFile();
void loadFromFile();
void displayMenu();
void searchById();
double calculateTotalPower();
bool isRoomOccupied(int roomNumber);
void displayAvailableRooms();

// Function to display menu
void displayMenu() {
    cout << "\nINVENTORY MANAGEMENT SYSTEM" << endl;
    cout << "1. Add a new component" << endl;
    cout << "2. Display all components" << endl;
    cout << "3. Search component by ID" << endl;
    cout << "4. Calculate total power consumption" << endl;
    cout << "5. Save inventory to file" << endl;
    cout << "6. Load inventory from file" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to check if a room is occupied
bool isRoomOccupied(int roomNumber) {
    Component* ptr = inventory;
    for (int i = 0; i < componentCount; i++, ptr++) {
        if (ptr->statusType == ROOM_NUMBER && ptr->status.roomNumber == roomNumber) {
            return true;
        }
    }
    return false;
}

// Function to display available rooms
void displayAvailableRooms() {
    cout << "\nAvailable rooms: ";
    bool foundAvailable = false;
    
    for (int room = 1; room <= 100; room++) {
        if (!isRoomOccupied(room)) {
            if (foundAvailable) {
                cout << ", ";
            }
            cout << room;
            foundAvailable = true;
            
            // Display first 10 available rooms
            if (room - 1 >= 10) {
                break;
            }
        }
    }
    cout << endl;
}

// Function to add a new component
void addComponent() {
    if (componentCount >= 10) {
        cout << "\nInventory is full! Cannot add more components." << endl;
        return;
    }

    cout << "\nAdd New Component" << endl;
    
    // Validate ID input - accept only integers
    bool validId = false;
    while (!validId) {
        cout << "Enter component ID: ";
        if (cin >> inventory[componentCount].id) {
            // Check if the input was successfully read as an integer
            validId = true;
        } else {
            // Clear the error flag and discard invalid input
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please check the ID again and use integers only." << endl;
        }
    }
    cin.ignore();  // Clear input buffer

    cout << "Enter component name: ";
    cin.getline(inventory[componentCount].name, 50);

    bool validPower = false;
    while (!validPower) {
        cout << "Enter power consumption (watts): ";
        if (cin >> inventory[componentCount].powerConsumption) {
            validPower = true;
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter an integer." << endl;
        }
    }

    bool validChoice = false;
    int choice = 0;
    while (!validChoice) {
        cout << "Select status type:\n1. Room Number\n2. Is Available\nEnter choice (1 or 2): ";
        if (cin >> choice) {
            validChoice = true;
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter an integer." << endl;
        }
    }

    if (choice == 1) {
        bool validRoom = false;
        while (!validRoom) {
            cout << "Enter room number: ";
            int roomNum;
            if (cin >> roomNum) {
                if (isRoomOccupied(roomNum)) {
                    cout << "Room occupied! ";
                    displayAvailableRooms();
                } else {
                    inventory[componentCount].status.roomNumber = roomNum;
                    inventory[componentCount].statusType = ROOM_NUMBER;
                    validRoom = true;
                }
            } else {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter an integer." << endl;
            }
        }
    } else if (choice == 2) {
        bool validAvail = false;
        int avail = 0;
        while (!validAvail) {
            cout << "Is component available? (1 for Yes, 0 for No): ";
            if (cin >> avail) {
                validAvail = true;
            } else {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter an integer." << endl;
            }
        }
        inventory[componentCount].status.isAvailable = (bool)avail;
        inventory[componentCount].statusType = IS_AVAILABLE;
    } else {
        cout << "Invalid choice! Setting as available by default." << endl;
        inventory[componentCount].status.isAvailable = true;
        inventory[componentCount].statusType = IS_AVAILABLE;
    }

    componentCount++;
    cout << "Component added successfully!" << endl;
}

// Function to display all components using pointer arithmetic
void displayAllComponents() {
    if (componentCount == 0) {
        cout << "\nNo components in inventory!" << endl;
        return;
    }

    cout << "\n" << setw(35) << right << "CURRENT INVENTORY" << endl;
    cout << left << setfill(' ') << setw(12) << "ID" 
         << setw(35) << "Name" 
         << setw(15) << "Power (W)" 
         << "Status" << endl;

    // Using pointer arithmetic to display all components
    Component* ptr = inventory;
    for (int i = 0; i < componentCount; i++, ptr++) {
        cout << left << setw(12) << ptr->id 
             << setw(35) << ptr->name 
             << setw(15) << fixed << setprecision(2) << ptr->powerConsumption
             << "";

        if (ptr->statusType == ROOM_NUMBER) {
            cout << "Room " << ptr->status.roomNumber << endl;
        } else {
            cout << (ptr->status.isAvailable ? "Available" : "Not Available") << endl;
        }
    }
}

// Function to search component by ID
void searchById() {
    if (componentCount == 0) {
        cout << "\nNo components in inventory!" << endl;
        return;
    }

    bool validSearch = false;
    int searchId = 0;
    while (!validSearch) {
        cout << "\nEnter component ID to search: ";
        if (cin >> searchId) {
            validSearch = true;
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter an integer." << endl;
        }
    }

    // Using pointer arithmetic to search
    Component* ptr = inventory;
    bool found = false;

    for (int i = 0; i < componentCount; i++, ptr++) {
        if (ptr->id == searchId) {
            cout << "\nComponent Found" << endl;
            cout << "ID: " << ptr->id << endl;
            cout << "Name: " << ptr->name << endl;
            cout << "Power Consumption: " << fixed << setprecision(2) 
                 << ptr->powerConsumption << " watts" << endl;

            if (ptr->statusType == ROOM_NUMBER) {
                cout << "Location: Room " << ptr->status.roomNumber << endl;
            } else {
                cout << "Available: " << (ptr->status.isAvailable ? "Yes" : "No") << endl;
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nComponent with ID " << searchId << " not found!" << endl;
    }
}

// Function to calculate total power consumption
double calculateTotalPower() {
    if (componentCount == 0) {
        cout << "\nNo components in inventory!" << endl;
        return 0.0;
    }

    double totalPower = 0.0;
    Component* ptr = inventory;

    // Using pointer arithmetic to calculate total power
    for (int i = 0; i < componentCount; i++, ptr++) {
        totalPower += ptr->powerConsumption;
    }

    cout << "\nTotal power consumption of all components: " 
         << fixed << setprecision(2) << totalPower << " watts" << endl;

    return totalPower;
}

// Function to save inventory to binary file
void saveToFile() {
    ofstream outFile(FILENAME, ios::binary);

    if (!outFile) {
        cout << "\nError: Could not open file for writing!" << endl;
        return;
    }

    // Write the number of components first
    outFile.write((char*)&componentCount, sizeof(componentCount));

    // Write all components using pointer arithmetic
    Component* ptr = inventory;
    for (int i = 0; i < componentCount; i++, ptr++) {
        outFile.write((char*)ptr, sizeof(Component));
    }

    outFile.close();
    cout << "\nInventory saved to file successfully!" << endl;
}

// Function to load inventory from binary file
void loadFromFile() {
    ifstream inFile(FILENAME, ios::binary);

    if (!inFile) {
        cout << "\nNo saved inventory file found. Starting with empty inventory." << endl;
        componentCount = 0;
        return;
    }

    // Read the number of components
    inFile.read((char*)&componentCount, sizeof(componentCount));

    // Read all components
    Component* ptr = inventory;
    for (int i = 0; i < componentCount; i++, ptr++) {
        inFile.read((char*)ptr, sizeof(Component));
    }

    inFile.close();
    cout << "\nInventory loaded successfully! (" << componentCount << " components found)" << endl;
}

// Main function
int main() {
    // Load inventory from file on startup
    loadFromFile();

    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        bool validChoice = false;
        while (!validChoice) {
            if (cin >> choice) {
                validChoice = true;
            } else {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter an integer." << endl;
                cout << "Enter your choice: ";
            }
        }

        switch (choice) {
            case 1:
                addComponent();
                break;
            case 2:
                displayAllComponents();
                break;
            case 3:
                searchById();
                break;
            case 4:
                calculateTotalPower();
                break;
            case 5:
                saveToFile();
                break;
            case 6:
                loadFromFile();
                break;
            case 7:
                cout << "\nExiting the application. Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    }

    return 0;
}
