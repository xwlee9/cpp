class Solution {
public:
    string addBinary(string a, string b) 
    {
        int c = 0;
        vector<int> temp;
        int i = a.size() - 1;
        int j = b.size() - 1;
        string res;
        while (i >= 0 && j >= 0)
        {
            int sum = a[i] - '0' + b[j] - '0' + c;
            if (sum == 2)
            {
                sum = 0;
                c = 1;
            }
            else if (sum == 3)
            {
                sum = 1;
                c = 1;
            }
            else c = 0;
            temp.push_back(sum);
            --i;
            --j;
        }
        while (i >= 0)
        {
            int sum = a[i] -'0' + c;
            if (sum == 2)
            {
                sum = 0;
                c = 1;
            }
            else c = 0;
            temp.push_back(sum);
            --i;
        }
        while (j >= 0)
        {
            int sum = b[j] -'0' + c;
            if (sum == 2)
            {
                sum = 0;
                c = 1;
            }
            else c = 0;
            temp.push_back(sum);
            --j;
        }
        if (c==1) temp.push_back(c);
        for (int k = temp.size()-1; k >= 0; --k) res += temp[k] + '0';
        return res;
    }
};