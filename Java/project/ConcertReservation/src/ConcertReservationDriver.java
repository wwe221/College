import java.util.Scanner;
public class ConcertReservationDriver {
	public static void main(String[] args)
	{	System.out.println("예약(1) 조회(2) 취소(3) 끝내기(4)");
		int in;
		Scanner scan= new Scanner(System.in);
		in = scan.nextInt();
		ConcertReservation CR=new ConcertReservation(in);	
		int i=0;		
			switch(in){
				case 1:
					CR.Reserv();
					break;
				case 2:	
					CR.search();
					break;
				case 3:	
					break;
				case 4:
					return;
				}}}

