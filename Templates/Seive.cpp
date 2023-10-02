vector<bool> notPrime;
void sieve ()   // O(N loglog(N))
{
	notPrime[0] = notPrime[1] = true;
	for (ll i = 2; i <= sqrt(N); i++) // constant time
	{
		if (!notPrime[i])
		{
			for (ll j = i*i; j <= N; j+=i) // n log log(N)
			{
				notPrime[j] = true;
			}
		}
	}
}

vector<bool> notPrime;
vector<int> primes;
void linSieve (int N)  // O(N)
{
	notPrime[0] = notPrime[1] = true;
	for (int i = 2; i < N; i++)  // constant time
	{
		if (!notPrime[i]) primes.push_back(i);
		for (int j = 0; j < primes.size() && i * primes[j] < N; j++)  // O(N)
		{
			notPrime[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}
