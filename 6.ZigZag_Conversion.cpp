class Solution {
public:
    string convert(string s, int n) {
        if (n <= 1) return s;
        
        int curr = 0, nxt = 0;
        vector<string> v(n);
        
        for (int i = 0; i < s.size(); i++) {
            v[curr].push_back(s[i]);
            
            if (curr == 0) {
                nxt = 1;
            }
            else if (curr == n - 1)
                nxt = -1;
            
            curr += nxt;
        }
        
        string res;
        
        for (int i = 0; i < n; i++) {
            res += v[i];
        }
        
        return res;
    }
};
