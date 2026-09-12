//WE WILL USE  POINTER APPROACH HERE !
// i , j for loop iteration  and p , q 2 pointers
//Timecomplexity  : O(nlogn + n^3 ) Space complexity : O(unique elements ) ek ans hi toh use kiya alag se 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end()); //O(nlogn)

        int n = nums.size();

        for(int i = 0; i < n; i++) { //O(n)

            // Remove duplicate values for i
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            for(int j = i + 1; j < n; j++) {//O(n)

                // Remove duplicate values for j
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;

                int p = j + 1;
                int q = n - 1;

                while(p < q) {

                    int sum = nums[i] + nums[j] + nums[p] + nums[q];

                    if(sum < target) {
                        p++;
                    }
                    else if(sum > target) {
                        q--;
                    }
                    else {
                        // sum == target
                        ans.push_back({ nums[i] , nums[j] , nums[p] , nums[q] });
                        p++;
                        q--;
                        // Remove duplicate p
                        while(p < q && nums[p] == nums[p-1])
                            p++;
                        // Remove duplicate q
                        while(p < q && nums[q] == nums[q+1])
                            q--;
                    }
                }
            }
        }

        return ans;
    }
};
