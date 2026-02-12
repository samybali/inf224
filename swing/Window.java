import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * @file Window.java
 * @brief Main window for the Java Swing Client.
 */

/**
 * @class Window
 * @brief The main GUI frame for the Remote Control Application.
 *
 * This class inherits from JFrame and provides a graphical user interface
 * to interact with the C++ Multimedia Server.
 * It includes a text area to display server responses, a menu bar, and a toolbar.
 * It uses the Client class to establish a TCP connection.
 */
public class Window extends JFrame {
    
    private static final long serialVersionUID = 1L;

    /**
     * @brief Text area to display the history of interactions and server responses.
     */
    private final JTextArea textArea;

    /**
     * @brief The network client used to communicate with the server.
     */
    private Client client;

    /**
     * @brief Action to request the display of a media object.
     *
     * Opens an input dialog to ask for the media name, then sends
     * the "display <name>" command to the server.
     * Bound to the shortcut CTRL+D (or CMD+D on Mac).
     */
    private final Action DisplayAction = new AbstractAction("Display") {
        {
            putValue(Action.SHORT_DESCRIPTION, "Display media info");
            putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_D, 
                Toolkit.getDefaultToolkit().getMenuShortcutKeyMaskEx()));
        }
        @Override
        public void actionPerformed(ActionEvent e) {
            String name = JOptionPane.showInputDialog(Window.this, "Enter media name to display:");
            if (name != null && !name.trim().isEmpty()) {
                // Sends the command to the C++ server
                String response = client.send("display " + name);
                textArea.append(response + "\n");
            }
        }
    };

    /**
     * @brief Action to request the playback of a media object.
     *
     * Opens an input dialog to ask for the media name, then sends
     * the "play <name>" command to the server.
     * Bound to the shortcut CTRL+P (or CMD+P on Mac).
     */
    private final Action PlayAction = new AbstractAction("Play") {
        {
            putValue(Action.SHORT_DESCRIPTION, "Play selected media");
            putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_P, 
                Toolkit.getDefaultToolkit().getMenuShortcutKeyMaskEx()));
        }
        @Override
        public void actionPerformed(ActionEvent e) {
            String name = JOptionPane.showInputDialog(Window.this, "Enter media name to play:");
            if (name != null && !name.trim().isEmpty()) {
                String response = client.send("play " + name);
                textArea.append(response + "\n");
            }
        }
    };

    /**
     * @brief Action to remove a media object.
     *
     * Opens an input dialog to ask for the media name, then sends
     * the "remove <name>" command to the server.
     * Bound to the shortcut CTRL+R (or CMD+R on Mac).
     */
    private final Action RemoveAction = new AbstractAction("Remove") {
      {
         this.putValue("ShortDescription", "Remove media");
         this.putValue("AcceleratorKey", KeyStroke.getKeyStroke(KeyEvent.VK_R, Toolkit.getDefaultToolkit().getMenuShortcutKeyMaskEx()));
      }

      public void actionPerformed(ActionEvent e) {
         String name = JOptionPane.showInputDialog(Window.this, "Enter media name to remove:");
         if (name != null && !name.trim().isEmpty()) {
            String response = Window.this.client.send("remove " + name);
            Window.this.textArea.append(response + "\n");
         }
      }
    };

    /**
     * @brief Action to create a new Group on the server.
     *
     * Opens an input dialog to ask for the group name, then sends
     * the "creategroup <name>" command to the server.
     * Bound to the shortcut CTRL+G (or CMD+G on Mac).
     */
    private final Action AddGroup = new AbstractAction("Create Group") {
      {
         this.putValue("ShortDescription", "Create Group");
         this.putValue("AcceleratorKey", KeyStroke.getKeyStroke(KeyEvent.VK_G, Toolkit.getDefaultToolkit().getMenuShortcutKeyMaskEx()));
      }

      public void actionPerformed(ActionEvent e) {
         String name = JOptionPane.showInputDialog(Window.this, "Enter group name: ");
         if (name != null && !name.trim().isEmpty()) {
            String response = Window.this.client.send("creategroup " + name);
            Window.this.textArea.append(response + "\n");
         }
      }
    };

    /**
     * @brief Action to quit the application.
     *
     * Terminates the Java program.
     */
    private final Action QuitAction = new AbstractAction("Quit") {
        @Override
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    };

    /**
     * @brief Constructor for the Window class.
     *
     * Initializes the connection to the server (Client).
     * Builds the graphical interface (Menu Bar, Tool Bar, Text Area).
     */
    public Window() {
        super("Remote Control App");

        try {
            // Attempt to connect to localhost on default port
            client = new Client(Client.DEFAULT_HOST, Client.DEFAULT_PORT);
        } catch (Exception e) {
            System.err.println("Client: Could not connect to server");
        }

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(new BorderLayout());

        // Menu Bar setup
        JMenuBar menuBar = new JMenuBar();
        JMenu actionsMenu = new JMenu("Actions");
        
        // Add actions to the menu
        actionsMenu.add(new JMenuItem(AddGroup));
        actionsMenu.add(new JMenuItem(PlayAction));
        actionsMenu.add(new JMenuItem(DisplayAction));
        actionsMenu.add(new JMenuItem(RemoveAction));
        
        JMenu quitMenu = new JMenu("Quit");
        quitMenu.add(new JMenuItem(QuitAction));
        
        menuBar.add(actionsMenu);
        menuBar.add(quitMenu);
        this.setJMenuBar(menuBar);

        // Tool Bar setup
        JToolBar toolBar = new JToolBar();
        toolBar.add(AddGroup);
        toolBar.addSeparator();
        toolBar.add(PlayAction);
        toolBar.add(DisplayAction);
        toolBar.add(RemoveAction);
        toolBar.addSeparator();
        toolBar.add(QuitAction);
        this.add(toolBar, BorderLayout.NORTH);

        // Text area setup
        textArea = new JTextArea(15, 40);
        this.add(new JScrollPane(textArea), BorderLayout.CENTER);

        this.pack();
        this.setLocationRelativeTo(null); // Center the window
    }

    /**
     * @brief Main entry point of the client application.
     *
     * Configures the look and feel (specifically for macOS) and launches
     * the GUI on the Event Dispatch Thread.
     *
     * @param args Command line arguments (not used).
     */
    public static void main(String[] args) {
        System.setProperty("apple.laf.useScreenMenuBar", "true");

        SwingUtilities.invokeLater(() -> {
            new Window().setVisible(true);
        });
    }
}