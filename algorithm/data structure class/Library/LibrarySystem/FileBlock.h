#pragma once
/**
�ļ�����
*/
#include <string>

using namespace std;

/**
�򵥵ļ���ϵͳ
�˷������㷨
�Ƚ������ƽ����ҹ���
*/
string simpleEncoding(string inputText, int code) {
	string encodeText;
	char *str;
	encodeText.append(ltoa(code, str, 0)); // �������
	for each (char ch in inputText) {
		ch *= code;
		encodeText.push_back(ch);
	}
	return encodeText;
}

string simpleUnEncoding(string inputText, int code) {
	string unencodingcode;

}