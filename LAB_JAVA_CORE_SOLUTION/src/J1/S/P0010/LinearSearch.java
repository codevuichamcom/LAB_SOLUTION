/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package J1.S.P0010;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author Hai
 */
public class LinearSearch {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Validate validate = new Validate();
        int length = validate.getInt("Enter number of array:", "Enter a Positive integer",1,Integer.MAX_VALUE);
  
        int search = validate.getInt("Enter search value:", "Enter a integer",Integer.MIN_VALUE,Integer.MAX_VALUE);

        int[] array = new int[length];
        for (int i = 0; i < length; i++) {
            array[i] = new Random().nextInt(length);
        }
        LinearSearch searcher = new LinearSearch();
        System.out.print("The array: ");
        searcher.displayArray(array);

        if(searcher.check(array, search)==true){
        System.out.print("\nFound " + search + " at index: ");
        searcher.linerSearch(array, search);
        }else{
            System.out.println("\nNot Found!!!");
        }
    }

    public void displayArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length-1; i++) {
            System.out.print(arr[i]+", ");
        }
        System.out.print(arr[arr.length-1]+"]");
    }
    public boolean check(int[] arr, int key){
        int size = arr.length;
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                return true;
            }
        }
        return false;
    }
    public void linerSearch(int[] arr, int key) {
        int size = arr.length;
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                System.out.print(i+" ");
            }
        }
    }
}
