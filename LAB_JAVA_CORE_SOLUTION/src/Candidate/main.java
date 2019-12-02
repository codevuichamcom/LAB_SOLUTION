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
public class main {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
                ArrayList<Candidates> lst = new ArrayList<>();
                Validate validate = new Validate();
                Management management = new Management();
        int choice;
        boolean loop_condition = true;
        while(loop_condition){
            System.out.println("=============Candidates Management System=============");
            System.out.println("1. Experience");
            System.out.println("2. Fresher");
            System.out.println("3. Internship");
            System.out.println("4. Seaching");
            System.out.println("5. Exit");
            choice = validate.getInt("Enter your choice: ", "Enter again!!!", 1, 5);
            switch(choice){
                case 1:
                    management.addCandidates(lst, 0);
                    validate.checkYesNo(lst, 0);
                    
                    break;
                case 2:
                    management.addCandidates(lst, 1);
                    validate.checkYesNo(lst, 1);
                    break;
                case 3:
                    management.addCandidates(lst, 2);
                    validate.checkYesNo(lst, 2);
                    break;
                case 4:
                    management.search(lst);
                    break;
                case 5:
                    loop_condition=false;
            }
        }
    }
    
}
