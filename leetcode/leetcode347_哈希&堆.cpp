class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> count;
        
        // priority_queue<pair<int,int>,vector<pair<int, int> >,greater<pair<int, int> > > n;  // 最小堆
        priority_queue <pair<int, int> > n;  // 最大堆
        vector <int> result(k);
        for(int i = 0; i < nums.size(); ++i)   
                count[nums[i]]++;
        map<int, int> :: iterator ite;
        for(ite = count.begin(); ite != count.end(); ++ite)  
                n.push(make_pair(ite->second, ite -> first));
        for (int i = 0; i < k; ++i)
        {
            result [i] = n.top().second;
            n.pop();
        }
        return result;
    }
};