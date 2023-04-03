
/**
 * This starts up the application.
 *
 * @author Alberto Medalla
 * @version March 22, 2021
 *
 */

public class EmojiAppStarter {

  public static void main(String[] args) {
    EmojiFrame ef = new EmojiFrame(640,480);
    ef.setUpFrame();
    ef.setUpButtonListener();
  }

}
