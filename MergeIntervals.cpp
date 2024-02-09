#include <iostream>
#include <ostream>
using namespace std;

class Solution {
public:
  vector<vector<int>> mergedIntervals;
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    int prev;
    vector<int> temp;
    for (int i = 0; i < intervals.size(); i++) {
      temp.clear();
      if (i == 0) {
        temp.push_back(intervals[i][0]);
        temp.push_back(intervals[i][1]);
        mergedIntervals.push_back(temp);
        prev = 0;
      }
      if (intervals[i][0] <= mergedIntervals[prev][1] &&
          intervals[i][1] <= mergedIntervals[prev][1]) {
        continue;
      } else if (intervals[i][0] <= mergedIntervals[prev][1] &&
                 intervals[i][1] > mergedIntervals[prev][1]) {
        mergedIntervals[prev][1] = intervals[i][1];
      } else {
        mergedIntervals.push_back(intervals[i]);
        prev++;
      }
    }
    return mergedIntervals;
  }
};

int main() {
  vector<vector<int>> intervals;
  cout << "enter the number of intervals" << endl;
  int n;
  cin >> n;
  int start;
  int end;
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    cin >> start;
    cin >> end;
    temp.push_back(start);
    temp.push_back(end);
    intervals.push_back(temp);
  }
  Solution obj;
  obj.merge(intervals);
  cout << "MergedIntervals are" << endl;
  for (int i = 0; i < obj.mergedIntervals.size(); i++) {
    cout << obj.mergedIntervals[i][0] << " " << obj.mergedIntervals[i][1]
         << endl;
  }
}
