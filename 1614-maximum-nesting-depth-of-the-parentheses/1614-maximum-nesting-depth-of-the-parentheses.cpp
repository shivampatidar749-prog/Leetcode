class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int n=s.length();
        int depth=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
                depth++;
                maxi=max(depth,maxi);
            }
            else if(s[i]==')'){
                st.pop();
                depth--;
            }
            else{
                continue;
            }
        }

    return maxi;  
    }
};