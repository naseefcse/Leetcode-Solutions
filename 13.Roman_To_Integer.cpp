class Solution {
public:
    int romanToInt(string s) {
        
        int count = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'M') count += 1000;
            else if(s[i] == 'D') count += 500;
            else if(s[i] == 'C') count += 100;
            else if(s[i] == 'L') count += 50;
            else if(s[i] == 'X') count += 10;
            else if(s[i] == 'V') count += 5;
            else count += 1;
        }
        if(s.find("CM") != string::npos || s.find("CD") != string::npos) count -= 200;
        if(s.find("XC") != string::npos || s.find("XL") != string::npos) count -= 20;
        if(s.find("IX") != string::npos || s.find("IV") != string::npos) count -= 2;
        return count;
        
    }
};
