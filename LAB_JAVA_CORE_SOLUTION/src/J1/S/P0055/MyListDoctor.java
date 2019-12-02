/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package J1.S.P0055;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class MyListDoctor {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    Validate validate = new Validate();
    
        public void addDoctor(ArrayList<Doctor> lst) throws IOException{
            String code="";
            do{
                code =validate.getString("[a-zA-Z 0-9]+", "Enter code: ");
                if(validate.indexID(lst, code)!=-1){
                    System.out.println("code is existed. please another code.");
                }
            }while(validate.indexID(lst, code)!=-1);
            String name = validate.getString("[a-zA-Z ]+", "Enter Name: ");
            String specialization = validate.getString("[a-zA-Z]+", "Enter Specialization: ");
            int availability =validate.getInt("Enter Availability: ", "Enter a positive integer.", 1, Integer.MAX_VALUE);
            Doctor D = new Doctor(code, name, specialization, availability);
            lst.add(D);
        }
        
        public void updateDoctor(ArrayList<Doctor> lst) throws IOException{
            
            String code=validate.getString("[a-zA-Z 0-9]+", "Enter code to update: ");
            if(validate.indexID(lst, code)==-1){
                System.out.println("Doctor code does not exist");
            }else{
                int indexCode = validate.indexID(lst, code);
                System.out.println("1. Update Code:");
                System.out.println("2. Update Name:");
                System.out.println("3. Update Specialization:");
                System.out.println("4. Update Availability:");

                int option=validate.getInt("Enter option(1-4): ", "Enter again.", 1, 4);

                switch(option){
                    case 1:
                        String N_code="";
                        do {                            
                            N_code=validate.getString("[a-zA-Z 0-9]+", "Enter new Code: ");
                            if(validate.indexID(lst, N_code)!=-1){
                                System.out.println("Code is existed, enter another code.");
                            }
                        } while (validate.indexID(lst, N_code)!=-1);
                        lst.get(indexCode).setCode(N_code);
                        break;
                    case 2:
                        String N_name="";
                        do {                            
                            N_name=validate.getString("[a-zA-Z ]+", "Enter new name: ");
                            if(N_name.equalsIgnoreCase(lst.get(indexCode).getName())){
                                System.out.println("Name is same old name, enter another name.");
                            }
                        } while (N_name.equalsIgnoreCase(lst.get(indexCode).getName()));
                        lst.get(indexCode).setName(N_name);
                        break;
                    case 3:
                        String N_Specialization="";
                        do {                            
                            N_Specialization=validate.getString("[a-zA-Z ]+", "Enter new Availability: ");
                            if(N_Specialization.equalsIgnoreCase(lst.get(indexCode).getSpecialization())){
                                System.out.println("Specialization is same old Specialization, enter another Specialization.");
                            }
                        } while (N_Specialization.equalsIgnoreCase(lst.get(indexCode).getSpecialization()));
                        lst.get(indexCode).setSpecialization(N_Specialization);
                        break;
                    case 4:
                        int N_Availability=0;
                        do {                            
                            N_Availability =validate.getInt("Enter Availability: ", "Enter a positive integer.", 1, Integer.MAX_VALUE);
                            if(N_Availability==lst.get(indexCode).getAvailability()){
                                System.out.println("Availability is same old Availability, enter another Availability.");
                            }
                        } while (N_Availability==lst.get(indexCode).getAvailability());
                        lst.get(indexCode).setAvailability(N_Availability);
                        break;
                }
            }
            
            
        }
        
        public void deleteDoctor(ArrayList<Doctor> lst) throws IOException{
            String code=validate.getString("[a-zA-Z 0-9]+", "Enter code to update: ");
            if(validate.indexID(lst, code)==-1){
                System.out.println("Doctor code does not exist");
            }else{
                int indexCode = validate.indexID(lst, code);
                lst.remove(indexCode);
                
            }
        }
        
        public void searchDoctor(ArrayList<Doctor> lst) throws IOException{
            String text=validate.getString("[a-zA-Z ]+","Enter text: ");
            for(Doctor d : lst){
                if(d.getCode().contains(text)||d.getName().contains(text)
                        ||d.getSpecialization().contains(text)||(d.getAvailability()+"").contains(text)){
                    System.out.println(d.getCode()+"\t"+d.getName()+"\t"+d.getSpecialization()+"\t"+d.getAvailability());
                }
            }
        }
        
    
}
