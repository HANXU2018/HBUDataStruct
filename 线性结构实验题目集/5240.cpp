#include<iostream>
#include<vector>
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> m(26, 0);   // 当作哈希状态表，记录每个小写字母出现的次数
        return dfs(arr, 0, m);  // 以0号元素为根结点，开始回溯。
    }
    int dfs(vector<string>& arr, int childIndex, vector<int> m) {
        if (childIndex == arr.size()) return 0;
        vector<int> t(m); // 再定义一个状态表来记录走第一条路的状态
        if (isUnique(arr[childIndex], t)) {
            int curLen = arr[childIndex].length();
            return max(curLen + dfs(arr, childIndex+1, t), dfs(arr, childIndex+1, m));
        }
        return dfs(arr, childIndex+1, m);
    }
    //判断加入字符串s后，是否满足不含相同字符
    bool isUnique(string& s, vector<int>& t) {
        for (int i = 0; i < s.length(); i++)  t[s[i]-'a']++;
        for (int i = 0; i < 26; i++) if (t[i] > 1) return false;
        return true;
    }
};
