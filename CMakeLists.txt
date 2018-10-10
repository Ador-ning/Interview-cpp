# CMAKE 要求版本
cmake_minimum_required(VERSION 3.1)

# 项目名称
project(interview-cpp)

# 编译标准
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(JSON)
add_subdirectory(Recipes)

# 源文件
set(SRC_FILE main.cpp)

# 添加可执行文件
add_executable(TestProject ${SRC_FILE})

# #### #### 简单结构
# 功能函数实现在其他目录下
# 在 main.cpp 中测试
