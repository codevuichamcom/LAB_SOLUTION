package Candidate;


import J1.S.P0010.*;
import J1.S.P0050.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

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
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    
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
                        System.out.println(err);
                        check=false;
                    }
                } catch (Exception e) {
                    System.out.println(err);
                    check=false;
                }
            }while(check==false);
            return a;
    }
    public String getString(String msg) throws IOException{
        String s="";
        do { 
            System.out.println(msg);
            s=in.readLine();
            if(s==null||s=="")System.out.println("Please enter a string.");
        } while (s==""||s==null);
        return s;
    }
    public String getString(String regex, String msg) throws IOException{
        String s = null;
        boolean check;
        do{
            check = true;
            System.out.println(msg);
            s = in.readLine();
            if(!s.matches(regex)){
                check = false;
            }   
        }while(check==false);
        return s;
    }
    public static boolean isDateFormat(String format, String value) {
        Date date = null;
        SimpleDateFormat sdf = new SimpleDateFormat(format);
        sdf.setLenient(false);
        try {
            
            date = sdf.parse(value);

        }catch (Exception e) {
            date=null;
        }
        return date != null;
    }
    public void checkYesNo(ArrayList<Candidates> lst, int type) throws IOException {
        Management m = new Management();
        do {
            String c = getString("[yYNn]", "Do you want to continue (Y/N)?");
            if (c.equalsIgnoreCase("y")) {
                m.addCandidates(lst, type);
            } else {
                break;
            }
        } while (true);
    }
}
