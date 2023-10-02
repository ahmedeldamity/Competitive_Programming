
/*
- Information
- (2520) number divisibility by numbers from 1 : 10
- if (a/b=c) -> (a/c=b)
- T-prime -> that number be square as 49 -> 7*7 and 7 be prime
- (a,b) called coprime if GCD(a,b) = 1
- Last Digit To factorial to any (number >= 10) = 0
- If we need to bring last digit of multiplication some numbers
 we don't multiply numbers, but we multiply last digit of numbers
 EX: 101 * 102 * 103 = 1061106 | 1 * 2 * 3 = 6
*/

ll ModularExponentiation (ll n, ll p, ll mod)
{
	int res = 1;
	while (p)
	{
		if (n % 2 != 0)
			res = (res * n ) % mod;
		n = ((n%mod) * (n%mod)) %mod;
		p /= 2;
	}
	return res;
}

/*
Modular arithmetic (%)
a % b = a - [b * a/b]
(a+b)%c = ( (a%c)+(b%c) )%c
(a*b)%c = ( (a%c)*(b%c) )%c
(a-b)%c = ( (a%c)-(b%c)+c )%c
*/

/*
- Fast Power (x power n)
- if n even -> (x^2)^n/2
- if n odd  -> x * (x^n-1)
*/
ll FastPower(ll n, ll p)
{
	ll res = 1;
	while (p)
	{
		if (p & 1)
			res = res * n;
		n = n * n;
		p = p / 2;
	}
	return res;
}

bool IsPrime(ll n)
{
	if (n%2 == 0 || n == 1) return false;
	for (ll i = 3; i * i <= n; i+=2)
		if (n % i == 0)
			return false;
	return true;
}

ll FixMod(ll x, ll y)
{
	 return (x % y + y) % y;
}

vector <ll> GetDivisors(ll n)
{
	 vector<ll>v;
	 for (ll i = 1; i * i <= n; i++)
	 {
		 if (n % i == 0)
		 {
			 v.push_back(i);
			 if (i != n / i)
				 v.push_back(n / i);
		 }
	 }
	 return v;
}

ll GetCommonDivisorsFromArray (vector<ll> v)
{
	vector<ll> res;
	ll n = v.size(), GCD = 0;
	for (int i = 0; i < n; i++) GCD = gcd(GCD, v[i]);
	res = GetDivisors(GCD);
	return res.size();
}

vector <ll> GetPrimeFactors(ll n)
{
	vector<ll>v;
	for (ll i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			v.push_back(i);
			n /= i;
		}
	}
	if (n != 1)
		v.push_back(n);
	return v;
}

// - GCD by Euclidean Algorithm
ll GCD(ll a, ll b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}
/*
- GCD (ev, ev, ev, ev, ev, .. ) >= 2
- GCD (n , n+1) = 1
- GCD (a,b) = GCD (b,a%b)    {if b > 0}
- GCD (a,b) = a              {if b = 0}
- GCD(x,y) = GCD(x , |x-y| )
- GCD(x,y) = GCD(y , |x-y| )
- GCD(x,y) = GCD(y , a % y )
- GCD(a1, a2, a3) = GCD(a1 , |a1-a2| , |a1-a3| )
- GCD(a1+b1, a2+b1, a3+b1) = GCD(a1+b1, |a1-a2| , |a1-a3| )
- GCD (a1,a2,a3,a4,a5) = GCD (a3,a1,a2,a5,a4) = GCD of any order
- a*b = GCD(a,b) * LCM(a,b)
- GCD(a,b) = a*b / LCM(a,b)
- GCD (a,b) = GCD (b,a%b)
- note :
- GCD ( a! , b! ) = min(a,b)!
- The biggest GCD between range from 1 to n -> GCD (n,n/2) = n/2
- GCD of consecutive two numbers of group of consecutive numbers = 1
- GCD(a,1) = 1
- GCD(a,0) = a
*/

/*
- a*b = GCD(a,b) * LCM(a,b)
- LCM(a,1) = a
*/
ll LCM(ll a, ll b)
{
	//return a * b / GCD(a, b);
	return a / GCD(a, b) * b;
}
