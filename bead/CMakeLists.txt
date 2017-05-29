cmake_minimum_required(VERSION 2.8.11)

project(cmakebead)

set(main_SOURCES main.c)
set(test1_SOURCES test1.c)

add_executable(test1 ${test1_SOURCES})
add_executable(main ${main_SOURCES})

add_custom_target(main_run
  	COMMAND main
  	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  	COMMENT "run generated main in ${CMAKE_CURRENT_SOURCE_DIR}"
  	SOURCES ${main_SOURCES}
)

add_dependencies(test1 main_run)

add_subdirectory( plot )