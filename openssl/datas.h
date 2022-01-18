#ifndef DATAS_H
#define DATAS_H
#include <string>
#include <random>
// 随机产生指定长度的字符串
// @param: int            字符串长度
// @ret: 返回             字符串
std::string strRand(int length) {			
    char tmp;							
    std::string buffer;						

    std::random_device rd;					// 产生一个 std::random_device 对象 rd
    std::default_random_engine random(rd());	// 用 rd 初始化一个随机数发生器 random
    char ch[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        tmp = random() % (sizeof(ch)-1);
        buffer += ch[tmp];
    }
    return buffer;
}

#endif //DATAS_H