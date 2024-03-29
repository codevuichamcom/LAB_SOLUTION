
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JButton;
import javax.swing.JOptionPane;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author ThinkPro
 */
public class NewJFrame extends javax.swing.JFrame implements ActionListener {

    /**
     * Creates new form NewJFrame
     */
    private int SIZE = 3;
    Random rand = new Random();
    private int xBlank;
    private int yBlank;
    JButton[][] btnArr;
    Thread timeThread = null;
    private int sec = 0;
    private int moveCount = 0;

    public void initGame() {

        ArrayList<Integer> list = null;

        list = new ArrayList<>();
        for (int i = 0; i < (SIZE * SIZE); i++) {
            list.add(i);
        }
        do {
            Collections.shuffle(list);
        } while (!canWin(list));

        paneScreen.removeAll();
        paneScreen.setLayout(new java.awt.GridLayout(SIZE, SIZE));
        setSize(SIZE * 80, SIZE * 80 + 150);
        btnArr = new JButton[SIZE][SIZE];
        int count = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (list.get(count) == 0) {
                    btnArr[i][j] = new JButton("");
                    xBlank = i;
                    yBlank = j;
                } else {
                    btnArr[i][j] = new JButton(list.get(count) + "");
                }
                paneScreen.add(btnArr[i][j]);
                btnArr[i][j].addActionListener(this);
                count++;
            }
        }
        sec = 0;
        moveCount = 0;
        lbMoveCount.setText("0");
        lbTime.setText("0");
        if (timeThread == null) {

            timeThread = new Thread(new Runnable() {
                @Override
                public void run() {
                    while (true) {
                        try {
                            Thread.sleep(1000);
                            sec++;
                            lbTime.setText(sec + "");
                        } catch (InterruptedException ex) {
                            ex.printStackTrace();
                        }
                    }
                }
            });
            timeThread.start();
        }

    }

    public static int indexValue(ArrayList<Integer> list, int x) {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) == x) {
                return i;
            }
        }
        return -1;
    }

    public NewJFrame() {
        initComponents();
        initGame();

    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        lbMoveCount = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        lbTime = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jComboBox1 = new javax.swing.JComboBox<>();
        jButton1 = new javax.swing.JButton();
        paneScreen = new javax.swing.JPanel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("Move count: ");

        lbMoveCount.setText("0");

        jLabel3.setText("Elapsed: ");

        lbTime.setText("0");

        jLabel5.setText("Size");

        jComboBox1.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "3x3", "4x4", "5x5", "6x6", "7x7", "8x8", "9x9" }));

        jButton1.setText("New Game");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        paneScreen.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(51, 51, 255)));
        paneScreen.setLayout(new java.awt.GridLayout(SIZE, SIZE));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(50, 50, 50)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(paneScreen, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGap(50, 50, 50))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                .addGroup(layout.createSequentialGroup()
                                    .addComponent(jLabel3)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(lbTime, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addGroup(layout.createSequentialGroup()
                                    .addComponent(jLabel1)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(lbMoveCount, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                .addComponent(jButton1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addGroup(layout.createSequentialGroup()
                                    .addComponent(jLabel5)
                                    .addGap(18, 18, 18)
                                    .addComponent(jComboBox1, javax.swing.GroupLayout.PREFERRED_SIZE, 87, javax.swing.GroupLayout.PREFERRED_SIZE))))
                        .addContainerGap(193, Short.MAX_VALUE))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(40, 40, 40)
                .addComponent(paneScreen, javax.swing.GroupLayout.DEFAULT_SIZE, 300, Short.MAX_VALUE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(lbMoveCount))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(lbTime))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(jComboBox1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        String selectSize = (String) jComboBox1.getSelectedItem();
        selectSize = selectSize.substring(0, selectSize.indexOf("x"));
        SIZE = Integer.parseInt(selectSize);
        initGame();
    }//GEN-LAST:event_jButton1ActionPerformed

    /**
     * @param args the command line arguments
     */
    private boolean isClick(int i, int j) {
        if (i == xBlank && Math.abs(j - yBlank) == 1) {
            return true;
        } else if (j == yBlank && Math.abs(i - xBlank) == 1) {
            return true;
        } else {
            return false;
        }
    }

    public void changeWithBlank(int x, int y) {
        moveCount++;
        lbMoveCount.setText(moveCount + "");
        btnArr[xBlank][yBlank].setText(btnArr[x][y].getText());
        btnArr[x][y].setText("");
        xBlank = x;
        yBlank = y;
    }

    public boolean checkWin() {
        int count = 1;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (btnArr[SIZE - 1][SIZE - 1].getText().equals("")) {
                    if (!btnArr[i][j].getText().equals(count + "")) {
                        return false;
                    }
                    count++;
                    if (count == SIZE * SIZE) {
                        break;
                    }
                } else {
                    return false;
                }

            }
        }
        return true;
    }

    public boolean canWin(ArrayList<Integer> list) {
        int count = 0;
        int zezo = -1;
        for (int i = 0; i < list.size() - 1; i++) {
            if (list.get(i) == 0) {
                zezo = i;
            }
            for (int j = i + 1; j < list.size(); j++) {
                if (list.get(i) > list.get(j) && list.get(j) != 0) {
                    count++;
                }
            }
        }
        if (zezo == -1) {
            zezo = list.size() - 1;
        }
        if (SIZE % 2 != 0) {
            if (count % 2 == 0) {
                return true;
            }
        } else {
            int row = zezo / SIZE;
            if ((SIZE - row) % 2 == 0 && count % 2 == 1) {
                return true;
            }
            if ((SIZE - row) % 2 == 1 && count % 2 == 0) {
                return true;
            }

        }
        return false;
    }

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
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(NewJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new NewJFrame().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JComboBox<String> jComboBox1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel lbMoveCount;
    private javax.swing.JLabel lbTime;
    private javax.swing.JPanel paneScreen;
    // End of variables declaration//GEN-END:variables

    @Override
    public void actionPerformed(ActionEvent e) {
        int x = 0, y = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (btnArr[i][j].getText().equals(((JButton) e.getSource()).getText())) {
                    x = i;
                    y = j;
                }
            }
        }
        if (isClick(x, y)) {
            changeWithBlank(x, y);
        }
        if (checkWin()) {
            timeThread.suspend();
            JOptionPane.showMessageDialog(null, "Thắng cmnr");

            timeThread.resume();
            initGame();
        }

    }

}
