/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm> 

using namespace std;


std::map<std::pair<int,int>, bool> visited;

int move(vector<vector<int>> &M, int i, int j){
int m=M.size(), n=M[0].size();

visited[std::make_pair(i,j)] = true;
if(M[i][j]==0) {
    cout << "i=" << i << ", j=" << j << " 0000" << endl;
    return m*n+1;
}
if(M[i][j]==9) {
    cout << "i=" << i << ", j=" << j << " 9999" << endl;
    return 0;
}
int a,b,c,d;
a=b=c=d=m*n+1;
if(i-1>=0 && visited.find(std::make_pair(i-1,j)) == visited.end()) {
   a=move(M,i-1,j);
}
if(i+1<m  && visited.find(std::make_pair(i+1,j)) == visited.end()){
    b=move(M,i+1,j);
} 
if(j-1>=0  && visited.find(std::make_pair(i,j-1)) == visited.end()){
   c=move(M,i,j-1); 
} 
if(j+1<n  && visited.find(std::make_pair(i,j+1)) == visited.end()){
  d=move(M,i,j+1);  
} 
cout << "i=" << i << ", j=" << j << "----";
cout << "a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << endl;
return min(a,min(b,min(c,d))) + 1; 
}

int main() {
vector<vector<int> > M{ 
   { 1, 1, 1, 1, 1}, 
    { 1, 0, 0, 0, 1}, 
    { 1, 0, 0, 9, 1},
    { 1, 1, 1, 1, 1}
   
     /*  { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
        { 0, 0, 0, 0, 9, 0, 0, 0, 0, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }  */
};

int m=M.size(), n=M[0].size();
int res=move(M,0,0);
res=res>m*n? -1:res;
cout << res;

return 0;
}
