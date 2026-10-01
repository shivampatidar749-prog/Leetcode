class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int index) {

        // Target achieved
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Target became negative or no candidates left
        if (target < 0 || index == candidates.size()) {
            return;
        }

        // Option 1: Choose candidates[index]
        temp.push_back(candidates[index]);

        // Same index because we can use the number unlimited times
        solve(candidates, target - candidates[index], index);

        // Backtrack
        temp.pop_back();

        // Option 2: Don't choose candidates[index]
        solve(candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
};