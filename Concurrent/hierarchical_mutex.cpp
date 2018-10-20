//
// Created by ning on 2018/10/19.
//

#include <iostream>
#include <mutex>
#include "hierarchical_mutex.h"

using namespace Concurrent;

hierarchical_mutex high_level_mutex(10000);
hierarchical_mutex low_level_mutex(5000);

int do_low_level_stuff() {
	std::cout << "low level stuff." << std::endl;
}

int low_level_func() {
	std::lock_guard<hierarchical_mutex> lock(low_level_mutex);
	return do_low_level_stuff();
}

int do_high_level_stuff(int some_param) {
	std::cout << "high level stuff. ";
	std::cout << some_param << std::endl;
}

int high_level_func() {
	std::lock_guard<hierarchical_mutex> lock(high_level_mutex);
	return do_high_level_stuff(low_level_func());
}

void thread_a() {
	high_level_func();
}

hierarchical_mutex other_mutex(100);

void do_other_stuff() {
	std::cout << "other stuff." << std::endl;
}

void other_stuff() {
	high_level_func();
	do_other_stuff();
}

void thread_b() {
	std::lock_guard<hierarchical_mutex> lock(other_mutex);
	other_stuff();
}