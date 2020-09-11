class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> freq(256, 0);
        int max_len = 0;
        int start = 0;
        
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            
            if (freq[s[i]] > 1) {
                while(s[start] != s[i] && start < s.size()) {
                    freq[s[start]]--;
                    start++;
                }
                
                freq[s[start++]]--;
            }
            
            auto curr_len = i - start + 1;
            
            max_len = max(curr_len, max_len);
        }
        
        return max_len;
    }
};
