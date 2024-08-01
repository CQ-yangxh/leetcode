using namespace std;
// fib: 0 1 1 2 3 5 8 
class Solution {
public:
    int fib(int n) {
        int n0 = 0;
        int n1 = 1;
        int res;
        if(n == 0) return 0;
        if(n == 1) return 1;
        for(int i = 2; i <= n; i++){
            res = n0 + n1;
            n0 = n1;
            n1 = res;
        }
        return res;
    }
};

int main(){
    int n = 2;
    Solution sol;
    int res = sol.fib(n);
    return 0;
}