class Share 
{
	private int x;
	private boolean flag;
	Share(int p){x=p;flag=true;}
	Share(){x=1;flag=false;} 
	synchronized void update()
	{x+=1;}
	synchronized void display()
	{System.out.print(x+"\n");}
	synchronized int valx(){return x;}
	boolean getFlag()
		{return flag;}
	void toggle()
		{flag=!flag;}
}


class Writer extends Thread
{
	Share n;Thread t;
	Writer(Share obj)
	{
		this.n=obj;
		t=new Thread(this,"writerthread");
		t.start();
	}
	@Override
	public void run()
	{
		try
		{
		while(true)
		{	
			if(n.getFlag())
			{
				System.out.println("Writing the int ......."+t.isAlive()+"\n");
				n.update();
				n.toggle();
			}
		
		Thread.sleep(1000);
		}}
		catch(Exception e)
		{
			System.out.println("Writer thread interupted");
		}
	} 
} 


class Reader extends Thread
{
	Share n;Thread t;
	Reader(Share obj)
	{
		this.n=obj;
		t=new Thread(this,"readerthread");
		t.start();
	}
	public void run()
	{
		try{
		while(true){
			if(!(n.getFlag())){
		System.out.print("reading the int = "+t.isAlive());
		System.out.print(" & x = ");n.display();n.toggle();}
	Thread.sleep(1000);
}}
	catch(Exception e)
		{
			System.out.println("Writer thread interupted");
		}
	}
}

class demothread //extends Share
{
	public static void main(String args[])
	{
		Share commonobj = new Share();
		Writer w=new Writer(commonobj);
		Reader r=new Reader(commonobj);
	}
}
