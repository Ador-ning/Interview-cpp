cmake_minimum_required(VERSION 3.10)

project(Recipes)

set(CMAKE_CXX_STANDARD 11)

add_library(thread_src Except.h Except.cpp Atomic.h BlockingQueue.h Mutex.h Thread.h Thread.cpp ThreadPool.h ThreadPool.cpp Condition.h ThreadLocal.h ThreadLocalSingleton.h Callback.h BoundedBlockingQueue.h)