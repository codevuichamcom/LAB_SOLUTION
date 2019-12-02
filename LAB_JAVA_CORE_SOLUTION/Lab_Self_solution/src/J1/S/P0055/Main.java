package J1.S.P0055;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class Main {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        ArrayList<Doctor> lst = new ArrayList<>();
        MyListDoctor M = new MyListDoctor();
        Validate validate =  new Validate();
        boolean loop = true;
         while(loop){
            System.out.println("---------- Doctor Infomation ----------");
            System.out.println("1. Add Doctor");
            System.out.println("2. Update Doctor");
            System.out.println("3. Delete Doctor");
            System.out.println("4. Search Doctor");
            System.out.println("5. Exit");
            int choice = validate.getInt("Enter choice(1-5): ", "Enter again!!", 1, 5);
            switch(choice){
                case 1:
                    M.addDoctor(lst);
                    break;
                case 2:
                    M.updateDoctor(lst);

                    break;   
                case 3:
                    M.deleteDoctor(lst);
                    break;   
                case 4:
                    M.searchDoctor(lst);
                    break;
                case 5:
                    loop = false;
                    break;

            }
        }
    }
}
