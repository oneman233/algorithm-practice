class Solution
{
public:
    long long section(vector<int> &a, int t)
    {
        int n = a.size();
        long long ans = 0;
        vector<int> nxt(n + 5, 0x3f3f3f3f);
        map<int, int> mp;
        for (int i = n - 1; i >= 0; --i)
        {
            nxt[i] = nxt[i + 1];
            if (mp[a[i] ^ t])
                nxt[i] = min(nxt[i], mp[a[i] ^ t]);
            mp[a[i]] = i;
        }
        for (int i = 0; i < n; ++i)
            cout << nxt[i] << ' ';
        for (int i = 0; i < n; ++i)
            if (nxt[i] == 0x3f3f3f3f)
            {
                ans += n - i - 1;
            }
            else
            {
                ans += nxt[i] - i - 1;
            }
        return ans;
    }
};