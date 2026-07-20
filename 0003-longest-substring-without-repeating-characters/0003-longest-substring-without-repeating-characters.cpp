class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        // Stores the last index of each ASCII character
        int hash[256];

        // Initialize all values to -1
        for (int i = 0; i < 256; i++) {
            hash[i] = -1;
        }

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {

            // If character already exists in current window
            if (hash[s[right]] != -1) {
                left = max(left, hash[s[right]] + 1);
            }

            // Update last occurrence of current character
            hash[s[right]] = right;

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};