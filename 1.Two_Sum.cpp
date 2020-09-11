class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            
            auto itr = mp.find(target - nums[i]);
            
            if  (itr != mp.end()) {
                return {itr->second, i};
            }
            else {
                mp[nums[i]] = i;
            }
        }
        
        return std::vector<int>();
        
    }
};
