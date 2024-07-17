// 两个整数a与b,构造两个正整数x和y满足：1.x mod y = a; 2. y mod x = b
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        cout << a + b << endl;
    }
}