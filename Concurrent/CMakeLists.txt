cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

add_executable(thread_test test.cpp)

add_library(thread thread_test.h hierarchical_mutex.cpp hierarchical_mutex.h WaitTime.h Atomic.h DataStructure.h DataStructureNoLock.h threadPool.h interrupt_thread.h)