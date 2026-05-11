struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
    struct Product *next;
};

extern struct Product *head;
extern float totalSales;
extern int billCount;

// function declarations
void addProduct();
void deleteProduct();
void updateProduct();
void viewProducts();
void generateBill();
void dailySummary();
struct Product* searchProduct(int id);