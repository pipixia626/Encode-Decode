#ifndef VALIDATION_H
#define VALIDATION_H
#include"source.h"

class Validation {
public:
	void MD5_Test();
	void SHA1_Test();
	void printHex(const unsigned char* buf, int len);
};
#endif // !VALIDATION_H
