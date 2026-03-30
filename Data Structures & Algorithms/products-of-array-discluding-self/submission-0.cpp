class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pre(nums.size());
        vector<int>post(nums.size());
        int i=0,j=nums.size()-1,p1=1,p2=1;
        while(i<nums.size()){
            p1*=nums[i];
            p2*=nums[j];
            pre[i]=p1;
            post[j]=p2;
            i++;j--;
        }
        vector<int>result;
        int m,prod,k;
        for(int i=0;i<nums.size();i++){
            m=i-1;k=i+1;
            if(m<0||k>nums.size()-1){
                if(m<0){
                    prod=post[k];
                    result.emplace_back(prod);
            }else{
                prod=pre[m];
                result.emplace_back(prod);
            }
        }else{
            prod=post[k]*pre[m];
            result.push_back(prod);
        }

    }
    return result;}
};
