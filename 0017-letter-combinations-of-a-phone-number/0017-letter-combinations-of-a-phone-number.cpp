class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> ans;
        
        string current = "";
        
        function<void(int)> backtrack = [&](int index) {
            
            // If we have processed all digits
            if (index == digits.size()) {
                ans.push_back(current);
                return;
            }
            
            // Get letters corresponding to current digit
            string letters = mp[digits[index] - '0'];
            
            // Try every letter
            for (char ch : letters) {
                
                current.push_back(ch);
                
                // Move to next digit
                backtrack(index + 1);
                
                // Remove last character (backtrack)
                current.pop_back();
            }
        };
        
        backtrack(0);
        
        return ans;
    }
};