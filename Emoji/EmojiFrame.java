import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * This is the class for the frame.
 *
 * @author Alberto Medalla
 * @version March 22, 2021
 *
 */

public class EmojiFrame {

  private int width;
  private int height;
  private JFrame frame;
  private JButton up;
  private JButton down;
  private JButton left;
  private JButton right;
  private JButton rotate;
  private EmojiCanvas emojiCanvas;

  public EmojiFrame(int w, int h) {
    width = w;
    height = h;
    frame = new JFrame();
    emojiCanvas = new EmojiCanvas(width, height);
    up = new JButton("UP");
    down = new JButton("DOWN");
    left = new JButton("LEFT");
    right = new JButton("RIGHT");
    rotate = new JButton("ROTATE");
  }

  public void setUpFrame() {
    Container contentPane = frame.getContentPane();
    JPanel buttonsPanel = new JPanel();

    buttonsPanel.setLayout(new GridLayout(3,3));
    buttonsPanel.add(new JLabel());
    buttonsPanel.add(up);
    buttonsPanel.add(new JLabel());
    buttonsPanel.add(left);
    buttonsPanel.add(rotate);
    buttonsPanel.add(right);
    buttonsPanel.add(new JLabel());
    buttonsPanel.add(down);
    buttonsPanel.add(new JLabel());

    contentPane.add(emojiCanvas, BorderLayout.CENTER);
    contentPane.add(buttonsPanel, BorderLayout.SOUTH);

    frame.setTitle("Emoji Demo");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.pack();
    frame.setVisible(true);
  }

  public void setUpButtonListener() {

    ActionListener al = new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent ae) {
        Object o = ae.getSource();
        double amount = 5;
        Emoji emoji = emojiCanvas.getEmoji();

        if(o == up) {
          emoji.adjustY(-amount);
        } else if(o == down) {
          emoji.adjustY(amount);
        } else if(o == left) {
          emoji.adjustX(-amount);
        } else if(o == right) {
          emoji.adjustX(amount);
        } else if(o == rotate) {
          emoji.adjustAngle(amount);
        }
        emojiCanvas.repaint();
      }
    };

    up.addActionListener(al);
    down.addActionListener(al);
    left.addActionListener(al);
    right.addActionListener(al);
    rotate.addActionListener(al);

  }

}
