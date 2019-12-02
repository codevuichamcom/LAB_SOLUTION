/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package J1.S.P0056;

import java.util.Random;

/**
 *
 * @author ThinkPro
 */
public class BinarySearch {
    public static void main(String[] args) {
        Validate validate = new Validate();
        int length = validate.getInt("Enter number of array:", "Enter a Positive integer",1,Integer.MAX_VALUE);
  
        int search = validate.getInt("Enter search value:", "Enter a integer",Integer.MIN_VALUE,Integer.MAX_VALUE);

        int[] array = new int[length];
        for (int i = 0; i < length; i++) {
            array[i] = new Random().nextInt(length);
        }
        
            
        BinarySearch searcher = new BinarySearch();
        System.out.print("The array: ");
        searcher.displayArray(array);
        searcher.sort(array);
        System.out.println("\nThe array after sort: ");
        searcher.displayArray(array);

        int foundIndex = searcher.binarySearch(array, search);
        if(foundIndex!=-1)
            System.out.println("\nFound " + search + " at index: " + foundIndex);
        else
            System.out.println("\nDon't find "+search+" in array.");
    }

    public void displayArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length-1; i++) {
            System.out.print(arr[i]+", ");
        }
        System.out.print(arr[arr.length-1]+"]");
    }

    public int binarySearch(int[] array, int target) {
        int left=0;
        int mid;
        int right=array.length-1;
        while(left<=right){
            mid=(left+right)/2;
        if(array[mid]==target)
            return mid;
        else if(target<array[mid])
            right=mid-1;
        else
            left=mid+1;
        }
        return -1;
        
    }
    
    public void sort(int[] a){
        for(int i=0;i<a.length-1;i++){
            for(int j=i+1;j<a.length;j++){
                if(a[i]>a[j]){
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        
    }
}
