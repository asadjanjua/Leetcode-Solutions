class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //  Brute Force Approach (O(n^2))
        /*
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        */

        //  Optimal Approach (Hash Map - O(n))
        unordered_map<int, int> mp; // value → index

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            if (mp.count(need)) {
                return {mp[need], i};
            }

            mp[nums[i]] = i;
        }

        return {}; // safety (problem guarantees solution)
    }
};