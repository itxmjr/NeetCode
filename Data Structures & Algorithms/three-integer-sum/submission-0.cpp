class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int threeSum = 0;

        for(int i = 0; i < n-2; i++) {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            l = i + 1;
            r = n - 1;
            while(l < r) {
                threeSum = nums[i] + nums[l] + nums[r];
                if(threeSum > 0) r--;
                else if(threeSum < 0) l++;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]) l++;
                }
            }
        }
        return res;
    }
};
