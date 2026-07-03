class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n);
        //brute force
        // for (int i=0;i<n;i++)
        // {
        //     int product=1;
        //     for (int j=0;j<n;j++)
        //     {
        //         if (i!=j)
        //         {
        //             product*=nums[j];
        //         }
        //     }
        //      answer[i]=product;
        // }
        // return answer;

       // prefix and suffix variable approach
        
        int prefix=1;
        for (int i=0;i<n;i++){
            answer[i]=prefix;
            prefix*=nums[i];
        }

        int suffix=1;
        for (int i=n-1;i>=0;i--){
            answer[i]*=suffix;
            suffix*=nums[i];
        }
        return answer;
    }
};