// https://takeuforward.org/plus/dsa/problems/two-sum?subject=dsa-concept-revision

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m; // element, index
        int n=nums.size();
        for(int i=0;i<n;i++){
            int y = nums[i];
            int x = target-y;
            if(m.find(x)!=m.end()){
                return {m[x],i};
            }
            m.insert({y,i});
        }
        return {-1,-1};
    }
};