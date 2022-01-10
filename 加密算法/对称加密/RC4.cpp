#include"RC4.h"

RC4::RC4(unsigned char* data, int keylen) {
	int i = 0;
	while (data[i] != '\0') {
		de_data[i] = data[i];
		++i;
	}
	this->keylen = keylen;

	for (i = 0; i < keylen; ++i) {
		key_[i] = rand() % 256;
	}
}
void RC4::init(){
	for (int i = 0; i < 256; ++i) {
		S[i] = i;
		T[i] = key_[i % keylen];
	}
}

void RC4::transform()
{
	int i, j = 0;
	for (i; i < 256; ++i) {
		j = (j + S[i] + T[i])%256;
		std::swap(S[i], S[j]);
	}
}

void RC4::keyflow()
{
	int i, j, t, f = 0;
	for (f; f < keylen; ++f) {
		i = (i +f) % 256;
		j = (j + S[i]) % 256;
		std::swap(S[i], S[j]);
		t = (S[i] + S[j]) % 256;
		flow[f] = S[t];
	}

}

void RC4::encrypt()
{
	for (int i = 0; i < keylen; ++i) {
		en_data[i] ^= flow[i];
	}
}

void RC4::decrypt()
{
	for (int i = 0; i < keylen; ++i) {
		en_data[i] ^= flow[i];
		de_data[i] = en_data[i];
	}
}

void RC4::showtext()
{
	std::cout << "����" << std::endl;
	for (int i = 0; i < keylen; ++i) {
		std::cout << de_data[i];
	}
	std::cout<<std::endl;
	std::cout << "����" << std::endl;
	for (int i = 0; i < keylen; ++i) {
		std::cout <<en_data[i];
	}
	std::cout << std::endl;
}

