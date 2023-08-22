#include <bits/stdc++.h>
#include <unordered_map>
#define dp double
#define ll long long
#define F .first
#define S .second
#define el << "\n"
#define pob pop_back
#define pub push_back
#define ve v.end()
#define vb v.begin()
#define all(v) ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define test_case int t; cin >> t; while (t--)
#define lop(i, a, n) for (ll i = a; i < n; i++)
#define pol(i, a, n) for (ll i = (n - 1); i >= a; i--)
#define rd  vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
void El_DamitY()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}
int O = 2e9+9;
struct segtree {

	int size;
	vector<ll> sums;
	void init (int n)
	{
		size = 1;
		while (size < n) size*=2;
		sums.assign(2 * size, 0LL);
	}

	void set (int i, int num, int x, int lx, int rx)
	{
		if (rx == lx)
		{
			sums[x] = num;
			return;
		}
		int m = (lx + rx) / 2;
		if (i <= m)
			set(i, num, 2 * x, lx, m);
		else
			set(i, num, 2 * x + 1, m + 1, rx);
		sums[x] = sums[2 * x] + sums[2 * x + 1];
	}

	void set (int i, int num)
	{
		set(i, num, 1, 1, size);
	}


	ll cal (int l, int r, int x, int lx, int rx) // 1 3 // 1 8
	{
		if (lx > r || l > rx) return 0;
		if (lx >= l && rx <= r) return sums[x];
		int m = (lx + rx) / 2;
		ll sl = cal(l, r, 2 * x , lx, m);
		ll sr = cal(l, r, 2 * x + 1, m + 1, rx);
		return sl + sr;
	}

	ll cal (int l, int r)
	{
		return cal(l, r, 1, 1, size);
	}

};

void solve()
{
	int n; cin >> n;
	n*=2;
	vector<int>v(n+1), res(n/2+1);
	map<int,int>mp;
	segtree st;
	st.init(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		if (mp[v[i]] == 0)
			st.set(i, 1);
		else
			st.set(i, -1);
		mp[v[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		if (mp[v[i]])
		{
			res[v[i]] = st.cal(i, mp[v[i]]);
			st.set(mp[v[i]], 1);
			mp[v[i]] = 0;
		}
	}
	for (int i = 1; i <= n/2; i++) cout << abs(res[i]) << " ";
}

signed main()
{
	El_DamitY();
	//file();
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
}
