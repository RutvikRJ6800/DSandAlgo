class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     
        
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
  for (int i = 0; i < rows; i++) {
    //checking if 0 is present in the 0th column or not
    if (matrix[i][0] == 0) col0 = 0;
    for (int j = 1; j < cols; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  //traversing in the reverse direction and
  //checking if the row or col has 0 or not
  //and setting values of matrix accordingly.
  for (int i = rows - 1; i >= 0; i--) {
    for (int j = cols - 1; j >= 1; j--) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
    if (col0 == 0) {
      matrix[i][0] = 0;
    }

  }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//     set<int> stRow;
//     set<int> stColumn;
//     // int n11 = matrix.size();
//     // int n12 = matrix[0].size();

//     for(int i=0; i<matrix.size(); i++){

//         for(int j=0; j<matrix[i].size(); j++){
            
//             if(matrix[i][j]==0){
//                 stRow.insert(i);
//                 stColumn.insert(j);
//             }
//         }
//     }

//     set<int>::iterator itr;
//     for (itr = stRow.begin(); itr != stRow.end(); itr++) {
//         int r= *itr;
//         for(int i=0; i<matrix[r].size(); ++i){
//             matrix[r][i]=0;
//         }
//     }

//     for (itr = stColumn.begin(); itr != stColumn.end(); itr++) {
//         int c= *itr;
//         for(int i=0; i<matrix.size(); ++i){
//             matrix[i][c]=0;
//         }
//     }

    }
};