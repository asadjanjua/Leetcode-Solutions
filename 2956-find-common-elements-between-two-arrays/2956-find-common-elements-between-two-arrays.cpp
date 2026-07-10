class Solution 
{
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) 
    {
        int answer1 = 0;
        int answer2 = 0;

        /*
        Example

        nums1 = [4,3,2,3,1]
        nums2 = [2,2,5,2,3,6]

        -------------------------
        Dry Run (answer1)
        -------------------------
        nums1[i]   Found?   answer1
        4          No       0
        3          Yes      1
        2          Yes      2
        3          Yes      3
        1          No       3

        -------------------------
        Dry Run (answer2)
        -------------------------
        nums2[i]   Found?   answer2
        2          Yes      1
        2          Yes      2
        5          No       2
        2          Yes      3
        3          Yes      4
        6          No       4

        Return {3,4}
        */

        // Count indices of nums1 whose value exists in nums2
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    answer1++;
                    break;      // Count this index only once
                }
            }
        }

        // Count indices of nums2 whose value exists in nums1
        for (int i = 0; i < nums2.size(); i++)
        {
            for (int j = 0; j < nums1.size(); j++)
            {
                if (nums2[i] == nums1[j])
                {
                    answer2++;
                    break;      // Count this index only once
                }
            }
        }

        return {answer1, answer2};
    }
};