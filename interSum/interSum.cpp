#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> sum(n+1, 0);
    int cum;
    // [1 2 3 4 5]
    // [0 1 3 6 10 15]
    for(int i = 0; i < n; i++){
        cin >> vec[i];
        cum += vec[i];
        sum[i] = cum;
    }

    int a1, a2;
    while (cin >> a1 >> a2){
        if(a1 == 0) cout << sum[a2];
        else cout << sum[a2] - sum[a1-1];
    }
    return 0;
}