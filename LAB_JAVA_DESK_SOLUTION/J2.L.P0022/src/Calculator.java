
import java.math.BigDecimal;
import javax.swing.JButton;
import javax.swing.JTextField;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ThinkPro
 */
public class Calculator {
    private BigDecimal firstNum;
    private BigDecimal secondNum;
    private JTextField text;
    private String operator = "";
    private boolean process;
    private boolean reset;
    private BigDecimal memory = new BigDecimal("0");
    private boolean isMR=false;
    public Calculator(JTextField txt) {
        this.text=txt;
        operator="";
    }

    public void setOperator(String operator) { // set operator
        this.operator = operator;
    }
    
    
    public void pressNumber(JButton btn){//when press number
        BigDecimal temp;
        String value = btn.getText();
        if(process||reset){
            text.setText("0");
            process=false; // process'll be set = false to do any operator.
            reset=false;
        }
        isMR=false;
        temp = new BigDecimal(text.getText()+value);
        text.setText(temp+"");
    }
    
    public BigDecimal getValue(){//return a big decimal
        if(isMR)
           return memory;
        BigDecimal temp;
        String value = text.getText();
        temp = new BigDecimal(value);
        return temp;
    }
    
    public void calculate() {
        try {
            if (!process) {
                if (operator.equals("")) {
                    firstNum = getValue();
                } else {// bat dau tinh toan
                    secondNum = getValue();

                    if (operator.equals("Add")) {
                        firstNum = firstNum.add(secondNum);
                    }
                    if (operator.equals("Sub")) {
                        firstNum = firstNum.subtract(secondNum);
                    }
                    if (operator.equals("Mul")) {
                        firstNum = firstNum.multiply(secondNum);
                    }
                    if (operator.equals("Div")) {
                        double result = firstNum.doubleValue() / secondNum.doubleValue();//divide second number to first
                        firstNum = new BigDecimal(result + "");
                    }
                    
                }
                
                text.setText(firstNum + "");
                process = true;
            }
        } catch (Exception e) {
            reset = true; // else reset will be set = true to user can press a new number.
            text.setText("Math ERROR");
        }

    }
    
    public void pressEqual(){
        if(!text.getText().equals("Math ERROR")){//khi khong co bat ki toan tu nao sai
            calculate();
            if(!text.getText().equals("Math ERROR")){
                  String display = firstNum.doubleValue() + "";//return square number
                if (display.endsWith(".0")) {
                    display = display.replace(".0", "");
                }
                text.setText(display);
            }

            operator="";
        }else{
            text.setText(firstNum+"");//tra ve so dau tien
        }
                  
    }
    public void pressDot(){
        if (process || reset) {
            text.setText("0");
            process = false;
            reset = false;
        }
        if (!text.getText().contains(".")) {
            text.setText(text.getText() + ".");
        }
    }
    public void pressNegative(){
        try {
            if(operator.equals("")){
                pressEqual();
                operator="";
            }
            text.setText(getValue().negate() + "");
            process=false;
        } catch (Exception e) {
            text.setText("Math ERROR");
        }
        reset=true;
    }
    public void pressSqrt() {
        try {
            BigDecimal result = getValue();
            if (result.doubleValue() >= 0) {
                String display = Math.sqrt(result.doubleValue()) + "";//return square number
                if (display.endsWith(".0")) {
                    display = display.replace(".0", "");
                }
                text.setText(display);
                process = false;// process set to false to do any operator
            } else {
                text.setText("Math ERROR");
            }
        } catch (Exception e) {
            text.setText("Math ERROR");
        }
        reset = true; //reset set = true to press a new number
    }
    public void pressPercent() {
        try {
            pressEqual();
            text.setText((getValue().doubleValue()) / 100 + "");
            process = false;// process set to false to do any operator
        } catch (Exception e) {
            text.setText("Math ERROR");
        }
        reset = true;//reset set = true to press a new number
    }

    public void pressInvert() {
        try {
            double result = getValue().doubleValue();
            if (result != 0) {
                text.setText((1 / result) + "");
                process = false;// process set to false to do any operator
            } else {
                text.setText("Math ERROR");
            }
        } catch (Exception e) {
            text.setText("Math ERROR");
        }
        reset = true;//reset set = true to press a new number
    }
     public void pressMAdd() {
        try {
            memory = memory.add(getValue());
            process = false;
        } catch (Exception e) {
            text.setText("Math ERROR");
        }
        reset = true;
    }

    public void pressMSub() {
        try {
            memory = memory.add(getValue().negate());
            process = false;
        } catch (Exception e) {
            text.setText("Math ERROR");
        }
        reset = true;
    }
    
    public void pressMR(){
        text.setText(memory+"");
        isMR=true;
    }
    public void pressMC(){
        memory = new BigDecimal("0");
    }
    
    public void pressAllClear(){
        firstNum = new BigDecimal("0");
        secondNum = new BigDecimal("0");
        memory = new BigDecimal("0");
        operator="";
        text.setText("0");
    }
}
