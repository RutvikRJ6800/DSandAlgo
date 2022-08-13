package com.company;

import java.util.Scanner;

public class MatrixMultiplication {
    public static void main(String args[]){
        // Make Matrix Additon
                int [][] a = new int[3][3],b =new int[3][3];
                Scanner sc = new Scanner(System.in);
                System.out.println("Enter Array a");
                for (int i = 0; i<3 ; i++){
                    for (int j=0; j<3; j++){
                        a[i][j] = sc.nextInt();
                    }
                }
                System.out.println("Enter Array b");

                for (int i = 0; i<3 ; i++){
                    for (int j=0; j<3; j++){
                        b[i][j] = sc.nextInt();
                    }
                }
                int c[][] = new int[3][3];
                int m,n,o,p;
                for (int i=0; i<3; i++){

                    for(int j=0; j<3; j++){

                        for(int k=0; k<3; k++){

                            c[i][j] = c[i][j] + a[i][k] * b[k][j];

                        }

                    }
                }
                System.out.println("Multiplication of two array is");
                for (int i = 0; i<3 ; i++){
                    for (int j=0; j<3; j++){
                        System.out.print(c[i][j]+" ");
                    }
                    System.out.println();
        }

    }
}
