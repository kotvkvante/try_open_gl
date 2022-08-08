add_library(AlgFunctions
    my_alg.c
    flower.c
)
#target_sources(AlgFunctions PRIVATE )

target_include_directories(
    AlgFunctions PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

# install(TARGETS AlgFunctions DESTINATION lib)
# install(FILES my_alg.h DESTINATION include)
# install(FILES flower.h DESTINATION include)
