class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        // Step 1: Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        // Dry Run
        // Input:
        // [[2,6],[1,3],[8,10],[15,18]]
        //
        // After Sorting:
        // [[1,3],[2,6],[8,10],[15,18]]

        // Step 2: Add the first interval
        ans.push_back(intervals[0]);

        // Step 3: Traverse remaining intervals
        for (int i = 1; i < intervals.size(); i++)
        {
            // If current interval overlaps with last merged interval
            if (intervals[i][0] <= ans.back()[1])
            {
                // Merge by updating the ending point
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);

                // Dry Run
                // ans = [1,3]
                // current = [2,6]
                // 2 <= 3 → Overlap
                // Merge → [1,6]
            }
            else
            {
                // No overlap, add new interval
                ans.push_back(intervals[i]);

                // Dry Run
                // ans = [1,6]
                // current = [8,10]
                // 8 > 6 → No Overlap
                // ans = [1,6] [8,10]
            }
        }

        return ans;

        /*
        Final Dry Run

        Sorted:
        [1,3] [2,6] [8,10] [15,18]

        ans = [1,3]

        [2,6]  -> Overlap -> [1,6]

        [8,10] -> No Overlap -> Add

        [15,18] -> No Overlap -> Add

        Final Answer:
        [[1,6],[8,10],[15,18]]
        */
    }
};