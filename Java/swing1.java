import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class swing1
{
	public static void main(String args[])
	{
		//args[0]="oh no";
		JFrame f=new JFrame();
		JButton b=new JButton("xD");
		b.setBounds(60,50,100,40);
		f.add(b);
		JTextField tf=new JTextField();
		tf.setBounds(60,100,100,40);
		f.add(tf);
		b.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{tf.setText("Hello world");
			}
		});
		JCheckBox rb1,rb2;
		rb1=new JCheckBox("One");
		rb2=new JCheckBox("Two");
		rb1.setBounds(50,150,100,30);    
		rb2.setBounds(150,150,100,30);  
		JTextArea ta=new JTextArea();
		ta.setBounds(200,50,100,50);
		f.add(ta);
		JLabel l=new JLabel();
		l.setText("This is a label");
		l.setBounds(60,200,100,50);f.add(l);
		rb1.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{	String s;
				//if(rb1.isSelected()) {tf.setText("Option 1 selected");
				//tf.setFont(new Font("Comic Sans MS",Font.BOLD,9));}
				if(ta.getText()!=null) {
					s=tf.getText();
					l.setText(s);
				l.setFont(new Font("Comic Sans MS",Font.PLAIN,14));
					JOptionPane.showMessageDialog(null,tf.getText());
			}
			}});
		

		ButtonGroup bg=new ButtonGroup();
		bg.add(rb1);bg.add(rb2);
		f.add(rb1);
		f.add(rb2);
		
		f.setSize(480,360);
		f.setLayout(null);
		f.setVisible(true);
		pack();
	}
}