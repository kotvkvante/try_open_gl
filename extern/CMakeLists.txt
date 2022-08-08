if(WITH_GL3W)
    add_subdirectory(gl3w)
	target_link_libraries(Matryoshka PUBLIC
		gl3w
	)
endif()

if(WITH_GLAD)
	add_subdirectory(glad)
	target_link_libraries(Matryoshka PUBLIC 
		glad
	)
endif()

if(WITH_GLEW)
	add_subdirectory(glew)
	target_link_libraries(Matryoshka PUBLIC
		glew
	)
endif()

if(USE_MYMATH)
	add_subdirectory(alg)
	target_link_libraries(Matryoshka PUBLIC
		AlgFunctions
	)
endif()

