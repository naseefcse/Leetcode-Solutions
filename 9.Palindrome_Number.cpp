class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) return false;
        
        int orig = x;
        
        long n = 0;
        
        while(orig)
        {
            n= n*10 + (orig%10);
            orig /= 10;
        }
        
        if (x == n)
            return true;
            
        return false;
    }
};
