class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>> pq; // minheap
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
        // sort(arr.begin(),arr.end());
        // return arr[arr.size()-k];
    }
};