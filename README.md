# libunifex test

A simple template to make use of vcpkg in a project. [libunifex](https://github.com/facebookexperimental/libunifex) is chosen to show how to use vcpkg in a project.

# Requirements
- CMake 3.30+
- A C++23 supporting compiler (clang++/g++)

# How to build
```bash
cmake -S . -B build --preset=default
cmake --build build
```

# How to run the program
```bash
./build/zoo
```
