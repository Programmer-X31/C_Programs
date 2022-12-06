/*
 * =====================================================================================
 *
 *       Filename:  1d-arrays.c
 *
 *    Description:  Hackerrank Exercise 
 *
 *        Version:  1.0
 *        Created:  10/30/2022 09:28:06 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Programmer-X31, 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int lim, num = 0;
    char c;  
    scanf("%d", &lim);
    int arr[lim];
    for(int i = 0; i < lim; ++i) {
        while(isdigit(c = getchar())) {
            num = 10 * num + c - '0';
        }
        printf("%d ", num);
        arr[i] = num;
        num = 0;
    }

    return 0;
}
