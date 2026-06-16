// https://takeuforward.org/plus/dsa/problems/kadane's-algorithm?subject=dsa-concept-revision&tab=description

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=0,ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            ans=max(ans,cursum);
            if(cursum<0) cursum=0;
        }
        return ans;
    }
};