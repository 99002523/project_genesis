#include<stdio.h>
#include<math.h>

int main(){
  int choice;
  while(1){
    printf("\nEnter your choice:\t1.Encrypt\t2.Decrypt\t3.Exit\n");
    scanf("%d",&choice);
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
  return 0;
}