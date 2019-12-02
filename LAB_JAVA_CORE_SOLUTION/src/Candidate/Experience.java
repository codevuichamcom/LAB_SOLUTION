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
public class Experience extends Candidates{
    private int ExplnYear;
    private String ProSkill;

    public Experience() {
    }

    public Experience(int Id, String firsName, String lastName, String birthDate, String address, String phone, String email, int type,int ExplnYear, String ProSkill) {
        super(Id, firsName, lastName, birthDate, address, phone, email, type);
        this.ExplnYear = ExplnYear;
        this.ProSkill = ProSkill;
    }

    public int getExplnYear() {
        return ExplnYear;
    }

    public void setExplnYear(int ExplnYear) {
        this.ExplnYear = ExplnYear;
    }

    public String getProSkill() {
        return ProSkill;
    }

    public void setProSkill(String ProSkill) {
        this.ProSkill = ProSkill;
    }
    
    
}
