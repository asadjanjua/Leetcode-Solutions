class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Store minimum length
        int ans = INT_MAX;
        // Current window sum
        int sum = 0;
        // Left pointer
        int left = 0;
        // Expand window
        for(int right=0; right<nums.size(); right++){
            // Add new element
            sum += nums[right];
            // Shrink window while sum >= target
            while(sum >= target){
                // Update minimum length
                ans = min(ans, right-left+1);
                // Remove left element
                sum -= nums[left];
                // Move left pointer
                left++;
            }
        }
        // No valid subarray found
        if(ans == INT_MAX)
            return 0;

        return ans;
    }
};

/*
Dry Run

target = 7
nums = [2,3,1,2,4,3]

right=0
Window=[2]
sum=2

right=1
Window=[2,3]
sum=5

right=2
Window=[2,3,1]
sum=6

right=3
Window=[2,3,1,2]
sum=8 >=7
ans=4
Remove 2
Window=[3,1,2]
sum=6

right=4
Window=[3,1,2,4]
sum=10 >=7
ans=4
Remove 3
Window=[1,2,4]
sum=7 >=7
ans=3
Remove 1
Window=[2,4]
sum=6

right=5
Window=[2,4,3]
sum=9 >=7
ans=3
Remove 2
Window=[4,3]
sum=7 >=7
ans=2
Remove 4
Window=[3]
sum=3

Final Answer = 2
Subarray = [4,3]
*/