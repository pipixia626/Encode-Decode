#ifndef BASE64_H
#define BASE64_H
#include"source.h"

class Base64 {
private:
public:
	char* Base64Encode(const char* in, int len);//����
	char* Base64Decode(const char* in, int len);//����
};
#endif // BASE64_H