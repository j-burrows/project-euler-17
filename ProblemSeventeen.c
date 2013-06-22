/* ProblemSeventeen.c*/
#include "ProblemSeventeen.h"

/* Function: letters_for_ones
 * @param:	ones, a number between 1-10 whos letters will be counted.
 *			add_and, will determine if an and is needed to be added, 1 if so, 0 otherwiser.
 * @return:	letters, the letters required to write the number passed in.
 *
 * Will check if an and is needed to be added, and adds 3 letters if so. Then, checks which number is in the ones spot, 
 * stringifies the matching (so that the string holds the variable name one/two/ect), then finds the length of the string
 * and returns it.
*/
int letters_for_ones(int ones, int add_and){
	int letters = 0;
	
	/*If an add is pending, it is added.*/
	if(ones > 0 && add_and){
		letters+=AND_LEN;
	}
	/* Matches the number to the macro, stringifies to get the variable name, then adds the length of the variable name to 
	 * the latter count.*/
	if(ones==ONE){
		letters+= strlen(stringify(ONE));
	}
	else if(ones==TWO){
		letters+= strlen(stringify(TWO));
	} 
	else if(ones==THREE){
		letters+= strlen(stringify(THREE));
	} 
	else if(ones==FOUR){
		letters+= strlen(stringify(FOUR));
	} 
	else if(ones==FIVE){
		letters+= strlen(stringify(FIVE));
	} 
	else if(ones==SIX){
		letters+= strlen(stringify(SIX));
	} 
	else if(ones==SEVEN){
		letters+= strlen(stringify(SEVEN));
	} 
	else if(ones==EIGHT){
		letters+= strlen(stringify(EIGHT));
	} 
	else if(ones==NINE){
		letters+= strlen(stringify(NINE));
	}
	return letters;
}

/* Function:	letters_for_special_ones
 * @param:	ones, a number between 11-19 whos written length will be checked.
 *			add_and, will determine if an and is needed to be added, 1 if so, 0 otherwiser.
 * @return:	letters, the required letters to write the given number.
 *
 * Will add an add if pending, Then, will match the number with the respected macro, get the macro name, then convert the name
 * into its length, and add that to the letters. The final result is returned.
 */
int letters_for_special_ones(int ones, int add_and){
	int letters = 0;
	/*Adds an and if necissary*/
	if(add_and){
		letters+=AND_LEN;
	}
	/* Matches the number to the macro, stringifies to get the variable name, then adds the length of the variable name to 
	 * the latter count.*/
	if(ones==ELEVEN){
		letters+= strlen(stringify(ELEVEN));
	}
	else if(ones==TWELVE){
		letters+= strlen(stringify(TWELVE));
	}
	else if(ones==THIRTEEN){
		letters+= strlen(stringify(THIRTEEN));
	}
	else if(ones==FOURTEEN){
		letters+= strlen(stringify(FOURTEEN));
	}
	else if(ones==FIFTEEN){
		letters+= strlen(stringify(FIFTEEN));
	}
	else if(ones==SIXTEEN){
		letters+= strlen(stringify(SIXTEEN));
	}
	else if(ones==SEVENTEEN){
		letters+= strlen(stringify(SEVENTEEN));
	}
	else if(ones==EIGHTEEN){
		letters+= strlen(stringify(EIGHTEEN));
	}
	else if(ones==NINETEEN){
		letters+= strlen(stringify(NINETEEN));
	}
	return letters;
}

/* Function:	letters_for_tens
 * @param:	ones, a number below 100 whos written length will be checked.
 *			add_and, will determine if an and is needed to be added, 1 if so, 0 otherwiser.
 * @return:	letters, the required letters to write the given number.
 *
 * If the given number is between 11-19, a special case will be called, and the letters
 * will be returned. Otherwise, if the number is greater or equal to ten, will add an and if pending, and the value will
 * be matched with the respected macro, whos variable name length will be added to the letter count. The number is modded
 * with ten and the letters for ones required is found, added to letters, and letters is returned.
 */
int letters_for_tens(int number, int add_and){
	int tens = ((int) number/TEN)*TEN;
	int letters = 0;	
	
	/*use special ones if between 19-20*/
	if(number < TWENTY && number > TEN){
		return letters_for_special_ones(number,add_and);
	}
	if(number >= TEN && add_and){
		letters+= AND_LEN;
		/*An and cannot follow after a tens word.*/
		add_and = 0;
	}
	if(tens==TEN){
		letters+= strlen(stringify(TEN));
	}
	else if(tens==TWENTY){
		letters+= strlen(stringify(TWENTY));
	}
	else if(tens==THIRTY){
		letters+= strlen(stringify(THIRTY));
	}
	else if(tens==FORTY){
		letters+= strlen(stringify(FOURTY));
	}
	else if(tens==FIFTY){
		letters+= strlen(stringify(FIFTY));
	}
	else if(tens==SIXTY){
		letters+= strlen(stringify(SIXTY));
	}
	else if(tens==SEVENTY){
		letters+= strlen(stringify(SEVENTY));
	}
	else if(tens==EIGHTY){
		letters+= strlen(stringify(EIGHTY));
	}
	else if(tens==NINETY){
		letters+= strlen(stringify(NINETY));
	}
	return letters + letters_for_ones(number%TEN,add_and);
}

/* Function:	letters_for_hundreds
 * @param:	number, the number below 1000 whos letter count will be found.
 * 			add_and, determines if an and will be added, 1 if so, 0 if not.
 * @return:	letters, the total letters required to write the number.
 *
 * Will find the number of of the hundreds place. If it is, and an and is needed, 3 is added. If over one hundred, 
 * the letters required for the leading digit is found, and added to the letters required for "Hundred". The letters
 * for below 100 are then found and added to the letter count. The result is returned.
 */
int letters_for_hundreds(int number, int add_and){
	int hundreds = ((int)number/HUNDRED)*HUNDRED;
	int letters = 0;
	
	if(number >= HUNDRED){
		/*adds an and if needed.*/
		if(add_and){
			letters += AND_LEN;
		}
		letters+= strlen(stringify(HUNDRED));
		/*adds characters for the word x in "x hundred"*/
		letters+= letters_for_ones((hundreds/HUNDRED)%TEN,0);
		add_and = 1;
	}
	return letters + letters_for_tens(number%HUNDRED,add_and);
}

/* Function:	letters_for_thousands
 * @param:	number, the number whos required letters will be found.
 *			add_and, determines if an and is needed. 1 means there is, 0 means not.
 * @return:	letters, the total letter count required to write the number.
 *
 * Finds the number of the thousands place. If greater or equal to a thousand, the leading number's length is found
 * and added, and the and flag is set to one. The letters required for the hundreds is then found.
 */
int letters_for_thousands(int number, int add_and){
	int thousands = ((int) number/THOUSAND)*THOUSAND;
	int letters = 0;

	if(number >= THOUSAND){
		/*adds the letters for "thousand"*/
		letters+= strlen(stringify(THOUSAND));
		/* Adds the letters for the number of thousands there are*/
		letters += letters_for_hundreds(thousands/THOUSAND,0);
		add_and = 1;
	}
	return letters + letters_for_hundreds(number%THOUSAND,add_and);
}

/* Function: find_letters_upto
 * @param:	upto, the highest number whos letter count will be added.
 * @return:	letters, the number of all letters required to write the numbers.
 *
 * Will go through every number, call upon a function to find how many letters are required to write each number,
 * add that number to the total letters. Once all letters have been added, the number is returned.
 */
int find_letters_upto(int upto){
	int letters;
	int i;
	
	letters = 0;
	for(i=1;i<=upto;i++){
		letters+=letters_for_thousands(i,0);
	}
	return letters;
}

/* Program will prompt the user to enter a number. It will then display the required letters needed to write all
 * numbers between 1 and that number, using British usage. Max Number: 999 999*/
int main(){
	int letters, limit;
	char* inputted;
	fprintf(stdout,"\nThis program will display the number of letters required to write between 1 and an inputted"
					" number using British usage of AND. Maximum number is 999 999. Entering a zero or non-digit "
					"number will exit the program.");
	while(1){
		fprintf(stdout, "\n\n\nPlease Enter a desired number:\t");
		scanf("%s",inputted);
		limit = atoi(inputted);
		/*If an invalid input is given, the program will break and begin to exit.*/
		if(limit==0){
			break;
		}
		letters = find_letters_upto(limit);
		fprintf(stdout, "The total letters required is:\t%d",letters);
	}
	return 0;
}
