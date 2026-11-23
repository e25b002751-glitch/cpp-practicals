#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>
using namespace std;

class Item {
public:
    int id;
    string name;
    int quantity;
    double price;
};

class InventoryManager {
private:
    vector<Item> items;
    const string filename = "inventory.csv";

    int findIndex(int id) {
        for (int i = 0; i < items.size(); i++) {
            if (items[i].id == id)
                return i;
        }
        return -1;
    }

    void saveToFile() {
        ofstream file(filename);

        if (!file) {
            cout << "Error saving inventory!\n";
            return;
        }

        for (const Item &item : items) {
            file << item.id << ","
                 << item.name << ","
                 << item.quantity << ","
                 << item.price << "\n";
        }

        file.close();
        cout << "Inventory saved successfully!\n";
    }

    void loadFromFile() {
        ifstream file(filename);
        items.clear();

        if (!file) {
            cout << "No previous inventory found. Starting fresh.\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Item item;
            string id, quantity, price;

            if (getline(ss, id, ',') &&
                getline(ss, item.name, ',') &&
                getline(ss, quantity, ',') &&
                getline(ss, price, ',')) {

                try {
                    item.id = stoi(id);
                    item.quantity = stoi(quantity);
                    item.price = stod(price);

                    if (item.id > 0 && item.quantity >= 0 && item.price >= 0
                        && findIndex(item.id) == -1) {
                        items.push_back(item);
                    }
                }
                catch (...) {
                    // Ignore invalid records
                }
            }
        }

        file.close();
        cout << "Inventory loaded successfully!\n";
    }

    void addItem() {
        Item item;

        cout << "Enter Item ID: ";
        cin >> item.id;

        if (item.id <= 0 || findIndex(item.id) != -1) {
            cout << "Invalid or duplicate Item ID!\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Item Name: ";
        getline(cin, item.name);

        if (item.name.empty() || item.name.find(',') != string::npos) {
            cout << "Invalid item name!\n";
            return;
        }

        cout << "Enter Quantity: ";
        cin >> item.quantity;

        cout << "Enter Price: ";
        cin >> item.price;

        if (cin.fail() || item.quantity < 0 || item.price < 0) {
            cout << "Invalid quantity or price!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        items.push_back(item);
        saveToFile();
        cout << "Item added successfully!\n";
    }

    void searchItem() {
        int id;
        cout << "Enter Item ID to search: ";
        cin >> id;

        int index = findIndex(id);

        if (index == -1) {
            cout << "Item not found!\n";
            return;
        }

        displayItem(items[index]);
    }

    void displayItem(const Item &item) {
        cout << "\nItem ID: " << item.id
             << "\nName: " << item.name
             << "\nQuantity: " << item.quantity
             << "\nPrice: Rs. " << fixed << setprecision(2) << item.price
             << "\n";
    }

    void displayAll() {
        if (items.empty()) {
            cout << "Inventory is empty!\n";
            return;
        }

        cout << "\n========== INVENTORY ==========\n";
        cout << left << setw(10) << "ID"
             << setw(25) << "Name"
             << setw(12) << "Quantity"
             << setw(12) << "Price" << "\n";

        for (const Item &item : items) {
            cout << left << setw(10) << item.id
                 << setw(25) << item.name
                 << setw(12) << item.quantity
                 << setw(12) << fixed << setprecision(2) << item.price
                 << "\n";
        }
    }

    void updateItem() {
        int id;
        cout << "Enter Item ID to update: ";
        cin >> id;

        int index = findIndex(id);

        if (index == -1) {
            cout << "Item not found!\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string newName;
        int newQuantity;
        double newPrice;

        cout << "Enter New Name: ";
        getline(cin, newName);

        cout << "Enter New Quantity: ";
        cin >> newQuantity;

        cout << "Enter New Price: ";
        cin >> newPrice;

        if (cin.fail() || newName.empty() ||
            newName.find(',') != string::npos ||
            newQuantity < 0 || newPrice < 0) {
            cout << "Invalid input! Update cancelled.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        items[index].name = newName;
        items[index].quantity = newQuantity;
        items[index].price = newPrice;

        saveToFile();
        cout << "Item updated successfully!\n";
    }

    void stockIn() {
        int id, amount;

        cout << "Enter Item ID: ";
        cin >> id;

        int index = findIndex(id);

        if (index == -1) {
            cout << "Item not found!\n";
            return;
        }

        cout << "Enter quantity to add: ";
        cin >> amount;

        if (cin.fail() || amount <= 0) {
            cout << "Invalid stock quantity!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        items[index].quantity += amount;
        saveToFile();
        cout << "Stock added successfully!\n";
    }

    void stockOut() {
        int id, amount;

        cout << "Enter Item ID: ";
        cin >> id;

        int index = findIndex(id);

        if (index == -1) {
            cout << "Item not found!\n";
            return;
        }

        cout << "Available Stock: " << items[index].quantity << "\n";
        cout << "Enter quantity to remove: ";
        cin >> amount;

        if (cin.fail() || amount <= 0) {
            cout << "Invalid stock quantity!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        if (amount > items[index].quantity) {
            cout << "Insufficient stock! Operation cancelled.\n";
            return;
        }

        items[index].quantity -= amount;
        saveToFile();
        cout << "Stock removed successfully!\n";
    }

public:
    InventoryManager() {
        loadFromFile();
    }

    void menu() {
        int choice;

        do {
            cout << "\n====== INVENTORY MANAGER ======\n";
            cout << "1. Add Item\n";
            cout << "2. Search Item\n";
            cout << "3. Update Item\n";
            cout << "4. Stock In\n";
            cout << "5. Stock Out\n";
            cout << "6. Display All Items\n";
            cout << "7. Save Inventory\n";
            cout << "8. Exit\n";
            cout << "Enter Choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addItem(); break;
                case 2: searchItem(); break;
                case 3: updateItem(); break;
                case 4: stockIn(); break;
                case 5: stockOut(); break;
                case 6: displayAll(); break;
                case 7: saveToFile(); break;
                case 8:
                    saveToFile();
                    cout << "Exiting Inventory Manager...\n";
                    break;
                default:
                    cout << "Invalid choice! Try again.\n";
            }

        } while (choice != 8);
    }
};

int main() {
    InventoryManager inventory;
    inventory.menu();
    return 0;
}
