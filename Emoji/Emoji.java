import java.awt.*;
import javax.swing.*;
import java.awt.geom.*;

/**
 * This class is responsible for drawing the Emoji and adjusting its properties.
 *
 * @author Alberto Medalla
 * @version March 22, 2021
 *
 */

public class Emoji {

    private double x;
    private double y;
    private double size;
    private double angle;

    public Emoji(double x, double y, double size) {
        this.x = x;
        this.y = y;
        this.size = size;
        this.angle = 0;
    }

	public void draw(Graphics2D g2d) {
      AffineTransform reset = g2d.getTransform();

      Color headColor = Color.decode("#2F78C5");
      Color shadesColor = Color.decode("#FFFFFF");
      Color noseColor = Color.decode("#FFFFFF");
      Color mouthColor = Color.decode("#FFFFFF");

      g2d.rotate(Math.toRadians(angle),x+size*.5,y+size*.5);

      Ellipse2D.Double head = new Ellipse2D.Double(x,y,size,size);
      g2d.setColor(headColor);
      g2d.fill(head);

      Line2D.Double line = new Line2D.Double(x,y+size*.35,x+size,y+size*.35);
      g2d.setColor(shadesColor);
      g2d.setStroke(new BasicStroke(2));
      g2d.draw(line);

      Rectangle2D.Double shades1 = new Rectangle.Double(x+size*.2,y+size*.3,size*.2,size*.1);
      g2d.setColor(shadesColor);
      g2d.fill(shades1);

      Rectangle2D.Double shades2 = new Rectangle.Double(x+size*.6,y+size*.3,size*.2,size*.1);
      g2d.setColor(shadesColor);
      g2d.fill(shades2);

      Ellipse2D.Double nose = new Ellipse2D.Double(x+size*.5-size*.05*.5,y+size*.5-size*.05*.5,size*.05,size*.05);
      g2d.setColor(noseColor);
      g2d.fill(nose);

      Path2D.Double mouth = new Path2D.Double();
      mouth.moveTo(x+size*.5-size*.15,y+size*.5+size*.1);
      mouth.curveTo(x+size*.5-size*.1,y+size*.5+size*.2,x+size*.5+size*.1,y+size*.5+size*.2,x+size*.5+size*.15,y+size*.5+size*.1);
      g2d.setColor(mouthColor);
      g2d.draw(mouth);

      g2d.setTransform(reset); // Why are we resetting? This is if we want to draw other elements, so that they won't be rotated.
    }

    public void adjustX(double amount) {
      x += amount;
    }

    public void adjustY(double amount) {
      y += amount;
    }

    public void adjustAngle(double amount) {
      angle += amount;
    }

}
