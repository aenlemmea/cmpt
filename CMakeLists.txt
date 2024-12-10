cmake_minimum_required(VERSION 3.28)
project(cmpt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20 CACHE STRING "The CPP standard in use")
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_definitions(-DDEBUG)

list(APPEND SOURCE_FILES	src/main.cpp
							src/execf.cc
							src/fetchers/one.cc
							src/fetchers/contest.cc
							src/config/config.cc
						)

add_executable(cry ${SOURCE_FILES})
target_include_directories(cry PUBLIC include/)
target_include_directories(cry PRIVATE include/internal)
target_include_directories(cry PRIVATE include/crow_include/)

set(SUBMODULES_LIST
	"${PROJECT_SOURCE_DIR}/lib/Crow/"
	"${PROJECT_SOURCE_DIR}/lib/args/"
)
set(MISSING_SUBMODULES FALSE)

find_package(Git QUIET)

if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
	option(GIT_SUBMODULE "Check submodules during build" ON)
	if (GIT_SUBMODULE)
		message(STATUS "Submodule Update")
		execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
						WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
						RESULT_VARIABLE GIT_SUBMOD_RESULT)
		if (NOT GIT_SUBMOD_RESULT EQUAL "0")
			message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
			endif()
	endif()
endif()

foreach(SUBMODULE ${SUBMODULES_LIST})
	if (NOT EXISTS ${SUBMODULE})
		message(WARNING "Submodule not found: ${SUBMODULE}")
		set(MISSING_SUBMODULES TRUE)
	endif()
endforeach()

if (MISSING_SUBMODULES)
	message(FATAL_ERROR "The submodule were not downloaded! GIT_SUBMODULE was turned off or failed. Please update the submodules and try again.")
endif()
