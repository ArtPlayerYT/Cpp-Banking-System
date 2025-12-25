# 🏦 C++ Banking System Management

A robust, console-based banking application developed in C++ that simulates real-world banking operations. This project demonstrates proficiency in Object-Oriented Programming (OOP), file handling for data persistence, and C++ Standard Template Library (STL).

![Banking System Interface]
<img width="1077" height="576" alt="Screenshot 2025-12-25 171253" src="https://github.com/user-attachments/assets/7ff4031a-5ac9-4c22-88b4-c3610b45bcbc" />


## 📖 Project Overview
This program serves as a comprehensive management tool for banking data. Unlike simple runtime programs, this system utilizes **File Handling** to ensure that account data and transaction histories are saved permanently, allowing the user to close the program and retrieve data later.

## ✨ Key Features & Benefits

* **Persistent Data Storage:** Automatically saves account details and account counters to `accl.txt` and `counter.txt` upon exit, ensuring no data is lost.
* **Dynamic Account Management:** Uses `std::vector` to handle an unlimited number of accounts dynamically without fixed array sizes.
* **Secure Encapsulation:** Account data (balance, names) is protected using `private` access modifiers, accessible only through secure public methods.
* **User-Friendly Interface:** Features a clean, menu-driven command line interface with ASCII art branding.

## 🛠️ Technical Concepts & Complex Topics Covered

This project implements several advanced C++ programming concepts:

### 1. Operator Overloading (Stream Insertion/Extraction)
Instead of writing manual print functions, this program overloads the `<<` and `>>` operators. This allows objects of the class `acc` to be written to and read from files/streams directly, treating custom objects like standard variables.
* **Code Reference:** `friend ostream& operator<<(ostream& c, acc& s);`

### 2. File Handling (`fstream`)
The system creates a persistent database using text files. It handles input (`ifstream`) to load existing accounts at startup and output (`ofstream`) to save the state when the program terminates.
* **Code Reference:** `ofstream fps("accl.txt");`

### 3. Object-Oriented Design
* **Classes & Objects:** The `acc` class bundles data (names, balance, account number) with behavior (deposit, withdraw).
* **Constructors:** Uses parameterized constructors to initialize new accounts instantly.
* **Encapsulation:** Keeps sensitive data like `blc` (balance) private.

### 4. Standard Template Library (STL)
Utilizes `std::vector<acc>` to manage the list of accounts. This provides efficient memory management and easy iteration compared to traditional arrays.
* **Code Reference:** `vector<acc> listacc;`

## 🚀 Functionality Breakdown

The system offers 7 distinct operations handled via a `switch-case` menu:

1.  **Create Account:** Captures First Name, Last Name, and Initial Balance. Automatically assigns a unique Account Number.
2.  **Balance Enquiry:** Fetches current funds for a specific account.
3.  **Deposit:** Adds funds to an existing account.
4.  **Withdrawal:** Deducts funds (with validation).
5.  **Close Account:** Permanently removes a user record from the vector and file.
6.  **Show All Accounts:** Iterates through the vector to display every account in the database.
7.  **Exit & Save:** Writes the current state of the vector to the local file system before terminating.

## 💻 How to Run

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/yourusername/banking-system.git](https://github.com/yourusername/banking-system.git)
    ```
2.  **Compile the code:**
    ```bash
    g++ banksys.cpp -o bankapp
    ```
3.  **Run the executable:**
    * Windows: `bankapp.exe`
    * Linux/Mac: `./bankapp`

## 🔮 Future Improvements
* Implement password protection for individual accounts.
* Add an interest calculation feature based on time.
* Migrate from `.txt` storage to a binary file format for better security.

---
*Created by [Aayush Ae]*
