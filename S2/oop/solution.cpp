#include<vector>
#include<iostream>
using namespace std;
#include<math.h>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        int sum;
        sum=(n*(n+1))/2;
        int ans=sum-accumulate(nums.begin(),nums.end(),0);
        // int n=nums.size();
        // int ans;
        // vector <int> temp(n,-1);
        // temp.push_back(2);
        // for(int i=0;i<n;i++)
        // {
        //     temp[nums[i]]=1;
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(temp[i]==-1)
        //     {
        //         ans=i;
        //         break;
        //     }
        // }
    return ans;
    }
};