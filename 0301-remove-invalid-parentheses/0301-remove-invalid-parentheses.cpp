class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char ch : s) {

            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {
                balance--;
            }

            if (balance < 0) {
                return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            int n = q.size();

            while (n--) {

                string current = q.front();
                q.pop();

                // Check whether current string is valid
                if (isValid(current)) {
                    ans.push_back(current);
                    found = true;
                }

                // If valid strings are found,
                // don't remove more characters.
                if (found) {
                    continue;
                }

                // Try removing every parenthesis
                for (int i = 0; i < current.length(); i++) {

                    if (current[i] != '(' && current[i] != ')') {
                        continue;
                    }

                    string next = current.substr(0, i)
                                + current.substr(i + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // This guarantees minimum removals
            if (found) {
                break;
            }
        }

        return ans;
    }
};