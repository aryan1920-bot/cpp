#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> nums, int target)
{
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==target || nums[i]>target)
        {
            return i;
        }
    }
    return nums.size();
}

int main()
{
    vector<int> nums;
    cout<<"enter n"<<endl;
    int n;
    cin>>n;
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    
    }
    int target;
    cout<<"enter target "<<endl;
    cin>>target;
    cout<<search(nums,target)<<endl;

}