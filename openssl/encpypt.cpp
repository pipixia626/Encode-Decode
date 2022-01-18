#include"encpypt.h"

Encpypt::Encpypt(unsigned char* datas, int len)
{
	this->datas = datas;
	this->len = len;
}


//1~256�ֽ�
void Encpypt::RC4_Test()
{
	unsigned char* en_data=new unsigned char [strlen((const char*)keyflow)];
	unsigned char* de_data = new unsigned char[len];
	
	//����
	RC4_KEY key;
	RC4_set_key(&key, strlen((const char*)keyflow), (unsigned char*)keyflow);
	RC4(&key, len, datas, en_data);

	std::cout << "����:" <<std::endl;
	std::cout << en_data << std::endl;
	//����
	RC4_set_key(&key, strlen((const char*)keyflow), (unsigned char*)keyflow);
	RC4(&key, len, en_data, de_data);

	std::cout << "����:" << std::endl;
		for (int i = 0; i < len; ++i) {
			std::cout << de_data[i];
	}
		std::cout<<std::endl;
}
// 8�ֽ�
void Encpypt::DES_Test()
{   
	
	unsigned char* en_data = new unsigned char[(len/8)*8+8];
	unsigned char* de_data = new unsigned char[8];

	// ������Կ
	const_DES_cblock key = "1234567";//ԭʼ��Կ����������Կ
	DES_key_schedule key_sch;//������Կ

	DES_set_key(&key, &key_sch);

	//ECB�ķ�ʽ���ܣ�8�ֽڣ�
	DES_ecb_encrypt((const_DES_cblock*)datas, (DES_cblock*)en_data, &key_sch, 1);//1�Ǽ��ܣ�0�ǽ���
	std::cout << "���ܣ�" << std::endl;
	std::cout << en_data << std::endl;
	//ECB��ʽ����
	DES_ecb_encrypt((const_DES_cblock*)en_data, (DES_cblock*)de_data, &key_sch, 0);
	std::cout << "���ܣ�" << std::endl;
	std::cout << de_data << std::endl;
	
		
}

//8�ֽ�
void Encpypt::DES3_Test()
{
	unsigned char* en_data = new unsigned char[(len / 8) * 8 + 8];
	unsigned char* de_data = new unsigned char[8];


	// ������Կ1
	const_DES_cblock key1 = "1234567";//ԭʼ��Կ����������Կ
	DES_key_schedule key_sch1;//������Կ
	// ������Կ2
	const_DES_cblock key2 = "2345678";//ԭʼ��Կ����������Կ
	DES_key_schedule key_sch2;//������Կ
	// ������Կ3
	const_DES_cblock key3 = "3456789";//ԭʼ��Կ����������Կ
	DES_key_schedule key_sch3;//������Կ

	DES_set_key((DES_cblock*)key1, &key_sch1);

	DES_set_key((DES_cblock*)key2, &key_sch2);
	
	DES_set_key((DES_cblock*)key3, &key_sch3);
	

	
	// ����
	DES_ecb3_encrypt((const_DES_cblock*)datas, (DES_cblock*)en_data, &key_sch1,&key_sch2,&key_sch3,1);//1�Ǽ��ܣ�0�ǽ���
	std::cout << "���ܣ�" << std::endl;
	std::cout << en_data << std::endl;
	// ����
	DES_ecb3_encrypt((const_DES_cblock*)en_data, (DES_cblock*)de_data, &key_sch1, &key_sch2, &key_sch3, 0);//1�Ǽ��ܣ�0�ǽ���
	std::cout << "���ܣ�" << std::endl;
	std::cout << de_data << std::endl;
}

// 16�ֽ�
void Encpypt::AES_Test()
{

	unsigned char* en_data = new unsigned char[(len +1) /16 + 16];
	unsigned char* de_data = new unsigned char[16];
	unsigned char iv[AES_BLOCK_SIZE] = { 0 };

	unsigned char* key = (unsigned char*)"1wradfr4e3fefefad4545454h6thrsf";//32�ֽ� 256λ
	AES_KEY aes;

	AES_set_encrypt_key(key, 256, &aes);
	//����
	AES_ecb_encrypt((unsigned char*)datas, (unsigned char*)en_data,&aes, 1);
	std::cout << "���ܣ�" << std::endl;
	std::cout << en_data << std::endl;
	//����
	AES_set_decrypt_key(key, 256, &aes);
	AES_ecb_encrypt((unsigned char*)en_data, (unsigned char*)de_data, &aes, 0);
	std::cout << "���ܣ�" << std::endl;
	std::cout << de_data << std::endl;

}

int Encpypt::public_key_encrypt(unsigned char* data, int len, unsigned char* key, unsigned char* encrypted)
{
	return 0;
}

int Encpypt::public_key_decrypt(unsigned char* en_data, int len, unsigned char* key, unsigned char* decrypted)
{
	return 0;
}

int Encpypt::private_key_encrypt(unsigned char* data, int len, unsigned char* key, unsigned char* encrypted)
{
	return 0;
}

int Encpypt::private_key_decrypt(unsigned char* en_data, int len, unsigned char* key, unsigned char* decrypted)
{
	return 0;
}

