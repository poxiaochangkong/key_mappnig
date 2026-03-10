cmake_minimum_required(VERSION 3.10)

project(key_mapping VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)           # 要求使用C++14标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # 强制要求，不支持则报错
set(CMAKE_CXX_EXTENSIONS OFF)        # 禁用编译器扩展

include_directories(${CMAKE_SOURCE_DIR}/include)
