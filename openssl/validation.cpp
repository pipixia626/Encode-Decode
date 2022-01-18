#include"validation.h"
void Validation::printHex(const unsigned char* buf, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%02x", buf[i]);
    }
    printf("\n");
}
//任意字符串 校验 ->输出的散列值为16字节
void Validation::MD5_Test()
{
    const std::string str1 = "niasdkjasjdpajsdanspdnapjsocma;lsmdpoasohasdlkanslkcnaioshcyahscnaposcuays8ahsdkapsocja9usoias";
    const std::string str2 = "niasdkjasjdpajsdanspdnapjsocma;lsmdpoasohasdlkanslkcnaioshcyahscnaposcuays8ahsdkapsocja9usoiab";//最后一个字母不同
    unsigned char md5bigest1[16]={0};
    unsigned char md5bigest2[16] = {0};

    MD5_CTX ctx1;
    MD5_Init(&ctx1);
    for (int i = 0; i < str1.length(); ++i) {
        MD5_Update(&ctx1, (void*)&str1[i], 1);
    }
    MD5_Final(md5bigest1, &ctx1);
    printHex(md5bigest1, 16);

    MD5_CTX ctx2;
    MD5_Init(&ctx2);
    for (int i = 0; i < str2.length(); ++i) {
        MD5_Update(&ctx2, (void*)&str2[i], 1);
    }
    MD5_Final(md5bigest2, &ctx2);
    printHex(md5bigest2, 16);
}
//任意字符串 校验 ->输出的散列值为20字节
void Validation::SHA1_Test()
{
    const std::string str1 = "niasdkjasjdpajsdanspdnapjsocma;lsmdpoasohasdlkanslkcnaioshcyahscnaposcuays8ahsdkapsocja9usoias";
    const std::string str2 = "niasdkjasjdpajsdanspdnapjsocma;lsmdpoasohasdlkanslkcnaioshcyahscnaposcuays8ahsdkapsocja9usoiab";//最后一个字母不同
    unsigned char sha1bigest1[20] = { 0 };
    unsigned char sha1bigest2[20] = { 0 };

    SHA_CTX ctx1;
    SHA1_Init(&ctx1);
    for (int i = 0; i < str1.length(); ++i) {
        SHA1_Update(&ctx1, (void*)&str1[i], 1);
    }
    SHA1_Final(sha1bigest1, &ctx1);
    printHex(sha1bigest1, 20);

    SHA_CTX ctx2;
    SHA1_Init(&ctx2);
    for (int i = 0; i < str1.length(); ++i) {
        SHA1_Update(&ctx2, (void*)&str2[i], 1);
    }
    SHA1_Final(sha1bigest2, &ctx2);
    printHex(sha1bigest2, 20);
}


