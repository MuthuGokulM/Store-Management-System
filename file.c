#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "file.h"

// SAVE PRODUCTS
void saveToFile() {
    FILE *fp = fopen("products.dat", "wb");
    if(!fp) return;

    struct Product *temp = head;

    while(temp) {
        fwrite(temp, sizeof(struct Product), 1, fp);
        temp = temp->next;
    }

    fclose(fp);
}

// LOAD PRODUCTS
void loadFromFile() {
    FILE *fp = fopen("products.dat", "rb");
    if(!fp) return;

    struct Product *newNode;

    while(1) {
        newNode = malloc(sizeof(struct Product));

        if(fread(newNode, sizeof(struct Product), 1, fp) != 1) {
            free(newNode);
            break;
        }

        newNode->next = head;
        head = newNode;
    }

    fclose(fp);
}

// SAVE BILLING
void saveBilling() {
    FILE *fp = fopen("bill.dat", "wb");
    if(!fp) return;

    fwrite(&billCount, sizeof(int), 1, fp);
    fwrite(&totalSales, sizeof(float), 1, fp);

    fclose(fp);
}

// LOAD BILLING
void loadBilling() {
    FILE *fp = fopen("bill.dat", "rb");
    if(!fp) return;

    fread(&billCount, sizeof(int), 1, fp);
    fread(&totalSales, sizeof(float), 1, fp);

    fclose(fp);
}