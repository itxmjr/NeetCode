class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        int currSum = 0;

        while(i < j) {
            currSum = numbers[i] + numbers[j];
            if(currSum > target) j--;
            else if(currSum < target) i++;
            else return {i + 1, j + 1};
        }
        return {};
    }
};
