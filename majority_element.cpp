#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;

   
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    return (count > nums.size() / 2) ? candidate : -1; 
}

int main() {
    vector<int> nums = {3, 3, 4, 2, 3, 3, 3, 2, 4, 3};

    int result = findMajorityElement(nums);

    if (result != -1) {
        cout << "Majority Element: " << result << endl;
    } else {
        cout << "No Majority Element found!" << endl;
    }

    return 0;
}
