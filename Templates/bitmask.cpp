void DecToBin(int n)
{
	if (n <= 1)
	{
		cout << n;
		return;
	}
	DecToBin(n >> 1);
	cout << (n & 1);
}

int BinToDec(int num)
{
	 int base = 0, res = 0, last_digit;
	 while (num > 0)
	 {
		 last_digit = num % 10;
		 num /= 10;
		 res += (last_digit * pow(2, base));
		 base++;
	 }
	 return res;
 }

// check is a number odd or even ?
if (number & 1) cout << "odd";
if (!(number & 1)) cout << "even";

// Information about XOR
A ^ A = 0
0 ^ A = n
(A ^ B ^ C ^ A ^ B) = (A ^ A ^ B ^ B ^ C) = (0 ^ 0 ^ C) = C
(A ^ A ^ A) = A // Odd Repeat
(A ^ A ^ A ^ A) = 0 // Even Repeat

// Shift Left ( ( << ) = ( *2 ) )
(n << 1) = (n * 2) = (n * (2 ^ 1) )
(n << 2) = (n * 2 * 2) = (n * (2 ^ 2) )
(n << 3) = (n * 2 * 2 * 2) = (n * (2 ^ 3) )

// Shift Right ( ( >> ) = ( /2 ) )
(n >> 1) = (n / 2) = (n / (2 ^ 1) )
(n >> 2) = (n / 2 / 2) = (n / (2 ^ 2) )
(n >> 3) = (n / 2 / 2 / 2) = (n / (2 ^ 3) )

(n - 1) In Binary
16 In Binary (10000)
14 In Binary (01111)

// number % (2 ^ x)
int mod = 2 ^ x;
cout << number & (mod - 1);

int cntBits1(int num)
{
	 int cnt = 0;
	 while (num)
	 {
		cnt++;
		 num &= (num - 1);
	 }
	 return cnt;
}

Is That Index On ?
((num >> index) & 1)

Make That Index On ?
(num | (1 << index))

Make That Index Off ?
(num & ~(1 << index))

Flip That Index
(num ^ (1 << index))

Is This Number Power Of Two ?
if (! (num & (num - 1) ) ) cout << "YES";

Make The First Bit From Right Equal one Be Equal Zero
10011001000 -> 10011000000
num & (num - 1)
