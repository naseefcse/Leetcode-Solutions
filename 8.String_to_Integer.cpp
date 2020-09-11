class Solution {
public:
    int myAtoi(string str) {
        
        bool neg {false};
        
        bool found {false};
        
        long long num = 0;
        bool pos {false};
        
        for (auto c : str) {
            if (!isdigit(c)) {
                if (found)
                    break;
                else if (c == '+' && !neg) {
                    pos = true; found = true;   
                }
                else if (c == '-' && !pos) {
                    neg = true; found = true;
                }
                else if (c != ' ' && !found)
                    return 0;
            }
            else {
                found = true;
                
                num = num * 10 + ((int)c - 48);
                
                if (num > INT_MAX)
                {
                    if (neg)
                        return INT_MIN;
                    else return INT_MAX;
                }
            }
        }
        
        if (neg)
            num = num * -1;
        
        return num;
    }
};
