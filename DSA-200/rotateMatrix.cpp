// https://takeuforward.org/plus/dsa/problems/rotate-matrix-by-90-degrees?subject=dsa-concept-revision

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};