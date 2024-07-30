#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    string s;
    int k;
    cin >> k >> s;
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
    return 0;
}