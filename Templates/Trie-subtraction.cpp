// subtraction of minstring and suffix of this min string
// link problem (https://codeforces.com/group/1dLj6whCKn/contest/464950/problem/H)
struct Trie{
	struct Node{
		Node*child[26];
		int mn;
		Node(){
			memset(child,0,sizeof child);
			mn = O;
		}
	};
	Node*root=new Node();
	void insert(string &s)
	{
		Node*cur=root;
		for(auto it:s)
		{
			int idx=it-'a';
			if(cur->child[idx] == 0)
			{
				cur->child[idx]=new Node();
			}
			cur=cur->child[idx];
			cur->mn = min(cur->mn, (int)s.size());
		}
	}
	int find (string &s)
	{
		Node*cur=root;
		for(auto it:s)
		{
			int idx=it-'a';
			if (cur->child[idx] == 0) return -1;
			cur=cur->child[idx];
		}
		return cur->mn;
	}
};
