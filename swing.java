import javax.swing.*;
import java.awt.*;

public class swing {
    public static void main(String[] args) {
        milk m=new milk();
    }
}
class milk extends JFrame {
    JTextField milk_money_1,milk_money_2,nol1,nol2;
    JLabel l;
    JButton btn;
    public milk(){
        super("Milkman calculation");
        milk_money_1 = new JTextField(20);
        milk_money_2 = new JTextField(20);
        nol1 = new JTextField(20);
        nol2 = new JTextField(20);
        btn = new JButton("Enter");
        l = new JLabel("Enter number of liters of milk 1(Gokul Milk):");
        l.setFont(new Font("SansSerif",Font.BOLD,20));

        JLabel label = new JLabel("<html><div style='display: flex; justify-content: center; align-items: center;'><div style='text-align: center; font-size: 30px;'><b>Welcome to Milk calculator!!!!</b></div></div></html>");

        add(label);
        add(new JLabel("<html><br></html>"));
        add(l);
        add(nol1);
        l = new JLabel("Enter MONEY / PAISA / RUPEES of liters of milk 1(Gokul Milk):");
        l.setFont(new Font("SansSerif",Font.BOLD,20));
        add(l);
        add(milk_money_1);
        add(new JLabel("<html><br></html>"));
        l = new JLabel("Enter number of liters of milk 2(Mahananda Milk):");
        l.setFont(new Font("SansSerif",Font.BOLD,20));
        add(l);
        add(nol2);

        l = new JLabel("Enter MONEY / PAISA / RUPEES of liters of milk 2(Mahananda Milk):");
        l.setFont(new Font("SansSerif",Font.BOLD,20));
        add(l);
        add(milk_money_2);
        add(new JLabel("<html><br></html>"));
        add(btn);

        btn.addActionListener(ae->{
            int no_of_l1=Integer.parseInt(nol1.getText());
            int no_of_l2=Integer.parseInt(nol2.getText());
            int money1=Integer.parseInt(milk_money_1.getText());
            int money2=Integer.parseInt(milk_money_2.getText());

            int total1 = no_of_l1*money1;
            int total2 = no_of_l2*money2;

            JLabel j=new JLabel("Money of Gokul Milk = Rs "+total1);
            j.setFont(new Font("SansSerif",Font.BOLD,25));
            add(j);
            add(new JLabel("<html><br></html>"));

            JLabel j2=new JLabel("Money of Mahananda Milk = Rs "+total2);
            j2.setFont(new Font("SansSerif",Font.BOLD,25));
            add(j2);
            add(new JLabel("<html><br></html>"));

            JLabel j3=new JLabel("Total Money = Rs " +(total2+total1));
            j3.setFont(new Font("SansSerif",Font.BOLD,30));
            add(j3);
            add(new JLabel("<html><br></html>"));

            SwingUtilities.invokeLater(() -> {      // VERY VERY VERY IMPORTANT
                revalidate();
                repaint();
            });
        });

        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500,500);
        setLayout(new GridLayout(20, 1));
    }
}