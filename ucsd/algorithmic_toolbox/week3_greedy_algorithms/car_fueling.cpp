#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int range, vector<int> & stops) {
    // write your code here
    int last_fillup_location{ 0 };
    int last_fillup_location_index{ 0 };
    int skipped_stations{ 0 };
    int total_fillups{ 0 };
    while (last_fillup_location + range < dist) {

        if (last_fillup_location_index + skipped_stations < stops.size() && last_fillup_location + range >= stops[last_fillup_location_index + skipped_stations]) {
            skipped_stations++;
        }
        else if (total_fillups > 0 && skipped_stations == 1) {
            return -1;
        }
        else {
            total_fillups++;
            last_fillup_location_index += skipped_stations-1;
            skipped_stations = 1;
            last_fillup_location = stops[last_fillup_location_index];
        }
    }
    return total_fillups;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
