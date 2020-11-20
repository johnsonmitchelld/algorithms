#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_euclidean(int a, int b) {
    int r = 1;
    while (r != 0) {
        if (a < b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm_quick(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (long long) a * b / gcd_euclidean(a, b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_quick(a, b) << std::endl;
  return 0;
}
