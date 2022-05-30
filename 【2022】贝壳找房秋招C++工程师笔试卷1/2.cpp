typedef long long ll;

class Solution
{
public:
    vector<long> FarmerNN(int n, ll m)
    {
        vector<long> ans(n, 1);
        if (m < n)
        {
            for (int i = m; i < n; ++i)
                ans[i] = 0;
            return ans;
        }
        m -= n;
        vector<ll> sum(n + 5, 0);
        auto add = [&](int l, int r, ll val)
        {
            if (l > r)
                return;
            sum[l] += val;
            sum[r + 1] -= val;
        };
        ll round = m / (n - 1);
        add(0, n - 2, round / 2);
        add(1, n - 1, round / 2);
        if (round % 2 != 0)
            add(0, n - 2, 1);
        m %= (n - 1);
        if (round % 2 != 0)
            add(1, m, 1);
        else
            add(n - m - 1, n - 2, 1);
        for (int i = 1; i < n; ++i)
            sum[i] += sum[i - 1];
        for (int i = 0; i < n; ++i)
            ans[i] += sum[i];
        return ans;
    }
};