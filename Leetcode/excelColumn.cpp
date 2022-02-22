// https://leetcode.com/problems/excel-sheet-column-number/submissions/
#include <cmath>
class Solution {
public:
    int titleToNumber(string columnTitle) {
        
//         first aproach
        
        
//         size_t length = columnTitle.size();
        
//         unordered_map<char,int> alphabets;
//         alphabets['A'] = 1;
//         alphabets['B'] = 2;
//         alphabets['C'] = 3;
//         alphabets['D'] = 4;
//         alphabets['E'] = 5;
//         alphabets['F'] = 6;
//         alphabets['G'] = 7;
//         alphabets['H'] = 8;
//         alphabets['I'] = 9;
//         alphabets['J'] = 10;
//         alphabets['K'] = 11;
//         alphabets['L'] = 12;alphabets['M'] = 13;alphabets['N'] = 14;alphabets['O'] = 15;
//         alphabets['P'] = 16;alphabets['Q'] = 17;alphabets['R'] = 18;alphabets['S'] = 19;alphabets['T'] = 20;alphabets['U'] = 21;alphabets['V'] = 22;alphabets['W'] = 23;alphabets['X'] = 24;alphabets['Y'] = 25;alphabets['Z'] = 26;
        
//         int result = 0;
//         for(size_t i= 0; i<length; i++){
        
//         result = result + (pow(26,length-i-1))*(alphabets[columnTitle[i]]);
        // }
        
        int result=0; 
        int length=columnTitle.size();
        for(size_t i=0; i<length; i++){
            int d=columnTitle[i] - 'A' + 1;
            result = result*26 + d;
            
        }
        
    
        
     return result;   
    }
};