class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        // Two pointers
        int left = 0;
        int right = numbers.size()-1;
        while(left < right){
            // Example: 2+15=17
            int sum = numbers[left] + numbers[right];
            // Found target
            if(sum == target)
                return {left+1, right+1};
            // 2+3=5<9 -> left++
            else if(sum < target)
                left++;
            // 2+15=17>9 -> right--
            else
                right--;
        }

        return {};
    }
};

/*
Dry Run:
[2,7,11,15], target=9
2+15=17>9 → R--
2+11=13>9 → R--
2+7=9 ✓ → Return {1,2}
*/