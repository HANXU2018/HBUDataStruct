class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums,res,0);
        return res;
    }
    void swap(int &a,int &b)
  {
      int temp;
      temp=a;
      a=b;
      b=temp;
  }
     void backtrack(vector<int> &nums,vector<vector<int>> &res,int i){
         if(i==nums.size())
             res.push_back(nums);
         for(int j=i;j<nums.size();j++){
             swap(nums[i],nums[j]);
             backtrack(nums,res,i+1);
             swap(nums[i],nums[j]);
         }
     }
};

作者：she-wo-qi-shui
链接：https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-c-by-she-wo-qi-shui/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。