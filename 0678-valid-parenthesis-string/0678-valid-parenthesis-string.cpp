class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // '*' can become ')'
                high++;  // '*' can become '('
            }

            // We cannot have negative minimum
            if (low < 0) {
                low = 0;
            }

            // Even maximum is negative -> impossible
            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
};