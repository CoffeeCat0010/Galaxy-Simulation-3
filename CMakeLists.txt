# set the project name and version
project(Galaxy-Simulation-3)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory (Main)
add_subdirectory (Main/System)
set(SOURCES Main/Main.cpp
						Main/System/Logger.cpp							
						Main/System/Logger.h
							)
add_executable (Galaxy_Simulation_3 ${SOURCES})

