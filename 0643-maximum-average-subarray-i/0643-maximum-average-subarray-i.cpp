class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int currentsum = 0;
        // First window
        // nums = [1,12,-5,-6,50,3], k = 4
        // Window = [1,12,-5,-6]
        // currentsum = 1+12-5-6 = 2
        for(int i=0;i<k;i++){
            currentsum += nums[i];
        }
        // First window is the maximum initially
        int maxsum = currentsum;
        // Slide the window
        for(int i=k;i<nums.size();i++){
            // Add incoming element
            // i=4 -> +50
            currentsum += nums[i];
            // Remove outgoing element
            // i-k=0 -> -1
            // New window = [12,-5,-6,50]
            // currentsum = 2+50-1 = 51
            currentsum -= nums[i-k];
            // Update maximum sum
            maxsum = max(maxsum, currentsum);
        }
        // Maximum average
        return (double)maxsum / k;
    }
};