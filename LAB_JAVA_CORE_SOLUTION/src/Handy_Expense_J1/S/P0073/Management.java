/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Handy_Expense_J1.S.P0073;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

/**
 *
 * @author ThinkPro
 */


public class Management {
    int ID=0;
    
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    Validate validate = new Validate();
    public void addExpense(ArrayList<Expenses> lst) throws Exception{
        ID++;
        String date="";
        do{
            System.out.println("Enter date valid(dd/MM/yyyy):");
            date=in.readLine();
        }while(validate.checkDate("dd/MM/yyyy", date)==false);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        Date date1=null;
        date1 = sdf.parse(date);
        SimpleDateFormat sdf1 = new SimpleDateFormat("dd-MMMM-yyyy");
        date=sdf1.format(date1);
        double number=validate.getDouble("Enter amount of money: ", "Enter a real positive", 1, Double.MAX_VALUE);
        String content=validate.getString("[a-zA-Z ]+", "Enter content: ");
        
        Expenses E = new Expenses(ID, date, number, content);
        lst.add(E);
    }
    
    public void displayExpense(ArrayList<Expenses> lst){
        if(lst.isEmpty()){
            System.out.println("List is empty. Please add at least Expense");
        }else{
            double Total=0;
            System.out.println("ID\tDate\t\t\tAmount of money\t\tContent");
            for(Expenses E :lst){
                System.out.println(E.getID()+"\t"+E.getDate()+"\t\t"+E.getNumber()+"\t\t\t"+E.getContent());
                Total+=E.getNumber();
            }
            System.out.println(" Total: "+Total);
        }
    }
    
    public void deleteByID(ArrayList<Expenses> lst, int idDelete){
        int index=validate.indexID(lst, idDelete);
        lst.remove(index);
        for(int i=index;i<lst.size();i++){
            lst.get(i).setID(lst.get(i).getID()-1);
        }
        ID--;
    }
    public void deleteExPense(ArrayList<Expenses> lst){
        if(lst.isEmpty()){
            System.out.println("List is empty. Please add at least Expense");
        }else{
            int ID=validate.getInt("Enter ID to detete: ", "Enter a positive integer: ", 1, Integer.MAX_VALUE);
            if(validate.indexID(lst, ID)==-1){
                System.out.println("Code you entered not exist.");
                System.out.println("Delete Expense Fail.");
            }else{
                deleteByID(lst, ID);
            }
        }
    }
}
