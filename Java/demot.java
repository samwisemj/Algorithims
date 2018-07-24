import java.io.*;
class Mythread1 extends Thread
{
	String S;
	Thread t;
	int n;
	Mythread1(int k)
	{	S="Factorial";
		t=new Thread(this,S);
		n=k;
	}
	public void run()
	{
		int k=1;
		try{
		for(int i=1;i<=n;i++)
			k=k*i;
		System.out.println("Factorial is : "+k);
		}
		catch (Exception e)
		{
			System.out.println("Factorial thread interrupted");
		}	
	}
}

class Mythread2 extends Thread
{
	String S;
	Thread t;
	int n;
	Mythread2(int k)
	{
		S="Even or odd";
		t=new Thread(this,S);
		n=k;
	}
	public void run()
	{
		try{
			if (n%2==0)
				System.out.println("Even No");
			else
				System.out.println("odd no");
			}
			catch (Exception e)
			{
				System.out.println("EVEN OR ODD thread interrupted");
			}
	}
}
class MyThread4 extends Thread
{
	Thread t;
	int n;
	MyThread4(int n)
	{
		this.n=n;
		t=new Thread(this,"magic no");
		t.start();
	}
	public void run()
	{
		int sum=0,r;
		while (n>0)
		{
		while(n<0)
		{
			r=n%10;
			n=n/10;
			sum=sum+r;
		}
		if(sum <10)
		{
			if(sum==1)
				System.out.println("magic no");
			else {System.out.println("Not magic");
				n=0;}
		}
		else
		{
			n=sum;
			sum=0;
		}
	}
}
}
class MyThread3 implements Runnable
{
	Thread t;
	String S;
	public MyThread3(String k)
	{
		S=k;
		t=new Thread(this,"Palindrome thread");
		
	}
	public void run()
	{
		String str="";
		for(int i=0;i<S.length();i++)
			str=S.substring(i,i+1)+str;
		if (S.equalsIgnoreCase(str))
			System.out.println("Palindrome");
		else
			System.out.println("Not Palindrome");
	}
}

class demot 
{
	public static void main(String args[])throws Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Mythread1 m1=new Mythread1(Integer.parseInt(br.readLine()));
		Mythread2 m2=new Mythread2(Integer.parseInt(br.readLine()));
		m1.start();
		m2.start();
		try{
			m1.t.join();
			m2.t.join();
			MyThread3 m3=new MyThread3(br.readLine());
			m3.t.start();
			MyThread4 m4 = new MyThread4(Integer.parseInt(br.readLine()));

		}
		catch(Exception e)
		{
			System.out.println(e);
		}

	}
}