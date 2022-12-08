cmake_minimum_required(VERSION 3.10)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -Wcast-qual -Wmissing-declarations -Wmaybe-uninitialized")
set(CMAKE_C_FLAGS_DEBUG "-g -Werror -O0")
set(CMAKE_C_FLAGS_RELEASE "")

# generate the compile_commands for vscode / clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# set the project name
project(imu)


set(SOURCES
    src/libimu/imu_algebra.c
    src/libimu/imu_math.c
    src/libimu/imu_utils.c
    src/libimu/imu.c
)

# add the executable
add_library(imu SHARED ${SOURCES})
add_executable(demo src/demo.c ${SOURCES})

target_link_libraries(imu -lm)
target_link_libraries(demo -lglfw -lGL -lGLU -lglut -lm -lpthread)

install(TARGETS imu DESTINATION lib)
