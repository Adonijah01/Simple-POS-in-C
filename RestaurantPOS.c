#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_USERS 10

// Structure to represent a product
typedef struct {
    char name[50];
    float price;
} Product;

// Structure to represent a user
typedef struct {
    char username[20];
    char password[20];
} User;

Product products[MAX_PRODUCTS];
User users[MAX_USERS];
int numProducts = 0;
int numUsers = 0;

// Function to display the main menu
void displayMenu() {
    printf("\n=========== Restaurant POS ===========\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. View Order\n");
    printf("4. Checkout\n");
    printf("5. Add New Product\n");
    printf("6. User Login\n");
    printf("7. Exit\n");
    printf("=======================================\n");
    printf("Enter your choice: ");
}

// Function to add a new product to the inventory
void addNewProduct() {
    if (numProducts >= MAX_PRODUCTS) {
        printf("Product limit reached. Cannot add more products.\n");
        return;
    }

    printf("Enter the product name: ");
    scanf("%s", products[numProducts].name);

    printf("Enter the product price: ");
    scanf("%f", &products[numProducts].price);

    numProducts++;

    printf("Product added successfully.\n");
}

// Function to find a product by name
int findProductByName(const char* name) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add an item to the order
void addItem() {
    printf("Enter the item name: ");
    char name[50];
    scanf("%s", name);

    int index = findProductByName(name);
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    // Add the item to the order
    // Add your own implementation here
    printf("Item added to the order.\n");
}

// Function to remove an item from the order
void removeItem() {
    printf("Enter the item name to remove: ");
    char name[50];
    scanf("%s", name);

    // Remove the item from the order
    // Add your own implementation here
    printf("Item removed from the order.\n");
}

// Function to view the current order
void viewOrder() {
    // Display the current order
    // Add your own implementation here
    printf("Current Order:\n");
    printf("1. Item 1: $10.00\n");
    printf("2. Item 2: $15.00\n");
    printf("Total: $25.00\n");
}

// Function to process the checkout and print the receipt
void checkout() {
    // Calculate the total amount
    // Add your own implementation here
    float total = 25.00;

    printf("Total amount: $%.2f\n", total);

    // Print the receipt
    printf("\n=========== Receipt ===========\n");
    printf("Items:\n");
    printf("1. Item 1: $10.00\n");
    printf("2. Item 2: $15.00\n");
    printf("Total: $25.00\n");
    printf("Payment received. Thank you!\n");
}

// Function to add a new user
void addNewUser() {
    if (numUsers >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }

    printf("Enter the username: ");
    scanf("%s", users[numUsers].username);

    printf("Enter the password: ");
    scanf("%s", users[numUsers].password);

    numUsers++;

    printf("User added successfully.\n");
}

// Function to perform user login
void userLogin() {
    printf("Enter the username: ");
    char username[20];
    scanf("%s", username);

    printf("Enter the password: ");
    char password[20];
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }

    printf("Invalid username or password.\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                viewOrder();
                break;
            case 4:
                checkout();
                break;
            case 5:
                addNewProduct();
                break;
            case 6:
                userLogin();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

