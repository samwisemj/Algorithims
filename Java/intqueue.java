import java.io.*;
import java.util.LinkedList;
import java.util.Date;
class car
{
	String name,no;
	String time;
	long intym;
	public car(String...args)
	{
		name=args[0];
		no=args[1];
		Date date=new Date();
		time =date.toString();
		intym=System.currentTimeMillis();
	}
}
interface queue 
{
	void enqueue(car c);
	void dequeue()throws Exception;
	void showall()throws Exception;
}
class parking implements queue
{
	LinkedList<car> list;
	public parking()
	{
		list =new LinkedList<>();
	}
	public void enqueue(car c)
	{
		list.addLast(c);
	}
	public void dequeue()throws Exception
	{
		if(list.size()==0)
			throw new Exception("No items in the queue");
		car dc=list.removeFirst(); // removeFirst will remove and return front....
		long outtym=System.currentTimeMillis();
		System.out.println("Removed Car details:-\nCar name-->"+dc.name+"\n car no-->"+dc.no+"\nParking IN time-->"+dc.time+"\nParking OUT time"+(new Date()).toString()+"\nTotal duration of parking(milisecs)"+(outtym-dc.intym));
	}
	public void showall()throws Exception
	{
		if(list.isEmpty()) // use isEmpty... size() will not return a boolean.. if( ) needs a boolean value.
			throw new Exception("No items in queue");
		for(int i=0;i<list.size();i++)
			System.out.println((i+1)+"Car name-- "+list.get(i).name+"Car no"+list.get(i).no+"Time of entry--"+list.get(i).time);
	}

}
public class intqueue //extends parking
{
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public static void main(String args[])throws Exception
	{
		System.out.println("\t\tCar Parking");
		parking park=new parking();
		while(true)
		{
			int ch;
			
			System.out.println("Commands:-\n1.add\n2.show all\n3.Remove\nAny other key to exit");
			ch=Integer.parseInt(br.readLine()); // Input choice
			switch(ch)
			{
				case 1:System.out.println("Option chosen-->Add\nEnter car name and car no respectively");
						String name=br.readLine();
						String no=br.readLine();
						car cr=new car(name,no);
						park.enqueue(cr);
						break;
				case 2:System.out.println("Option chosen-->Show all");
						park.showall();
						break;
				case 3:System.out.println("Option chosen-->Remove");
						park.dequeue();
						break;
					default:System.exit(1);
			}
		}
	}
}