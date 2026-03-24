// https://takeuforward.org/plus/dsa/problems/3-sum?subject=dsa-concept-revision&sidebar=open

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // no need to manage indexes, so do sorting here
        set<vector<int>>triplet;
        int n=nums.size();
        for(int i=0;i<n;i++){
            set<int>s; //element seen so far
            for(int j=i+1;j<n;j++){
                int third = -1*(nums[i]+nums[j]);
                if(s.find(third)!=s.end()){
                    triplet.insert({nums[i],nums[j],third});
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(triplet.begin(),triplet.end());
        return ans;
    }
};