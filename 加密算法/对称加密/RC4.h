#ifndef RC4_H
#define RC4_H

#include<iostream>
class RC4 {
public:
	RC4() {};
	RC4(unsigned char *data,int keylen) {};
	~RC4() {};
	//��ʼ��S,T��
	void init();
	//S���ĳ�ʼ�û�
	void transform();
	//��Կ��������
	void keyflow();
	//����
	void encrypt();
	//����
	void decrypt();
	void showtext();
private:
	unsigned char S[256] = {};
	unsigned char T[256] = {};
	unsigned char flow[256] = {};
	unsigned char de_data[256] = {};//����
	unsigned char en_data[256] = {};//����
	int keylen=0;
	unsigned char key_[256] = {};//��Կ
};

#endif // RC4_H
