#include "TessException.h"
#include<sstream>

TessException::TessException(int line, const char* file) noexcept : line(line), file(file) {}

const char* TessException::what() const noexcept {
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* TessException::GetType() const noexcept {
	return "Tesseract Exception";
}

int TessException::GetLine() const noexcept {
	return line;
}

const std::string& TessException::GetFile() const noexcept {
	return file;
}

std::string TessException::GetOriginString() const noexcept {
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}
