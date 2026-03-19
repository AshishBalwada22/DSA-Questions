// https://takeuforward.org/plus/dsa/problems/pascals-triangle-iii?subject=dsa-concept-revision

class Solution {
public:
    vector<vector<int>> pascalTriangleIII(int n) {
        vector<vector<int>>ans;
        vector<int>subset;
       for(int i=0;i<n;i++){
        subset.clear();
        for(int j=0;j<=i;j++){
            if(j==0||j==i) subset.push_back(1);
            else{
                subset.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
        }
        ans.push_back(subset);
       }
       return ans;
    }
};