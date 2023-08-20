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
		sums[x] = max(sums[2 * x] , sums[2 * x + 1]);
	}

	void built (vector<int> &v)
	{
		built (v, 1, 1, size);
		//for (int i = 0; i < sums.size(); i++) cout << sums[i] << " ";
		//cout el;
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
		sums[x] = max(sums[2 * x] , sums[2 * x + 1]);
	}

	void set (int i, int num)
	{
		set(i, num, 1, 1, size);
	}


	ll cal (int num, int x, int lx, int rx) // 1 3 // 1 8
	{
		if (sums[x] < num) return -1;
		if (rx == lx)
			return lx - 1;
		int m = (lx + rx) / 2;
		int acc = cal (num, 2 * x, lx, m);
		if (acc == -1)
			acc = cal (num, 2 * x + 1, m + 1, rx);
		return acc;
	}

	ll cal (int num)
	{
		return cal(num, 1, 1, size);
	}

};
