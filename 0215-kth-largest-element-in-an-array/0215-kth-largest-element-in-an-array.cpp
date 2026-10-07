class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        nth_element(arr.begin(), arr.begin() + k - 1, arr.end(), greater<int>());
        return arr[k - 1];
        // sort(arr.begin(),arr.end());
        // return arr[arr.size()-k];
    }
};
