#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int64_t MaxPairwiseProduct(const std::vector<int>& numbers, int algo) {
    int64_t max_product = 0;
    int n = numbers.size();
    int64_t current_product{ 0 };
    if (algo == 0) {
        for (int first = 0; first < n; ++first) {
            for (int second = first + 1; second < n; ++second) {
                current_product = (int64_t) numbers[first] * numbers[second];
                max_product = std::max(max_product, current_product);
            }
        }
    }

    else if (algo == 1) {
        int first{ 0 };
        int second{ 0 }; 
        for (int i = 0; i < n; i++) {
            if (numbers[i] > second) {
                if (numbers[i] > first) {
                    second = first;
                    first = numbers[i];
                }
                else {
                    second = numbers[i];
                }
            }
        }
        max_product = (int64_t) first * second;
    }
    return max_product;
}

int main() {
    int algo{ 1 }; 
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers, algo) << "\n";
    return 0;
}
