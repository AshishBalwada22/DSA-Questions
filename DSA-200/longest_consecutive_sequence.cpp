// https://takeuforward.org/plus/dsa/problems/longest-consecutive-sequence-in-an-array?subject=dsa-concept-revision&tab=description

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=1,cnt=1,cur=nums[0];
        for(int i=1;i<nums.size();i++){
            if(cur==nums[i]) continue;
            else if(cur+1==nums[i]){
                cur=nums[i];
                cnt++;
            }else{
                cur=nums[i];
                cnt=1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};