/*import java.io.*;
public class Solution
{
    public void merge(int ar[],int l,int mid,int u)
    {
    int temp[]= new int [u-l+1];
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=u)
    {
        if(ar[i]<=ar[j])
        {
            temp[k]=ar[i];
            i++;
        }
        else
        {
            temp[k]=ar[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
        temp[k++]=ar[i++];
    while(j<=u)
        temp[k++]=ar[j++];
    for(i=l,k=0;k<(u-l+1);k++,i++)
        ar[i]=temp[k];
	/*for(;i<=mid;i++)
	{
		temp[k]=ar[i];
		k++;
	}
	for(;j<=u;j++)
	{
		temp[k]=ar[j];
		k++;
	}*/
	/*for(i=l,k=0;k<(u-l+1);k++,i++)
		ar[i]=temp[k];
}
public void split(int ar[], int l, int u)
{
    int mid =(l+u)/2;
    split(ar,l,mid);
    split(ar,mid+1,u);
    merge(ar,l,mid,u);
}
public void main(String args[])throws Exception
{
    BufferedReader br=new BufferedReader (new InputStreamReader(System.in));

    System.out.println("Enter the array size");
    int n=Integer.parseInt(br.readLine());
    System.out.println("Enter array elements");
    int ar[]=new int [n];
    for(int i=0;i<n;i++)
        ar[i]=Integer.parseInt(br.readLine());
    split(ar,0,n);
    System.out.println("\nSorted Array");
    for(int i=0;i<n;i++)
        System.out.println("\t"+ar[i]);
}
}*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args)throws Exception {
        BufferedReader br=new BufferedReader (new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());int i;
        int [] ar=new int [26];
        for(i=0;i<26;i++) ar[i]=0;
        for(i=1;i<=n;i++)
            {
            String s=br.readLine();
            int j=0;
            while(j<s.length())
                {
                    int ch=(int)s.charAt(j);
                    ch-=97;j++;
                    if(ar[ch]<i)
                       ar[ch]=ar[ch]+1;
                  
                        
                }
            }
        int c=0;
        for(i=0;i<26;i++)
            {
            	 System.out.println(c);
    			 if(ar[i]==n) c++;
            }
        System.out.println(c);
    }}
