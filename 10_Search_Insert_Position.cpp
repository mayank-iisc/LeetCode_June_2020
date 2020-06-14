/*
Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

*/

class Solution {
public:
    //Modified Binary Search
    int searchInsertAux(vector <int>& nums, int target, int start, int end){
        
        int mid = start + (end-start)/2;
        
        if(nums[mid] == target)
            return mid;
        
        else if(nums[mid] < target && nums[mid+1] > target)
            return mid+1;
        
        else if(nums[mid] > target && target > nums[mid-1])
            return mid;
        
        else if(target < nums[mid])
            return searchInsertAux(nums, target, start, mid-1);
        
        else
            return searchInsertAux(nums, target, mid+1, end);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        
        if(target < nums[0])
            return 0;
        
        if(target > nums[nums.size()-1])
            return nums.size();
        
        int ans = searchInsertAux(nums, target, 0, nums.size()-1);
    
        return ans;
    }
};
