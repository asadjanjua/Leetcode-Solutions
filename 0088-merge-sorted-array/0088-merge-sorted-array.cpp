class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        //approch1 copy + sort

        // for (int i=0;i<n;i++){
        //     nums1[m+i]=nums2[i];
        // }
        // sort(nums1.begin(),nums1.end());

        //approch 3 pointers
        
        // i -> Last valid element of nums1
        int i = m - 1;

        // j -> Last element of nums2
        int j = n - 1;

        // k -> Last index of nums1
        int k = m + n - 1;

        /*
        Dry Run 1 (First while only)

        nums1 = [1,2,3,0,0,0]
        nums2 = [2,5,6]

        Step 1: 3 vs 6 -> copy 6
        [1,2,3,0,0,6]

        Step 2: 3 vs 5 -> copy 5
        [1,2,3,0,5,6]

        Step 3: 3 vs 2 -> copy 3
        [1,2,3,3,5,6]

        Step 4: 2 vs 2 -> copy 2
        [1,2,2,3,5,6]

        j = -1

        nums1 elements (1,2) are already
        in correct position.

        Second while NOT executed.
        */

        while (i >= 0 && j >= 0) {

            // Copy larger element at the end
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        /*
        Dry Run 2 (Second while executes)

        nums1 = [4,5,6,0,0,0]
        nums2 = [1,2,3]

        First while

        6>3 -> [4,5,6,0,0,6]
        5>3 -> [4,5,6,0,5,6]
        4>3 -> [4,5,6,4,5,6]

        Now

        i = -1
        j = 2
        k = 2

        nums2 still has:
        [1,2,3]

        Need to copy remaining nums2.
        */

        while (j >= 0) {

            // Copy remaining nums2 elements
            nums1[k] = nums2[j];

            /*
            Iteration 1
            nums1[2]=3
            [4,5,3,4,5,6]

            Iteration 2
            nums1[1]=2
            [4,2,3,4,5,6]

            Iteration 3
            nums1[0]=1
            [1,2,3,4,5,6]
            */

            j--;
            k--;
        }

        /*
        No need for

        while(i>=0)

        because remaining nums1 elements
        are already in correct position.
        */
    }
};