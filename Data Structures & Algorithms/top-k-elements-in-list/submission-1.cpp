class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto& num:nums) mp[num]++;
        
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        for(const auto& [k,v]: mp) {
            freq[v].push_back(k);
        }

        vector<int> result;
        for(int i = n; i > 0; i--) {
            for(int n:freq[i]) {
                result.push_back(n);
                if(result.size() == k) return result;
            }
        }

        return result;
    }
};
