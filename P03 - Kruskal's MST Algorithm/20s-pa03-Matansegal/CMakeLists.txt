cmake_minimum_required(VERSION 3.15)
project(20s_pa03_Matansegal)
set (EXE_NAME P03)
#set(CMAKE_CXX_FLAGS "-Wall")

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

set (input01 "inputFiles/graph10low.txt")
set (input02 "inputFiles/graph10dens.txt")
set (input03 "inputFiles/graph50low.txt")
set (input04 "inputFiles/graph50dens.txt")
set (input05 "inputFiles/graph100low.txt")
set (input06 "inputFiles/graph100dens.txt")
set (input07 "inputFiles/graph200low.txt")
set (input08 "inputFiles/graph200dens.txt")
set (input09 "inputFiles/graph500low.txt")
set (input10 "inputFiles/graph500dens.txt")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04 input05 input06 input07 input08 input09 input10)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)

add_executable(${EXE_NAME} main.cpp edge.h utilities.h utilities.cpp disjointList.h disjointListIndex.cpp disjointListIndex.h index.cpp index.h disjointTree.h disjointTreeIndex.cpp disjointTreeIndex.h preprocess.cpp preprocess.h)