cmake_minimum_required(VERSION 3.15)
project(engine)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL)

file(GLOB SRC
		src/*.cpp
		src/application/*.cpp
		src/graphics/*.cpp
		modules/glad/src/glad.c
		)

#инклюды
include_directories(modules/glfw-3.3.2/include
		modules/glad/include
		include
		modules/glm/glm)


#Сабмодуль
add_subdirectory(modules/glfw-3.3.2)

#твой ебучий таргет, 1й параметр, 2й - исходники
add_executable(engine
		 ${SRC})

#линковка блядских либ к твоему ссаному таргету
target_link_libraries(engine

		glfw
	)
