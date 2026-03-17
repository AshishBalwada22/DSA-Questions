// https://takeuforward.org/plus/dsa/problems/quick-sorting?subject=dsa-concept-revision&tab=description

class Solution {
public:

    int sortingleftandrightside(vector<int>&nums,int st,int en)
    {
        int pivot=nums[st];
        int i=st,j=en;
        while(i<=j)
        {
            while(nums[i]<=pivot&&i<=en) i++;
            while(nums[j]>pivot&&j>=st) j--;
            if(i<j) swap(nums[i],nums[j]);
        }
        swap(nums[st],nums[j]);//swap the pivot element with right most element of left subarray
        return j;//return position where you have placed pivot
    }
    void quicksort(vector<int>&nums,int st,int en)
    {
        if(st>=en) return;
        int pivotindex=sortingleftandrightside(nums,st,en);//place pivot element at right position
        quicksort(nums,st,pivotindex-1);
        quicksort(nums,pivotindex+1,en);
    }
    vector<int> quickSort(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
};
