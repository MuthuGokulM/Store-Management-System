#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

struct Product *head = NULL;
float totalSales = 0;
int billCount = 0;

// SEARCH
struct Product* searchProduct(int id) {
    struct Product *temp = head;
    while(temp) {
        if(temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// ADD
void addProduct() {
    struct Product *newNode = malloc(sizeof(struct Product));

    printf("Enter ID Name Price Quantity:\n");
    scanf("%d %s %f %d",
          &newNode->id,
          newNode->name,
          &newNode->price,
          &newNode->quantity);

    if(searchProduct(newNode->id)) {
        printf("Product ID already exists\n");
        free(newNode);
        return;
    }

    newNode->next = head;
    head = newNode;

    printf("Product Added\n");
}

// DELETE
void deleteProduct() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    struct Product *temp = head, *prev = NULL;

    while(temp) {
        if(temp->id == id) {
            if(prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Deleted\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Not found\n");
}

// UPDATE
void updateProduct() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    struct Product *p = searchProduct(id);

    if(!p) {
        printf("Not found\n");
        return;
    }

    printf("Enter new price & qty: ");
    scanf("%f %d", &p->price, &p->quantity);

    printf("Updated\n");
}

// VIEW
void viewProducts() {
    if(!head) {
        printf("No products\n");
        return;
    }

    int count = 0;
    struct Product *temp = head;

    while(temp) {
        count++;
        temp = temp->next;
    }

    struct Product arr[count];
    temp = head;

    for(int i = 0; i < count; i++) {
        arr[i] = *temp;
        temp = temp->next;
    }

    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(arr[j].id > arr[j + 1].id) {
                struct Product t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    printf("\nID\tName\tPrice\tQty\n");

    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n",
               arr[i].id,
               arr[i].name,
               arr[i].price,
               arr[i].quantity);
    }
}

// BILL
void generateBill() {
    int id, qty;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    struct Product *p = searchProduct(id);

    if(!p) {
        printf("Not found\n");
        return;
    }

    printf("Enter qty: ");
    scanf("%d", &qty);

    if(qty <= 0 || qty > p->quantity) {
        printf("Invalid qty\n");
        return;
    }

    float amount = qty * p->price;

    p->quantity -= qty;
    totalSales += amount;
    billCount++;

    printf("\nBill %d\n", billCount);
    printf("%s x%d = %.2f\n", p->name, qty, amount);

    FILE *fp = fopen("daily_report.txt", "a");

    if(fp) {
        fprintf(fp, "Bill %d\n", billCount);
        fprintf(fp, "%s %d %.2f\n", p->name, qty, amount);
        fprintf(fp, "------\n");
        fclose(fp);
    }
}

// SUMMARY
void dailySummary() {
    FILE *fp = fopen("daily_report.txt", "a");

    if(!fp) return;

    fprintf(fp, "\nSummary\nBills: %d\nSales: %.2f\n", billCount, totalSales);

    struct Product *temp = head;
    while(temp) {
        fprintf(fp, "%s %d\n", temp->name, temp->quantity);
        temp = temp->next;
    }

    fclose(fp);

    printf("Summary saved\n");
}