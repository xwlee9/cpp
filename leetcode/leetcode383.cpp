class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int m = ransomNote.size();
        int n = magazine.size();
        if (m == 0 && n == 0) return true;
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int i = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i < m && ransomNote[i] == magazine[j]) ++i;
            if (i == m) return true;
        }
        // cout << ransomNote << " " << magazine << endl;
        return false;
    }
};