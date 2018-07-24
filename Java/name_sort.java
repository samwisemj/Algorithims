class stack extends Exception
{
	
		int s[],max,top=-1;
		
		public stack(int max)
		{
			this.max=max;
			s=new int[max];
			
		}
		
		public stack()
		{
			this.max=10;
			s=new int[max];
			
		}
		
		void push(int val)throws Exception
		{
			if(top==max-1)
				throw new Exception("Stack overloaded");
			s[++top]=val;
		}
		
		int pop()throws Exception
		{
			if(top==-1)
				throw new Exception("Stack underflow");
			return s[top--];
			
		}
		
		public String toString()
		{
			String result="[";
			for(int i=top ;i>=0;i--)
				result=result+s[i]+",";
			return result+"]";
			
		}
	}

public class name_sort
{
	public static void main(String args[])throws Exception
	{
		stack s1=new stack(20);
		for(int i=1;i<21;i++)
			s1.push(i);
		System.out.println("curreent stack :"+s1);
		System.out.println("poped value: "+s1.pop());
		System.out.println("stack after deleting: "+s1);
	}
}