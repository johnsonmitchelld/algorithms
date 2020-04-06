#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;

struct Point
{
  int x;
  int y;
};

bool CompareX(Point point1, Point point2){
  return (point1.x < point2.x);
}

bool CompareY(Point point1, Point point2){
  return (point1.y < point2.y);
}

double find_distance(Point point1, Point point2){
  return sqrt((double) (pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2)));
}

vector<Point> minimal_distance_(vector<Point> &points, int lo, int hi, double &min_dist){
  vector<Point> points_y_sorted(hi-lo+1);
  double cur_dist = 0.0;
  if (hi - lo <= 2){
    // bottom of recursion tree
    int j = 0;
    for(int i = lo; i <= hi; i++){
      points_y_sorted[j] = points[i];    
      for(int k = j - 1; k >= 0; --k){
        cur_dist = find_distance(points_y_sorted[j], points_y_sorted[k]);
        if(j == 1){
          min_dist = cur_dist;
        }
        if (cur_dist < min_dist){
          min_dist = cur_dist;
        }
      }
      ++j;
    }
    std::sort(points_y_sorted.begin(), points_y_sorted.end(), CompareY);
  }
  else{
    int mid = (hi + lo) / 2;
    double mid_x_coord = (points[mid+1].x + points[mid].x) / 2.0;
    double min_dist_left{0.0};
    double min_dist_right{0.0};
    vector<Point> left_y_sorted = minimal_distance_(points, lo, mid, min_dist_left);
    vector<Point> right_y_sorted = minimal_distance_(points, mid+1, hi, min_dist_right);
    if (min_dist_left < min_dist_right){
      min_dist = min_dist_left;
    }
    else{
      min_dist = min_dist_right;
    }
    
    int left_i = left_y_sorted.size() - 1;
    int right_i = right_y_sorted.size() - 1;
    for(int i = points_y_sorted.size() - 1; i >= 0; --i){
      if(right_i < 0 || (left_i >= 0 && left_y_sorted[left_i].y > right_y_sorted[right_i].y)){
        points_y_sorted[i] = left_y_sorted[left_i];
        --left_i;
      }
      else{
        points_y_sorted[i] = right_y_sorted[right_i];
        --right_i;
      }
    }
    double current_dist{0.0};
    for(int i = 0; i < points_y_sorted.size(); i++){
      int z = i;
      int val = points_y_sorted[i].x;
      if(abs(points_y_sorted[i].x - mid_x_coord) < min_dist){
        int j = i + 1;
        int k = i + 1;
        while(j < i + 8 && k < points_y_sorted.size()){
          if(abs(points_y_sorted[j].x - mid_x_coord) < min_dist){
            current_dist = find_distance(points_y_sorted[i], points_y_sorted[j]);
            if(current_dist < min_dist){
              min_dist = current_dist;
            }
            ++j;
          }
          ++k;
        }
      }
    }
  }
  return points_y_sorted;
}

double minimal_distance(vector<Point> &points) {
  // fill points_y with integers 0:n
  // sort points_y by y values in points
  double min_dist;
  int lo = 0;
  int hi  = points.size() - 1;
  std::sort(points.begin(), points.end(), CompareX);
  vector<Point> points_y_sorted = minimal_distance_(points, lo, hi, min_dist);
  return min_dist;
}

int main() {
  size_t n;
  std::cin >> n;
  int x;
  int y;
  //vector<int> x = {4, -2, -3, -1, 2, -4, 1, -1, 3, -4, -2};
  //vector<int> y = {4, -2, -4, 3, 3, 0, 1, -1, -1, 2, 4};
  vector<Point> points(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x >> y;
    points[i] = Point {x, y};
    //points[i] = Point {x[i], y[i]};
  }

  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points) << "\n";
  //system("pause");
}
