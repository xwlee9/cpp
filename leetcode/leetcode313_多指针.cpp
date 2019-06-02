class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        map<int, int> p;
        vector<int> res(1,1); 
        for (auto i : primes)
        {
            p.insert(pair<int, int>(i,0));
        }
        while(--n)
        {
            int temp = INT_MAX;
            for (auto ite = p.begin(); ite != p.end(); ++ite)  // auto = map<int, int>::iterator
            {
                temp = min(temp, res[ite->second]*ite->first);
            }
            res.push_back(temp);
            for (auto ite = p.begin(); ite != p.end(); ++ite)
            {
                
                if (temp == res[ite->second]*ite->first) ite->second += 1;
            }            
        }
        return res.back();
    }
};