/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0 || n == 1)
            return nums;
        
        sort(nums.begin(), nums.end());
        
        vector <int> dp (n,1);
        
        int max = INT_MIN;
        
        for(int i = 1; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[i] % nums[j] == 0){
                    int t = 1 + dp[j];
                        if(t > dp[i])
                            dp[i] = t;
                }
                if(dp[i] > max)
                    max = dp[i];
            }
        }
        
        vector <int> res;
        
        for(int i = n-1; i >= 0; i--){
            if(dp[i] == max){
                res.push_back(nums[i]);
                max--;
            }
        }
    return res;
    }
};
