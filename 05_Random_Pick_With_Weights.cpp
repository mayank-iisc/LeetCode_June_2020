/*
Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

For example, given an input list of values [1, 9], when we pick up a number out of it, the chance is that 9 times out of 10 we should pick the number 9 as the answer.

Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
*/

#include<algorithm>
class Solution {
public:
    
    vector <int> weights;
    
    //calcluate the prefix sum in this array
    Solution(vector<int>& w) {
        
       for(int i : w){
           if(weights.empty())
               weights.push_back(i);
           else
               weights.push_back(i+weights.back());
       }
        
    }
    
    int pickIndex() {
        
        int sum = weights.back();
        int p = rand()%sum;
        auto it = upper_bound(weights.begin(), weights.end(), p);
     
        return it - weights.begin();
    }
};
