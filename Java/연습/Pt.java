public class Pt
{
	public static void main(String[] args)
	{
		Pm modifier = new Pm();
		int a1=111;
		Num a2 = new Num(222);
		Num a3 = new Num(333);
		System.out.println ("Before calling changeValues:");
		System.out.println ("a1\ta2\ta3");
		System.out.println (a1 + "\t" + a2 + "\t" + a3 + "\n");
		modifier.changeValues (a1, a2, a3);
		System.out.println ("After calling changeValues:");
		System.out.println ("a1\ta2\ta3");
		System.out.println (a1 + "\t" + a2 + "\t" + a3 + "\n");
	}
}

		