class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        /*
        Dry Run

        Input:
        [-1,0,1,2,-1,-4]

        After Sorting:
        [-4,-1,-1,0,1,2]
        */

        int n = nums.size();

        // Step 2: Fix one element
        for (int i = 0; i < n - 2; i++)
        {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            // Step 3: Find remaining two numbers
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    // Triplet found
                    ans.push_back({nums[i], nums[left], nums[right]});

                    /*
                    Example

                    i=-1 left=-1 right=2

                    Sum = -1 + (-1) + 2 = 0

                    Answer:
                    [-1,-1,2]
                    */

                    left++;
                    right--;

                    // Skip duplicate second element
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    // Skip duplicate third element
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }

                // Sum is too small → move left to increase sum
                else if (sum < 0)
                {
                    left++;
                }

                // Sum is too large → move right to decrease sum
                else
                {
                    right--;
                }

                /*
                Small Dry Run

                Sorted Array

                -4 -1 -1 0 1 2

                i=0 (-4)
                L=-1 R=2
                Sum=-3 → left++

                L=-1 R=2
                Sum=-3 → left++

                L=0 R=2
                Sum=-2 → left++

                L=1 R=2
                Sum=-1 → left++

                --------------------

                i=1 (-1)

                L=-1 R=2
                Sum=0 ✓

                Save [-1,-1,2]

                left++, right--

                L=0 R=1
                Sum=0 ✓

                Save [-1,0,1]

                --------------------

                i=2

                nums[2]==nums[1]

                Skip duplicate
                */
            }
        }

        return ans;

        /*
        Final Answer

        [
          [-1,-1,2],
          [-1,0,1]
        ]
        */
    }
};