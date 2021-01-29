#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//StudybarCommentBegin
#include <stdio.h>
main()
{ char max, s[20]="I am a student";
  int n;
  max=s[0];
//StudybarCommentEnd

  for(n=0;n<20;n++)
  if(max<s[n]) max=s[n];



	
//StudybarCommentBegin
 printf("The max character is: %c", max);
}
//StudybarCommentEnd
