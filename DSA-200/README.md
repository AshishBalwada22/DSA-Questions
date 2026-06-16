DSA-200
=======

1) Merge sort -> divide and conquer algorithm
find mid
do left sort mergesort(arr,st,mid)
do right sort mergsort(arr,mid+1,en)
merging

2) quick sort
find pivot index {
    treat first element as pivot element
    swap the pivot element with right most element of left subarray
    return the position where you have placed pivot element
}
quicksort(arr,st,pivot_index-1);
quicksort(arr,pivot_index+1,en);

3) 3 sum and 4 sum 
- no need to manage indexes, so do sorting
- once you sort, apply two pointer approach



