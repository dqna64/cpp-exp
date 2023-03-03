## Run g++ and specify c++ version

```bash
g++ -std=c++11 ./main.cpp && ./a.out
```

## CMake and Clang

```
mkdir build
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=<Debug|Release>
cmake --build ./build
./build/
```

