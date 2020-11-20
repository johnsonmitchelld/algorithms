#include <cstddef>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::size_t;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  const size_t size1 = str1.size();
  const size_t size2 = str2.size();

  std::vector<std::vector<unsigned int>> matrix(size1 + 1, std::vector<unsigned int>(size2 +1));

  matrix[0][0] = 0;
  for(size_t i = 0; i <= size1; ++i) matrix[i][0] = i;
  for(size_t j = 0; j <= size2; ++j) matrix[0][j] = j;

  for(size_t i = 1; i <= size1; ++i){
    for(size_t j = 1; j <= size2; ++j){
      matrix[i][j] = std::min({ matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + (str1[i - 1] == str2[j - 1] ? 0 : 1) });
    }
  }

  return matrix[size1][size2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
