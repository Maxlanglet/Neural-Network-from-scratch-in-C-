cmake_minimum_required(VERSION 3.10)
project( NN_C++ )

set(CMAKE_CXX_FLAGS "-O3")

add_subdirectory(Image_Reader)
add_subdirectory(NN)

add_executable( main main.cpp)

set_property(TARGET main PROPERTY CXX_STANDARD 11)

target_link_libraries(main PUBLIC Image_Reader)
target_include_directories(main PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Image_Reader"
                          )
target_link_libraries(main PUBLIC Path_Loader)
target_include_directories(main PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Image_Reader"
                          )
target_link_libraries(main PUBLIC Timer)
target_include_directories(main PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Image_Reader"
                          )

target_link_libraries(main PUBLIC Layer)
target_include_directories(main PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/NN"
                          )
target_link_libraries(main PUBLIC Neural_Network)
target_include_directories(main PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/NN"
                          )