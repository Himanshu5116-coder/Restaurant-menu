#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct MenuItem {
    int id;
    string itemName;
    string itemCategory;
    float cost;
    bool inStock;
    vector<string> labels;
};

struct OrderItem {
    int menuId;
    int qty;
    string customerNote;
};

struct Order {
    int id;
    vector<OrderItem> orderedItems;
    string currentStatus;
    time_t timePlaced;
};

vector<MenuItem> menuList;
vector<Order> orderList;

int menuIdCounter = 100;
int orderIdCounter = 500;

string getTimeNow() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}

void createMenuItem() {
    MenuItem m;
    m.id = menuIdCounter++;
    cout << "Item Name: ";
    cin.ignore();
    getline(cin, m.itemName);
    cout << "Category: ";
    getline(cin, m.itemCategory);
    cout << "Price: ";
    cin >> m.cost;
    cout << "Available (1 = yes, 0 = no): ";
    cin >> m.inStock;
    
    menuList.push_back(m);
    cout << "New item added to menu.\n";
}

void showMenu() {
    cout << "\n------ MENU ------\n";
    for (auto &it : menuList) {
        cout << "ID: " << it.id << " | Name: " << it.itemName
             << " | ₹" << it.cost
             << " | In Stock: " << (it.inStock ? "Yes" : "No") << endl;
    }
}

void takeOrder() {
    Order o;
    o.id = orderIdCounter++;
    o.currentStatus = "Received";
    o.timePlaced = time(0);
    
    int count;
    cout << "How many different items? ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        OrderItem oi;
        cout << "Enter Menu ID: ";
        cin >> oi.menuId;
        cout << "Qty: ";
        cin >> oi.qty;
        cout << "Note (optional): ";
        cin.ignore();
        getline(cin, oi.customerNote);
        o.orderedItems.push_back(oi);
    }

    orderList.push_back(o);
    cout << "Order saved! Order ID: " << o.id << "\n";
}

void findOrder() {
    int lookId;
    cout << "Enter Order ID to check: ";
    cin >> lookId;

    bool found = false;
    for (auto &ord : orderList) {
        if (ord.id == lookId) {
            found = true;
            cout << "Order Status: " << ord.currentStatus << endl;
            cout << "Ordered At: " << ctime(&ord.timePlaced);
        }
    }

    if (!found)
        cout << "No order found with that ID.\n";
}

int main() {
    int option;

    while (true) {
        cout << "\nMenu:\n1. Add Menu Item\n2. Show Menu\n3. New Order\n4. Check Order\n5. Exit\nChoose: ";
        cin >> option;

        if (option == 1) createMenuItem();
        else if (option == 2) showMenu();
        else if (option == 3) takeOrder();
        else if (option == 4) findOrder();
        else if (option == 5) break;
        else cout << "Wrong input. Try again.\n";
    }

    return 0;
}