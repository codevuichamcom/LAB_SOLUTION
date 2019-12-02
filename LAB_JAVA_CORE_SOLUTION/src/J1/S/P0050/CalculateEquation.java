/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package J1.S.P0050;

/**
 *
 * @author ThinkPro
 */
public class CalculateEquation {
    int a,b,c;
    double x;
    
    public void calSupEquation(){
        Validate validate = new Validate();
        do {            
            a=validate.getInt("Enter A:","Please input number");
            if(a==0)
                System.out.println("Enter (a<>0)");
        } while (a==0);
        
        b=validate.getInt("Enter B: ", "Please input number");
        x=(double)-b/a;
        
        System.out.println("Solution: x = "+x);
        System.out.print("Number is Odd:");
        int count=0;
        if(a%2==1){
            System.out.println(a);
            count++;
        }
            
        if(b%2==1){
            if(count>0)
                System.out.println(",\t"+b);
            else
                System.out.println(b);
            count++;
        }
        if(x%2==1){
            if(count>0)
                System.out.println(",\t"+x);
            else
                System.out.println(x);
            count++;
        }
        System.out.println("");
        System.out.print("Number is Even:");
        count=0;
        if(a%2==0){
            System.out.println(a);
            count++;
        }
            
        if(b%2==0){
            if(count>0)
                System.out.println(",\t"+b);
            else
                System.out.println(b);
            count++;
        }
        if(x%2==0){
            if(count>0)
                System.out.println(",\t"+x);
            else
                System.out.println(x);
            count++;
        }
        
        
    }
    
}
