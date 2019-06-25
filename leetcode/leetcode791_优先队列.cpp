class Solution {
public:
    string customSortString(string S, string T) 
    {
    
        int l[128] = {0};
        priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        string result;
        for (int i = 0; i < S.length(); ++i) l[S[i]] = i+1;
        // cout << l['a'] << endl;
        for (int i = 0; i < T.length(); ++i) 
        {
            if (0 == l[T[i]])  result += T[i];
            else 
            {
                q.push(make_pair(l[T[i]],T[i]));
                // l[T[i]] = 0;
            }
        }
        // cout << q.size();
        // cout << result;
        // cout << l['a'] << endl;
        while (!q.empty())
        {
            result += q.top().second;
            q.pop();
        }
        return result;    
    }
};