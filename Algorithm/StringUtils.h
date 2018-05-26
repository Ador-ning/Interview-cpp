//
// Created by ning on 2018/5/26.
//

#ifndef INTERVIEW_CPP_STRINGUTILS_H
#define INTERVIEW_CPP_STRINGUTILS_H

void Reverse(char *pBegin, char *pEnd) {
	if (pBegin == nullptr || pEnd == nullptr)
		return;

	while (pBegin < pEnd) {
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin++;
		pEnd--;
	}
}

#endif //INTERVIEW_CPP_STRINGUTILS_H
