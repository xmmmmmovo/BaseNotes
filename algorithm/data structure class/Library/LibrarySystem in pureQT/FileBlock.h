#pragma once
/**
文件加密
*/
#include <string>

using namespace std;

/**
简单的加密系统
乘法加密算法
比较容易破解与找规律
*/
string simpleEncoding(string inputText, int code) {
    string encodeText;
    char *str;
    encodeText.append(ltoa(code, str, 0)); // 添加密码
    for each (char ch in inputText) {
        ch *= code;
        encodeText.push_back(ch);
    }
    return encodeText;
}

string simpleUnEncoding(string inputText, int code) {
    string unencodingcode;

}
