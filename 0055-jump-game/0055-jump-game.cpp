class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxINt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>maxINt){
                return false;
            }
            maxINt=max(maxINt,i+nums[i]);
        }
        return true;
        
    }
};