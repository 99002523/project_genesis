#include<stdio.h>
#include<math.h>
#include<string.h>
void RSA();
void monoalphabetic();
void polyalphabetic();
void main(){
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
}



