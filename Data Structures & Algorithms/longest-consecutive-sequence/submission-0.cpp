class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int len = 0, maxLen = 0, currNum;
        for(int num:numSet) {
            if(!numSet.count(num-1)) {
                len = 1;
                currNum = num;
                while(numSet.count(++currNum)) len++;
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};
