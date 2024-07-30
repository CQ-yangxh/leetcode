/*
54. 替换数字（第八期模拟笔试）
题目描述
给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
输入描述
输入一个字符串 s,s 仅包含小写字母和数字字符。
输出描述
打印一个新的字符串，其中每个数字字符都被替换为了number
输入示例
a1b2c3
输出示例
anumberbnumbercnumber
*/
#include <string>
#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count = 0;
    int oldIndex = s.size() - 1;
    for(int i = 0; i < s.size(); i++)
        if(s[i] >= '0' && s[i] <= '9')
            count++;
    s.resize(s.size() + count * 5);
    int newIndex = s.size() - 1;
    while(oldIndex >= 0){
        if(s[oldIndex] >= '0' && s[oldIndex] <= '9'){
            s[newIndex--] = 'r';
            s[newIndex--] = 'e';
            s[newIndex--] = 'b';
            s[newIndex--] = 'm';
            s[newIndex--] = 'u';
            s[newIndex--] = 'n';
        }
        else s[newIndex--] = s[oldIndex];
        oldIndex--;
    }
    cout << s;
    return 0;
}