#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  edges root;
  t.push_back(root);
  edges* curNode;
  for (auto pattern: patterns) {
    curNode = &t[0];  
    for(char c: pattern) {
      if(curNode->find(c) != curNode->end()){
        curNode = &t[curNode->operator[](c)];
      }
      else {
        curNode->insert(std::pair<char, int>(c, t.size()));
        edges newNode;
        t.push_back(newNode);
        curNode = &t[t.size() - 1];
      }
    }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}