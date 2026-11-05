#include <array>
#include <iostream>
#include <sstream>
#include <string>

struct Product {
    std::string name;
    int category;
    int price;
};

const std::array<Product, 9> products = {{
    {"Headphone", 1, 655},
    {"Logitech Mouse", 1, 500},
    {"Pendrive 64 GB", 1, 950},
    {"Adidas Shoes", 2, 3550},
    {"Nike Shoes", 2, 5000},
    {"Puma Shoes", 2, 2800},
    {"Mi Note 7", 3, 11000},
    {"Nokia 3", 3, 9866},
    {"Samsung A15", 3, 12800}
}};

const std::array<std::string, 4> categoryNames = {
    "",
    "Computer Accessories",
    "Shoes",
    "Mobiles"
};

int readInt(const std::string& prompt) {
    while (true) {
        std::cout << prompt;

        std::string line;
        if (!std::getline(std::cin, line)) {
            return 0;
        }

        std::istringstream input(line);
        int value;
        char extra;

        if (input >> value && !(input >> extra)) {
            return value;
        }

        std::cout << "Please enter a whole number.\n";
    }
}

long long calculateTotal(const std::array<int, 9>& cart) {
    long long total = 0;

    for (std::size_t i = 0; i < products.size(); ++i) {
        total += static_cast<long long>(cart[i]) * products[i].price;
    }

    return total;
}

void showCart(const std::array<int, 9>& cart) {
    std::cout << "\nYour cart\n";

    bool isEmpty = true;

    for (std::size_t i = 0; i < products.size(); ++i) {
        if (cart[i] > 0) {
            isEmpty = false;
            const long long itemTotal =
                static_cast<long long>(cart[i]) * products[i].price;

            std::cout << "ID " << (i + 1) << " - "
                      << products[i].name
                      << " | Quantity: " << cart[i]
                      << " | Cost: Rs. " << itemTotal << '\n';
        }
    }

    if (isEmpty) {
        std::cout << "The cart is empty.\n";
    }

    std::cout << "Total: Rs. " << calculateTotal(cart) << "\n\n";
}

void showProducts(int category) {
    std::cout << "\n" << categoryNames[category] << '\n';

    for (std::size_t i = 0; i < products.size(); ++i) {
        if (products[i].category == category) {
            std::cout << "ID " << (i + 1) << " - "
                      << products[i].name
                      << " - Rs. " << products[i].price << '\n';
        }
    }
}

void addProduct(int category, std::array<int, 9>& cart) {
    showProducts(category);

    const int id = readInt("Enter a product ID (or 0 to go back): ");

    if (id == 0) {
        return;
    }

    if (id < 1 || id > static_cast<int>(products.size()) ||
        products[id - 1].category != category) {
        std::cout << "That product ID is not in this category.\n";
        return;
    }

    const int confirmation =
        readInt("Add this product? Enter 1 for Yes or 2 for No: ");

    if (confirmation == 1) {
        ++cart[id - 1];
        std::cout << products[id - 1].name << " added to your cart.\n";
        showCart(cart);
    } else {
        std::cout << "Purchase cancelled.\n";
    }
}

void removeProduct(std::array<int, 9>& cart) {
    showCart(cart);

    if (calculateTotal(cart) == 0) {
        return;
    }

    const int id = readInt("Enter the product ID to remove (or 0 to go back): ");

    if (id == 0) {
        return;
    }

    if (id < 1 || id > static_cast<int>(products.size()) ||
        cart[id - 1] == 0) {
        std::cout << "That product ID is not in your cart.\n";
        return;
    }

    cart[id - 1] = 0;
    std::cout << "Product removed from your cart.\n";
    showCart(cart);
}

int main() {
    std::array<int, 9> cart = {};

    std::cout << "Please enter your name: ";
    std::string name;

    if (!std::getline(std::cin, name) || name.empty()) {
        name = "Customer";
    }

    std::cout << "\nHello, " << name
              << "! Welcome to the online shopping demo.\n";

    while (true) {
        std::cout << "\nMain Menu\n"
                  << "1 - Computer Accessories\n"
                  << "2 - Shoes\n"
                  << "3 - Mobiles\n"
                  << "4 - View Cart\n"
                  << "5 - Remove an Item\n"
                  << "0 - Checkout and Exit\n";

        const int choice = readInt("Choose an option: ");

        if (choice == 0) {
            break;
        }

        if (choice >= 1 && choice <= 3) {
            addProduct(choice, cart);
        } else if (choice == 4) {
            showCart(cart);
        } else if (choice == 5) {
            removeProduct(cart);
        } else {
            std::cout << "Please choose a valid menu option.\n";
        }
    }

    showCart(cart);
    std::cout << "Thank you, " << name << ". Visit us again!\n";

    return 0;
}
