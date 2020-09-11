class Solution {
public:
    std::vector<int> merge(std::vector<int> & num1, std::vector<int>& num2) {
        std::vector<int> res;
        res.resize(num1.size() + num2.size());
        
        int i = 0, j = 0, k = 0;
        
        while(i < num1.size() && j < num2.size()) {
            if(num1[i] < num2[j]) {
                res[k++] = num1[i++];
            }
            else {
                res[k++] = num2[j++];
            }
        }
        
        while (i < num1.size())
            res[k++] = num1[i++];
        while (j < num2.size())
            res[k++] = num2[j++];
        
        
        return res;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> v = merge(nums1, nums2);
        
        if (v.size() % 2 == 0) {
            return ((double) v[(v.size() - 1)/2] + (double)v[(v.size()-1)/2 + 1]) /2.0;
        }
        
        else return v[v.size() / 2];
    }
};
