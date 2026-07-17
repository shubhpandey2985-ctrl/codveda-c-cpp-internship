# ⚙️ Producer–Consumer Queue Simulator

A multithreaded console application built using **Modern C++17** and **POSIX Threads (pthread)** that demonstrates the classic **Producer–Consumer synchronization problem** using a shared bounded buffer, mutexes, and condition variables.

This project was developed as part of the **Codveda Technology C++ Internship (Level 3 – Task 2)**.

---

## 📖 Overview

The Producer–Consumer problem is one of the most fundamental synchronization problems in concurrent programming and operating systems.

This application simulates multiple producer and consumer threads operating on a shared bounded buffer. Producers generate data and place it into the buffer, while consumers retrieve and process that data. Synchronization is implemented using mutexes and condition variables to ensure thread-safe access and prevent race conditions.

---

## ✨ Features

- 🧵 Multiple producer threads
- 🧵 Multiple consumer threads
- 📦 Shared bounded buffer
- 🔒 Thread synchronization using mutexes
- ⏳ Condition variables for thread coordination
- ⚡ Real-time production and consumption logs
- 📊 Simulation statistics
- ⚙️ Configurable thread count and buffer size
- 📝 Activity logging
- ⚠️ Robust error handling

---

## 🛠️ Tech Stack

| Category | Technology |
|----------|------------|
| Language | C++17 |
| Compiler | GCC / Clang / MSVC |
| Thread Library | POSIX Threads (pthread) |
| Build System | CMake |
| Data Structure | Circular Queue / Queue (STL) |
| Programming Paradigm | Object-Oriented Programming |

---

## 📂 Project Structure

```text
Task-2-ProducerConsumer/

├── README.md
├── CMakeLists.txt
│
├── include/
│   ├── Buffer.hpp
│   ├── Producer.hpp
│   ├── Consumer.hpp
│   ├── Logger.hpp
│   ├── Statistics.hpp
│   └── SimulationManager.hpp
│
├── src/
│   ├── main.cpp
│   ├── Buffer.cpp
│   ├── Producer.cpp
│   ├── Consumer.cpp
│   ├── Logger.cpp
│   ├── Statistics.cpp
│   └── SimulationManager.cpp
│
├── logs/
│   └── simulation.log
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
cd Level-3/Task-2-ProducerConsumer
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
g++ src/*.cpp -Iinclude -std=c++17 -pthread -o ProducerConsumer
```

Run the application:

```bash
./ProducerConsumer
```

---

## 📋 Application Menu

```text
==================================
 Producer–Consumer Simulator
==================================

1. Configure Simulation
2. Start Simulation
3. View Statistics
4. View Activity Log
5. Reset
6. Exit
```

---

## ⚙️ Simulation Configuration

Users can configure:

- Number of producer threads
- Number of consumer threads
- Buffer capacity
- Total items to produce
- Producer delay
- Consumer delay

Example:

```text
Producer Threads : 2
Consumer Threads : 2
Buffer Size      : 10
Items            : 100
```

---

## 📊 Sample Output

```text
==================================
 Producer–Consumer Simulator
==================================

Simulation Started...

[Producer 1] Produced Item #1
Buffer: 1/10

[Producer 2] Produced Item #2
Buffer: 2/10

[Consumer 1] Consumed Item #1
Buffer: 1/10

[Consumer 2] Consumed Item #2
Buffer: 0/10

...

Simulation Completed!

Produced : 100
Consumed : 100
Execution Time : 3.14 sec
```

---

## 📸 Screenshots

Add screenshots after implementation.

```text
screenshots/

├── menu.png
├── simulation.png
├── statistics.png
└── logs.png
```

---

## 🏗️ Architecture

```text
                    User
                      │
                      ▼
             Console Interface
                      │
                      ▼
          Simulation Manager
          ┌──────────┴──────────┐
          ▼                     ▼
   Producer Threads      Consumer Threads
          │                     │
          └──────────┬──────────┘
                     ▼
             Shared Circular Buffer
                     │
         Mutex + Condition Variables
                     │
                     ▼
          Statistics & Activity Logger
```

---

## 📚 Concepts Demonstrated

- Multithreading
- POSIX Threads (pthread)
- Mutex Synchronization
- Condition Variables
- Producer–Consumer Pattern
- Circular Queue
- Thread-safe Programming
- Object-Oriented Programming
- Modular Software Design
- Error Handling

---

## 🎯 Learning Outcomes

This project demonstrates practical knowledge of:

- Concurrent programming
- Synchronization mechanisms
- Shared resource management
- Race condition prevention
- Thread lifecycle management
- Modular C++ application design
- Real-world operating system concepts

---

## 🚧 Future Improvements

- Thread Pool implementation
- Dynamic buffer resizing
- GUI using Qt
- Real-time queue visualization
- Priority scheduling
- Performance benchmarking
- JSON/CSV log export
- Cross-platform implementation using `std::thread`
- Interactive monitoring dashboard

---

## 📄 Documentation

- Product Requirements Document (PRD)
- System Architecture
- Source Code Documentation
- Sample Outputs
- Activity Logs

---

## 👨‍💻 Author

**Your Name**

Codveda Technology C++ Internship

GitHub: https://github.com/<your-username>

LinkedIn: https://linkedin.com/in/<your-profile>

---

## 📜 License

This project is developed for educational purposes as part of the **Codveda Technology C++ Internship**.
