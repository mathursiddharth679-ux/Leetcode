//Yaad rakhne ka simple rule

//for loop + continue
//→ current iteration skip karke next iteration.

//Duplicate values ko continuously skip karna ho
//→ while + j++ useful hai.
//Time complexity : O(nlogn + n^2)
//So tumhara current j handling bilkul sahi approach hai.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     // use 2 pointer approach
     sort(nums.begin(),nums.end()); // O(nlogn) 
     vector<vector<int>> ans;
     int n = nums.size();
     for(int i = 0 ; i < n ; i++){ //O(N)
        if(i > 0 && nums[i]==nums[i-1]) continue; //repeated values wali condition
        int j = i + 1;
        int k = n - 1 ;
        while(j < k ){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum > 0){
                k--;
            }else if(sum < 0){
                j++;
            }else{
                vector<int> triplet = {nums[i],nums[j],nums[k]};
                ans.push_back(triplet);
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]) j++; // repeated values wali concition  // ~O(N) So total O(N*N) = O(N^2)
            }
        }
     }
     return ans;
    }
};
