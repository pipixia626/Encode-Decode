#include"base64.h"
#include"datas.h"
#include"encpypt.h"
#include"validation.h"
int main() {
	/*std::cout << "Base64:" << std::endl;
	std::string in = "nihaohelloworld";
	Base64 B;
	char* base64_out = B.Base64Encode(in.c_str(), in.length());
	std::cout << "base64_out:" << base64_out << std::endl;

	std::string base64_in = base64_out;
	char* str_in = B.Base64Decode(base64_in.c_str(), base64_in.length());
	std::cout << "str_in:" << str_in << std::endl;*/



	/*std::string str = strRand(16);
	unsigned char* datas = (unsigned char*)str.c_str();
	std::cout << "数据：" << std::endl;
	std::cout << datas << std::endl;
	Encpypt *E=new Encpypt(datas,16);

	std::cout << "对称加密" << std::endl;
	std::cout << "RC4" << std::endl;
	E->RC4_Test();
	std::cout << "DES" << std::endl;
	E->DES_Test();
	std::cout << "DES3" << std::endl;
	E->DES3_Test();
	std::cout << "AES" << std::endl;
	E->AES_Test();
	std::cout << "非对称加密" << std::endl;
	std::cout << "RSA" << std::endl;*/

	
	Validation V;
	V.MD5_Test();
	V.SHA1_Test();
	return 0;



}