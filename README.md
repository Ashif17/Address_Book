# 📘 Address Book Management System (C Project)

The **Address Book Management System** is a **console-based application written in C** that provides an efficient way to manage and organize personal or professional contact information. It allows users to perform essential contact management operations such as **adding**, **searching**, **editing**, **deleting**, and **listing** contacts, while maintaining persistent storage using a **CSV file** (`addressBook.csv`).  

Each contact entry includes a **name**, **phone number**, and **email ID**, which are validated for correctness and checked for duplicates before saving. The project demonstrates key programming concepts in C, such as **structures**, **file handling**, **string manipulation**, and **modular programming** through multiple source and header files.

---

## 🔹 Core Functionalities

- **Add New Contacts:** Users can create new contact entries. Each input is validated — names must contain only alphabets, phone numbers must be exactly 10 digits, and email IDs must follow the standard format (e.g., `example@mail.com`).
- **Search Contacts:** Contacts can be searched using partial or full matches of the name, phone number, or email ID, providing a flexible and user-friendly experience.
- **Edit Contacts:** Existing records can be updated by selecting a specific contact and modifying any of its fields — name, phone number, or email.
- **Delete Contacts:** Users can remove one or more contacts from the address book easily.
- **List Contacts:** Displays all stored contacts or filters them based on name, phone, or email. The listing is neatly formatted and indexed for clarity.
- **File Operations:** Contacts are saved to a CSV file to ensure that data is not lost between program executions. During startup, the system automatically loads existing records from the file.
- **Data Sorting:** Before saving, contacts are alphabetically sorted by name for better readability.

---

## 🔹 Technical Highlights

- Implements **structured programming** with modular source files (`main.c`, `contact.c`, `file.c`).
- Uses **structures** to group related data fields.
- Demonstrates **file I/O operations** using `fopen`, `fprintf`, and `fscanf`.
- Validates user inputs and handles erroneous entries gracefully.

---

This project serves as an excellent example of a practical **data management system in C**, combining simplicity, modularity, and persistent storage — ideal for learning and demonstration purposes.
