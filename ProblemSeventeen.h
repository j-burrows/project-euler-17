/* ProblemSeventeen.h
 *
 * Purpose: To find and display the the number of letters needed to write between 1 and some given number using 
 * 			British usage.
 *
 * Author: 	Jonathan Burrows
 * Date:	November 12th 2012
 */
#ifndef PROBLEMSEVENTEEN_H
#define PROBLEMSEVENTEEN_H 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define stringify(x) #x

/*Ones*/
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9

/*Special Ones*/
#define ELEVEN 11
#define TWELVE 12
#define THIRTEEN 13
#define FOURTEEN 14
#define FIFTEEN 15
#define SIXTEEN 16
#define SEVENTEEN 17
#define EIGHTEEN 18
#define NINETEEN 19

/*Tens*/
#define TEN 10
#define TWENTY 20
#define THIRTY 30
#define FORTY 40
#define FIFTY 50
#define SIXTY 60
#define SEVENTY 70
#define EIGHTY 80
#define NINETY 90

/*Hundreds*/
#define HUNDRED 100

/*Thousands*/
#define THOUSAND 1000

/*other length*/
#define AND_LEN 3

/* Finds the letters required to write the number in the ones place, and returns the result.*/
int letters_for_ones(int ones, int add_and);

/* Finds the letters required to write the numbers 11-19, and returns the result.*/
int letters_for_special_ones(int ones, int add_and);

/* Finds the letters required to write the number in the tens place, then adds it to the letters required for the ones
 * place, and returns the result. A number between 11-19 will replace ones and tens with special ones count.*/
int letters_for_tens(int tens, int add_and);

/* Finds the letters required for hundreds place, then adds it to the letters required for tens and ones, and returns
 * the result.*/
int letters_for_hundreds(int hundreds, int add_and);

/* Finds the letters required for the thousands place, then adds it to the letters required for hundreds, tens, and ones,
 * then returns the result.*/
int letters_for_thousands(int thousands, int add_and);

/*Finds all the letters required to write numbers 1-upto*/
int find_letters_upto(int upto);

#endif
