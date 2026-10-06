class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int diff;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(mp.find(nums[i]) != mp.end()) return {mp[nums[i]], i};
            diff = target - nums[i];
            mp[diff] = i;
        }
        return {};
    }
};
