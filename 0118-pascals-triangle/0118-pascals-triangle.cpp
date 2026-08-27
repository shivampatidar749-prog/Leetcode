class Solution {
public:
    vector<vector<int>> generate(int nums) {
        vector<vector<int>> ans;

        for (int i = 0; i < nums; i++) {
            vector<int> row(i + 1, 1);

            // Calculate middle elements
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans.push_back(row);
        }

        return ans;
    }
};
