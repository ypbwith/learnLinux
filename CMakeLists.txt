cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 11)

project (learnLinux)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install/bin)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DAI_DEV=0 -DAO_DEV=0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DELPP_NO_DEFAULT_LOG_FILE")

include_directories(
          src
          src/main
          src/easylogging++
)

link_libraries(
      rt
      dl
#      /root/data/hi3536/Hi3536_SDK_V2.0.2.0/mpp_master/lib/libmpi.a
     
)

add_subdirectory(src/main)
add_subdirectory(src/easylogging++)

# aux_source_directory( ./src
#  DIR_SRCS)

add_executable( learnLinux
                src/main/main.cpp
                src/easylogging++/easylogging++.cc
                ${DIR_SRCS}
              )

ADD_LIBRARY(learnLinuxSo SHARED
            src/easylogging++/easylogging++.cc
            ${DIR_SRCS})

TARGET_LINK_LIBRARIES (learnLinux 
                        main
                        dl m
                      )

