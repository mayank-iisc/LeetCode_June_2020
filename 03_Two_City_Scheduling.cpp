/* There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], 
and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
*/

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
