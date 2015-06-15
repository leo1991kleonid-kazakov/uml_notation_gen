#ifndef UTIL_H_
#define UTIL_H_

#include <string>

extern bool quiet;

#define LOG if (!quiet) std::cout

std::string replaceStr(
		std::string subject,
		const std::string& search,
		const std::string& replace);

#endif /* UTIL_H_ */
