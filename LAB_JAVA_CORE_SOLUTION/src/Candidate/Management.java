/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Candidate;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

/**
 *
 * @author ThinkPro
 */
public class Management {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    Validate validate=new Validate();
    
    public int isIdExist(ArrayList<Candidates> lst,int value){
        for(int i=0;i<lst.size();i++){
            if(value==lst.get(i).getId())
                return i;
        }
        return -1;
    }
    
    public void addCandidates(ArrayList<Candidates> lst,int type) throws IOException{
        int Id;
        do{
            Id=validate.getInt("Enter Id: ", "Enter again!!!", 1, Integer.MAX_VALUE);
        }while(isIdExist(lst, Id)!=-1);
        
        String firstName = validate.getString("Enter first name: ");
        String lastName = validate.getString("Enter last name: ");
        String birthDate="";
        while(true){
            birthDate=validate.getString("Enter Birth Date: ");
            if(validate.isDateFormat("dd/MM/yyyy", birthDate)){
                String [] tmp = birthDate.split("/");
                int year=Integer.parseInt(tmp[2]);
                if(year>=1900&&year<=2019){
                    birthDate=year+"";
                    break;
                }else{
                    System.out.println("Year of brithday is number that has four digit(1900-2019)");
                }
            }else{
                System.out.println("Invalid date, please input again");
            }
        }
        
        String address=validate.getString("Enter address: ");
        String phone=validate.getString("[0-9]{10,}", "Enter a phone number: ");
        String email=validate.getString("^[a-zA-Z]\\w+@([a-zA-Z]\\w+\\.)+[a-zA-Z]\\w+$", "Enter a email: ");
        
        switch(type){
            case 0: 
                int year=0;String pro="";
                addExperience(year, pro);
                Experience E = new Experience(Id, firstName, lastName, birthDate, address, phone, email, 0, year, pro);
                lst.add(E);
                break;
            case 1: 
                String graDate="", graRank="",education="";
                addFresher(graDate, graRank,education);
                Fresher F = new Fresher(Id, firstName, lastName, birthDate, address, phone, email, 1, graDate, graRank,education);
                lst.add(F); 
                break;
            case 2: 
                String Majors="";int Semester=0; String UniversityName="";
                addIntern(Majors, Semester, UniversityName);
                Intern I = new Intern(Id, firstName, lastName, birthDate, address, phone, email, 2, Majors, Semester, UniversityName);
                lst.add(I);
                break;
        }
        
        
        
        
    }
    public void addExperience(int year,String pro) throws IOException{
        year=validate.getInt("Enter year of experience: ", "Enter again!!!", 0, 100);
        pro=validate.getString("Enter Professional Skill: ");
    }
    
    public void addFresher(String graDate,String graRank,String education) throws IOException{
        do {            
            graDate=validate.getString("Enter graduated time: ");
        } while (validate.isDateFormat("dd/MM/yyyy", graDate));
        do {            
            graRank=validate.getString("Enter rank of graduation: ");
        } while (graRank!="Excellence"||graRank!="Good"||graRank!="Fair"||graRank!="Poor");
        education=validate.getString("Enter education:");
        
    }
    public void addIntern(String Majors,int Semester, String UniversityName) throws IOException{
        Majors=validate.getString("Enter major: ");
        Semester=validate.getInt("Enter semester", "Enter again!!!", 0, Integer.MAX_VALUE);
        UniversityName=validate.getString("Enter University Name: ");
    }
    public void search(ArrayList<Candidates> lst) throws IOException {
        if (lst.isEmpty()) {
            System.out.println("List is empty , please add more element.");
        } else {
            String nameToSeach = validate.getString("Input Candidate name (First name or Last name): ");
            int type = validate.getInt("Input type of candidate: ", "Enter again!!!", 0, 2);
            System.out.println("The candidates found:");
            for (int i = 0; i < lst.size(); i++) {
                String fullName = (lst.get(i).getFirsName() + lst.get(i).getLastName()).toLowerCase();
                if (fullName.indexOf(nameToSeach.toLowerCase()) != -1) {
                    print(lst, i);
                }
            }
        }
    }
    public void print(ArrayList<Candidates> lst,int i){
            String fullname = lst.get(i).getFirsName()+" "+lst.get(i).getLastName();
            System.out.println(fullname+" | "+lst.get(i).getBirthDate()+" | "+lst.get(i).getAddress()+" | "+lst.get(i).getPhone()+" | "+lst.get(i).getEmail()+" | "+lst.get(i).getType());
    }
    public void printAll(ArrayList<Candidates> lst){
        for(int i=0;i<lst.size();i++){
            print(lst, i);
        }
    }
    
    
}
