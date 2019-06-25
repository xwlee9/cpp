class Solution {
public:
    string strWithout3a3b(int A, int B) 
    {
        string result = "";
        if (A >= B)
        {
            int temp = A - B;
            if (A > 2*B) temp -= 1;
            for (int i = 0; i < temp ; ++i) result.append("aab");
            if (temp*3-1 == A + B) return result.substr(0,temp*3-1);
            int k = temp * 3;
            int flag = 0;
            while (k < A + B)
            {
                if (flag == 0)
                {
                    result += 'a';
                    flag = 1;
                }
                else if (flag == 1)
                {
                    result += 'b';
                    flag = 0;
                }
                k++;
            }
        }
        else 
        {
            int temp = B - A;
            // cout << temp << endl;  
            if (B > 2*A)  temp -= 1;
            for (int i = 0; i < temp; ++i)  result.append("bba");
            if (temp*3-1 == B + A) return result.substr(0,temp*3-1);
            int k = temp * 3;
            int flag = 0;
            while (k < A + B)
            {
                if (flag == 0)
                {
                    result += 'b';
                    flag = 1;
                }
                else if (flag == 1)
                {
                    result += 'a';
                    flag = 0;
                }
                ++k;
            }
        }
        return result;  
    }
};