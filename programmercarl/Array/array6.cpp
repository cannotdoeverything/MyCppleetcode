/*给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
输入描述
第一行输入为整数数组 Array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间，直至文件结束。
输出描述
输出每个指定区间内元素的总和*/
#include<iostream>
#include<vector>

using namespace std;
int main(){
    //前缀和 在涉及计算区间和的问题时非常有用
    int n,a,b;
    cin>>n;
    vector<int>vec(n);
    vector<int>p(n);
    int presum = 0;
    for(int i=0; i<n; i++){
        cin>>vec[i];
        presum += vec[i];
        p[i] = presum;
    }
    while(cin>>a>>b){
        int sum;
        if(a==0) sum = p[b];
        else sum = p[b]-p[a-1];
        cout<<sum<<endl;
    }
}