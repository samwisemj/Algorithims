import java.io.*;
class mythread implements Runnable
{
	String name;int k;
	Thread t;
	public mythread(String n,int tv)
	{
		t=new Thread(this,"Thread2Factorial");
		name=n;
		k=tv;
		t.start();
	}
	public void run()
	{
		try{
		int prod=1;
		for(int i=k;i>0;i--)
			prod*=i;
		t.sleep(500);
		System.out.println("Thread Name "+t.getName());
		System.out.println("Factorial"+prod);
		}
		catch(Exception e)
		{System.out.println("Thread iterrupted 2");}
	}
} 
public class demo2
{
	public static void main(String args[])throws Exception
	{
		Thread ct;
		ct=Thread.currentThread();
		mythread t1=new mythread("factorial",5);//factorial thread started
		try{
			int n=5;
			t1.t.join();
				
			}
		catch(Exception e)
		{System.out.println("Thread iterrupted 1");}
		for(int i=0;i<=5;i++)
				{
				if(n%i==0)
				System.out.println(i + " is a factor");
			//ct.sleep(1000000);}
				}
	}

}
for(int i=0;i<=5;i++)
				{
				if(n%i==0)
				System.out.println(i + " is a factor");
			//ct.sleep(1000000);}
				}