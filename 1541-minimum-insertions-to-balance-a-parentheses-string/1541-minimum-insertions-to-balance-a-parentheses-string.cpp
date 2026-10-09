
class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            }
            else {
                // If the next character is also ')',
                // we have a complete closing pair.
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    // Insert one ')' to complete the pair.
                    insertions++;
                }

                // Match the closing pair with an opening '('.
                if (open > 0) {
                    open--;
                }
                else {
                    // No opening '(' exists, so insert one.
                    insertions++;
                }
            }
        }

        // Each remaining '(' needs two ')' characters.
        return insertions + open * 2;
    }
};