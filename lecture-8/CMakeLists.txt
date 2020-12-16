add_executable(Lecture8-Performance "performance.c")
add_executable(Lecture8-Image "main.c" "image.h" "image.c" "stb_image.h" "stb_image_write.h")

add_executable(Lecture8-WinAPI "main-winapi.c" "image.h" "image.c" "stb_image.h" "stb_image_write.h")
target_compile_options(Lecture8-WinAPI PUBLIC /DUNICODE /D_UNICODE /utf-8)
