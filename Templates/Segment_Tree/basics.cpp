// calculate min | max | Bitwise operators | sum
struct segtree {

	int size;
	vector<ll> sums;
	void init (int n)
	{
		size = 1;
		while (size < n) size*=2;
		sums.assign(2 * size, 0LL);
	}

	void built (vector<int> &v, int x, int lx, int rx)
	{
		if (rx == lx)
		{
			if (lx <= v.size())
				sums[x] = v[lx-1];
			return;
		}
		int m = (lx + rx) / 2;
		built(v, 2 * x , lx, m);
		built(v, 2 * x + 1, m + 1, rx);
		sums[x] = min(sums[2 * x] , sums[2 * x + 1]);
	}

	void built (vector<int> &v)
	{
		built (v, 1, 1, size);
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
		sums[x] = min(sums[2 * x] , sums[2 * x + 1]);
	}

	void set (int i, int num)
	{
		set(i, num, 1, 1, size);
	}


	ll cal (int l, int r, int x, int lx, int rx) // 1 3 // 1 8
	{
		if (lx > r || l > rx) return O;
		if (lx >= l && rx <= r) return sums[x];
		int m = (lx + rx) / 2;
		ll sl = cal(l, r, 2 * x , lx, m);
		ll sr = cal(l, r, 2 * x + 1, m + 1, rx);
		return min(sl , sr);
	}

	ll cal (int l, int r)
	{
		return cal(l, r, 1, 1, size);
	}

};
