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
public class Fresher extends Candidates{
    private String Graduation_date;
    private String Graduation_rank;
    private String Education;

    public Fresher(int Id, String firsName, String lastName, String birthDate, String address, String phone, String email, int type,String Graduation_date, String Graduation_rank, String Education) {
        super(Id, firsName, lastName, birthDate, address, phone, email, type);
        this.Graduation_date = Graduation_date;
        this.Graduation_rank = Graduation_rank;
        this.Education = Education;
    }

    public Fresher() {
    }

    public String getGraduation_date() {
        return Graduation_date;
    }

    public void setGraduation_date(String Graduation_date) {
        this.Graduation_date = Graduation_date;
    }

    public String getGraduation_rank() {
        return Graduation_rank;
    }

    public void setGraduation_rank(String Graduation_rank) {
        this.Graduation_rank = Graduation_rank;
    }

    public String getEducation() {
        return Education;
    }

    public void setEducation(String Education) {
        this.Education = Education;
    }
    
    
}
