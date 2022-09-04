/* Francis Lu
 * 9080557540
 */

/* This function takes a string as input and removes 
 * leading and trailing whitespace including spaces
 * tabs and newlines. It also removes multiple internal
 * spaces in a row. Arrays are passed by reference.
 */

#include <stdio.h>
#include <stdlib.h>
#include "student_functions.h"

void Clean_Whitespace(char str[]) {
	//removing frontspaces, newlines, and tabs.
	int j, i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
		i++;
	}
	while (str[j + i] != '\0') {
		str[j] = str[j + i];
		j++;
	}
	str[j] = '\0';
//////////////////////////////////////////////
	//Removing trailing whitespaces
	// copied from: https://codeforwin.org/2016/04/c-program-to-trim-both-leading-and-trailing-white-spaces-in-string.html
	i = -1;
	j = 0;

	while (str[j] != 0) {
		if (str[j] == " " && str[j] == '\t' && str[j] == '\n') {
			j = i;
		}
		j++;
	}
	str[j + 1] = '\0';
	return;
}

/* This function takes a string and makes the first
 * letter of every word upper case and the rest of the
 * letters lower case
 */
void Fix_Case(char str[]) {
	// coppied "str[index_case] = str[index_case] + 32;" from:  https://www.includehelp.com/c-programs/capitalize-first-character-of-each-word-in-string.aspx
	int index_case;

	for (index_case = 0; str[index_case] != '\0'; index_case++) {
		//check first character is lowercase alphabet
		if (index_case == 0) {
			if ((str[index_case] >= 'a' && str[index_case] <= 'z'))
				str[index_case] = str[index_case] - 32; //subtract 32 to make it capital
			continue; //continue to the loop
		}
		if (str[index_case] == ' ') //check space
				{
			//if space is found, check next character
			++index_case;
			//check next character is lowercase alphabet
			if (str[index_case] >= 'a' && str[index_case] <= 'z') {
				str[index_case] = str[index_case] - 32; //subtract 32 to make it capital
				continue; //continue to the loop
			}
		} else {
			//all other uppercase characters should be in lowercase
			if (str[index_case] >= 'A' && str[index_case] <= 'Z')
				str[index_case] = str[index_case] + 32; //subtract 32 to make it small/lowercase
		}
	}

	return;
}

/* this function takes a string and returns the 
 * integer equivalent
 */
int String_To_Year(char str[]) {
	int i = 0;
	int year;
	for (i; str[i] != '\0'; i++) {
		int year = atoi(str);
	}
	return year;
}

/* this function takes the name of a 
 * director as a string and removes all but
 * the last name.  Example:
 * "Bucky Badger" -> "Badger"
 */
void Director_Last_Name(char str[]) {
	int i = 0;
	char str1[1024] = "";
	int j = 0;

	//pointer goes to the end of the name and stops right before null.
	for (i; str[i] != '\0'; i++) {
		j++;

	}
	//pointer goes all the way back the string until the most recent blank space
	for (i; str[i] != ' '; i--) {
		j--;

	}
	//pointer stores everything between the most recent blank space and null to get the last name.
	for (i; str[i] != '\0'; i++) {
		str1[i - j - 1] = str[i];

	}
	return;

}

/* this function takes the a string and returns
 * the floating point equivalent
 */
float String_To_Rating(char str[]) {
	int i = 0;
	float rating;
	for (i; str[i] != '\0'; i++) {
		rating = atof(str);
	}
	return rating;
}

/* this function takes a string representing
 * the revenue of a movie and returns the decimal
 * equivlaent. The suffix M or m represents millions,
 * K or k represents thousands.
 * example: "123M" -> 123000000
 */
long long String_To_Dollars(char str[]) {
	int i = 0;
	long long dollars;

	for (i; str[i] != '\0'; i++) {
		if (str[i + 1] == '\0') {
			dollars = atoll(str);
			if (str[i] == 'M' || str[i] == 'm') {
				dollars = 1000000 * dollars;
			}
			if (str[i] == 'K' || str[i] == 'k') {
				dollars = dollars * 1000;
			}
		}
	}
	return dollars;
}

/* This function takes the array of strings representing 
 * the csv movie data and divides it into the individual
 * components for each movie.
 * Use the above helper functions.
 */
void Split(char csv[10][1024], int num_movies, char titles[10][1024],
		int years[10], char directors[10][1024], float ratings[10],
		long long dollars[10]) {

	int i = 0;
	int number_of_lines;
	int store_num_movies;
	char store_titles[][] = "";
	int store_years;
	char store_directors[][] = "";
	float store_ratings;
	long long store_dollars;

	while (csv[number_of_lines][1024] != '\0') {
		//to see the number of movies the in the list
		for (i; csv[number_of_lines][i] != ' '; i++) {
			store_num_movies = Clean_Whitesapce(csv[number_of_lines][i]);
		}
		number_of_lines++; //go to the next line to start getting directors, ratings, etc.

		for (i; csv[number_of_lines][i] != ','; i++) {
			Fix_Case(csv[number_of_lines][i]);
			store_years = String_To_Year(csv[number_of_lines][i + 1]);

			Fix_Case(csv[number_of_lines][i + 3]);
			Director_Last_Name(store_directors);

			store_ratings = String_to_Ratings(csv[number_of_lines][i + 4]);

			store_dollars = String_To_Dollars(csv[number_of_lines][i + 5]);

			Clean_Whitespace(store_titles);
			Clean_Whitespace(store_years);
			Clean_Whitespace(store_directors);
			Clean_Whitespace(store_ratings);
			Clean_Whitespace(store_dollars);

			//traverse to the next line of directors, ratings, etc.
			if (csv[number_of_lines][i] == '\0') {
				number_of_lines++;
			}
		}
	}

	return;
}

/* This function prints a well formatted table of
 * the movie data 
 * Row 1: Header - use name and field width as below
 * Column 1: Id, field width = 3, left justified
 * Column 2: Title, field width = lenth of longest movie + 2 or 7 which ever is larger, left justified, first letter of each word upper case, remaining letters lower case, one space between words
 * Column 3: Year, field with = 6, left justified
 * Column 4: Director, field width = length of longest director last name + 2 or 10 (which ever is longer), left justified, only last name, first letter upper case, remaining letters lower case
 * column 5: Rating, field width = 6, precision 1 decimal place (e.g. 8.9, or 10.0), right justified
 * column 6: Revenue, field width = 11, right justified
 */
void Print_Table(int num_movies, char titles[10][1024], int years[10],
		char directors[10][1024], float ratings[10], long long dollars[10]) {
	/// I honestly have no clue how to do this :( Lesson leanred I will start earlier next time :(
	int i = 0;
	int title_width;
	int number_of_lines = 0;
	char id[] = "Id ";
	char title[] = "Title       ";
	char year[] = "Year ";
	char director[] = "Director         ";
	char rating[] = "Ratings     ";
	char revenue[] = "Revenue";

	printf("%s%s%s%s%s%s\n", id, title, year, director, rating, revenue);

	}

	return;
}

