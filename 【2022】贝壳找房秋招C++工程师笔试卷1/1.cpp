class Solution
{
public:
    string NS_String(string s, int k)
    {
        string ss = s;
        sort(ss.begin(), ss.end());
        int cnt = 1;
        map<char, int> mp;
        for (auto i : ss)
            if (mp[i] == 0)
                mp[i] = cnt++;
        string tmp = "";
        for (auto i : s)
            if (mp[i] > k)
                tmp += i;
        return tmp;
    }
};