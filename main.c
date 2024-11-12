#include<stdio.h>
#include <windows.h>

FILE *pF;

#define BLACK   "\x1b[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
#define RESET   "\x1b[0m"

int J1[5],J2[5];
int *p1 ,  *p2 , *p3 ;
char joueur1[20] ;
char joueur2[20] ;
void BABY ()
{
    int i,a ;
    int j,b, joker = 0;
    int bp , mp;
    system ("cls");
    int ten = 1 ;
    int score ;

    code:
    printf("\n\n\tPLAYER 1 ==> "RED"%s"RESET" <== ENTER THE SECRET CODE ( 5 DIFFERENT NUMBERS ) :\n",joueur1);
    for ( p1=J1 ; p1<J1+5 ; p1++)
    {
        printf("\t\t\t\t");

       if (scanf("%d", p1) != 1) {
        printf(RED "\tINVALID INPUT. PLEASE ENTER A NUMBER." RESET);
        while (getchar() != '\n');  // Clear the input buffer
        goto code;
    }
    }
    for(p1=J1 ; p1<J1+5 ; p1++){
         for(p2=p1+1 ; p2<J1+5 ; p2++){
        if (*p1==*p2 || *p1>9 || *p1<0)
        {
         printf(RED "\tUNACCEPTABLE CODE"RESET);
         goto code;
        }

         }
    }
    system("cls");

    printf("\n\t"RED"%s"RESET" PLAYER CODE IS :"RED"  X  X  X  X  X"RESET,joueur1);
    do {
            bp = 0 ;
            mp = 0 ;

 code2:

    printf("\n\n\t"YELLOW"==>%d try  "RESET"PLAYER 2 ==> "GREEN"%s"RESET" <== GUESS THE SECRET CODE ( 5 DIFFERENT NUMBERS ) :\n",ten,joueur2);
    for ( p3=J2 ; p3<J2+5 ; p3++)
    {
        printf("\t\t");
       scanf("%d",p3);
       if (*p3>9 || *p3<0)
        {
         printf(RED "\tUNACCEPTABLE CODE"RESET);
         goto code2;
    }
    }

for (int i = 0; i < 5; i++) {
        if (J1[i] == J2[i]) {
            bp++;
        } else {
            for (int j = 0; j < 5; j++) {
                if (i != j && J1[i] == J2[j]) {
                    mp++;
                    break;
                }
            }
        }
    }


   printf("\n\t\t"CYAN"%d Good Place"RESET"\t\t"RED"%d Bad Place"RESET, bp, mp);

  if ( ten >= 9 && ten <17 && joker==0 )
  {
      printf("\n\n______________________________________"GREEN"J O K E R"RESET"________________________________________\n");
    printf(GREEN"\n\n\t IF U WANT TO USE JOKER click (1) if u don't click (2) : " RESET );
    scanf("%d", &a);
     if ( a == 1 )
   {
       joker++;
       ten = ten+3;
    printf ("\n\n\t"MAGENTA"CHOOSE THE CASE OF THE NUMBER U WANT TO SHOW '1'-'2'-'3'-'4'-'5' : "RESET);
    scanf("%d", &b);
    printf ("\n\n\t"GREEN"THIS IS THE CODE AFTER USING JOKER : "RESET);
     if ( b == 1){printf(GREEN " %d "RESET RED" X  X  X  X "RESET,J1[b-1]);}
     else if ( b == 2 ) {printf(RED" X " RESET GREEN " %d " RESET RED " X  X  X "RESET,J1[b-1]);}
     else if ( b == 3 ) {printf(RED" X  X"RESET GREEN "  %d " RESET RED " X  X "RESET,J1[b-1]);}
     else if ( b == 4 ) {printf(RED" X  X  X "RESET GREEN " %d " RESET RED " X "RESET,J1[b-1]);}
     else if ( b == 5 ) {printf(RED" X  X  X  X " RESET GREEN " %d "RESET ,J1[b-1]);}

   } else
   {
     goto no;
   }

  }
no:
 ten++  ;
  } while(ten < 20 && bp != 5) ;
  if(bp == 5){
        system("cls");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tcongratulation player 2 ==>"GREEN" %s "RESET"<== win\n\n\n\n\n\n\n",joueur1) ;
  }
  // show player 1 his score, player 2 as much as early gets the code right his score be higher

  score=ten-20;

  printf("\n\n\t\t player 1 "GREEN" %s "RESET" SCORE : "RED" %d "RESET,joueur1,ten*100);
  printf("\n\n\t\t player 2 "GREEN" %s "RESET" SCORE :"RED" %d "RESET,joueur2,score*(-100));

 pF = fopen("SCORE-lvl-1.txt", "a");
   if (pF == NULL) {
        printf("Error opening file!\n");
   } else {
        fprintf(pF, " %s : %d \n", joueur2, score * (-100));
        fclose(pF);
    }
}




void NORMAL ()
{
    int i,a ;
    int j,b, joker = 0;
    int bp , mp;
    system ("cls");
    int ten = 1 ;
    int score ;
    int exist=0;

    code:
    printf("\n\n\tPLAYER 1 ==> "RED"%s"RESET" <== ENTER THE SECRET CODE ( 5 DIFFERENT NUMBERS ) :\n",joueur1);
    for ( p1=J1 ; p1<J1+5 ; p1++)
    {

        printf("\t\t\t\t");

     if (scanf("%d", p1) != 1) {
        printf(RED "\tINVALID INPUT. PLEASE ENTER A NUMBER." RESET);
        while (getchar() != '\n');  // bach mayt9rach carachtere
        goto code;
    }

         if (*p1>9 || *p1<0)
        {
         printf(RED "\tUNACCEPTABLE CODE"RESET);
         goto code;
    }
    }


    system("cls");

    printf("\n\t"RED"%s"RESET" PLAYER CODE IS :"RED"  X  X  X  X  X"RESET,joueur1);
    do {
            bp = 0 ;
            mp = 0 ;
code2:

    printf("\n\n\t"YELLOW"==>%d try  "RESET"PLAYER 2 ==> "GREEN"%s"RESET" <== GUESS THE SECRET CODE ( 5 DIFFERENT NUMBERS ) :\n",ten,joueur2);
    for ( p3=J2 ; p3<J2+5 ; p3++)
    {
        printf("\t\t");
       scanf("%d",p3);
       if (*p3>9 || *p3<0)
        {
         printf(RED "\tUNACCEPTABLE CODE"RESET);
         goto code2;
    }
    }

for (int i = 0 ; i < 5 ; i++) {
      for(int e=1 ; e<5 ; e++){
        if (J1[i]==J1[e])
            exist++;
      }
        if (J1[i] == J2[i]) {
            bp++;
        } else {
            for (int j = 0; j < 5; j++) {
                if (i != j && J1[i] == J2[j] && exist==0 || exist==1 ) {
                    mp++;
                    break;
                }
            }
        }
    }


   printf("\n\t\t"CYAN"%d Good Place"RESET"\t\t"RED"%d Bad Place"RESET, bp, mp);

  if ( ten >= 9 && ten <17 && joker==0 )
  {
      printf("\n\n______________________________________"GREEN"J O K E R"RESET"________________________________________\n");
    printf(GREEN"\n\n\t IF U WANT TO USE JOKER click (1) if u don't click (2) : " RESET );
    scanf("%d", &a);
     if ( a == 1 )
   {
       joker++;
       ten = ten+3;
    printf ("\n\n\t"MAGENTA"CHOOSE THE CASE OF THE NUMBER U WANT TO SHOW '1'-'2'-'3'-'4'-'5' : "RESET);
    scanf("%d", &b);
    printf ("\n\n\t"GREEN"THIS IS THE CODE AFTER USING JOKER : "RESET);

     if ( b == 1){printf(GREEN " %d "RESET RED" X  X  X  X "RESET,J1[b-1]);}
     else if ( b == 2 ) {printf(RED" X " RESET GREEN " %d " RESET RED " X  X  X "RESET,J1[b-1]);}
     else if ( b == 3 ) {printf(RED" X  X"RESET GREEN "  %d " RESET RED " X  X "RESET,J1[b-1]);}
     else if ( b == 4 ) {printf(RED" X  X  X "RESET GREEN " %d " RESET RED " X "RESET,J1[b-1]);}
     else if ( b == 5 ) {printf(RED" X  X  X  X " RESET GREEN " %d "RESET ,J1[b-1]);}

   } else
   {
     goto no;
   }

  }
no:
 ten++  ;
  } while(ten < 20 && bp != 5) ;
  if(bp == 5){
        system("cls");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tcongratulation player 2 ==>"GREEN" %s "RESET"<== win\n\n\n\n\n\n\n",joueur2) ;
  }
  // nwriw l players score dyalhom player 2 kolma kano ten 9lal score dyalo khas ikon kter

  score=ten-20;

  printf("\n\n\t\t player 1 "GREEN" %s "RESET" SCORE : "RED" %d "RESET,joueur1,ten*100);
  printf("\n\n\t\t player 2 "GREEN" %s "RESET" SCORE :"RED" %d "RESET,joueur2,score*(-100));

 pF = fopen("SCORE-lvl-2.txt", "a");
   if (pF == NULL) {
        printf("Error opening file!\n");
   } else {
        fprintf(pF, " %s : %d \n", joueur2, score * (-100));
        fclose(pF);
    }
}




int main(){

char z1[]="\t\t\t\t\t\tARE YOU READY FOR THE GREATNESS OF";
char z2[]="\n\t\t\t\t\t\t      M A S T E R    M I N D";
char z3[100]="\n\n\n\t\tENTRE THE FIRST PLAYER NAME  :";
char z4[]="\n\n\n\t\tENTRE THE SECOND PLAYER NAME  :";
int niv;
int i1 ;
system("cls");
for(i1=0 ; z1[i1]!='\0'  ; i1++){
    printf(GREEN"%c"RESET,z1[i1]);
    usleep(50000);
}
for(i1=0 ; z2[i1]!='\0'  ; i1++){
    printf(RED"%c"RESET,z2[i1]);
    usleep(100000);
}
for(i1=0 ; z3[i1]!='\0'  ; i1++){
    printf("%c",z3[i1]);
    usleep(10000);
}

gets(joueur1);
for(i1=0 ; z4[i1]!='\0'  ; i1++){
    printf("%c",z4[i1]);
    usleep(10000);
}
gets(joueur2);
printf("\n\n\n\t\t\t\t\t\t press 'ENTER' to continue");
getch();
system("cls");
printf("\n     THERE IS 3 LEVELS OF DIFFICULTY  \t\t\t\t\t\n");
printf("\n\t==> LEVEL (1): "GREEN"BABY"RESET);
printf("\n\t==> LEVEL (2): "YELLOW"NORMAL"RESET);
printf("\n\t==> LEVEL (3): "RED"NIGHTMARE"RESET);
hh:
printf("\n\n\t  "CYAN" CHOOSE THE DIFFICULTY LEVEL (CLICK 1 OR 2 OR 3) : "RESET);
scanf("%d",&niv);

if (niv==1){

   BABY();

} else if (niv == 2)
{
    NORMAL();

} else if (niv == 3)
 {

     printf("NIGHTMARE");

 }else {
 printf("\n\t\t\t\t"RED"THE LEVEL YOU HAVE CHOSEN IS UNAVAILABLE "RESET);
 goto hh ;
 }

 return 0;
}

