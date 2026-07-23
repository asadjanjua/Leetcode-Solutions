class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // Step 1: Transpose the matrix
        // Swap matrix[i][j] with matrix[j][i]
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);

                /*
                Dry Run (3x3)

                1 2 3
                4 5 6
                7 8 9

                Swap (0,1)<->(1,0): 2↔4
                Swap (0,2)<->(2,0): 3↔7
                Swap (1,2)<->(2,1): 6↔8

                After Transpose

                1 4 7
                2 5 8
                3 6 9
                */
            }
        }

        // Step 2: Reverse every row
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());

            /*
            Row 0: 1 4 7 -> 7 4 1
            Row 1: 2 5 8 -> 8 5 2
            Row 2: 3 6 9 -> 9 6 3
            */
        }

        /*
        Final Output

        7 4 1
        8 5 2
        9 6 3
        */
    }
};