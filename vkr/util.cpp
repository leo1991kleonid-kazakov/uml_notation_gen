#include "util.h"
#include <string>

bool quiet = false;

std::string replaceStr(
		std::string subject,
		const std::string& search,
		const std::string& replace) {
	size_t pos = 0;
	while((pos = subject.find(search, pos)) != std::string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}
