class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if ((m + n - 1) % 2 != 0)
            return false;
        vector<vector<set<int>>> dp(m, vector<set<int>>(n));
        if (grid[0][0] == '(')
            dp[0][0].insert(1);
        else
            return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;
                set<int> prev;
                if (i > 0) {
                    prev.insert(dp[i - 1][j].begin(),
                                dp[i - 1][j].end());
                }
                if (j > 0) {
                    prev.insert(dp[i][j - 1].begin(),
                                dp[i][j - 1].end());
                }
                for (int balance : prev) {
                    int newBalance;
                    if (grid[i][j] == '(')
                        newBalance = balance + 1;
                    else
                        newBalance = balance - 1;
                    if (newBalance >= 0)
                        dp[i][j].insert(newBalance);
                }
            }
        }
        return dp[m - 1][n - 1].count(0) > 0;
    }
};