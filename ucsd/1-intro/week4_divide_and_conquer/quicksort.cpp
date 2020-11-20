#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  // save leftmost element (which is the randomly selected value from below)
  int x = a[l];
  // j is a placeholder for the partition point. 
  // we start by setting it at the leftmost element
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    // if the element being inspected is less than the partition element, swap it into lower segment
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  // swap partition element back to rightmost end of 
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<int> &a, int lo, int hi, int &middle_left, int &middle_right){
  int x  = a[lo];
  middle_left = lo;
  middle_right = hi;
  int i = lo + 1;
  while(i <= middle_right){
    if (a[i] < x){
      swap(a[i], a[middle_left]);
      middle_left++;
      i++;
    }
    else if (a[i] == x){
      i++;
    }
    else if (a[i] > x){
      swap(a[i], a[middle_right]);
      middle_right--;
    }
  }  
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  // generate random array index to partition at
  int k = l + rand() % (r - l + 1);
  // swap randomly selected element with leftmost element
  swap(a[l], a[k]);
  int middle_left = l;
  int middle_right = r;
  //int m = partition2(a, l, r);
  //randomized_quick_sort(a, l, m - 1);
  //randomized_quick_sort(a, m + 1, r);
  partition3(a, l, r, middle_left, middle_right);
  randomized_quick_sort(a, l, middle_left - 1);
  randomized_quick_sort(a, middle_right + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << "\n";
  system("pause");
}
