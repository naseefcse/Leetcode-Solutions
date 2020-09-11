class Solution {
public:
    string longestPalindrome(string s) {
        
        string palind;
        
        for (int window = s.size(); window > 0; window--) {
            
            int start = 0;
            int end = window - 1;
            
            while (end != s.size()) {
                
                for (int left = start, right = end; left <= right; left++, right--) {
                    if (s[left] != s[right])
                        break;
                    
                    if (left + 1 >= right - 1) {
                        palind = s.substr(start, window);
                        return palind;
                    }
                }
                
                start++;
                end++;
                
            }
            
        }
        
        return "";
    }
};
