import javax.swing.*;
import java.awt.*;
import java.awt.geom.*;

/**
 * This is the class that extends JComponent and overrides the paintComponent method
 * so that the custom drawing can be made.
 *
 * @author Alberto Medalla
 * @version March 22, 2021
 *
 */

public class EmojiCanvas extends JComponent {

  private int width;
  private int height;
  private Emoji emoji;

  public EmojiCanvas(int w, int h) {
    width = w;
    height = h;
    emoji = new Emoji(width*.5-width*.3*.5,height*.5-width*.3*.5,width*.3);
    setPreferredSize(new Dimension(width, height));
  }

  @Override
  protected void paintComponent(Graphics g) {
    Graphics2D g2d = (Graphics2D) g;

    Color backgroundColor = Color.BLUE;

    RenderingHints rh = new RenderingHints(
      RenderingHints.KEY_ANTIALIASING,
      RenderingHints.VALUE_ANTIALIAS_ON);
    g2d.setRenderingHints(rh);

    Rectangle2D.Double background = new Rectangle2D.Double(0,0,width,height);
    g2d.setColor(backgroundColor);
    g2d.fill(background);

    emoji.draw(g2d);
  }

  public Emoji getEmoji() {
    return emoji;
  }

}
