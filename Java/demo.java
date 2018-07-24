import java.io.*;
class someexception extends Exception
{
	someexception(String s)
	{
		super (s);
	}
	public String toString()
	{
		return "Exception has occoured "+getMessage();
	}
}
class demo
{
	public static void main(String args[])throws Exception
	{	try{
		Exception e=new Exception("hello");
		throw e;}
		catch(someexception e){
		System.out.println(e);}
		/*}
		catch(Exception e)
		{
			System.out.println(e);
		}
		try{
			throw new someexception ("World");
		}
		catch(Exception f)
		{
			System.out.println(f);
		}
		//throw new someexception("choda");*/
	}
}