class Solution {
public:

int twoCitySchedCost(vector<vector<int>>& costs) {
    
        //Cost of Sending everyone to A
        int n = costs.size()/2;
        int costA = 0;
        
        for(int i = 0; i < costs.size(); i++){
            costA = costA + costs[i][0];
        }
            
        //Maximum refund that can be obtained by sending people to B
        //refund +ve means we need to pay, -ve means we get back money; we need to maximize -ve money.
        vector <int> refund(2*n);
        
        for(int i = 0; i < costs.size(); i++){
            refund.push_back(costs[i][1] - costs[i][0]);
        }
        
        sort(refund.begin(), refund.end());
        
        int refundSum = 0;
        //Add first n/2 refund elements
        for(int i = 0; i < n; i++){
            refundSum += refund[i];
        }
        
    return costA + refundSum;
    }
};
