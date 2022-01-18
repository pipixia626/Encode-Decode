#ifndef ENCPYPT_H
#define ENCPYPT_H
#include"source.h"

class Encpypt {
public:
	Encpypt(unsigned char* datas, int len);
	//对称加密

	// RC4
	void RC4_Test();

	// DES
	void DES_Test();

	// DES3
	void DES3_Test();

	// AES
	void AES_Test();

	//非对称加密
	
	// RSA
	
	/* 公钥加密 */
	int public_key_encrypt(unsigned char* data, int len, unsigned char* key, unsigned char* encrypted);
	/* 公钥解密 */
	int public_key_decrypt(unsigned char* en_data, int len, unsigned char* key, unsigned char* decrypted);
	
	/* 私钥加密 */
	int private_key_encrypt(unsigned char* data, int len, unsigned char* key, unsigned char* encrypted);
	/* 私钥解密 */
	int private_key_decrypt(unsigned char* en_data, int len, unsigned char* key, unsigned char* decrypted);
private:

	unsigned char* keyflow = (unsigned char*)"This is key flow";
	unsigned char* datas;

	int len = 0;
	const int PADDING = RSA_PKCS1_PADDING;
	
};
#endif // !ENCPYPT_H
