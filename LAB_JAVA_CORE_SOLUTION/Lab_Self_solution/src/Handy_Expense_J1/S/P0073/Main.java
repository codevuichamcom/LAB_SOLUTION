/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Handy_Expense_J1.S.P0073;

import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author ThinkPro
 */
public class Main {

    public static void main(String[] args) throws Exception {
        Management M = new Management();
        ArrayList<Expenses> lst = new ArrayList<>();
        Validate validate = new Validate();

        boolean loop = true;
        while (loop) {
            System.out.println("===============System expense management=================");
            System.out.println("1. Add an expense\n"
                    + "2. Display all expenses\n"
                    + "3. Remove an expense\n"
                    + "4. Exit");

            int choice = validate.getInt("Enter choice[1-4]: ", "Enter again.", 1, 4);
            switch (choice) {
                case 1:
                    M.addExpense(lst);
                    break;
                case 2:
                    M.displayExpense(lst);
                    break;
                case 3:
                    M.deleteExPense(lst);
                    break;
                case 4:
                    loop = false;
                    break;
            }

        }
    }

}
