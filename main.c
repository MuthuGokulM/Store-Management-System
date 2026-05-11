#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
#include "file.h"


int login();

void exitProgram() {
    saveToFile();
    saveBilling();
    printf("Exiting...\n");
    exit(0);
}

void (*menu[])(void) = {
    addProduct,
    viewProducts,
    generateBill,
    updateProduct,
    deleteProduct,
    dailySummary,
    exitProgram
};

int login() {
    char username[20], password[20];

    // Predefined credentials
    char correctUser[] = "admin";
    char correctPass[] = "1234";

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    // Compare
    if(strcmp(username, correctUser) == 0 &&
       strcmp(password, correctPass) == 0) {
        printf("Login Successful\n");
        return 1;
    } else {
        printf("Invalid Credentials\n");
        return 0;
    }
}

int main() {
    int choice;

    loadFromFile();
    loadBilling();

    if(!login()) {
        printf("Access denied\n");
        return 0;
    }

    while(1) {
        printf("\n1.Add Product\n2.View Products\n3.Generate Bill\n4.Update Product\n5.Delete Product\n6.Daily Summary\n7.Exit\n");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 7)
            menu[choice - 1]();
        else
            printf("Invalid choice\n");
    }
}