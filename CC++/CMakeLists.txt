cmake_minimum_required(VERSION 3.5)
 
set (CMAKE_CXX_STANDARD 11)

add_compile_options(-std=c++11)

project (cc++)
 
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

include_directories(${OpenCV_INCLUDE_DIRS}
          /root/lib/libopenblas/include/
          /root/lib/libncnn/include/
          /root/lib/libdilb/include/
          ./src
)

link_libraries(
${OpenCV_LIBS}
/root/lib/libncnn/lib/libncnn.a    
/root/lib/libopenblas/lib/libopenblas.a

)

aux_source_directory(./src DIR_SRCS)

add_executable(cc++ ${DIR_SRCS})



