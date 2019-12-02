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
public class main {
    public static void main(String[] args) {
        int option;
        Validate validate = new Validate();
        CalculateEquation cal = new CalculateEquation();
        while(true){
            System.out.println("1. Calculate Superlative Equation");
            System.out.println("2. Calculate Quadratic Equation");
            System.out.println("3.Exit");
            System.out.println("Please choice one option");
            
            option=validate.getInt("", "Enter again");
            if(option==1){
                cal.calSupEquation();
            }
            
        }
        
    }
    
}
