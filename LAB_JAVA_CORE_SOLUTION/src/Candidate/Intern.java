/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Candidate;

/**
 *
 * @author ThinkPro
 */
public class Intern extends Candidates{
    private String Majors;
    private int Semester;
    private String UniversityName;

    public Intern() {
    }

    public Intern(int Id, String firsName, String lastName, String birthDate, String address, String phone, String email, int type,String Majors, int Semester, String UniversityName) {
        super(Id, firsName, lastName, birthDate, address, phone, email, type);
        this.Majors = Majors;
        this.Semester = Semester;
        this.UniversityName = UniversityName;
    }

    public String getMajors() {
        return Majors;
    }

    public void setMajors(String Majors) {
        this.Majors = Majors;
    }

    public int getSemester() {
        return Semester;
    }

    public void setSemester(int Semester) {
        this.Semester = Semester;
    }

    public String getUniversityName() {
        return UniversityName;
    }

    public void setUniversityName(String UniversityName) {
        this.UniversityName = UniversityName;
    }
    
    
}
