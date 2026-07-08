class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        /*
        Dry Run
        nums = [-2, 3, -4]

        Initial
        maxProd = -2
        minProd = -2
        ans = -2
        */

        for (int i = 1; i < nums.size(); i++) {

            /*
            ----------------------------
            i = 1
            nums[i] = 3

            Positive number
            No swap

            maxProd = max(3, 3 * -2)
                    = max(3, -6)
                    = 3

            minProd = min(3, 3 * -2)
                    = min(3, -6)
                    = -6

            ans = max(-2, 3)
                = 3

            Current State
            maxProd = 3
            minProd = -6
            ans = 3
            ----------------------------
            */

            /*
            ----------------------------
            i = 2
            nums[i] = -4

            Negative number
            Swap(maxProd, minProd)

            Before Swap
            maxProd = 3
            minProd = -6

            After Swap
            maxProd = -6
            minProd = 3

            maxProd = max(-4, -4 * -6)
                    = max(-4, 24)
                    = 24

            minProd = min(-4, -4 * 3)
                    = min(-4, -12)
                    = -12

            ans = max(3, 24)
                = 24

            Current State
            maxProd = 24
            minProd = -12
            ans = 24
            ----------------------------
            */

            if (nums[i] < 0)
                swap(maxProd, minProd);

            maxProd = max(nums[i], nums[i] * maxProd);

            minProd = min(nums[i], nums[i] * minProd);

            ans = max(ans, maxProd);
        }

        return ans;
    }
};