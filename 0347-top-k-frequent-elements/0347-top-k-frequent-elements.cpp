class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // HashMap Key   = Number Value = Frequency
        unordered_map<int, int> freq;
        // Step 1: Count frequency of every number
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
            /*    Dry Run
            nums = [1,1,1,2,2,3]
            1 -> 3,    2 -> 2,     3 -> 1       */
        }
        // Vector of pairs, pair.first  = Number,  pair.second = Frequency
        vector<pair<int, int>> arr;
        // Step 2: Copy HashMap into vector
        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            arr.push_back({it->first, it->second});
            /* arr (1,3) (2,2) (3,1) */
        }
        // Step 3: Sort by frequency (highest first)
        sort(arr.begin(), arr.end(),
             [](pair<int,int>& a, pair<int,int>& b)
             {
                 // Compare frequency
                 return a.second > b.second;
             });
        /*
        After Sorting
        (1,3)  (2,2)  (3,1)
        */
        vector<int> ans;
        // Step 4: Take first k most frequent numbers
        for (int i = 0; i < k; i++)
        {
            // first = number
            ans.push_back(arr[i].first);
            /*
            k = 2
            i = 0 -> 1
            ans = [1]
            i = 1 -> 2
            ans = [1,2]
            */
        }
        // Return top k frequent numbers
        return ans;
    }
};