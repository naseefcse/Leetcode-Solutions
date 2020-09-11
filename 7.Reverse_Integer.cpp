class Solution {
public:

    int reverse(int x) {
        
        string s = to_string(x);
        
        std::reverse(s.begin(), s.end());
        
        string res;
        
        if (s.back() == '-') {
            res = "-";
            
            bool fnd = false;
            
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] == 'O' && !fnd) {
                    continue;
                }
                
                fnd = true;
                res += s[i];
            }
            
            if (res.size() == 1)
                return 0;
            
            if (stol(res) < INT_MIN)
                return 0;
            
            return stoi(res);
        }
        else {
            bool fnd = false;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '0' && !fnd)
                    continue;
                
                fnd = true;
                res += s[i];
            }
            
            if (res.size() == 0)
                return 0;
            
            if (stol(res) > INT_MAX)
                return 0;
            
            return stoi(res);
        }
    }
};
