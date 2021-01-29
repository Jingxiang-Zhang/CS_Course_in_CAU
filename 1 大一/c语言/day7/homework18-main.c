#include <stdio.h>
#include <string.h>
main()
{ char s[81],*p1,*p2;
  int n;
  gets(s);
  n=strlen(s);
  p1=s;
  p2=s+n-1;
  while (p1!=p2)
     { if (*p1!=*p2) break;
       else { p1++; p2--;}
  }
  if (p1<p2) printf("No");
  else printf("Yes");
}
