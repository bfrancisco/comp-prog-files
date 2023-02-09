import java.util.ArrayList;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class ButtonMessages{

    private JFrame frame;
    private ArrayList<JButton> buttons;
    private ArrayList<String> messages;
    private JTextArea display;

    public ButtonMessages(){
        frame = new JFrame();
        buttons = new ArrayList<JButton>();
        messages = new ArrayList<String>();
        display = new JTextArea();
        
        for (int i = 0; i < 5; i++) buttons.add(new JButton("Button " + (i+1)));
        messages.add("marcus pogi 123");
        messages.add("zapi pogi");
        messages.add("eyy");
        messages.add("ian pogi");
        messages.add("WAKODSADOASJDSD");
    }

    public void setUpGUI(){
        Container cp = frame.getContentPane();
        frame.setSize(500,400);
        cp.setLayout(new GridLayout(buttons.size() + 1, 1));

        for (JButton b : buttons) cp.add(b);

        cp.add(display);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    public void setUpButtonListeners(){ 
        for (int i = 0; i < buttons.size(); i++){
            buttons.get(i).addActionListener(new ButtonListener(messages.get(i)));
        }
    }

    private class ButtonListener implements ActionListener{
        private String message;
        public ButtonListener(String msg){
            message = msg;
        }
        
        @Override
        public void actionPerformed(ActionEvent ae){
            display.setText(message);
        }
    }

    public static void main(String[] args){
        ButtonMessages bm = new ButtonMessages();
        bm.setUpGUI();
        bm.setUpButtonListeners();
    }
}