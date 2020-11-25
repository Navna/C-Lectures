add_executable(Lecture6-App "main.c")
target_link_libraries(Lecture6-App libio)
add_custom_command(TARGET Lecture6-App POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:libio> $<TARGET_FILE_DIR:Lecture6-App>)
