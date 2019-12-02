package Handy_Expense_J1.S.P0073;




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
    
    
    public int indexID(ArrayList<Expenses> lst ,int code){
        for(int i=0;i<lst.size();i++){
            if(lst.get(i).getID()==code){
                return i;
            }
        }
        return -1;
    }
    
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
    public double getDouble(String msg, String err, double min, double max){
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            double a=0;
            boolean check;
            do{
                check=true;
                try {
                    System.out.print(msg);
                    a=Double.parseDouble(in.readLine());
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
    public boolean checkDate(String format, String value) {
        Date date = null;
        SimpleDateFormat sdf = new SimpleDateFormat(format);
        sdf.setLenient(false);
        try {
            
            date = sdf.parse(value);
            Date now = new Date();
            if(date.after(now)){
                System.out.println("Ngay ban nhap lon hon ngay hien tai.");
                date=null;
            }
        }catch (Exception e) {
            date=null;
        }
        return date != null;
    }
}
