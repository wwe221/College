import java.util.Scanner;
import java.io.*;
public class CountingAndSumming
{
public static void main(String[] args) throws IOException
{
String fileName = "input.txt";
Scanner fileScan = new Scanner(new File(fileName));
int sum = 0;
int count = 0;
int a;
while(fileScan.hasNext())
{
	a= fileScan.nextInt();
	sum=sum+a;
	count++;
}
System.out.println("There were " + count + " numbers in " + fileName + " and their sum was " + sum + ".");
}
}