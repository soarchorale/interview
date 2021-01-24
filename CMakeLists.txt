cmake_minimum_required (VERSION 3.5)
project (interview)

#head file path
INCLUDE_DIRECTORIES(
include
)
#source directory
aux_source_directory(
src DIR_SRCS
)

#add executable file
add_executable(complexAdd ${DIR_SRCS})

#include(gTest)