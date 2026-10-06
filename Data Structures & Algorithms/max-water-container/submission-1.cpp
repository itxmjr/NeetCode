class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0, area = 0;
        int l = 0, r = heights.size() - 1;
        int h = 0, w = 0;
        while(l < r) {
            h = min(heights[l], heights[r]);
            w = r - l;
            area = h * w;
            res = max(area, res);
            heights[l] <= heights[r] ? l++ : r--;
        }
        return res;
    }
};
