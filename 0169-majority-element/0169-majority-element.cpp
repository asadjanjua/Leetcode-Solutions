// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int> freq;
//         for(int i=0;i<nums.size();i++)
//         {
//            freq[nums[i]]++;
//            if(freq[nums[i]]>nums.size()/2)
//             return nums[i];
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {

            if (count == 0)
                candidate = nums[i];

            if (nums[i] == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};