class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int n = words.size(); 
        int m = words[0].size();  // 长度相同
        int l = s.length() - (m * n);
        if (l < 0) return res;
        unordered_map<string, int> m1;
        for(int i = 0; i < words.size(); ++i)  m1[words[i]] += 1;
        for(int i = 0; i <= s.length() - (m * n); ++i)
        {
            unordered_map<string, int> m2;
            int j = 0;
            cout << i;
            for (; j < n; ++j)
            {
                string temp = s.substr(i+j*m,m);
                if (m1.find(temp) == m1.end() ) break;  // 没有找到
                m2[temp] += 1;
                if (m2[temp] > m1[temp]) break;
            }
            if (j == n) res.push_back(i);            
        }
        return res;
    }
};