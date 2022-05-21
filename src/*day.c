#include <stdio.h>

#define leap(a) ((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0)) ? 1 : 0 

static (*char)[] week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" "Saturday"}; /* An array with Sunday -> 0 and Saturday -> 6 */
static int[] month_codes = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};


int c_code();    /* Century Code */
int y_code(int); /* Year Code    */
int m_code(int); /* Month Code   */

/* y_code: Gives code of the year */
int y_code(int year)
{
	int yy, year_code; 
	yy = year % 100;
	year_code = (yy + (yy / 4)) % 7;
	return year_code;
}


/* m_code: Takes in integer representing month and returns the code */
int m_code(int month)  
{
	return month_codes[month - 1];
}

/* c_code: Gives code of a century year, -1 if it doesn't work */
int c_code(int year)
{
	int c;
	c = year % 400;

	switch(c)	{
		case 0: 
			return 6;
			break;
		case 100:
			return 4;
			break;
		case 200:
			return 2;
			break;
		case 300:
			return 0;
			break;
		default:
			return -1;
			break;
	}
}
