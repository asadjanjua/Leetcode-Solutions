class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<pair<int,int>> arr;
        for(auto i=freq.begin();i!=freq.end();i++){
            arr.push_back({i->first,i->second});
        }
        sort(arr.begin(),arr.end(),[](pair<int,int>&a,pair<int,int>&b)
        {
            return a.second>b.second;
        });
        vector <int> ans;
            for(int i=0;i<k;i++){
                ans.push_back(arr[i].first);
            }
            return ans;
    }
};