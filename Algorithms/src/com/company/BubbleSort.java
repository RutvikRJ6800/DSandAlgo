package com.company;

import java.util.Scanner;

public class BubbleSort {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] arr = new int[n];

        for (int i =0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        boolean swapped = false;
        for(int i=0; i<n; i++){
            swapped = false;
            for (int j =0; j<n-1-i;j++){
                if(arr[j+1]<arr[j]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swapped = true;
                }


            }
            if(swapped == false){
                break;
            }
        }
        System.out.println("Sorted array is");
        for(int e:arr){
            System.out.print(e+" ");
        }

    }
}
