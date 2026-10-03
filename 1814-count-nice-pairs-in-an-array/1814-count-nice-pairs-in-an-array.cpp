class Solution {
public:
    int rev(int n) {
        int r = 0;
        while(n > 0){
            r = r * 10 + (n % 10);
            n /= 10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int mod = 1e9 + 7;

        unordered_map<int, long long> m;
                for(int i=0; i<n; i++){
            nums[i] -= rev(nums[i]);
            m[nums[i]]++;
        }
        
        for(auto x : m){
            long long f = x.second;
            count = (count + (f * (f - 1)) / 2) % mod;
        }
        return count;
    }
};