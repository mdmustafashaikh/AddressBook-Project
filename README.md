# AddressBook-Project
A simple Address Book project in C that allows users to add, edit, delete, search, and list contacts. Uses structures, file handling, and validation functions for name, phone, and email. Demonstrates core C concepts like data storage, modular design, and input validation in a console-based contact management system.


## 📘 Address Book in C  

### 🧩 Project Overview  
The **Address Book** is a simple **C-based contact management system** that allows users to **create, edit, delete, list, and search contacts** easily from the terminal. It demonstrates the use of **file handling**, **structures**, and **modular programming** in C.  

### 🚀 Features  
- ➕ **Add New Contact** – Store name, phone number, and email address.  
- 🔍 **Search Contact** – Find a contact by name, phone, or email.  
- ✏️ **Edit Contact** – Update existing contact details.  
- ❌ **Delete Contact** – Remove contact from the file.  
- 📋 **List Contacts** – Display all saved contacts in a structured format.  
- ✅ **Input Validation** – Includes `ValidName`, `ValidPhone`, and `ValidEmail` functions for data accuracy.  
- 💾 **Persistent Storage** – Contacts are stored in a file for long-term access even after the program closes.  

### 🧠 Concepts Used  
- File Handling (`fopen`, `fread`, `fwrite`, etc.)  
- Structures and Functions  
- String Manipulation  
- Data Validation  
- Command-line Interface  

### ⚙️ How to Run  
1. Clone the repository:  
   ```bash
   git clone https://github.com/yourusername/addressbook.git
   cd addressbook
   ```
2. Compile the program:  
   ```bash
   gcc addressbook.c -o addressbook
   ```
3. Run the executable:  
   ```bash
   ./addressbook
   ```

### 🧑‍💻 Example Use  
```
1. Add Contact
2. List Contacts
3. Search Contact
4. Edit Contact
5. Delete Contact
6. Exit
Enter your choice: 1
Enter Name: John Doe
Enter Phone: 9876543210
Enter Email: john@example.com
Contact added successfully!
```

### 📂 File Structure  
```
├── addressbook.c
├── validation.c
├── validation.h
├── contacts.dat
└── README.md
```

### 🏁 Future Enhancements  
- Import/Export contacts in CSV format  
- Sort contacts alphabetically  
- GUI version using C++ or Python frontend  
