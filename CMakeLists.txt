# CMAKE 要求版本
cmake_minimum_required(VERSION 3.1)

# 项目名称
project(interview-cpp)

# 编译标准
set(CMAKE_CXX_STANDARD 17)

# set(BOOST_ROOT "/usr/local/Cellar/boost/1.67.0_1")
# find_package(Boost 1.67.0 REQUIRED COMPONENTS system)
# include_directories(${Boost_INCLUDE_DIRS})
# link_directories(${Boost_LIBRARY_DIRS})

add_subdirectory(JSON)
add_subdirectory(Recipes)
add_subdirectory(Concurrent)
add_subdirectory(Http)

# 源文件
set(SRC_FILE main.cpp)

# 添加可执行文件
add_executable(TestProject ${SRC_FILE})

# #### #### 简单结构
# 功能函数实现在其他目录下
# 在 main.cpp 中测试
