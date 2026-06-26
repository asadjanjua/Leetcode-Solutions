class Solution {
public:
    int search(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size();i++){
        //    if(nums[i]==target)
        //    return i;
        // }
        // return -1;
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if (nums[mid]==target)
            {
                return mid;
            }
            else if (target<=nums[mid])
            {
                right=mid-1;
            }
            else {
                left=mid+1;
            }

        }
        return -1;
    }
};