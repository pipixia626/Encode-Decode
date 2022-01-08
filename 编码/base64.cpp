#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<bitset>

//初始化
const std::map<int, char>init(const std::vector<char>init_strs) 
{
	std::map<int, char>index;
	for (int i = 0; i < 64; ++i) {
		index[i] = init_strs[i];
	}
    return index;
}


//拆分字符串加密
std::string getBase64(const std::map<int, char>index, std::string strs) {

    std::string res = "";//结果
    int padding = 0;//要填充的数目
    int len = strs.length();

    // 拆分 将strs切分成三个一组(24)，
    int  size = len/3;
    if (len % 3 != 0) {
        ++size;
        padding += 3-len % 3;
    }
    std::vector<std::vector<char>>str(size, std::vector<char>(3));
    //填充  不够的用“=”填充

    int j = 0;
    for (int i = 0; i < len + padding; ++j) {
        for (int k = 0; k < 3; ++k) {
            if (i < len) {
                str[j][k] = strs[i++];
            }
            else {
                str[j][k] = '=';
                i++;
            }
        }
    }
    //分段加密

    //转换
    for (int i = 0; i < size; ++i) {
        std::string temp_res = "";//截获的一个24位字符串
        std::string temp_str[4] = {"00","00","00","00"};//“00”+6位拆分的字符串->8位字符串

        //将三个字符合成一个24位的二进制字符串
        for (int j = 0; j < 3; ++j) {
            std::bitset<8>bit_num((int)(str[i][j]));//将char 的ASCII码转成8位的二进制表示
            temp_res += bit_num.to_string();//将二进制转成字符串
        }
        //将24位字符串拆分成4个6位，每个前面加"00"
        for (int j = 0; j < 4; ++j) {
            temp_str[j] += temp_res.substr(j * 5 + j,6);//获取6位字符串
            int str_num = std::stoi(temp_str[j],nullptr,2);//转成数字
            res += index.at(str_num);//获取索引
        }

    }
    return res;
    
}

int main() {
    const std::vector<char>init_strs{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
            'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
            'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
            'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
            'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
            'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
            'w', 'x', 'y', 'z', '0', '1', '2', '3',
            '4', '5', '6', '7', '8', '9', '+', '/' };

    auto index = init(init_strs);
    std::string strs = "";
    std::cin >> strs;
    std::cout << getBase64(index, strs) << std::endl;
    return 0;
}


