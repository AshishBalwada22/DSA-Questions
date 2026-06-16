// https://takeuforward.org/plus/dsa/problems/4-sum?subject=dsa-concept-revision&sidebar=open

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>quad;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1;
                int l=n-1;
                while(k<l){
                    int sum=nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum<target) k++;
                    else if(sum>target) l--;
                    else{
                        quad.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                }
            }
        }
        vector<vector<int>>ans(quad.begin(),quad.end());
        return ans;
    }
};