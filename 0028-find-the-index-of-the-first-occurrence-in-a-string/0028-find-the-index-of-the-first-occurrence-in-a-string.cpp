class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        // Check every possible starting position
        for (int i = 0; i <= n - m; i++) {
            int j = 0;

            // Compare needle with substring starting at i
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // If all characters matched
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};