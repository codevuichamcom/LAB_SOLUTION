package J1.S.P0056;


import J1.S.P0010.*;
import J1.S.P0050.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ThinkPro
 */
public class Validate {
    public int getInt(String msg, String err, int min, int max){
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            int a=0;
            boolean check;
            do{
                check=true;
                try {
                    System.out.print(msg);
                    a=Integer.parseInt(in.readLine());
                    if(a<min||a>max){
                        System.out.println("Enter a positive Integer");
                        check=false;
                    }
                } catch (Exception e) {
                    System.out.println(err);
                    check=false;
                }
            }while(check==false);
            return a;
    }
}
