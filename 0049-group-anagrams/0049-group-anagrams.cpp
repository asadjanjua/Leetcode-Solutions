class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // HashMap
        // Key   = Sorted string
        // Value = Vector of original anagrams
        unordered_map<string,vector<string>> mp;
        // Traverse every string
        for(int i=0;i<strs.size();i++){
            // Copy current string
            // Example: "eat"
            string key=strs[i];
            // Sort copied string
            // "eat" -> "aet"
            // "tea" -> "aet"
            // "ate" -> "aet"
            sort(key.begin(),key.end());
            // If key doesn't exist, create it
            // Otherwise append to existing group
            // mp["aet"] -> {"eat","tea","ate"}
            mp[key].push_back(strs[i]);
        }
        // Final answer
        vector<vector<string>> ans;
        // Traverse HashMap
        for(auto i=mp.begin();i!=mp.end();i++){
            // i->first  = Sorted key
            // Example: "aet"
            // i->second = Vector of anagrams
            // Example: {"eat","tea","ate"}
            // Store group into answer
            ans.push_back(i->second);
        }
        // Return grouped anagrams
        return ans;
    }
};