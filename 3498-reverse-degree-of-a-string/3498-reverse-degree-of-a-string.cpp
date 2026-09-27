class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            int value=26-(s[i]-'a');
            int index=i+1;
            count+=value*index;
        }
        return count;
    }
};