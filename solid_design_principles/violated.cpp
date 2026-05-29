#include <iostream>
#include <vector>

using namespace std;

// Product class representing any item of any ECommerce.
class Product {
public:
    string name;
    double price;
 
    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};
//using "has-a"rule so inheritence applied here
// Violating SRP: ShoppingCart is handling multiple responsibilities
class ShoppingCart {
private:
    vector<Product> products; 

public:
    void addProduct(Product p) { 
        products.push_back(p);
    }

    vector<Product> getProducts() { 
        //products is a vector which will store both name and price
        return products;
    } 

    // 1. Calculates total price in cart.
    double calculateTotal() {
        double total = 0;
        for (auto p=0;p<products.size();p++) {
            total += products[p].price;
        }
        return total;
    }

    // 2. Violating SRP - Prints invoice (Should be in a separate class)
    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : products) {
            cout << p.name << " - Rs " << p.price << endl;
        }
        cout << "Total: Rs " << calculateTotal() << endl;
    }

    // 3. Violating SRP - Saves to DB (Should be in a separate class)
    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart cart;
    cart.addProduct(Product("Laptop", 50000));
    cart.addProduct(Product("Mouse", 2000));

    cart.printInvoice();  
    cart.saveToDatabase();

    return 0;
}