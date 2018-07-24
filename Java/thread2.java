import java.io.*;
class factthread implements Runnable
{
	Thread t;
	int n;
	public factthread(){n=0;};

	public factthread(int k)
	{
		t=new Thread(this,"Factorial Thread");
		n=k;
		t.start();
	}
	public void run()
	{
		int prod=1;
		System.out.println("Running "+Thread.currentThread());
		try
		{
			for(int i=1;i<=n;i++)
			{
				prod*=i;
				//Thread.sleep(500);
			}
			System.out.println("Factorial is "+prod);
		}
		catch(Exception e)
		{
			System.out.println("Exception occured at Factorial thread");
		}
	}
}

public class thread2 extends factthread
{	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public static void main(String args[])throws Exception
	{
		System.out.println("Enter the no :-");
		int n=Integer.parseInt(br.readLine());int i;
		factthread nt=new factthread(n);
		Thread mt=Thread.currentThread();
		try{
			nt.t.join();
			}
		catch(Exception e)
		{
			System.out.println("Main thread interrupted ");
		}
		for(i=1;i<=n;i++)
				if(n%i==0)	System.out.println(i+" is a factor of "+n);
	}
}
