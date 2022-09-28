/*
 * =====================================================================================
 *
 *       Filename:  reprint.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2022 06:03:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("hello");
	printf("\33[2K\r");
	printf("bye\n");
}
