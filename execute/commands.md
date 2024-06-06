## Run g++ and specify c++ version

```bash
$ g++ -std=c++20 ./main.cpp && ./a.out
```
- ## CMake and Clang
  
  ```bash
  $ mkdir build
  $ cmake -S . -B ./build -DCMAKE_BUILD_TYPE=<Debug|Release>
  $ cmake --build ./build # basically run `make` in ./build 
  $ ./build/program # run built programs
  ```
- ## Build executables
  ```bash
  $ cd build
  $ make
  $ ./program
  ```
- ## Run test
  ```bash
  $ cd build
  $ make
  $ ./test_program
  ```
- ## Run all tests
  ```bash
  $ cd build
  $ make
  $ ctest
  ```