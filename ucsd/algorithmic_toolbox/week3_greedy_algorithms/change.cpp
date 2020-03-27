#include <iostream>
#include <vector>
int get_change(int m) {
    //write your code here
    int n = 0;
    int i = 0;
    std::vector<int> coins = { 10, 5, 1 };
    while (m != 0) {
        n += m / coins[i];
        m = m % coins[i];
        i++;
    }
    return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
