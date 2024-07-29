#include <vector>
using namespace std;
class Solution {
public:
    /*
    -> -> -> i = 0
    |  --  | i = 1
    <- <- <- i = 2
    j       
    */
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0;
        int loop = n / 2;
        int offset = 1;
        int count = 1;
        int mid = n / 2;
        while (loop--){
            int i = startx;
            int j = starty;
            for(j; j < n - offset; j++){
                res[i][j] = count++;
            }

            for(i; i < n - offset; i++){
                res[i][j] = count++;
            }

            for(j; j > starty; j--){
                res[i][j] = count++;
            }

            for(i; i > startx; i--){
                res[i][j] = count++;
            }

            startx++;
            starty++;

            offset++;
        }

        if (n%2)
            res[mid][mid] = count;

        return res;
    }
};

int main(){
    int n = 3;
    Solution sol;
    vector<vector<int>> res = sol.generateMatrix(n);
    return 0;
}