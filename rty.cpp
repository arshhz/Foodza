#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;     cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i]
    vector<long long> final(n + 1, 0);
    vector<vector<long long>> mp(n + 1);
    for (long long i = n-1; i >= 0; i--)
    {
    long long t = i;
       while (t > 0 && a[t - 1] == a[i])
          t--;
     final[t] = final[i + 1];
      for (auto yu : mp[a[i]])
       {
          final[t] = max(final[t], yu - t + 1 + final[yu + 1]);
       }     mp[a[i]].push_back(i);
        if (t<i)   i = t + 1;
    }
    cout << final[0] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}