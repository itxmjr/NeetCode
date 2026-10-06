class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        string key;
        for(auto& str : strs) {
            vector<int> freq(26, 0);
            for(auto& c: str) {
                freq[c - 'a']++;
            }
            key = to_string(freq[0]);
            for(int i = 1; i < 26; i++) {
                key += ',' + to_string(freq[i]);
            }
            mp[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& pair : mp) {
            result.push_back(pair.second);
        }
        return result;
    }
};
