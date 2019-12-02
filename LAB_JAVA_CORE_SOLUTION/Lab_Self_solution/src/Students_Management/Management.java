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
import java.util.Collections;
import java.util.Comparator;

/**
 *
 * @author ThinkPro
 */
public class Management {

    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    Validate validate = new Validate();

    public int indexID(ArrayList<Students> lst, int value) {
        for (int i = 0; i < lst.size(); i++) {
            if (value == lst.get(i).getId()) {
                return i;
            }
        }
        return -1;
    }

    public int indexSemester(ArrayList<Students> lst, int value) {
        for (int i = 0; i < lst.size(); i++) {
            if (value == lst.get(i).getSemester()) {
                return i;
            }
        }
        return -1;
    }

    public int indexCourse(ArrayList<Students> lst, String value) {
        for (int i = 0; i < lst.size(); i++) {
            if (value.equalsIgnoreCase(lst.get(i).getCourseName())) {
                return i;
            }
        }
        return -1;
    }

    public int indexStudent(ArrayList<Students> lst, Students stu) {
        for (int i = 0; i < lst.size(); i++) {
            if (stu.getId() == lst.get(i).getId() && stu.getSemester() == lst.get(i).getSemester()
                    && stu.getStudentName().equalsIgnoreCase(lst.get(i).getStudentName())
                    && stu.getCourseName().equalsIgnoreCase(lst.get(i).getCourseName())) {
                return i;
            }
        }
        return -1;
    }

    public void create(ArrayList<Students> lst) throws IOException {
        int Id = validate.getInt("Enter Id: ", "Enter again!!!", 1, Integer.MAX_VALUE);
        int semester = 0;
        String courseName = "", name;
        String studentName = "";
        if (indexID(lst, Id) != -1) {
            studentName = lst.get(indexID(lst, Id)).getStudentName();
            semester = validate.getInt("Enter semester: ", "Enter again!!!", 1, Integer.MAX_VALUE);

            do {
                courseName = validate.getString("[a-zA-Z ./+]+", "Enter course name (Java, .Net, C/C++): ");
                name = courseName.toLowerCase().trim();
            } while (!name.equals("java") && !name.equals(".net") && !name.equals("c/c++"));
        } else {
            studentName = validate.getString("[a-zA-Z ]+", "Enter student Name: ");

            semester = validate.getInt("Enter semester: ", "Enter again!!!", 1, Integer.MAX_VALUE);

            do {
                courseName = validate.getString("[a-zA-Z ./+]+", "Enter course name (Java, .Net, C/C++): ");
                name = courseName.toLowerCase().trim();
            } while (!name.equals("java") && !name.equals(".net") && !name.equals("c/c++"));
        }

        Students S = new Students(Id, studentName, semester, courseName);
        if (indexStudent(lst, S) != -1) {
            System.out.println("Student you want to create is exist,can't create");
            create(lst);
        } else {
            lst.add(S);
        }
    }

    public void findAndSort(ArrayList<Students> lst) throws IOException {
        if(lst.isEmpty()){
            System.out.println("List is empty. please add student");
            return;
        }
        ArrayList<Students> newList = new ArrayList<>();
        String name = validate.getString("[a-zA-Z ]+", "Enter Name: ");
        name = name.toLowerCase();
        for (int i = 0; i < lst.size(); i++) {
            if (lst.get(i).getStudentName().toLowerCase().indexOf(name) != -1) {
                newList.add(lst.get(i));
            }
        }
        Collections.sort(newList, new Comparator<Students>() {
            @Override
            public int compare(Students o1, Students o2) {
                return o1.getStudentName().compareTo(o2.getStudentName());
            }
        });
        for (int i = 0; i < newList.size(); i++) {
            System.out.println(newList.get(i).getStudentName() + " | " + newList.get(i).getSemester() + " | " + newList.get(i).getCourseName());
        }
    }

    public void updateOrDelete(ArrayList<Students> lst) throws IOException {
        if(lst.isEmpty()){
            System.out.println("List is empty. please add student");
            return;
        }
        int Id;
        do {
            Id = validate.getInt("Enter ID to search: ", "Enter a positive integer", 1, Integer.MAX_VALUE);
            if (indexID(lst, Id) == -1) {
                System.out.println("ID you entered not have in list");
            }
        } while (indexID(lst, Id) == -1);
        int indexID = indexID(lst, Id);
        String s = validate.getString("[uUdD]", "Do you want to update (U) or delete (D) student");
        int N_semester = 0;
        String N_courseName = "";
        String N_studentName = "";

        Students Temp_student = new Students();
        //Thực Hiện Update
        if (s.equalsIgnoreCase("u")) {
            System.out.println("1. update name.");
            System.out.println("2. update semester.");
            System.out.println("3. update course.");
            int option = validate.getInt("Choose option(1-3)", "Enter a number[1-3]", 1, 3);
            switch (option) {
                case 1:
                    N_studentName = validate.getString("[a-zA-Z ]+", "Enter new Name:");
                    if (!N_studentName.equals(lst.get(indexID).getStudentName()) ) {
                        for (int i = 0; i < lst.size(); i++) {
                            if (lst.get(i).getId() == Id) {
                                lst.get(i).setStudentName(N_studentName);
                            }
                        }
                        System.out.println("Update successfully");
                    } else {
                        System.out.println("please enter another name.");
                    }
                    break;
                case 2:
                    int indexUpdate;
                    String O_Course;
                    int O_Semester = 0;
                    //Nhập semester cũ
                    do {
                        O_Semester = validate.getInt("Enter old semester what you want to update: ", "please enter a positive integer.", 1, Integer.MAX_VALUE);
                        if (indexSemester(lst, O_Semester) == -1) {
                            System.out.println("Not found semester in list.");
                        }
                    } while (indexSemester(lst, O_Semester) == -1);
                    //Nhập course cũ
                    String n = "";
                    do {
                        O_Course = validate.getString("[a-zA-Z ./+]+", "Enter old course what you want to update");

                        if (indexCourse(lst, O_Course) == -1) {
                            System.out.println("Not found course in list.");
                        }
                        n = O_Course.toLowerCase().trim();
                        if (!n.equals("java") && !n.equals(".net") && !n.equals("c/c++")) {
                            System.out.println("Enter course name (Java, .Net, C/C++):");
                        }
                    } while (indexCourse(lst, O_Course) == -1 && !n.equals("java") && !n.equals(".net") && !n.equals("c/c++"));

                    String name = lst.get(indexID).getStudentName();

                    Temp_student = new Students(Id, name, O_Semester, O_Course);

                    indexUpdate = indexStudent(lst, Temp_student);
                    if (indexUpdate != -1) {
                        boolean check;
                        do {
                            check = true;
                            N_semester = validate.getInt("Enter new semester: ", "please enter a positive integer.", 1, Integer.MAX_VALUE);
                            if (N_semester == lst.get(indexUpdate).getSemester()) {
                                System.out.println("Infomation existed.Enter another Semester.");
                                check = false;
                            } else {
                                Temp_student.setSemester(N_semester);
                                if (indexStudent(lst, Temp_student) != -1) {
                                    System.out.println("Infomation existed.Enter another Semester.");
                                    check = false;
                                } else {
                                    lst.get(indexUpdate).setSemester(N_semester);
                                }
                            }

                        } while (check == false);
                    } else {
                        System.out.println("Not found Student have that information.\nUpdate fail...");
                    }
                    break;//Thoat option 2

                case 3:
                    //Nhập course cũ
                    do {
                        O_Course = validate.getString("[a-zA-Z ./+]+", "Enter old course what you want to update");

                        if (indexCourse(lst, O_Course) == -1) {
                            System.out.println("Not found course in list.");
                        }
                        n = O_Course.toLowerCase().trim();
                        if (!n.equals("java") && !n.equals(".net") && !n.equals("c/c++")) {
                            System.out.println("Enter course name (Java, .Net, C/C++):");
                        }
                    } while (indexCourse(lst, O_Course) == -1 && !n.equals("java") && !n.equals(".net") && !n.equals("c/c++"));

                    //Nhập semester cũ
                    do {
                        O_Semester = validate.getInt("Enter old semester: ", "please enter a positive integer.", 1, Integer.MAX_VALUE);
                        if (indexSemester(lst, O_Semester) == -1) {
                            System.out.println("Not found semester in list.");
                        }
                    } while (indexSemester(lst, O_Semester) == -1);

                    name = lst.get(indexID).getStudentName();

                    Temp_student.setId(Id);
                    Temp_student.setStudentName(name);
                    Temp_student.setSemester(O_Semester);
                    Temp_student.setCourseName(O_Course);

                    indexUpdate = indexStudent(lst, Temp_student);
                    if (indexUpdate != -1) {
                        boolean check;
                        do {
                            check = true;
                            N_courseName = validate.getString("[a-zA-Z ./+]+", "Enter new Course name: ");
                            if (N_courseName.equalsIgnoreCase(lst.get(indexUpdate).getCourseName())) {
                                System.out.println("Infomation existed.Enter another Semester.");
                                check = false;
                            } else {
                                Temp_student.setCourseName(N_courseName);
                                if (indexStudent(lst, Temp_student) != -1) {
                                    System.out.println("Infomation existed.Enter another Semester.");
                                    check = false;
                                } else {
                                    lst.get(indexUpdate).setCourseName(N_courseName);
                                }
                            }
                        } while (check == false);
                    } else {
                        System.out.println("Not found Student have that information.\nUpdate fail...");
                    }
                    break;//Thoat option 3 
            }
        }
        //Thực hiện Delete
        if (s.equalsIgnoreCase("d")) {
            while (indexID(lst, Id) != -1) {
                lst.remove(indexID(lst, Id));
            }
        }

    }

    public int countCourse(ArrayList<Students> lst, int Id, String course) {
        int count = 0;
        for (int i = 0; i < lst.size(); i++) {
            if (Id == lst.get(i).getId() && course.equalsIgnoreCase(lst.get(i).getCourseName())) {
                count++;
            }
        }
        return count;
    }

    public void report(ArrayList<Students> lst) throws IOException {
        if(lst.isEmpty()){
            System.out.println("List is empty. please add student");
            return;
        }

        ArrayList<Students> newList = new ArrayList<>();
        for (int i = 0; i < lst.size(); i++) {
            int count = countCourse(lst, lst.get(i).getId(), "Java");
            Students s = new Students(lst.get(i).getId(), lst.get(i).getStudentName(), count, "java");
            if (count != 0 && indexStudent(newList, s) == -1) {
                newList.add(s);
            }
        }
        for (int i = 0; i < lst.size(); i++) {

            int count = countCourse(lst, lst.get(i).getId(), ".net");
            Students s = new Students(lst.get(i).getId(), lst.get(i).getStudentName(), count, ".net");
            if (count != 0 && indexStudent(newList, s) == -1) {
                newList.add(s);
            }
        }

        for (int i = 0; i < lst.size(); i++) {

            int count = countCourse(lst, lst.get(i).getId(), "c/c++");
            Students s = new Students(lst.get(i).getId(), lst.get(i).getStudentName(), count, "c/c++");
            if (count != 0 && indexStudent(newList, s) == -1) {
                newList.add(s);
            }
        }
        for (int i = 0; i < newList.size(); i++) {
            System.out.println(newList.get(i).getStudentName() + " | " + newList.get(i).getCourseName() + " | " + newList.get(i).getSemester());
        }
    }
}
