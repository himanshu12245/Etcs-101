#include<dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy,i,j,x,y;
   int radius = 100;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "//turboc3//bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   //x=0
   //y=400
   setcolor(getmaxcolor());

   /* draw the circle */
   for(i=0;i<181;i++)
   {
   rectangle(0,0,getmaxx(),getmaxy());
   rectangle(600,0,getmaxx(),getmaxy());
   circle(midx++, midy, radius);
   //midx+=1;
   delay(10);
   cleardevice();
   }
   for(j=365;j>0;j--)
   {
   rectangle(0,0,getmaxx(),getmaxy());
   rectangle(600,0,getmaxx(),getmaxy());
   circle(midx--, midy, radius);
    delay(10);
   cleardevice();

   }
    setfillstyle(EMPTY_FILL, getmaxcolor());
 rectangle(0,0,getmaxx(),getmaxy());
   rectangle(600,0,getmaxx(),getmaxy());

pieslice(midx, midy, 45, 135, radius);
pieslice(midx, midy+20, 140, 230, radius);
pieslice(midx+20, midy+20, 240, 330, radius);
pieslice(midx+20, midy, 335, 360, radius);

   /* clean up */
   getch();
   closegraph();
   return 0;
}
