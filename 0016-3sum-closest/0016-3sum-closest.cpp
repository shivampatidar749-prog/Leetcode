
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // If this sum is closer to target
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                // Exact answer found
                if (sum == target) {
                    return sum;
                }

                // Need a bigger sum
                if (sum < target) {
                    left++;
                }
                // Need a smaller sum
                else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};

