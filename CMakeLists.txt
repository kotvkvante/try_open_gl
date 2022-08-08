cmake_minimum_required(VERSION 3.16)

set(EXTERN_DIR "${CMAKE_SOURCE_DIR}/extern")

set(GLFW_INC "${GLFW_ROOT}/include")


#
project(MatryoshkaProj VERSION 1.4)



#
option(USE_MYMATH "Use tutorial provided math implementation" ON)
option(WITH_GL3W "Use gl3w" OFF)
option(WITH_GLAD "Use glad" OFF)
option(WITH_GLEW "Use glew" OFF)

set(OPT "FIRST" CACHE STRING "Provider choosen")
set_property(CACHE OPT PROPERTY STRINGS "GLAD" "GL3W" "GLEW")
message("OPT:" ${OPT})

if("${OPT}" STREQUAL "GLAD")
	SET(WITH_GLAD ON)
	message("You choose GLAD.")
elseif("${OPT}" STREQUAL "GL3W")
	SET(WITH_GL3W ON)
	message("You choose GL3W")
elseif("${OPT}" STREQUAL "GLEW")
	SET(WITH_GLEW ON)
	message("You choose GLEW")
endif()

#
#
configure_file(Matryoshka.h.in Matryoshka.h)

#

add_executable(Matryoshka main.c)


add_subdirectory("extern")


#

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

#

target_link_libraries(Matryoshka PUBLIC
    ${EXTRA_LIBS}
    OpenGL::GL
    glfw
)

target_include_directories(Matryoshka PUBLIC
    ${PROJECT_BINARY_DIR}
)

install(TARGETS Matryoshka DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/Matryoshka.h"
        DESTINATION include
        )
