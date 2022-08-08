add_library(gl3w
    src/gl3w.c
)

target_include_directories(
    gl3w PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    # $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)

target_link_libraries(
    gl3w PUBLIC
    ${CMAKE_DL_LIBS}
)

# set(LIB
# )

#install(FILES GL/gl3w.h DESTINATION include)


# install(TARGETS gl3w DESTINATION lib)
