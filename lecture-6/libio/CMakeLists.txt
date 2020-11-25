set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(libio SHARED "include/io.h" "src/io.c")
target_include_directories(libio PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
