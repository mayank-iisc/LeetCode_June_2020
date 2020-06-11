class Solution {
public:
    void reverseString(vector<char>& s) {
    
      //Two pointer approach
        
        int begin = 0;
        int end = s.size()-1;
     
        while(end > begin){
            swap(s[begin], s[end]);
            begin++;
            end--;
        }        
    }
};
