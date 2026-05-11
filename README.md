# Store Management System

The Store Management System is a C-based console application designed to manage product inventory, billing, and daily sales operations efficiently. It uses Linked Lists for dynamic data storage and File Handling for maintaining records permanently. The system provides a simple menu-driven interface for managing store activities.

---

## Features

* **Add Products**: Insert new products with ID, name, price, and quantity.
* **View Products**: Display all available products sorted by product ID.
* **Update Products**: Modify product price and quantity.
* **Delete Products**: Remove products from the inventory.
* **Generate Bills**: Create bills and automatically update stock quantity.
* **Daily Summary**: Generate reports containing total sales and remaining stock.
* **Login Authentication**: Secure access using predefined username and password.
* **File Storage**: Save and load product and billing data using files.

---

## Prerequisites

* GCC Compiler
* C Standard Library
* Any Code Editor (VS Code, CodeBlocks, Dev-C++, etc.)

---

## Installation

### 1. Clone the Repository

```bash
git clone https://github.com/MuthuGokulM/Store-Management-System.git
```

### 2. Navigate to the Project Directory

```bash
cd Store-Management-System
```

### 3. Compile the Source Code

```bash
gcc main.c product.c file.c -o store
```

### 4. Run the Application

```bash
./store
```

---

## Usage

1. Run the application using the commands above.

2. Login using the credentials:

```text
Username: admin
Password: 1234
```

3. Use the menu options to manage products, billing, and reports.

4. Product and billing data will be automatically saved into files.

---

## Project Structure

```bash
Store-Management-System/
│
├── main.c
├── product.c
├── product.h
├── file.c
├── file.h
├── products.dat
├── bill.dat
├── daily_report.txt
└── README.md
```

---

## Data Structure Used

### Product Structure

```c
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
    struct Product *next;
};
```

---

## Concepts Implemented

* Linked Lists
* Dynamic Memory Allocation
* File Handling
* Structures
* Function Pointers
* Modular Programming

---

## Files Used

| File Name | Purpose |
|------------|----------|
| `products.dat` | Stores product details |
| `bill.dat` | Stores billing information |
| `daily_report.txt` | Stores generated bills and summaries |

---

## Sample Menu

```text
1. Add Product
2. View Products
3. Generate Bill
4. Update Product
5. Delete Product
6. Daily Summary
7. Exit
```

---

## Functional Modules

### Product Management
Manage products using linked list operations:
- Add products
- Update products
- Delete products
- Search products

### Billing System
- Generates customer bills
- Updates stock automatically
- Tracks total sales

### File Handling
Stores:
- Product records
- Billing information
- Daily sales reports

### Authentication System
Provides secure login access using predefined credentials.

---

## Contributing

Contributions are welcome! Feel free to fork the repository and submit pull requests for improvements.

---

## License

This project is open-source and free to use for learning purposes.

---

## Author

Developed by **Muthu Gokul**
