# cpp-exp

C++ experimentation and learning.

## Compile and run with clang
```sh
clang++ -std=c++20 general/01-main.cpp && ./a.out
```

Clang produces clearer error messages and has stricter warnings (e.g. `-Wno-unused-private-field`) that GCC lacks.

## Build and run with Cmake
Build Cmake project:

```sh
cmake -B build                        # configure: generate Makefiles in build/
cmake --build build -- --keep-going   # compile all targets, continue on failure
``;`

This builds in Debug mode by default, with AddressSanitizer and UBSanitizer enabled. To build release:

```sh
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -- --keep-going
```

After building, executables are in `build/general/` and `build/misc/`. Execute them:

```sh
./build/general/01-main
./build/misc/misc-algorithms
```

To compile and run a single target:

```sh
cmake --build build --target 01-main   # compile one executable
./build/general/01-main
```

## Add a new file in `general/`
1. Create `general/51-my-topic.cpp`
2. Add one line to [general/CMakeLists.txt](general/CMakeLists.txt):
   ```cmake
   add_executable(51-my-topic 51-my-topic.cpp)
   ```
3. Rebuild: `cmake --build build -- --keep-going`

## Add a new file in `misc/`
1. Create `misc/my-topic.cpp`
2. Add one line to [misc/CMakeLists.txt](misc/CMakeLists.txt):
   ```cmake
   add_executable(misc-my-topic my-topic.cpp)
   ```
3. Rebuild: `cmake --build build -- --keep-going`
