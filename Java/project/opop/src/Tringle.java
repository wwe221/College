public class Tringle {
	private int mit;
	private int high;
	
	public Tringle(int mitt, int highh)
	{
	mit=mitt;
	high=highh;
	}
	
	public int gethigh()
	{
	return high;
	}
	
	public int getmit()
	{
	return mit;
	}
	
	public int sethigh(int highh)
	{
		high=highh;
		return highh;
	}
	
	public int setmit(int mitt)
	{
	mit=mitt;
	return mit;
	}
	
	public double getarea()
	{
	return (mit*high)/2;
	}

}