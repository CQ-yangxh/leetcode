#include <vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int maxlen = 0;;
        // 为右下角，且只包含 1 的正方形的边长最大值。
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    maxlen = max(maxlen, dp[i][j]);
                }
            }
        }
        return maxlen * maxlen;
    }
};

int main(){
    vector<vector<char>> vec = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    Solution sol;
    int res = sol.maximalSquare(vec);
    return 0;
}