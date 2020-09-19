#include<stdio.h>
#include<math.h>
void RSA();
void monoalphabetic();
void polyalphabetic();
int main(){
   int choice;
  int choice;
  while(1){
    printf("Enter your choice 1.RSA\n2.Monoalphabetic\n3.Polyalbhabetic\n4.exit");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: {
          RSA();
          break;
        }
      case 2: {
        monoalphabetic();
        break;
      }
      case 3: {
          polyalphabetic();
        }
      case 4:{
        break;
      }
      default: {
          printf("\nInvalid choice,Enter valid choice.\n");
        }
    }
  }
  return 0;
}



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
            for(i=0;i<strlen(p);i++)
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
            for(i=0;i<strlen(c);i++)
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
    scanf("%s",pt);
    printf("\n enter the key:");
    scanf("%s",key);

    //length of plaintext equal to length of key
    j=0;
    for(i=strlen(key);i<strlen(pt);i++)
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
    for(i=0;i<strlen(pt);i++)
    {
        ct[i]=(((pt[i]-97)+(key[i]-97))%26)+97;
    }
    printf("\n \n cipher text is:%s",ct);

    //converting cipher text to plain text (decryption)
    for(i=0;i<strlen(ct);i++)
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