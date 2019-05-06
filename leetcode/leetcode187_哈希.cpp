#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> res;
        set<string> st;
        for (int i = 0; i + 9 < s.size(); ++i) {
            string t = s.substr(i, 10);
            if (st.count(t)) res.insert(t);
            else st.insert(t);
        }
        return vector<string> {res.begin(), res.end()};
    }
};