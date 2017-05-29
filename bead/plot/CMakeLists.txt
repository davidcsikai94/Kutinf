cmake_minimum_required (VERSION 2.8.11)

project(Plots LANGUAGES NONE)


find_package (Gnuplot REQUIRED)

add_custom_command(COMMAND ${GNUPLOT_EXECUTABLE} ${PROJECT_SOURCE_DIR}/script/gp.plt

                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}

                   OUTPUT ${CMAKE_BINARY_DIR}/en.png

                   DEPENDS ${PROJECT_SOURCE_DIR}/script/gp.plt data

                   COMMENT "Generating plot")



add_custom_target(plot DEPENDS ${CMAKE_BINARY_DIR}/en.png)