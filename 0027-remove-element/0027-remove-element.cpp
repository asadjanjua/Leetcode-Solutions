class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // j points to next position to write
        int j = 0;
        // i reads every element
        for(int i=0;i<nums.size();i++){
            // Keep only elements not equal to val
            if(nums[i] != val){
                // Copy valid element
                nums[j] = nums[i];
                // Move write pointer
                j++;
            }
        }
        // j = new length
        return j;
    }
};