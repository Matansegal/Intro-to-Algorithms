cmake_minimum_required(VERSION 3.15)
project(20S-3353-PA01)
set (EXE_NAME MemoryManager)
set(CMAKE_CXX_FLAGS "-Wall")

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

set (input01 "")
set (input02 "")
set (input03 "")
set (input04 "")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)

add_executable(${EXE_NAME} main.cpp AloMemory.h AllocatorSingleton.cpp AllocatorSingleton.h Allocator.cpp Allocator.h BookKeepingNode.cpp BookKeepingNode.h global.h global.cpp
        MyFit.cpp MyFit.h FirstFit.cpp FirstFit.h BestFit.cpp BestFit.h test1.cpp test1.h test2.cpp test2.h test3.cpp test3.h
        SentiAnalysis/SentAnal.cpp SentiAnalysis/SentAnal.h SentiAnalysis/dsstring.h SentiAnalysis/dsstring.cpp SentiAnalysis/dsvector.h SentiAnalysis/porter2_stemmer.h SentiAnalysis/porter2_stemmer.cpp
        SentiAnalysis/readingfiles.h SentiAnalysis/readingfiles.cpp SentiAnalysis/readTest.h SentiAnalysis/readTest.cpp SentiAnalysis/word.h SentiAnalysis/word.cpp SentiAnalysis/WordsFilter.h SentiAnalysis/WordsFilter.cpp
        SentiAnalysis/util/hash.h SentiAnalysis/util/string_view.h myAllocator.h test4.cpp test4.h)
