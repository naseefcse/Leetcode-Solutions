class Solution {
public:
    struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};
    
    unordered_map<pair<int, int>, bool, hash_pair> dp;
    bool isMatch(string s, string p) { 
        return helper(0, 0, s, p);
    }
    
    bool helper(int i, int j, string& s, string& p) {
        if (dp.find({i, j}) != dp.end()) {
            return dp[{i, j}];
        }
        
        bool res = false;
        
        if (i == s.size()) {
            if (j + 1 < p.size() && p[j + 1] == '*') {
                res = helper(i, j + 2, s, p);
            }
            else res = (j == p.size());
        } 
        else {
            if ((p[j] == '.' || p[j] == s[i]) && j + 1 < p.size() && p[j + 1] == '*') {
                res = helper(i + 1, j, s, p) || helper(i, j + 2, s, p);
            }
            else if (j + 1 < p.size() && p[j + 1] == '*') {
                res = helper(i, j + 2, s, p);
            }
            else {
                if (p[j] == '.') {
                    res = helper(i + 1, j + 1, s, p);
                }
                else {
                    res = (p[j] == s[i]) ? helper(i + 1, j + 1, s, p) :  false;
                }
            }
        }

            
        
        dp[{i, j}] = res;
        return res;
    }
};
