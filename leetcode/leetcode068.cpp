class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> res;
        int length = 0;
        int count = 0;
        int n = words.size();
        for (int i = 0; i < n; ++i)
        {
            length += words[i].size() + 1;
            count ++;
            if (length - 2 >= maxWidth) 
            {
                
                length = length - 2 - words[i].size();  // 减去两个空格
                count --;  // 减去一个单词的长度
                int bl = maxWidth - length + count - 1;  
                // cout << bl << endl;
                // cout << count << endl;
                int blank;  // 需要加空格的数量
                int more;  // 第一行需加空格数量
                if (count > 1) blank = bl / (count-1);
                else blank = 0;
                more = bl - blank * (count - 1);
                // cout << blank << " " << more << endl;
                string temp;
                for (int j = count; j > 1; --j)
                {
                    temp.append(words[i - j]);
                    if (more != 0) 
                    {
                        temp.append(1, ' ');
                        more--;
                    }       
                    temp.append(blank,' ');
                }
                if (i > 0) temp.append(words[i - 1]);
                if (temp.size() < maxWidth) temp.append(maxWidth - temp.size(),' ');
                res.push_back(temp);
                count = 0;
                length = 0;
                i--;
            }
        }
        if (length != 0)  // 来判断res的最后一行
        {
            string temp;
            for (int i = count; i > 1; --i)
            {
                temp.append(words[n - i]);
                temp.append(1, ' ');
            }
            temp.append(words[n - 1]);
            if (temp.size() < maxWidth) temp.append(maxWidth - temp.size(),' ');  // 补齐
            res.push_back(temp);
        }
        return res;
    }
};