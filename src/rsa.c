#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "rsa.h"

void RSA()
{
   int choice;
  printf("\nEnter your choice:\t1.Encrypt\t2.Decrypt\t3.Exit\n");
    scanf("%d",&choice);
    while(1){
    switch(choice) {
      case 1: {
          encrypt();
          break;
        }
      case 2: {
        decrypt();
        break;
      }
      case 3: {
          break;
        }
      default: {
          printf("\nInvalid choice,Enter valid choice.\n");
        }
    }
    if(choice==3)
      break;
  }
}


void monoalphabetic()
{
  char pt[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
            char ct[26]={'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};
            char p[20]={'\0'},c[20]={'\0'},r[20]={'\0'};
            int i,j;
            printf("\n enter the plain text:");
            gets(p);
            //converting plain text into cipher text (encryption)
            for(i=0;p[i]!="\0";i++)
            {
                        for(j=0;j<26;j++)
                        {
                        if(pt[j]==p[i])
                        {
                                    c[i]=ct[j];
                        }
                        }
            }
            printf("\n cipher text is: %s",c);

            //converting cipher text into plain text (decryption)
            for(i=0;c[i]!="\0";i++)
            {
                        for(j=0;j<26;j++)
                        {
                        if(ct[j]==c[i])
                        {
                                    r[i]=pt[j];
                        }
                        }
            }
            printf("\n \n plain text is: %s",r);
}


void polyalphabetic()
{
  char pt[20]={'\0'},ct[20]={'\0'},key[20]={'\0'},rt[20]={'\0'};
    int i,j;
    printf("\n enter the plain text:");
    gets(pt);
    printf("\n enter the key:");
    gets(key);

    //length of plaintext equal to length of key
    j=0;
    for(i=strlen(key);pt[i]!="\0";i++)
    {
    if(j==strlen(key))
    {
    j=0;
    }
    key[i]=key[j];
    j++;
    }
    printf("\n new key is:%s",key);

    //converting plain text to cipher text (encryption)
    for(i=0;pt[i]!="\0";i++)
    {
        ct[i]=(((pt[i]-97)+(key[i]-97))%26)+97;
    }
    printf("\n \n cipher text is:%s",ct);

    //converting cipher text to plain text (decryption)
    for(i=0;ct[i]!="\0";i++)
    {
    if(ct[i]<key[i])
    {
        rt[i]=26+((ct[i]-97)-(key[i]-97))+97;
    }
    else
        rt[i]=(((ct[i]-97)-(key[i]-97))%26)+97;
    }
    printf("\n \n plain text is:%s",rt);
} 


void key_pair(long int e,long int n,long int d) {
  printf("\nEncryption key(e,n):%ld\t%ld\n",e,n);
  printf("\nDecryption key(d,n):%ld\t%ld\n",d,n);
}
void encrypt(){
  long int pt,p,q,n,fn,e=2,temp,d,ct;
  printf("Enter your message to encrypt:\n");
  scanf("%ld",&pt);
  printf("Enter two prime numbers p and q:\n");
  scanf("%ld %ld",&p,&q);
  n=p*q;
  fn=(p-1)*(q-1);
  temp=findGCD(e,fn);
  while(temp!=1) {
    e++;
    temp=findGCD(e,fn);
    //printf("e=%ld\ttemp=%d\t",e,temp);
  }
  //printf("\ne=%ld\n",e);
  d=multipicative_inverse(fn,e);
  if(d==0) {
    printf("\nrsa is not possible for given p and q.\n");
    exit(0);
  }
  ct=fmod(pow(pt,e),n);
  key_pair(e,n,d);
  printf("\nencrypted text:\t%ld\n",ct);
  
}
void decrypt(){
  long int pt,d,ct,n;
  printf("Enter message to decrypt:\n");
  scanf("%ld",&ct);
  printf("Enter key pair(d,n):\n");
  scanf("%ld %ld",&d,&n);
  pt=fmod(pow(ct,d),n);
  printf("Decrypted message:\t%ld",pt);
}
long int multipicative_inverse(long int m,long int b) {
  long int a1=1,a2=0,a3=m,b1=0,b2=1,b3=b,t1,t2,t3,q;
  top:
  if(b3==0) return 0;
  else if(b3==1) {
    if(b2<0) return (b2+m);
    else return b2;
  }
  q=a3/b3;
  t1=b1;
  t2=b2;
  t3=b3;
  b1=a1-(q*b1);
  b2=a2-(q*b2);
  b3=a3-(q*b3);
  a1=t1;
  a2=t2;
  a3=t3;
  //printf("\nb2=%ld\n",b2);
  goto top;
}
long int findGCD(long int e,long int fn) {
  long int c=e,d=fn;
  
  while(d!=0) {
      long int r;
    r=c%d;
    c=d;
    d=r;
  }
  return c;
}
