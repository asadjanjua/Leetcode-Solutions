class Solution {
public:
    int maxArea(vector<int>& height) {
        // L=0, R=8
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while(left < right){
            // Example:
            // L=1 (8), R=8 (7)
            // h = min(8,7) = 7
            int h = min(height[left], height[right]);
            // Width = 8-1 = 7
            int w = right - left;
            // Area = 7*7 = 49
            int area = h * w;
            // ans = max(8,49) = 49
            ans = max(ans, area);
            // Move smaller height
            // 8 > 7 -> right--
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};