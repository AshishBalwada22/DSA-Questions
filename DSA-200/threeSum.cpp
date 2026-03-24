// https://takeuforward.org/plus/dsa/problems/3-sum?subject=dsa-concept-revision&sidebar=open

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // no need to manage indexes, so do sorting here
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i-1>=0 && nums[i-1]==nums[i]) continue; // skip duplicate
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }else if(sum>0){
                    k--;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k&&nums[j]==nums[j-1]) j++; // skip duplicate
                    while(k>j&&nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
        /*
        set<vector<int>>triplet;
        int n=nums.size();
        for(int i=0;i<n;i++){
            // now treat like two sum problem
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
        */
    }
};