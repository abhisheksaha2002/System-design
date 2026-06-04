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

    // 1. ShoppingCart: Only responsible for Cart related business logic.
    double calculateTotal() {
        double total = 0;
        for (auto p=0;p<products.size();p++) {
            total += products[p].price;
        }
        return total;
         cout << "Total: Rs " << calculateTotal() << endl;
    }
};
class ShoppingCartPrinter{
private:
ShoppingCart cart;

public:
    // 2. ShoppingCartPrinter: Only responsible for printing invoices
    void printInvoice(ShoppingCart cart) {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : cart.getProducts()) {
            cout << p.name << " - Rs " << p.price << endl;
        }
       
    }

};
class ShoppingCartStorage{
private:
ShoppingCart cart;
public:
   
// 3. ShoppingCartStorage: Only responsible for saving cart to DB
    void saveToDatabase(ShoppingCart cart) {
        cout << "Saving shopping cart to database..." << endl;
    }
};


int main() {
    ShoppingCart cart;
    ShoppingCartPrinter print;
    ShoppingCartStorage storage;
    cart.addProduct(Product("Laptop", 50000));
    cart.addProduct(Product("Mouse", 2000));

    print.printInvoice(cart);  
    storage.saveToDatabase(cart);

    return 0;
}