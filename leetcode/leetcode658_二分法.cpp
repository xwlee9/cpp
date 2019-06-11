class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int m = arr.size();
        int i = 0;
        int j = m-1;
        int num;
        vector<int> res;
        while (i <= j)
        {
            if (i > 0 && x-arr[i-1] >= 0 && x-arr[i] < 0)
            {
                if (abs(x-arr[i-1]) < abs(x-arr[i])) num = i-1;
                else num = i;
                break;
            }
            int mid = (i + j) / 2;
            num = mid;
            if (x-arr[mid] == 0) break;
            if (x-arr[mid] > 0) i = mid + 1;
            else j = mid - 1;
            // cout << num << i << endl;
        }
        int a = num;
        int b = num;
        // cout << num << endl;
        if (k) 
        {
            res.push_back(arr[num]);
            --k;
        }
        while (k--)
        {
            if (a > 0 && b < m - 1)
            {
                if(abs(x-arr[--a]) <= abs(x-arr[++b]))
                {
                    res.push_back(arr[a]);
                    --b;
                }
                else 
                {
                    res.push_back(arr[b]);
                    ++a;
                }   
            }
            else if (a == 0) res.push_back(arr[++b]);
            else if (b == m-1) res.push_back(arr[--a]);            
        }
        sort(res.begin(), res.end());
        return res;
    }
};