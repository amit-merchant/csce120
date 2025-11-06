#include <iostream>
#include <string>
#include <stdexcept>

struct InventoryItem {
    std::string itemName;
    int quantity;

    InventoryItem() : itemName(""), quantity(0) {}
    InventoryItem(const std::string& name, int qty) : itemName(name), quantity(qty) {}
};

class Inventory {
private:
    InventoryItem* items;
    int size;

public:
    // Constructor
    Inventory(int s) : size(s) {
        items = new InventoryItem[size];
        std::cout << "Constructor: Created inventory with " << size << " items\n";
    }

    // Destructor (Rule of 3 - part 1)
    ~Inventory() {
        delete[] items;
        std::cout << "Destructor: Freed inventory memory\n";
    }

    // Copy Constructor (Rule of 3 - part 2)
    Inventory(const Inventory& other) : size(other.size) {
        items = new InventoryItem[size];
        for (int i = 0; i < size; i++) {
            items[i] = other.items[i];
        }
        std::cout << "Copy Constructor: Created copy of inventory\n";
    }

    // Copy Assignment Operator (Rule of 3 - part 3)
    Inventory& operator=(const Inventory& other) {
        if (this != &other) {
            delete[] items;
            size = other.size;
            items = new InventoryItem[size];
            for (int i = 0; i < size; i++) {
                items[i] = other.items[i];
            }
            std::cout << "Copy Assignment: Assigned copy of inventory\n";
        }
        return *this;
    }

    // Set inventory item
    void setItem(int index, const std::string& name, int qty) {
        if (index >= 0 && index < size) {
            items[index].itemName = name;
            items[index].quantity = qty;
        }
    }

    // Get inventory item
    InventoryItem getItem(int index) const {
        if (index >= 0 && index < size) {
            return items[index];
        }
        return InventoryItem();
    }

    // Find item by name and return index, or -1 if not found
    int findItem(const std::string& name) const {
        for (int i = 0; i < size; i++) {
            if (items[i].itemName == name) {
                return i;
            }
        }
        return -1;
    }

    // Process new order - reduces inventory by order quantities
    void newOrder(const InventoryItem* orderItems, int orderSize) {
        // First, check if all items in the order exist in inventory
        for (int i = 0; i < orderSize; i++) {
            int index = findItem(orderItems[i].itemName);
            if (index == -1) {
                throw std::runtime_error("Order cannot be completed: Item '" + 
                                       orderItems[i].itemName + "' not found in inventory");
            }
            // Check if sufficient quantity is available
            if (items[index].quantity < orderItems[i].quantity) {
                throw std::runtime_error("Order cannot be completed: Insufficient quantity for '" + 
                                       orderItems[i].itemName + "'. Available: " + 
                                       std::to_string(items[index].quantity) + 
                                       ", Requested: " + std::to_string(orderItems[i].quantity));
            }
        }

        // If all items are found and quantities are sufficient, process the order
        std::cout << "Processing order...\n";
        for (int i = 0; i < orderSize; i++) {
            int index = findItem(orderItems[i].itemName);
            items[index].quantity -= orderItems[i].quantity;
            std::cout << "  Reduced " << orderItems[i].itemName << " by " 
                      << orderItems[i].quantity << ". Remaining: " 
                      << items[index].quantity << "\n";
        }
        std::cout << "Order completed successfully!\n";
    }

    // Print inventory
    void printInventory() const {
        std::cout << "Current Inventory:\n";
        for (int i = 0; i < size; i++) {
            std::cout << "  " << items[i].itemName << ": " << items[i].quantity << "\n";
        }
    }
};

int main() {
    std::cout << "=== Creating inventory1 ===\n";
    Inventory inventory1(4);
    inventory1.setItem(0, "Apples", 50);
    inventory1.setItem(1, "Bananas", 30);
    inventory1.setItem(2, "Oranges", 40);
    inventory1.setItem(3, "Grapes", 25);
    inventory1.printInventory();

    std::cout << "\n=== Copy Constructor (inventory2 = inventory1) ===\n";
    Inventory inventory2 = inventory1;
    inventory2.printInventory();

    std::cout << "\n=== Processing valid order ===\n";
    InventoryItem order1[] = {
        InventoryItem("Apples", 10),
        InventoryItem("Bananas", 5)
    };
    try {
        inventory1.newOrder(order1, 2);
        inventory1.printInventory();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    std::cout << "\n=== Processing order with missing item ===\n";
    InventoryItem order2[] = {
        InventoryItem("Apples", 5),
        InventoryItem("Pears", 10)  // Pears not in inventory
    };
    try {
        inventory1.newOrder(order2, 2);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    std::cout << "\n=== Processing order with insufficient quantity ===\n";
    InventoryItem order3[] = {
        InventoryItem("Oranges", 50)  // Only 40 available
    };
    try {
        inventory1.newOrder(order3, 1);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    std::cout << "\n=== inventory2 (copy) should be unchanged ===\n";
    inventory2.printInventory();

    std::cout << "\n=== Copy Assignment (inventory3 = inventory1) ===\n";
    Inventory inventory3(2);
    inventory3 = inventory1;
    inventory3.printInventory();

    std::cout << "\n=== Exiting main, destructors will be called ===\n";
    return 0;
}
