#include<bits/stdc++.h>
using namespace std;
// int t[1001][1001];
// int solve(string &s1 , string &s2 , int i , int j){
//     if(i >= s1.length() || j >= s2.length())
//         return 0;
    
//     if(t[i][j] != -1){
//         return t[i][j];
//     }

//     if(s1[i] == s2[j]){
//         return t[i][j] = 1 + solve(s1 , s2 , i+1 , j+1);
//     }

//     else{
//         return t[i][j] = max( solve(s1 ,s2 , i+1 ,j) , solve(s1 , s2 , i , j+1));
//     }
// }
int longCommonSub(string s1 , string s2){
    int n = s1.length();
    int m = s2.length();
     
    // memset(t , -1 , sizeof(t));
    // return solve(s1 , s2 , 0 , 0);

    vector<vector<int>> t(n+1, vector<int>(m+1));
    for(int i=0; i<n+1; i++){
        t[i][0] = 0;
    }

    for(int j=0; j<m+1; j++){
        t[0][j] = 0;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }

            else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
    return t[n][m];
}
int main(){

    string s1;
    cout << "Enter the first string :";
    cin >> s1;
    
    string s2;
    cout << "Enter the second string :";
    cin >> s2;
    
    int result = longCommonSub(s1 , s2);

    cout << "The longest common subsequence in both the strings is :" << result <<endl;

    return 0;
}
