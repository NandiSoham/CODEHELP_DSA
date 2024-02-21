vector<vector<int>> threeSumBetterApproach(vector<int>& nums) {
//         int n = nums.size();
//         set <vector<int>> st;

//         for(int i = 0; i < n; i++){
//             set <int> hashset;
//             for(int j = i+1; j < n; j++){
//                 int thirdElement = -(nums[i] + nums[j]);
//                 if(hashset.find(thirdElement) != hashset.end()){
//                     vector<int> temp = {nums[i], nums[j], thirdElement};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(nums[j]);
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }