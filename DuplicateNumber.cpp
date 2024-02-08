#include <iostream>
#include <ostream>
using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      int index = abs(nums[i]) - 1;
      if (nums[index] < 0) {
        return abs(nums[i]);
      } else {
        nums[index] = -1 * nums[index];
      }
    }
    return -1;
  }
};

int main() {
  Solution obj;
  vector<int> nums;
  int n;
  cout << "Enter size of array" << endl;
  cin >> n;
  cout << "Enter array" << endl;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums.push_back(num);
  }
  int duplicate = obj.findDuplicate(nums);
  cout << "Duplicate number in the array is: " << duplicate << endl;
  return 0;
}
