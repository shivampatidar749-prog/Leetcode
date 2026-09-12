class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int maxWater = 0;

        while (left < right) {

            // Width between the two lines
            int width = right - left;

            // Water height is the smaller line
            int minHeight = min(height[left], height[right]);

            // Calculate current water
            int currentWater = width * minHeight;

            // Update maximum
            if (currentWater > maxWater) {
                maxWater = currentWater;
            }

            // Move the smaller line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};