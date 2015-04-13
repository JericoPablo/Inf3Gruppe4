import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		ArrayList<Double> valuelist = new ArrayList<>();
		
		// printing arguments
		System.out.print("Arguments: ");
		for (String parameter : args) {
			System.out.print(parameter + ", ");
		}

		// summing arguments
		double sum = 0;
		for (String parameter : args) {
			try {
				valuelist.add(Double.valueOf(parameter));
				sum += Double.valueOf(parameter);
			} catch (Exception e) {
				for (int i = 0; i < parameter.length(); i++) {
					valuelist.add(Double.valueOf(parameter.charAt(i)));
					sum += parameter.charAt(i);
				}
			}
		}
		System.out.println();
		System.out.println("Sum of arguments: "+sum);
		
		//average
		System.out.println("Average: "+sum/args.length);
	}
}
