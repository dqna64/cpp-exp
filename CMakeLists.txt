cmake_minimum_required(VERSION 3.20)

# Debug builds should be compiled with sanitizers
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-fsanitize=address,undefined")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-fsanitize=address,undefined")
set(CMAKE_CXX_EXE_LINKER_FLAGS_DEBUG_INIT "-fsanitize=address,undefined")
set(CMAKE_CXX_EXE_LINKER_FLAGS_RELWITHDEBINFO_INIT "-fsanitize=address,undefined")

project(cpp-exp CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_compile_options(
    -Wall
    -Wextra
    -pedantic
    -Wconversion
    -Wsign-conversion
    -Wdouble-promotion
    -Wcast-align
    -Wformat=2
    -Wuninitialized
    -Wnull-dereference
    -Wnon-virtual-dtor
    -Woverloaded-virtual
    -Wdeprecated-copy-dtor
    -Wold-style-cast
    # -Wzero-as-null-pointer-constant
    -Wsuggest-override
    -fstack-protector-strong
    -Wno-unused-variable
    -Wno-unused-private-field
    -Wimplicit-fallthrough
)

add_subdirectory(general)
add_subdirectory(misc)