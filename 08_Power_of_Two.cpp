//Given an integer, write a function to determine if it is a power of two.

//O(log n) solution

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0)
            return false;
        
        while(n != 1){
                if(n%2 == 1)
                    return false;
                n = n/2;
            }
        
    return true;       
        
    }
};

//O(1) solution

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0)
            return false;
        
        if ((n & (n-1)) == 0)
        return true;
        
    return false;        
    }
};
