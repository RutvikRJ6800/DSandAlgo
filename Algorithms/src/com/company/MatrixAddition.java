// Make Matrix Additon
package com.company;

import java.util.Scanner;


public class MatrixAddition {

    public static void main(String[] args) {
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
        for (int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        System.out.println("Sum of two array is");
        for (int i = 0; i<3 ; i++){
            for (int j=0; j<3; j++){
                System.out.print(c[i][j]+" ");
            }
            System.out.println();
        }
    }
}
