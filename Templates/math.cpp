/*
ceil of (n/d) = (n+d-1)/d
*/

/*
- Sm all numbers from 1 -> n
int sm = n * (n+1) / 2;
*/

/*
- Arithmetic Progression
- suppose d (difference) be the same difference between numbers
- Sequence of numbers in same difference between every neighbour's numbers
- To Obtain Sum This Array Use This Rule
sum = (a1 + an) * n / 2;
- To Obtain Last Element In This Array Use This Rule
an = a1 + (n-1) * d;
*/

/*
- Geometric Progression
- Suppose r (ratio) be the same multiply between numbers
- Sequence of numbers in same multiply between every neighbour's numbers
- To Obtain Sum This Array Use This Rule
sm = a1 * (1 - (r ^ n) ) / (1 - r)
- to obtain the value of number from his position
aP = a1 * (r ^ (n-1) )
 */

/*
- cumulative sum
- you take array and some queries (l, r) and you output sum numbers from index l to position r
*/

/*
- Ranged Sum
- you take array and some queries (l, r) and you should add one on numbers from index l to position r
- slv : for each query put arr[l] = 1 and arr[r + 1] = -1
- after end all queries do prefix sum on all array
 */
