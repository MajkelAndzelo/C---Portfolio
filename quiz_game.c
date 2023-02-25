#include <stdio.h>

int main()
{
    int i;
    int ans1,ans2,ans3,ans4,ans5;
    int point1,point2,point3,point4,point5,point6,point7,point8,point9,point10;
    int point01,point02,point03,point04,point05,point06,point07,point08,point09,point010;
    int total1,total2,total3;
    
    printf("    Welcome to the Game\n\n");
    
    printf("> Press 7 to start the game\n");
    printf("> Press 0 to quit the game\n");
    
    scanf("%d", &i);
    
    if(i==7)
    {
         printf("The game has started\n\n");
    }
    else if(i==0)
    {
         printf("The game has ended\n\n");
    }
    else
    {
         printf("invalid\n\n");
    }
    
    if(i==7)
    {
         printf("1)Which one is the first search engine in internet?\n\n");
         printf("1)Google\n");
         printf("2)Archie\n");
         printf("3)Wais\n");
         printf("4)Altavista\n");
         
         printf("Enter Your Answer : ");
         scanf("%d", &ans1);
         
         if(ans1==2)
         {
              printf("Correct Answer\n");
              point1 = 5;
              printf("You have scored %d point\n", point1);
         }
         else
         {
              printf("Wrong Answer\n");
              point01 = 0;
              printf("You have scored %d point\n", point01);
         }
         
         printf("2)Which one is the first web browser invented in 1990?\n\n");
         printf("1)Internet Explorer\n");
         printf("2)Mosaic\n");
         printf("3)Mozilla\n");
         printf("4)Nexus\n");
         
         printf("Enter Your Answer : ");
         scanf("%d", &ans2);
         
         if(ans2==4)
         {
              printf("Correct Answer\n");
              point2 = 5;
              printf("You have scored %d point\n", point2);
         }
         else
         {
              printf("Wrong Answer\n");
              point02 = 0;
              printf("You have scored %d point\n", point02);
         }
         
         printf("3)First computer virus is known as?\n\n");
         printf("1)Rabbit\n");
         printf("2)Creeper Virus\n");
         printf("3)Elk Cloner\n");
         printf("4)SCA Virus\n");
         
         printf("Enter Your Answer : ");
         scanf("%d", &ans3);
         
         if(ans3==2)
         {
              printf("Correct Answer\n");
              point3 = 5;
              printf("You have scored %d point\n", point3);
         }
         else
         {
              printf("Wrong Answer\n");
              point03 = 0;
              printf("You have scored %d point\n", point03);
         }
         
         printf("4)Firewall in computer is used for?\n\n");
         printf("1)Security\n");
         printf("2)Data Transmission\n");
         printf("3)Monitoring\n");
         printf("4)Authentication\n");
         
         printf("Enter Your Answer : ");
         scanf("%d", &ans4);
         
         if(ans4==1)
         {
              printf("Correct Answer\n");
              point4 = 5;
              printf("You have scored %d point\n", point4);
         }
         else
         {
              printf("Wrong Answer\n");
              point04 = 0;
              printf("You have scored %d point\n", point04);
         }
         
         printf("5)Which of the following is not a database management software?\n\n");
         printf("1)Mysql\n");
         printf("2)Oracle\n");
         printf("3)cobal\n");
         printf("4)Sybase\n");
         
         printf("Enter Your Answer : ");
         scanf("%d", &ans5);
         
         if(ans5==3)
         {
              printf("Correct Answer\n");
              point5 = 5;
              printf("You have scored %d point\n", point5);
         }
         else
         {
              printf("Wrong Answer\n");
              point05 = 0;
              printf("You have scored %d point\n", point05);
         }
    }
    
     return 0;
}


