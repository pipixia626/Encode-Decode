#ifndef RC4_H
#define RC4_H

#include<iostream>
class RC4 {
public:
	RC4() {};
	RC4(unsigned char* data, int keylen) {};
	~RC4() {};
	//初始化
	void init();
	//转化
	void transform();
	//生成密钥流
	void keyflow();
	//加密
	void encrypt();
	//解密
	void decrypt();
	void showtext();
private:
	unsigned char S[256] = {};
	unsigned char T[256] = {};
	unsigned char flow[256] = {};
	unsigned char de_data[256] = {};//密文
	unsigned char en_data[256] = {};//明文
	int keylen = 0;
	unsigned char key_[256] = {};//密钥流
};

#endif // RC4_H
