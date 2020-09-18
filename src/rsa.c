#include<stdio.h>
#include "rsa.h"

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
  long int r;
  while(d!=0) {
    r=c%d;
    c=d;
    d=r;
  }
  return c;
}
