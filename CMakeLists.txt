cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 11)

project (learnLinux)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install/bin)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DELPP_NO_DEFAULT_LOG_FILE")

find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "version: ${OpenCV_VERSION}")
message(STATUS "libraries: ${OpenCV_LIBS}")
message(STATUS "include path: ${OpenCV_INCLUDE_DIRS}")

find_package(OpenMP)
if(OPENMP_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    if(MSVC90 OR MSVC10)
        if(MSVC90)
            set(OPENMP_DLL VCOMP90)
        elseif(MSVC10)
            set(OPENMP_DLL VCOMP100)
        endif(MSVC90)
        set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} /DELAYLOAD:${OPENMP_DLL}D.dll")
        set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DELAYLOAD:${OPENMP_DLL}.dll")
    endif(MSVC)
else(OPENMP_FOUND)
    message (STATUS "OpenMP not found")
endif()

include_directories(
          src
          src/main
          src/easylogging++
          src/opencv
          lib/libopencv/include
          lib/libopencv/include/opencv4
          lib/libopencv/include/opencv4/opencv2
)

link_libraries(
      rt
      dl
      ${CMAKE_HOME_DIRECTORY}/lib/libopencv/libopencv_core.so
      ${CMAKE_HOME_DIRECTORY}/lib/libopencv/libopencv_highgui.so
      ${CMAKE_HOME_DIRECTORY}/lib/libopencv/libopencv_imgproc.so
#      /root/data/hi3536/Hi3536_SDK_V2.0.2.0/mpp_master/lib/libmpi.a
)

add_subdirectory(src/main)
add_subdirectory(src/easylogging++)
add_subdirectory(src/opencv)

# aux_source_directory( ./src
#  DIR_SRCS)

add_executable( learnLinux
                src/main/main.cpp
                src/easylogging++/easylogging++.cc
                src/opencv/videoProcess.cpp
                ${DIR_SRCS}
              )

ADD_LIBRARY(learnLinuxSo SHARED
            src/easylogging++/easylogging++.cc
            src/opencv/videoProcess.cpp
            ${DIR_SRCS})

TARGET_LINK_LIBRARIES (learnLinux 
                        main
                        videoProcess
                        dl m
                      )

