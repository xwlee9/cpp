#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, n, n, "");
        return result;
    }
    void generate(vector<string> &result, int left, int right, string item)
    {
        if (right == 0)
        {
            result.push_back(item);
            return;
        }
        if (left > 0) generate(result, left-1, right, item + '(');
        if (right > left)  generate(result, left, right-1, item + ')');
    }
};