cmake_minimum_required(VERSION 3.15)
project(engine)

macro(add_msvc_pch pch_header pch_source sources)
	if (MSVC)
		GET_FILENAME_COMPONENT(PrecompiledBasename ${pch_header} NAME_WE)
		set(pch_bin "${CMAKE_CURRENT_BINARY_DIR}/${PrecompiledBasename}.pch")
		set(src ${${sources}})

		set_source_files_properties(${pch_source}
				PROPERTIES COMPILE_FLAGS "/Yc\"${pch_header}\" /Fp\"${pch_bin}\""
				OBJECT_OUTPUTS "${pch_bin}")
		set_source_files_properties(${src}
				PROPERTIES COMPILE_FLAGS "/Yu\"${pch_header}\" /FI\"${pch_header}\" /Fp\"${pch_bin}\""
				OBJECT_DEPENDS "${pch_bin}")
		# Add precompiled header to sources
		list(APPEND ${sources} ${pch_source})
	endif ()
endmacro()


set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC
		src/*.cpp
		src/application/*.cpp
		src/graphics/*.cpp
		src/util/*.cpp
		src/imgui/*.cpp
		modules/imgui/*.cpp

		)

#инклюды
include_directories(modules/glfw-3.3.2/include
		modules/glad/include
		modules/glm
		modules/imgui
		include
		src)


#Сабмодуль
add_subdirectory(modules/glfw-3.3.2)

add_msvc_pch("pch.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/pch/pch.cpp" SRC)

list(APPEND SRC modules/glad/src/glad.c)

#твой ебучий таргет, 1й параметр, 2й - исходники
add_executable(engine
		 ${SRC})

#линковка блядских либ к твоему ссаному таргету
target_link_libraries(engine
		glfw
	)


file(COPY res DESTINATION Q:/work/engine/cmake-build-debug)