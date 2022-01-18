#ifndef DATAS_H
#define DATAS_H
#include <string>
#include <random>
// �������ָ�����ȵ��ַ���
// @param: int            �ַ�������
// @ret: ����             �ַ���
std::string strRand(int length) {			
    char tmp;							
    std::string buffer;						

    std::random_device rd;					// ����һ�� std::random_device ���� rd
    std::default_random_engine random(rd());	// �� rd ��ʼ��һ������������� random
    char ch[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        tmp = random() % (sizeof(ch)-1);
        buffer += ch[tmp];
    }
    return buffer;
}

#endif //DATAS_H