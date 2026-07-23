class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;  // Next position to place a non-zero

        // Step 1: Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
        }

        /*
        Dry Run

        nums = [0,1,0,3,12]

        i=0 -> 0  -> Skip
        i=1 -> 1  -> nums[0]=1      => [1,1,0,3,12], j=1
        i=2 -> 0  -> Skip
        i=3 -> 3  -> nums[1]=3      => [1,3,0,3,12], j=2
        i=4 -> 12 -> nums[2]=12     => [1,3,12,3,12], j=3

        First 3 positions are correct.
        Remaining positions still contain old values.
        */

        // Step 2: Fill remaining positions with zeros
        while (j < nums.size())
        {
            nums[j] = 0;
            j++;
        }

        /*
        j = 3

        nums[3] = 0  => [1,3,12,0,12]
        nums[4] = 0  => [1,3,12,0,0]

        Final Answer

        [1,3,12,0,0]
        */
    }
};

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {

//         int j = 0;   // Position where next non-zero should go

//         for (int i = 0; i < nums.size(); i++)
//         {
//             // If current element is non-zero
//             if (nums[i] != 0)
//             {
//                 // Place it at index j
//                 swap(nums[i], nums[j]);

//                 // Move j to next position
//                 j++;
//             }
//         }
//     }
// };