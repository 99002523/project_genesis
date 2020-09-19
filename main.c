#include<stdio.h>
#include<math.h>
void RSA();
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