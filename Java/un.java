abstract class Account{
protected String holder_name,acno;
protected long balance,withdrawal_limit,penalty,min_bal,curr;
public abstract void deposit(long amount);
public abstract void withdraw(long amount);
public String toString(){ 
return this.getClass().getName()+"::[[ A/c No : "+acno+"\n Holder Name : "
+holder_name+"\n Balance : "+balance+" ]]";
}
}
class SavingsAccount extends Account{
public SavingsAccount(String name,String acno,long opening_bal)
{
min_bal=1000; withdrawal_limit=15000; balance+=opening_bal;
holder_name=name; this.acno=acno;
}
public void deposit(long amount) {
balance+=amount-penalty;
penalty=0;
System.out.println("Rs. "+amount+" is credited.. Closing Balance=Rs."+balance);
}
public void withdraw(long amount) {
if(amount+penalty>balance){ System.out.println("Insufficient Balance.."); return; }
if(curr>withdrawal_limit) { System.out.println("Daily Withdrawal Exceeded,, ");
 return; }
balance-=amount;
curr+=amount;
if(balance<min_bal) penalty+=20;
System.out.println("Rs. "+amount+" is debited.. Closing Balance=Rs."+(balance-
 penalty));
}
}
class CurrentAccount extends Account{
public CurrentAccount(String name,String acno,long opening_bal)
{
balance+=opening_bal;
holder_name=name; this.acno=acno;
}
public void deposit(long amount) {
balance+=amount;
System.out.println("Rs. "+amount+" is credited.. Closing Balance=Rs."+balance);
}
public void withdraw(long amount) {
if(amount>balance){ System.out.println("Insufficient Balance.."); return; }
balance-=amount;
System.out.println("Rs. "+amount+" is debited.. Closing Balance=Rs."+balance);
}
}
public class un{
public static void main(String[] args) throws Exception{
SavingsAccount s=new SavingsAccount("Arpan Pathak","03300110010488",15000);
System.out.println(s);
s.deposit(1000);
s.withdraw(1050);
s.withdraw(200);
s.deposit(5000);// 20 Rs penalty is debited
//s.withdraw(1000);
//s.withdraw(20); // Daily Withdrawal Limit Exceeded...
CurrentAccount c=new CurrentAccount("Arpan Pathak","00010203030300",50000);
System.out.println(c);
c.deposit(1000)
c.withdraw(25000);
}
}