class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string& s : strs)
            res += to_string(s.size()) + "#" + s;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.size();
        int t = 0, len = 0;
        for(int i = 0; i < n;) {
            t = i;
            while(s[t] != '#') t++;
            int len = stoi(s.substr(i, t-i));
            i = t+1;
            res.push_back(s.substr(i, len));
            i += len;
        }
        return res;
    }
};
