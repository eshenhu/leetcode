class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        unsigned int g_rev = 0;
       
        int rem;
        while (x)
        {
            rem = x % 10;            
            x = x / 10;
            g_rev = g_rev * 10 + rem;
        }
        
        return g_rev == x;
    }
};
