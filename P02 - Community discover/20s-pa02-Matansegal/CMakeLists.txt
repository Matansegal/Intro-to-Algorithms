cmake_minimum_required(VERSION 3.15)
project(20s_pa02_Matansegal)
set (EXE_NAME graphs)
#set(CMAKE_CXX_FLAGS "-Wall")

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

set (input01 "file.txt")
set (input02 "football.txt")
set (input03 "")
set (input04 "")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)

add_executable(${EXE_NAME} main.cpp graph.h utilities.cpp utilities.h graphNode.h edge.h)