## About

* A simple cmake project to show how to use [vcpkg](https://learn.microsoft.com/en-us/vcpkg/).
* [libunifex](https://github.com/facebookexperimental/libunifex) and [{fmt}](https://github.com/fmtlib/fmt) are used inside the project.

## Requirements
- [CMake](https://cmake.org/) 3.30+
- A C++23 supporting compiler (clang++/g++)
- [Ninja](https://github.com/ninja-build/ninja)

## How to build
```bash
cmake -S . -B build --preset=default
cmake --build build
```

## How to run the program
```bash
./build/zoo
```
