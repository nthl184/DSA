/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Lab3 - Homework - Exercise 1
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Product
{
    string name;
    string category;
    double price;
    string description;
};

class SearchEngine
{
private:
    vector<Product> products;
    string toLower(string str)
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
public:
    void addProduct(const Product& product)
    {
        products.push_back(product);
    }

    vector<Product> search(string& query, const string& category = "", double minPrice = 0.0, double maxPrice = 1e9)
    {
        vector<Product> results;
        query = toLower(query);
        for (const auto& product : products) {
            if ((toLower(product.name).find(query) != string::npos || toLower(product.description).find(query) != string::npos) &&
                (category.empty() || product.category == category) &&
                (product.price >= minPrice && product.price <= maxPrice))
            {
                results.push_back(product);
            }
        }
        return results;
    }

};

int main() {
    SearchEngine engine;
    engine.addProduct({"Laptop", "Electronics", 999.99, "A high-performance laptop"});
    engine.addProduct({"Smartphone", "Electronics", 499.99, "A latest model smartphone"});
    engine.addProduct({"Coffee Maker", "Home Appliances", 79.99, "A programmable coffee maker"});
    engine.addProduct({"Headphones", "Electronics", 199.99, "Noise-cancelling headphones"});
    engine.addProduct({"Blender", "Home Appliances", 49.99, "A powerful blender"});
    engine.addProduct({"Laptop", "Electronics", 1099.99, "A high-performance laptop with extra features"});
    engine.addProduct({"Smartphone", "Electronics", 599.99, "A latest model smartphone with more storage"});
    engine.addProduct({"Coffee Maker", "Home Appliances", 89.99, "A programmable coffee maker"});
    engine.addProduct({"Headphones", "Electronics", 239, "Noise-cancelling headphones"});


    string query;
    cout << "Enter search query: ";
    getline(cin, query);

    string category;
    cout << "Enter category (optional): ";
    getline(cin, category);

    double minPrice, maxPrice;
    cout << "Enter minimum price (optional): ";
    cin >> minPrice;
    cout << "Enter maximum price (optional): ";
    cin >> maxPrice;

    vector<Product> results = engine.search(query, category, minPrice, maxPrice);

    cout << "Search Results:\n";
    for (const auto& product : results) {
        cout << "Name: " << product.name << "\nCategory: " << product.category << "\nPrice: $" << product.price << "\nDescription: " << product.description << "\n\n";
    }

    return 0;
}
