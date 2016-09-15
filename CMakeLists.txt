cmake_minimum_required(VERSION 3.5)
project(Mesh_Memory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp "Mesh Mem API/xReference.cpp"  "Mesh Mem API/xReference.h" "Mesh Mem API/API.cpp" "Mesh Mem API/API.h" "Mesh Mem API/xType.cpp" "Mesh Mem API/xType.h" "Mesh Mem API/HexConverter.cpp" "Mesh Mem API/HexConverter.h" "Mesh Mem API/Token.cpp" "Mesh Mem API/Token.h" "Mesh Mem API/UUID.cpp" "Mesh Mem API/UUID.h" "Mesh  Mem  Client/Client.cpp" "Mesh  Mem  Client/Client.h" "Mesh  Mem  Client/Client.h" "Mesh Mem API/base64.cpp" "Mesh Mem API/base64.h")
add_executable(Mesh_Memory ${SOURCE_FILES} "Mesh Mem API/xReference.cpp" "Mesh Mem API/xReference.h" "Mesh Mem API/API.cpp" "Mesh Mem API/API.h" "Mesh Mem API/xType.cpp" "Mesh Mem API/xType.h" "Mesh Mem API/HexConverter.cpp" "Mesh Mem API/HexConverter.h" "Mesh Mem API/Token.cpp" "Mesh Mem API/Token.h" "Mesh Mem API/UUID.cpp" "Mesh Mem API/UUID.h" "Mesh  Mem  Client/Client.cpp" "Mesh  Mem  Client/Client.h" "Mesh Mem API/base64.cpp" "Mesh Mem API/base64.h")

set(TREADS_PREFERED_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Mesh_Memory Threads::Threads)
