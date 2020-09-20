cmake_minimum_required(VERSION 3.18)

project(spdlog_demo VERSION 1.0.1)


# 因为spdlog是基于c++11的库
set(CMAKE_CXX_STANDARD 11)

# 指定源文件
set(src_file 
	${CMAKE_CURRENT_SOURCE_DIR}/include/calc.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/calc.cc
)

# 创建可执行程序项目
add_library(spdlog_demo SHARED ${src_file}  )
# 指定头文件路径
target_include_directories(spdlog_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
# 指定lib文件路径
target_link_libraries(	spdlog_demo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


# -------------------------------------------------------------------------------------
# 下面开始引入第三方库
# -------------------------------------------------------------------------------------
# set cmake file'dir： to/path/serial_port/cmake/
# -------------------------------------------------------------------------------------
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

# 引入spdlog2.camake, 
include(spdlog2)	# 填写文件名

# 项目中使用spdlog
target_link_libraries(spdlog_demo PRIVATE spdlog::spdlog)
# -------------------------------------------------------------------------------------








# 指定源文件
set(exam_header_files 
	${CMAKE_CURRENT_SOURCE_DIR}/include/calc.h
	${CMAKE_CURRENT_SOURCE_DIR}/example/main.cpp
)

# 创建可执行程序项目
add_executable(call_lib  ${exam_header_files}  )
# 指定头文件路径
target_include_directories(call_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
# 指定lib文件路径
target_link_libraries(	call_lib PRIVATE spdlog_demo)















# 判断操作系统
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
	
ELSE ()
	MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")


## 判断编译器
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
# using Clang
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
# using GCC
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
# using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
# using Visual Studio C++
endif()


