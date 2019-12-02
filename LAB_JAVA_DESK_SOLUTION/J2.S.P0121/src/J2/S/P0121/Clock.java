package J2.S.P0121;


import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import static java.lang.Thread.sleep;
import java.text.SimpleDateFormat;
import java.time.ZonedDateTime;
import java.util.Calendar;
import java.util.Date;
import java.util.Locale;
import java.util.Timer;
import java.util.TimerTask;
import javax.swing.JLabel;
import javax.swing.JOptionPane;


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author NhungGH
 */
public class Clock extends javax.swing.JFrame {
   Timer t;
   Date curr, prev;
   Boolean Change;
   int xcenter = 0, ycenter = 0, lastxs = 0, lastys = 0, lastxm = 0, lastym = 0, lastxh = 0, lastyh = 0;
     class DigitalThread extends Thread{    
        @Override
        public void run()
        {
            try{
               while(true)
               {
                   Calendar c = Calendar.getInstance();
                   int h = c.get(Calendar.HOUR);
                   int m = c.get(Calendar.MINUTE);
                   int s = c.get(Calendar.SECOND);
                   String time = "Hour: " +h +" Minute: " + m + " Second: " + s;
                   jLabel1.setText(time);
                   sleep(1000);
               }
            }catch(InterruptedException e)
            {
                JOptionPane.showMessageDialog(Clock.this,e);
            }
        }
    }
   DigitalThread dt = null;
    public Clock() {
        initComponents();
         if (dt == null)
        {
            dt = new DigitalThread();
            dt.start();
        }
        t = new Timer();
        t.schedule(new SecondsTask(),1000,1000);
    }

 
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("jLabel1");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(193, Short.MAX_VALUE)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 345, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(137, 137, 137))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(379, Short.MAX_VALUE)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Clock.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Clock.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Clock.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Clock.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Clock().setVisible(true);
            }
        });
    }
    public void paint(Graphics g)
    {
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;
        g2d.translate(this.getWidth()/2, this.getHeight()/2);
        drawStructure(g2d);
        if(prev != null)
        {
            g.setColor(Color.black);
            paints(g);
        }
    }
        public void paints(Graphics g) {
            Date currentDate = new Date();
            SimpleDateFormat formatter = new SimpleDateFormat("s", Locale.getDefault());
        int xhour, yhour, xminute, yminute, xsecond, ysecond, second, minute, hour;
        currentDate = new Date();
        formatter.applyPattern("s");
        second = Integer.parseInt(formatter.format(currentDate));
        formatter.applyPattern("m");
        minute = Integer.parseInt(formatter.format(currentDate));
        formatter.applyPattern("h");
        hour = Integer.parseInt(formatter.format(currentDate));
        xsecond = (int) (Math.cos(second * 3.14f / 30 - 3.14f / 2) * 120 + xcenter);
        ysecond = (int) (Math.sin(second * 3.14f / 30 - 3.14f / 2) * 120 + ycenter);
        xminute = (int) (Math.cos(minute * 3.14f / 30 - 3.14f / 2) * 100 + xcenter);
        yminute = (int) (Math.sin(minute * 3.14f / 30 - 3.14f / 2) * 100 + ycenter);
        xhour = (int) (Math.cos((hour * 30 + minute / 2) * 3.14f / 180 - 3.14f / 2) * 80 + xcenter);
        yhour = (int) (Math.sin((hour * 30 + minute / 2) * 3.14f / 180 - 3.14f / 2) * 80 + ycenter);
     //   g.setColor(Color.white);
        if (xsecond != lastxs || ysecond != lastys) {
            g.drawLine(xcenter, ycenter, lastxs, lastys);
        }
        if (xminute != lastxm || yminute != lastym) {
            g.drawLine(xcenter, ycenter - 1, lastxm, lastym);
            g.drawLine(xcenter - 1, ycenter, lastxm, lastym);
        }
        if (xhour != lastxh || yhour != lastyh) {
            g.drawLine(xcenter, ycenter - 1, lastxh, lastyh);
            g.drawLine(xcenter - 1, ycenter, lastxh, lastyh);
        }
        g.setColor(Color.red);
        g.drawLine(xcenter, ycenter, xsecond, ysecond);
        g.setColor(Color.blue);
        g.drawLine(xcenter, ycenter - 1, xminute, yminute);
        g.drawLine(xcenter - 1, ycenter, xminute, yminute);
        g.setColor(Color.green);
        g.drawLine(xcenter, ycenter - 1, xhour, yhour);
        g.drawLine(xcenter - 1, ycenter, xhour, yhour);
        lastxs = xsecond;
        lastys = ysecond;
        lastxm = xminute;
        lastym = yminute;
        lastxh = xhour;
        lastyh = yhour;
    }   
     private void drawStructure(Graphics g) {
         
        g.setFont(new Font("TimesRoman", Font.BOLD, 18));
        g.setColor(Color.black);
        g.drawOval(xcenter - 150, ycenter - 150, 300, 300);
        g.setColor(Color.black);
        g.drawString("9", xcenter - 145, ycenter + 0);
        g.drawString("3", xcenter + 135, ycenter + 0);
        g.drawString("12", xcenter - 10, ycenter - 135);
        g.drawString("6", xcenter - 10, ycenter + 145);
    }
class SecondsTask extends TimerTask{

        @Override
        public void run() {
            curr = Date.from(ZonedDateTime.now().toInstant());
            if(prev!= null)
            {
                Change = curr.getHours()!= prev.getHours() || curr.getMinutes()!= prev.getMinutes(); 
                paints(Clock.this.getGraphics());
            }
            prev = curr;
            Clock.this.repaint();
        }
    
}
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel1;
    // End of variables declaration//GEN-END:variables
}
