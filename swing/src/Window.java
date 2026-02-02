import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Window extends JFrame {

    private static final long serialVersionUID = 1L;

    private JTextArea textZone;
    private JButton button1;
    private JButton button2;
    private JButton quitButton;

    public Window() {

        super("Window");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        textZone = new JTextArea(20, 40);
        JScrollPane scrollPane = new JScrollPane(textZone);

        button1 = new JButton("Button 1");
        button2 = new JButton("Button 2");
        quitButton = new JButton("Quit");

        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textZone.append("Lign added by button 1\n");
            }
        });

        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textZone.append("Lign added by button 2\n");
            }
        });

        quitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        this.add(scrollPane, BorderLayout.CENTER);

        JPanel buttonsPanel = new JPanel();
        buttonsPanel.add(button1);
        buttonsPanel.add(button2);
        buttonsPanel.add(quitButton);
        
        this.add(buttonsPanel, BorderLayout.SOUTH);

        this.pack();
        this.setVisible(true);


    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new Window();
            }
        });
    }
}


