/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Students_Management;

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
        ArrayList<Students> lst = new ArrayList<>();
        Validate validate = new Validate();
        Management management = new Management();
        int choice;
        while (true) {
            System.out.println("=============Student Management System=============");
            System.out.println("1. Create");
            System.out.println("2. Find and Sort");
            System.out.println("3. Update/Delete");
            System.out.println("4. Report");
            System.out.println("5. Exit");
            choice = validate.getInt("Enter your choice: ", "Enter again!!!", 1, 5);

            switch (choice) {
                case 1:
                    management.create(lst);
                    break;
                case 2:
                    management.findAndSort(lst);
                    break;

                case 3:
                    management.updateOrDelete(lst);
                    break;
                case 4:
                    management.report(lst);
                    break;

            }
        }
    }

}
