#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

vector<Node> buildTrie(const vector <string>& patterns) {
	vector <Node> trie(1);
	int index = 0;
	for (auto pattern: patterns) {
		index = 0;
		for (auto c: pattern) {
			Node& curNode = trie[index];
			if (curNode.next[letterToIndex(c)] == NA) {
				index = trie.size();
				curNode.next[letterToIndex(c)] = index;
				Node newNode;
				trie.push_back(newNode);
			}
			else {
				index = curNode.next[letterToIndex(c)];
			}
		}
	}
	return trie;
}

vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;

	vector<Node> trie = buildTrie(patterns);
	
	int curChar = 0;

	for (int patternStart = 0; patternStart < text.length(); patternStart++) {
		curChar = patternStart;
		int trieIndex = 0;
		while(true) {
			Node& curNode = trie[trieIndex];
			if (curNode.isLeaf()) {
				result.push_back(patternStart);
				break;
			}
			else if (curChar < text.length() && curNode.next[letterToIndex(text.at(curChar))] != NA){
				trieIndex = curNode.next[letterToIndex(text.at(curChar))];
				curChar++;
			}
			else {
				break;
			}
		}
	}

	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
