#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

/*#include <GL/glew.h>*/


#include "Matryoshka.h"


#ifdef USE_MYMATH
#	include <my_alg.h>
#endif

// GL3W
#if defined(WITH_GL3W) 
#	include <GL/gl3w.h>
#	include <GLFW/glfw3.h>
int gl3w_load()
{
	printf("Using gl3w.\n");
	return !gl3wInit();
}
#	define GLInit gl3w_load

// GLAD
#elif defined(WITH_GLAD) 
#	include <glad/glad.h>
#	include <GLFW/glfw3.h>
int glad_load()
{
	printf("Using glad.\n");
	return gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}
#	define GLInit glad_load 

// GLEW
#elif defined(WITH_GLEW)
#	include <GL/glew.h>
#	include <GLFW/glfw3.h>

int glew_load()
{
	printf("Using glew.\n");
	return !glewInit();
}
#	define GLInit glew_load 

#endif 



#include "flower.h"




#define USAGE_STR "Usage: %s [-m map_size] [-r path_range] \n"

struct T
{ int tag; union { float x; int n; }; };

inline void print(char* msg)
{
	printf("%s\n", msg);
}



int main(int argc, char *argv[])
{
	struct T dog;
	dog.tag = 10;
	dog.x = 102.20;
		printf("%f, %d\n", dog.x, dog.tag);

	printf("Matryoshka. Version: %d.%d\n", Matryoshka_VERSION_MAJOR, Matryoshka_VERSION_MINOR);
	int flags, opt;
	int range = 3, map_size = 12;

	while ((opt = getopt(argc, argv, "s:r:")) != -1)
	{
		switch (opt)
		{
			case 's':
				if(optarg == NULL) goto usage;
				map_size = atoi(optarg);
				break;
			case 'r':
				if(optarg == NULL) goto usage;
				range = atoi(optarg);
				break;
			default:
				usage:
				fprintf(stderr, USAGE_STR, argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	printf("map_size = %d; range = %d;\n", map_size, range);

	#ifdef USE_MYMATH
	 	const double outputValue = average_ii(map_size, range);
		printf("%f\n", outputValue);
	#else
		printf("AlgFunctions not specified.\n");
	#endif

    #ifdef USE_MYMATH
        #define size 8
        int arr[size] = {1, 2, 4, 5, 6, 7, 12, 23};
        double a = average(arr, size);
        printf("%f\n", a);
    #else
        printf("AlgFunctions not specified.\n");
    #endif

    flower_t red_flower;
    flower_init(&red_flower);
    flower_print(&red_flower);

    flower_t another_red_flower;
    flower_init(&another_red_flower);
    flower_print(&another_red_flower);

	if(!glfwInit())
	{
		printf("failed");
		return -1;	
	}
	
	GLFWwindow* win = glfwCreateWindow(1000, 600, "awesome", NULL, NULL);
	if(!win) return -1;

	glfwMakeContextCurrent(win);
	
	if(!GLInit())
	{
		return -1;
	}
	
	
	while (!glfwWindowShouldClose(win))
	{
	 	const double outputValue = average_ii(map_size, range);
		
/*		printf("%f\n", outputValue);*/
	}
	

	exit(EXIT_SUCCESS);
}
