// mm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{

	long double y1a, y1b, y1d, y2a, y2b, y2d, x11, x22,
		xm, yma, ymb, ymd;

	x11 = 1.0L / 100000000;
	x22 = 1.0L / 10000000;
	xm = 0.5L;

#define M	(-1)	//if yf is likely to be negative
	//#define M	(1)

	do
	{

		//y1a = ((25.0L / 1000000000000) / (4 * 299792) + x11) / x11 * sqrtl(powl((x11*11.186 - (x11 * 11.186 - (sqrtl(powl((x11 / ((2.75L / 1000) / 299792) * (2.75L / 1000)), 2) - powl((2.75L / 1000), 2))))), 2) + powl((2.75L / 1000), 2));
		y1a = ((25.0L / 1000000000000) / (4 * 299792) + x11) / x11 * sqrtl(powl((x11*11.186 - (x11 * 11.186 - M*(sqrtl(powl((x11 / ((2.75L / 1000) / 299792) * (2.75L / 1000)), 2) - powl((2.75L / 1000), 2))))), 2) + powl((2.75L / 1000), 2));
		y1b = sqrtl(powl(((25.0L / 1000000000000 / 299792 / 4 + x11) * 11.186 + (x11 * 11.186 - (sqrtl(powl((x11 / ((2.75L / 1000) / 299792) * (2.75L / 1000)), 2) - powl((2.75L / 1000), 2))))), 2) + powl((2.75L / 1000), 2));
		y1d = y1a - y1b;

		y2a = ((25.0L / 1000000000000) / (4 * 299792) + x22) / x22 * sqrtl(powl((x22*11.186 - (x22 * 11.186 - M*(sqrtl(powl((x22 / ((2.75L / 1000) / 299792) * (2.75L / 1000)), 2) - powl((2.75L / 1000), 2))))), 2) + powl((2.75L / 1000), 2));
		y2b = sqrtl(powl(((25.0L / 1000000000000 / 299792 / 4 + x22) * 11.186 + (x22 * 11.186 - (sqrtl(powl((x22 / ((2.75L / 1000) / 299792) * (2.75L / 1000)), 2) - powl((2.75L / 1000), 2))))), 2) + powl((2.75L / 1000), 2));
		y2d = y2a - y2b;

		yma = ((25.0L / 1000000000000) / (4 * 299792) + xm) / xm * sqrtl(powl((xm*11.186 - (xm * 11.186 - M*(sqrtl(powl((xm / ((2.75L / 1000) / 299792) * (2.75L / 1000)), 2) - powl((2.75L / 1000), 2))))), 2) + powl((2.75L / 1000), 2));
		ymb = sqrtl(powl(((25.0L / 1000000000000 / 299792 / 4 + xm) * 11.186 + (xm * 11.186 - (sqrtl(powl((xm / ((2.75L / 1000) / 299792) * (2.75L / 1000)), 2) - powl((2.75L / 1000), 2))))), 2) + powl((2.75L / 1000), 2));
		ymd = yma - ymb;

		printf("y1a,y1b,y1d(x11) = %0.19llf,%0.19llf,%0.19llf(%0.19llf),i=%0.19llf\r\n", y1a, y1b, y1d, x11, (x11 - (25.0L / 1000000000000) / (4 * 299792.0L)) * 11.186 - M* (sqrtl(powl((x11 / ((2.75L / 1000) / 299792) * (2.75L / 1000)), 2) - powl((2.75L / 1000), 2))));
		printf("y2a,y2b,y2d(x22) = %0.19llf,%0.19llf,%0.19llf(%0.19llf),i=%0.19llf\r\n", y2a, y2b, y2d, x22, (x22 - (25.0L / 1000000000000) / (4 * 299792.0L)) * 11.186 - M* (sqrtl(powl((x22 / ((2.75L / 1000) / 299792) * (2.75L / 1000)), 2) - powl((2.75L / 1000), 2))));
		printf("yma,ymb,ymd(xm) = %0.19llf,%0.19llf,%0.19llf(%0.19llf),i=%0.19llf\r\n", yma, ymb, ymd, xm, (xm - (25.0L / 1000000000000) / (4 * 299792.0L)) * 11.186 - M* (sqrtl(powl((xm / ((2.75L / 1000) / 299792) * (2.75L / 1000)), 2) - powl((2.75L / 1000), 2))));

		if (fabs(y1d) <= fabs(y2d))
		{
			y1a = yma;
			y1b = ymb;
			y1d = ymd;
			x11 = xm;
		}
		else
		{
			y2a = yma;
			y2b = ymb;
			y2d = ymd;
			x22 = xm;
		}

		if (y1a != y1a)
			system("pause");
		system("pause");

	} while (fabs(ymd) > 1.0 / 1000.0);


    return 0;
}

