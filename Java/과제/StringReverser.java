import java.util.Scanner;
import java.lang.String;
import java.io.*;

class StringReverser
{
	public static void main(String[] args)
	{
		Scanner scan,rev;
		String str;
		int i;
		
		scan = new Scanner(System.in);
		System.out.print ("input String : ");
		str = scan.nextLine();
	
		rev = new Scanner(str);
		rev.useDelimiter(" ");
	
		while(rev.hasNext())
		{
			str = rev.next();
			for(i = str.length()-1; i>=0; i--)
			{
				System.out.print (str.charAt(i));
			}
			System.out.print(" ");
		}
		System.out.println();
	}
}