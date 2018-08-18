import java.util.Scanner;
public class Average
{
public static void main(String[] args)
{
int val1, val2, val3, val4, val5;
double average;
	Scanner scan = new Scanner(System.in) ;
	System.out.println("Please enter five integers and " +"I will compute their average");
	System.out.print("Enter the first value:");
		val1 = scan.nextInt();
	System.out.print("Enter the second value:");
		val2 = scan.nextInt();
	System.out.print("Enter the third value:");
		val3 = scan.nextInt();
	System.out.print("Enter the fourth value:");
		val4 = scan.nextInt();
	System.out.print("Enter the fifth value:");
		val5 = scan.nextInt();
	average = (float)(val1 + val2 + val3 + val4 + val5)/5 ;
	System.out.println("\n\nThe Average is	" + average);
}}
