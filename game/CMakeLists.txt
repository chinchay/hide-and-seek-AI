cmake_minimum_required(VERSION 3.0)
project(hideseek)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(pybind11)

# Add the source files for your project
set(SOURCES
	game.cpp
	scenario.cpp
	tile.cpp
	fixedTile.cpp
	movableTile.cpp
	agent.cpp
	hider.cpp
	seeker.cpp
	cube.cpp
	ramp.cpp
	group.cpp
)

# Add the header files for your project
set(HEADERS
	game.h
	scenario.h
	tile.h
	fixedTile.h
	movableTile.h
	agent.h
	hider.h
	seeker.h
	cube.h
	ramp.h
	group.h
)

pybind11_add_module(hideseek pywrap.cpp ${SOURCES} ${HEADERS})

# add_library(hideseek ${SOURCES} ${HEADERS})

# Create an executable target for your project
# add_executable(hideseek ${SOURCES} ${HEADERS})

# Add compiler flags
target_compile_options(hideseek PRIVATE -c -std=c++11 -g)


