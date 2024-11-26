# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(MP_LABx)

# Define variables
set(MCU 16F877A)
set(SRC main.c)
set(OUTPUT output.hex)

# Custom build target
add_custom_target(build ALL
    COMMAND xc8 --chip=${MCU} ${SRC} #-o ${OUTPUT} //dont use this,its a bug. deacivated command//
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Building ${OUTPUT} using XC8"
)

