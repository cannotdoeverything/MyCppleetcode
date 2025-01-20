/*给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
示例:输入: 3 输出: [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]*/
#include<iostream>
#include<vector>

using namespace std;
class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> res(n,vector<int>(n,1));
        int loop = n/2,mid = n/2;
        int count = 1;
        int offset = 1;
        int startx=0, starty=0;
        int i,j;
        while(loop--){
            i = startx;
            j = starty;
            for(;j<n-offset;j++){
                res[i][j] = count++;
            }
            for(;i<n-offset;i++){
                res[i][j] = count++;
            }
            for(;j>starty;j--){
                res[i][j] = count++;
            }
            for(;i>startx;i--){
                res[i][j] = count++;
            }
            offset +=1;
            startx++;
            starty++;
        }
        if(n%2 != 0){
            res[mid][mid] = count++;
        }
        return res;
    }
};

int main(){
    Solution sol;
    int n =5;
    vector<vector<int>> res =  sol.generateMatrix(n);
    for(const auto& row : res){
        for(int num : row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
