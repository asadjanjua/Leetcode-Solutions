class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size())
        return false;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s==t;
    }
    // bool isAnagram(string s, string t) {
    //     if (s.size()!=t.size())
    //     return false;

    //      unordered_map<char,int> freq;

    //      for(int i=0;i<s.size();i++){
    //         freq[s[i]]++;
    //      }
    //      for(int i=0;i<t.size();i++){
    //         if (freq[t[i]]==0)
    //         return false;

    //         freq[t[i]]--;
    //      }
    //      return true;
    // }
};