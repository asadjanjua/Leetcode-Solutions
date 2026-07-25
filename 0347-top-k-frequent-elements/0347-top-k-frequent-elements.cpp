class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        // Count frequency
        // [1,1,1,2,2,3] -> {1:3,2:2,3:1}
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;

        // Store (number,frequency)
        // (1,3) (2,2) (3,1)
        vector<pair<int,int>> arr;
        for(auto i=freq.begin();i!=freq.end();i++)
            arr.push_back({i->first,i->second});

        // Sort by frequency (highest first)
        // (1,3) (2,2) (3,1)
        sort(arr.begin(),arr.end(),[](pair<int,int>& a,pair<int,int>& b){
            return a.second>b.second;
        });

        vector<int> ans;

        // Take first k numbers
        // k=2 -> [1,2]
        for(int i=0;i<k;i++)
            ans.push_back(arr[i].first);

        return ans;
    }
};