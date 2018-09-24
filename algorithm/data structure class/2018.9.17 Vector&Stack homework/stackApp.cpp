/*
没有啥能力，只能做一个简单的括号适配了
*/

#include "stack.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

bool match(string input){
    Stack<char> stack;
    for(int i = 0;i < input.length();i++)
    {
        char buffer = input[i];
        switch(buffer){
            case ')':
                if ((!stack.empty()) && (stack.pop() == '('))
                {
                    break;
                }else
                {
                    return false;
                }
            
            case ']':
                if (!stack.empty() && stack.pop() == '[')
                {
                    break;
                }else
                {
                    return false;
                }

            case '}':
                if (!stack.empty() && stack.pop() == '{')
                {
                    break;
                }else
                {
                    return false;
                }

            default:
                stack.push(buffer);
                break;
        }
    }

    return stack.empty();
}

void printBool(bool prt){
    if(prt){
        cout << "true\n";
    }else{
        cout << "false\n";
    }
}

int main(int argc, char const *argv[])
{
    printBool(match("{()}()[()]"));
    printBool(match("({)}[{]}"));

    system("pause");
    return 0;
}