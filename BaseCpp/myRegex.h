//
// Created by ning on 2018/9/20.
//

#ifndef INTERVIEW_CPP_REGEX_H
#define INTERVIEW_CPP_REGEX_H


#include <regex>
#include <string>
#include <iostream>

void test1() {
	string pattern("[^c]ei"); // 查找不在字符 c 之后的字符串 ei
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

	std::regex r(pattern, regex::icase); // 构造一个用于查找模式的 regex
	std::smatch results;    //  定义一个对象保存搜索结果

	string test_str = "receipt freind theif receive";

	for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
	     it != end_it; ++it)
		cout << it->str() << endl;
}

void testRegex_main() {
	test1();
}


#endif //INTERVIEW_CPP_REGEX_H
