class Solution {
public:
    vector<string> ans;

    void dfs(string s, int index, int part, string current) {

        // Base Case: Valid IP
        if (part == 4 && index == s.size()) {
            current.pop_back();          // Remove last '.'
            ans.push_back(current);
            return;
        }

        // Invalid Case
        if (part == 4 || index == s.size())
            return;

        // Try 1, 2, and 3 digits
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {

            // Take substring
            string segment = s.substr(index, len);

            // No leading zeros (except "0")
            if (segment.size() > 1 && segment[0] == '0')
                break;

            // Convert string to integer
            int num = stoi(segment);

            // Segment must be between 0 and 255
            if (num <= 255) {

                dfs(
                    s,                          // Original string
                    index + len,               // Move to next position
                    part + 1,                  // One segment completed
                    current + segment + "."    // Add segment with '.'
                );
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {

        dfs(s, 0, 0, "");

        return ans;
    }
};