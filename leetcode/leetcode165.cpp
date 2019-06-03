class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        int i = 0;
        int j = 0;
        int m = version1.size();
        int n = version2.size();
        while (i < m && j < n)
        {
            int temp1 = 0;
            int temp2 = 0;
            while (i < m && version1[i] != '.') 
            {
                temp1 += temp1*10 + version1[i] - '0';
                ++i;
            }
            while (j < n && version2[j] != '.')
            {
                temp2 += temp2*10 + version2[j] - '0';
                ++j;
            }
            // cout << temp1 << " " << temp2 << endl; 
            if (temp1 < temp2) return -1;
            else if (temp1 > temp2) return 1;
            else 
            {
                ++i;
                ++j;
            }
        }
        while (i < m) 
        {
            if (version1[i] != '0' && version1[i] != '.') return 1;
            ++i;
        }
        while (j < n) 
        {
            if (version2[j] != '0' && version2[j] != '.') return -1;
            ++j;
        }
        return 0;
    }
};