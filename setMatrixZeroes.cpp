/*
Approach:
1. Use the first row and the first column of the matrix to mark which rows and columns need to be set to 0.
2. Traverse the first row to check if it contains any zeros. If so, mark a flag (`FirstRowZero`) as true.
3. Similarly, traverse the first column to check if it contains any zeros. Mark another flag (`FirstColumnZero`) as true.
4. Traverse the rest of the matrix (excluding the first row and column). If a zero is encountered at `matrix[i][j]`, set `matrix[i][0]` and `matrix[0][j]` to 0.
5. Traverse the matrix again (excluding the first row and column). If either `matrix[i][0]` or `matrix[0][j]` is 0, set `matrix[i][j]` to 0.
6. If the first row or first column was marked earlier, set the entire first row or column to 0.

Time Complexity:
- O(m * n), where `m` is the number of rows and `n` is the number of columns.
  - Initial traversal to check the first row and column: O(m + n).
  - Second traversal to mark rows and columns based on zeros: O((m - 1) * (n - 1)).
  - Final traversal to update matrix: O((m - 1) * (n - 1)).
  - Overall: O(m * n).

Space Complexity:
- O(1) (in-place operation; no extra space used except for a few boolean variables).
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    bool FirstRowZero= false;
    bool FirstColumnZero= false;
    
    
    for(int i=0; i < n; i++){
        if(matrix[0][i]==0){
            FirstRowZero=true;
            break;
        }
    }
    for(int j=0; j < m; j++){
        if(matrix[j][0]==0){
            FirstColumnZero=true;
            break;
        }
    }
    for(int i=1; i < m; i++){
        for(int j=1; j < n; j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    
    for(int i=1; i<m; i++){
            for(int j=1; j<n ; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
    }
    
    if(FirstRowZero){
        for(int i=0; i<n; i++){
            matrix[0][i]=0;
        }
    }
    if(FirstColumnZero){
        for(int i=0; i<m; i++){
            matrix[i][0]=0;
        }
    }
    
    cout << "Modified Matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " "; 
        }
        cout << endl;
    }
    

    return 0;
}