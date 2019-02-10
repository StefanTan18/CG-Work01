#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if (x1 < x0) {
      int temp0 = x1;
      x1 = x0;
      x0 = temp0;
      int temp1 = y1;
      y1 = y0;
      y0 = temp1;
    }
  
  if (x1 == x0) {
    for (int y = y0; y <= y1; y++) {
      plot (s, c, x0, y);
    }
  }

  else if (y1 == y0) {
    for (int x = x0; x <= x1; x++) {
      plot (s, c, x, y1);
    }
  }
  
  else {
    
    int x = x0;
    int y = y0;
    int A = y1 - y0;
    int B = -(x1 - x0);
    double  m = -((double) A / B);
    
    if (m < -1) {
      int d = -2*B + A;
      
      while (y >= y1) {
	plot(s, c, x, y);
	if (d >= 0) {
	  x++;
	  d += 2*A;
	}
	y--;
	d += -2*B;
      } 
    }

    else if (m < 0) {
      int d = -2*A - B;
      
      while(x <= x1) {
	plot(s, c, x, y);
	if (d <= 0) {
	  y--;
	  d += -2*B;
	}
	x++;
	d += 2*A;
      }
    }
    
    else if (m < 1) {
      int d = 2*A + B;
    
      while(x <= x1) {
	plot(s, c, x, y);
	if (d > 0) {
	  y++;
	  d += 2*B;
	}
	x++;
	d += 2*A;
      }
    }
  
    else if (m >= 1) {
      int d = A + 2*B;

      while (y <= y1) {
	plot(s, c, x, y);
	if (d < 0) {
	  x++;
	  d += 2*A;
	}
	y++;
	d += 2*B;
      }
    }
  }
}
