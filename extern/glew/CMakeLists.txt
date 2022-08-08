add_library(glew
    src/glew.c
)

target_include_directories(
    glew PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

#target_link_libraries(
#    glew PUBLIC
#)

