# 📁 Simple File System Simulation

A console-based virtual file system built using **Modern C++17** that simulates basic file management operations such as creating, opening, editing, renaming, deleting, and searching files. This project was developed as part of the **Codveda Technology C++ Internship (Level 3 – Task 1)**.

---

## 📖 Overview

This project demonstrates the implementation of a simplified file system using object-oriented programming and file handling concepts in C++. Rather than interacting directly with the operating system's file system, the application manages virtual files within its own storage, providing a safe environment to understand how file management systems work.

The application features a menu-driven interface and persists data between program executions using local storage.

---

## ✨ Features

- 📄 Create new virtual files
- 📂 Open and view file contents
- ✏️ Edit existing files
- 📝 Rename files
- 🗑️ Delete files with confirmation
- 🔍 Search files by name
- 📋 Display all stored files
- ℹ️ View file metadata
- 💾 Persistent storage using local database/file
- ⚠️ Input validation and error handling
- 🧩 Modular and object-oriented architecture

---

## 🛠️ Tech Stack

| Category | Technology |
|----------|------------|
| Language | C++17 |
| Compiler | GCC / Clang / MSVC |
| Build System | CMake |
| Storage | File I/O (Binary/Text) |
| Paradigm | Object-Oriented Programming |

---

## 📂 Project Structure

```text
Task-1-FileSystemSimulation/

├── README.md
├── CMakeLists.txt
├── include/
│   ├── File.hpp
│   ├── FileManager.hpp
│   ├── Storage.hpp
│   ├── Validator.hpp
│   └── Utils.hpp
│
├── src/
│   ├── main.cpp
│   ├── File.cpp
│   ├── FileManager.cpp
│   ├── Storage.cpp
│   ├── Validator.cpp
│   └── Utils.cpp
│
├── data/
│   └── filesystem.db
│
├── docs/
│   ├── PRD.md
│   └── Architecture.md
│
└── screenshots/
```

---

## 🚀 Getting Started

### Clone the Repository

```bash
git clone https://github.com/<your-username>/codveda-cpp-internship.git
```

Navigate to the project directory:

```bash
cd Level-3/Task-1-FileSystemSimulation
```

---

## ⚙️ Build

Using CMake:

```bash
mkdir build
cd build

cmake ..

cmake --build .
```

Or compile directly using g++:

```bash
g++ src/*.cpp -Iinclude -std=c++17 -o FileSystem
```

Run the application:

```bash
./FileSystem
```

---

## 📋 Application Menu

```text
=============================
 Simple File System
=============================

1. Create File
2. Open File
3. Edit File
4. Rename File
5. Delete File
6. Display All Files
7. Search File
8. File Information
9. Save
10. Exit
```

---

## 📸 Screenshots

Add screenshots here after completing the project.

```text
screenshots/

├── menu.png
├── create-file.png
├── edit-file.png
├── search-file.png
└── file-list.png
```

---

## 🏗️ Architecture

```text
                User
                  │
                  ▼
            Console Menu
                  │
                  ▼
           File Manager
          ┌─────────────┐
          │ CRUD Logic  │
          └─────────────┘
                  │
                  ▼
             Storage Layer
                  │
                  ▼
          filesystem.db
```

---

## 📚 Concepts Demonstrated

- Object-Oriented Programming
- File Handling
- File Persistence
- Dynamic Memory Management
- STL Containers
- Modular Design
- Input Validation
- Error Handling
- Software Architecture

---

## 🎯 Learning Outcomes

Through this project, I gained practical experience in:

- Designing modular C++ applications
- Managing persistent data using file I/O
- Applying object-oriented design principles
- Implementing CRUD operations
- Building scalable console applications
- Writing maintainable and reusable code

---

## 🚧 Future Improvements

- Folder hierarchy support
- Copy and move files
- Password-protected files
- File compression
- Recycle Bin
- Undo/Redo functionality
- JSON import/export
- GUI using Qt
- Unit testing
- Logging system

---

## 📄 Documentation

- Product Requirements Document (PRD)
- Architecture Diagram
- Source Code Documentation
- Sample Outputs

---

## 👨‍💻 Author

**Your Name**

Codveda Technology C++ Internship

GitHub: https://github.com/<your-username>

LinkedIn: https://linkedin.com/in/<your-profile>

---

## 📜 License

This project is developed for educational purposes as part of the **Codveda Technology C++ Internship**.
