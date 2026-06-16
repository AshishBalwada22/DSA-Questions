class Solution {
public:
    void merging(vector<int>&nums,int st,int en)
    {
        int n=en-st+1;
        vector<int>temp(n);
        int k=0,mid=st+(en-st)/2;
        int i=st,j=mid+1;
        for(;i<=mid&&j<=en;)
        {
            if(nums[i]<=nums[j]) temp[k++]=nums[i++];
            else temp[k++]=nums[j++];
        }
        while(i<=mid)
        {
            temp[k++]=nums[i++];
        }
        while(j<=en)
        {
            temp[k++]=nums[j++];
        }
        for(int k=0;k<n;k++)
        {
            nums[st+k]=temp[k];
        }
    }
    void mergesortt(vector<int>&nums,int st,int en)
    {
        if(st>=en) return;
        int mid=st+(en-st)/2;
        mergesortt(nums,st,mid); // sort the first half
        mergesortt(nums,mid+1,en); // sort the second half
        merging(nums,st,en); // merge the two halves
    }
    vector<int> mergeSort(vector<int>& nums) {
        mergesortt(nums,0,nums.size()-1);
        return nums;
    }
};
