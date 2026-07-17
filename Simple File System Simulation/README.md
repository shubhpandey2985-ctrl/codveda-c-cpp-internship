# Simple File System Simulation

A C++17 console application that simulates a small file system with durable binary storage in `data/filesystem.dat`.

## Features

- Create, open, edit, rename, delete, search, and list virtual files
- Created/modified timestamps, IDs, and file statistics
- Filename and content validation, duplicate protection, and graceful errors
- Automatic load at launch and save at exit

## Build and run

Using CMake:

```sh
cmake -S . -B build
cmake --build build
./build/SimpleFileSystem
```

Or with g++:

```sh
g++ -std=c++17 -Iinclude src/*.cpp -o SimpleFileSystem
./SimpleFileSystem
```

For multi-line content, type `.end` on its own line to finish input.
