// KMP algorithm
//@author:  Subhamoy Sarkar
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char pattern[100];
    char text[1000];
    cout<<"Enter the String"<<endl;
    gets(text);
    cout<<"Enter the pattern"<<endl;
    gets(pattern);

    int i,j,f=0,k=0;
    int *prefix=(int*)calloc(strlen(pattern),sizeof(int));
    // We are generating prefix array required for kmp algorithm...If we have a character match
    //we will store at the current prefix position , 1 + previous prefx position's value....
    //else will drag k back to initial starting point 0. k moves by one only when there is a match
    prefix[0]=0;//for a string of len 1, prefix is always 0
    for(i=1;i<strlen(pattern);i++)
    {
        if(pattern[k]==pattern[i])
        {
            prefix[i]=1+prefix[i-1];//current pos val =1+prev position value
            k++;
        }
        else
            k=0;//take k back to starting point 0
    }
    k=0;

    for(i=0,j=0;i<strlen(text);)//travel through out the text string
    {
        if(text[j]==pattern [k])//for a char match in pattern and string
        {
            if(k==strlen(pattern)-1)//if pattern length is reached
             {
                 cout<<"Pattern found at text["<<i<<"]"<<endl;
                 i+=prefix[k]+1;
                 j=i;
                 f++;
                 k=0;
                 continue;
             }
             else{
                k++; j++;
                }
        }
        else //text[i]!=pattern[k]
        {
            i+=prefix[k]+1;
            j=i;
            k=0;
        }
    }
    if(f==0) cout<<"No pattern detected in string";
    return 0;
}
