class Solution {
public:
    string simplifyPath(string path) 
    {
        int count = 0;
        int flag = 0;
        vector<char> res;
        string s;
        int l = path.size();
        for(int i = 0; i < path.length(); ++i)
        { 
            if('/' == path[i])
            {
                if (!res.empty() && '/' == res.back()) continue;
                res.push_back(path[i]);
            }
            else if('.' == path[i])
            {
                if (i < l-2 && '.' == path[i+1] && '/' != path[i+2])
                {
                    while (path[l-1] == '/') --l;
                    return path.substr(0, l);  
                }
                if (i < path.length()-1 && '.' == path[i+1])
                {
                    res.pop_back();
                    if (!res.empty())
                    {
                        while ('/' != res.back()) res.pop_back();
                        res.pop_back();
                    }
                    ++i;
                }
                else if (i < path.length()-1 && '/' == path[i+1])  continue;
                else res.push_back(path[i]);
            }
            else res.push_back(path[i]);
        }
        int len = res.size();
        {
            for (int i = 0; i < len; ++i) s += res[i];
            while (len > 0 && (res[len - 1] == '/' || res[len - 1] == '.')) len--;
        }
        if (len < 1) return "/";
        return s.substr(0, len);
    }
};