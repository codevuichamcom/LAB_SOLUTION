/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Students_Management;

/**
 *
 * @author ThinkPro
 */
public class Students {

    private int Id;
    private String studentName;
    private int Semester;
    private String courseName;

    public Students() {
    }

    public Students(int Id, String studentName, int Semester, String courseName) {
        this.Id = Id;
        this.studentName = studentName;
        this.Semester = Semester;
        this.courseName = courseName;
    }

    public int getId() {
        return Id;
    }

    public void setId(int Id) {
        this.Id = Id;
    }

    public String getStudentName() {
        return studentName;
    }

    public void setStudentName(String studentName) {
        this.studentName = studentName;
    }

    public int getSemester() {
        return Semester;
    }

    public void setSemester(int Semester) {
        this.Semester = Semester;
    }

    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

}
