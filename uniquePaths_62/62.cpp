/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？
*/
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int i = 0;
        int j = 0;
        for(i; i < m; i++) dp[i][0] = 1;
        for(j; j < n; j++) dp[0][j] = 1;
        for(i = 1; i < m; i++){
            for(j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    int m = 3, n = 2;
    Solution sol;
    int res = sol.uniquePaths(m, n);
    return 0;
}