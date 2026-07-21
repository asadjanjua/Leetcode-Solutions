class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        // Four boundaries
        int top = 0;
        int left = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;

        /*
        Dry Run

        Matrix

        1 2 3
        4 5 6
        7 8 9

        Initial

        top = 0
        bottom = 2
        left = 0
        right = 2

        ans = []
        */

        while (left <= right && top <= bottom)
        {

            // ==========================
            // 1. Left -> Right
            // Fixed Row = top
            // Change Column = left -> right
            //
            // First Iteration
            // Visit : 1 2 3
            // ans = [1,2,3]
            // ==========================
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }

            // Top row completed
            top++;

            /*
            top = 1
            */

            // ==========================
            // 2. Top -> Bottom
            // Fixed Column = right
            // Change Row = top -> bottom
            //
            // Visit : 6 9
            // ans = [1,2,3,6,9]
            // ==========================
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }

            // Right column completed
            right--;

            /*
            right = 1
            */

            // If rows still remain
            if (top <= bottom)
            {

                // ==========================
                // 3. Right -> Left
                // Fixed Row = bottom
                // Change Column = right -> left
                //
                // Visit : 8 7
                // ans = [1,2,3,6,9,8,7]
                // ==========================
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }

                // Bottom row completed
                bottom--;

                /*
                bottom = 1
                */
            }

            // If columns still remain
            if (left <= right)
            {

                // ==========================
                // 4. Bottom -> Top
                // Fixed Column = left
                // Change Row = bottom -> top
                //
                // Visit : 4
                // ans = [1,2,3,6,9,8,7,4]
                // ==========================
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }

                // Left column completed
                left++;

                /*
                left = 1
                */
            }

            /*
            Current Boundaries

            top = 1
            bottom = 1
            left = 1
            right = 1

            One element remains:

            5

            Next iteration

            Left -> Right

            Visit : 5

            ans =

            [1,2,3,6,9,8,7,4,5]

            top = 2

            Loop condition

            top <= bottom

            2 <= 1

            False

            Loop ends.
            */
        }

        return ans;
    }
};