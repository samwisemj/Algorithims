package strUtil;
import strUtil.*;
import java.io.*;
public class StringUtil
{
	String s;
	int i;
	public StringUtil()
	{
		s="";
		i=-1;
	}
	public StringUtil(String x)
	{
		s=x;
		i=-1;
	}
	public StringUtil(String x, int y)
	{
		s=x;
		i=y;
	}
	public String reversestring()
	{
		String temp="";
		for(int i=s.length()-1;i>=0;i--)
			temp=temp+s.charAt(i);
		return temp;
	}
	public void printanswer()
	{
		if(i==-1){
		String temp=reversestring();
		System.out.println("Real string "+s+"\nReversed string "+temp);}
		else
		{
			if(i<s.length()-1)
				System.out.println("Character at "+i+" is "+s.charAt(i));
			else
				System.out.println("Invalid position");	
		}
	}
}