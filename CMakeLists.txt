# CMAKE 要求版本
cmake_minimum_required(VERSION 3.1)

# 项目名称
project(interview-cpp)

# 编译标准
set(CMAKE_CXX_STANDARD 11)

set(BOOST_ROOT "/usr/local/Cellar/boost")
#添加头文件搜索路径
include_directories(/usr/local/Cellar/boost/1.67/include)
#添加库文件搜索路径
link_directories(/usr/local/Cellar/boost/1.67/lib)

add_subdirectory(JSON)
add_subdirectory(Recipes)
add_subdirectory(Concurrent)

# 源文件
set(SRC_FILE main.cpp)

# 添加可执行文件
add_executable(TestProject ${SRC_FILE})

# #### #### 简单结构
# 功能函数实现在其他目录下
# 在 main.cpp 中测试
