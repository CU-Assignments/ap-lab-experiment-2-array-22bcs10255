#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int k = 1; // First element is always unique
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i]; // Move unique element to its correct position
            k++;
        }
    }
    return k;
}

vector<int> twoSum(std::vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(nums);
    
    cout << "Number of unique elements: " << k << "\n";
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
    
    vector<int> nums2 = {2,7,11,15};
    int target = 9;
    vector<int> result = twoSum(nums2, target);
    
    cout << "Indices of two numbers that add up to target: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << "\n";
    
    return 0;
}
