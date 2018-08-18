import java.util.Scanner;
public class EvenChecker{
public static void main (String[] args)
{	int i;
	int number,per;
	Scanner scan = new Scanner (System.in);
	System.out.print ("짝수를 입력하십시오.");
	
	number = scan.nextInt();
	while(number!=0)
	{if (number%2==0)
		break;
	else System.out.println("홀수입니다 다시입력해주세요");
		number = scan.nextInt();	}	
	
	

}}