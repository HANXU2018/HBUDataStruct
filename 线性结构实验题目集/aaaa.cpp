·class Solution {
public:
    int maxLength(vector<string>& a) {
        int n = a.size();
        int ret = 0;
        for (int s = 1; s < 1<<n; ++ s)
        {
            int flag = 0;
            int len = 0;
            vector<int> u(26);
            for (int i = 0; i < n; ++ i) if (s>>i&1)
            {

                for (auto c : a[i])
                {
                    u[c-'a'] ++;
                    if (u[c-'a'] >= 2) flag = 1;
                }
                if (flag) break;
                len += a[i].size();
                ret = max(ret, len);
            }
        }
        return ret;
        
    }
};
