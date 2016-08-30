import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class Sales_Tax_Calculator {
	public static void main(String[] args)
	{
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				TaxFrame frame = new TaxFrame();
				frame.setTitle("Sales Tax Calculator");
				frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				frame.setVisible(true);
			}
		});
	}
}

class TaxFrame extends JFrame
{
	private static final int DEFAULT_WIDTH = 300;
	private static final int DEFAULT_HEIGHT = 300;
	private double tax = 0.23;
	private JTextField TaxField;
	private JButton TaxButtonRes;
	
	TaxFrame()
	{
		setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
		setLayout(new GridLayout(4,1));
		JButton TaxButton = new JButton("Calculate Tax");
		JButton TaxButtonPl = new JButton("Please enter a value.");
		CalculateTax calc = new CalculateTax();
		TaxButtonRes = new JButton("Result");
		TaxField = new JTextField();
		TaxField.setHorizontalAlignment(JTextField.CENTER);
		TaxField.setFont( new Font("Calibri", 15, 20));
		TaxButtonPl.setEnabled(false);
		TaxButtonRes.setEnabled(false);
		
		TaxButton.addActionListener(calc);
		
		add(TaxButtonPl);
		add(TaxField);
		add(TaxButton);
		add(TaxButtonRes);
	}
	
	class CalculateTax implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			TaxButtonRes.setText(Double.toString(CalcTax()));
		}

	}
	
	public double CalcTax()
	{
		String taxSt = TaxField.getText().trim();
		return Double.valueOf(taxSt)+Double.valueOf(taxSt)*tax;
	}
}


