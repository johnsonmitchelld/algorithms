#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

// implement both iteratively and recursively

int binary_search_recursive(const vector<int> &a, int x, int lo, int hi) {
  int mid = (lo + hi) / 2;
  if (x == a[mid]){
    return mid;
  }
  else if (mid == lo){
    if (x == a[hi]){
      return hi;
    }
    else {
      return -1;
    }
  }
  else if (x > a[mid]){
    return binary_search_recursive(a, x, mid, hi);
  }
  else if (x < a[mid]){
    return binary_search_recursive(a, x, lo, mid);
  }
}

int binary_search_iterative(const vector<int> &a, int x) {
  int lo = 0;
  int hi = a.size() - 1;
  int mid = 1;
  while (hi - lo > 1){
    mid = (hi + lo) / 2;
    if (x == a[mid]){
      return mid;
    }
    else if (x > a[mid]){
      lo = mid;
    }
    else if (x < a[mid]){
      hi = mid;
    }
  }
  if(x == a[lo]){
    return lo;
  }
  if(x == a[hi]){
    return hi;
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //std::cout << binary_search_recursive(a, b[i], 0, a.size() - 1) << ' ';
    std::cout << binary_search_iterative(a, b[i]) << ' ';
  }
  std::cout << "\n";
  system("pause");
}
  
