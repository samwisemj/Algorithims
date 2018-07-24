import java.io.*;
class StackException extends Exception
{
	StackException (String s)
	{
		super(s);
	}
	public String toString()
	{return "An exception has occured "+getMessage();}
}
class Stack
{
	private int top,ar[];
	Stack()
	{
		top=-1;
	}
	Stack(int k)
	{
		ar=new int [k];
		top=-1;
	}
	void push(int k)throws Exception
	{
		if(check(k))//element not repeated
		{
			if(top==ar.length-1)//if stack limt is reached ie stack is full
			{
				if(top<49)
				{
				int tar[]=new int [ar.length+1];
				for(int i=0;i<=top;i++)
					tar[i]=ar[i];
				ar=tar;
				ar[++top]=k;
				}
				else
					throw new StackException("Size_Limit_Of_50_Reached");
			}
			else
				ar[++top]=k;
		}
		else
			throw new StackException("Repeated_Element_In_Stack");
	}
	void pop()
	{
		if(top==-1)
			System.out.println("Stack Underflow");
		else
			System.out.println("Popped Element : "+ar[top--]); 
	}
	boolean check(int a)
	{
		for(int i=0;i<=top;i++)
			if(ar[i]==a)
				return false;
		return true;	
	}
	void show()
	{
		if(top!=-1){
		System.out.println("Current Stack size "+ar.length);
		System.out.println("Stack Elements are");
		for(int i=top;i>=0;i--)
			System.out.println(ar[i]);
		}
		else
			System.out.println("Stack Underflow");
	}
}
class GrowableStack extends Stack
{
	static BufferedReader br=new BufferedReader (new InputStreamReader(System.in));
	public static void main(String args[])throws Exception
	{
		try
		{
			System.out.println("Initialize stack size(size must be less than 50)");
			int n=Integer.parseInt(br.readLine());
			Stack stk=new Stack(n);
			for(int i=0;;i++)
			{
				clearcon();
				System.out.print("\n\n\t\tStack Menu\nPress 1 to push\nPress 2 to pop\nPress 3 to peep\nPress any other key to exit\nEnter Choice:");
				int ch=Integer.parseInt(br.readLine());
				switch(ch)
				{
					case 1:System.out.print("\nEnter the element to be pushed : ");
							int k =Integer.parseInt(br.readLine());
							stk.push(k);
							break;
					case 2:stk.pop(); break;
					case 3:stk.show();break;
					default: System.exit(1);
				}
			}
		}
		catch(Exception e)
		{
			System.out.print(e);
		}
	}
	static void clearcon()
	{
		try
		{
			String os =System.getProperty("os.name");
			if(os.contains("Windows")||os.contains("WINDOWS")||os.contains("windows"))
				Runtime.getRuntime().exec("cls");
			else
				Runtime.getRuntime().exec("clear");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
