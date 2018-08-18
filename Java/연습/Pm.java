public class Pm
{
	public void changeValues(int f1, Num f2, Num f3)
	{
		System.out.println("바꾸기전 값:");
		System.out.println("f1\tf2\tf3");
		System.out.println(f1+"\t"+f2+"\t"+f3);
		
		f1 = 999;
		f2.setValue(888);
		f3 = new Num(777);
		
		System.out.println("바꾼후:");
		System.out.println("f1\tf2\tf3");
		System.out.println(f1+"\t"+f2+"\t"+f3);
	}
}