/* Assisted by and Assisted line numbers: Professor Su lines 35-43, 213-224 (assingment 2 driver)

*This program creates 4 of the most commonly used standard string functions without using them. Including
* strlen, strcpy, strcmp, and strcat.

*/


int mystrlen(const char compString[]) // Function declaration and definition
{

 int stringLength = 0;

   while (compString[stringLength] != '\0')
      stringLength++;
   return stringLength;   // Returns the length of string compString.
}



int mystrcmp(const char *compFirst, const char *compSecond) // Function declaration and definition
{
    while (*compFirst && *compSecond && *compFirst == *compSecond) {
        ++compFirst;
        ++compSecond;
    }

    return (unsigned char)(*compFirst) - (unsigned char)(*compSecond); // Returns the comparison of strings
                                                                       // compFirst and compSecond
                                                                       // If equal then it will return 0
                                                                       // If the first is greater than it will
                                                                       // Return a value > 0. If the second is
                                                                       // Greater than it will return a value < 0

}

char *mystrcpy(char *compTo, const char * compFrom) // Function definition and declaration
 	 {
 	   char* newString = compTo;

 	   if(('\0' != compTo) && ('\0' != compFrom)) {

 	     while ('\0' != *compFrom) {
  	       *compTo++ = *compFrom++;
  	     }

  	     *compTo = '\0';
  	   }

     return newString;  // Returns a new combined string (newString) which has copied
                        // compFrom into compTo
}

char *mystrcat(char *compTo, const char *compFrom) // Function definition and declaration
{
    char *compNew = compTo;

        if (compTo == '\0' || compFrom == '\0'){

            return compTo;
        }

        while ((*compTo) != '\0'){

            compTo++;
        }

        while ((*compFrom) != '\0'){

            *compTo++ = *compFrom++;
        }

    *compTo = '\0';

    return compNew; // Returns compNew which has copied the contents of compFrom onto the end
                   // Of the compTo
}


/*-------------------------------------------------------------------------*/
/* Lines 115 - 225 are part of the Assignment 2 test file                  */
/* cmpsc122 Assignment2 test file                                          */
/* File Name: Assign2driver.cpp                                            */
/* cmpsc122                                                                */
/* driver program for assignment 2                                         */
/*-------------------------------------------------------------------------*/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_STRING_LENGTH 256

#define ASSURE(b) assure(b, __LINE__)

void assure(bool bSuccessful, int iLineNum)
{
   if (! bSuccessful)
      printf("Test at line %d failed.\n", iLineNum);
}

void testmystrlen(void)
{
   size_t uiResult;

   uiResult = mystrlen("Ruth");
   ASSURE(uiResult == 4);

   uiResult = mystrlen("Gehrig");
   ASSURE(uiResult == 6);

   uiResult = mystrlen("");
   ASSURE(uiResult == 0);
}

void testmystrcmp(void)
{
   int iResult;

   iResult = mystrcmp("Ruth", "Ruth");
   ASSURE(iResult == 0);

   iResult = mystrcmp("Gehrig", "Ruth");
   ASSURE(iResult < 0);

   iResult = mystrcmp("Ruth", "Gehrig");
   ASSURE(iResult > 0);

   iResult = mystrcmp("", "Ruth");
   ASSURE(iResult < 0);

   iResult = mystrcmp("Ruth", "");
   ASSURE(iResult > 0);

   iResult = mystrcmp("", "");
   ASSURE(iResult == 0);
}

void testmystrcpy(void)
{
   char pc[MAX_STRING_LENGTH];
   char *pcResult;

   pcResult = mystrcpy(pc, "Ruth");
   ASSURE(pcResult != NULL);
   ASSURE(pcResult == pc);
   ASSURE((pcResult != NULL) && (strcmp(pc, "Ruth") == 0));

   pcResult = mystrcpy(pc, "");
   ASSURE(pcResult != NULL);
   ASSURE(pcResult == pc);
   ASSURE((pcResult != NULL) && (strcmp(pc, "") == 0));
}


void testmystrcat(void)
{
   char pc[MAX_STRING_LENGTH];
   char *pcResult;

   strcpy(pc, "Ruth");
   pcResult = mystrcat(pc, "Gehrig");
   ASSURE(pcResult != NULL);
   ASSURE(pcResult == pc);
   ASSURE((pcResult != NULL) && (strcmp(pcResult, "RuthGehrig") == 0));

   strcpy(pc, "Ruth");
   pcResult = mystrcat(pc, "");
   ASSURE(pcResult != NULL);
   ASSURE(pcResult == pc);
   ASSURE((pcResult != NULL) && (strcmp(pcResult, "Ruth") == 0));

   strcpy(pc, "");
   pcResult = mystrcat(pc, "Ruth");
   ASSURE(pcResult != NULL);
   ASSURE(pcResult == pc);
   ASSURE((pcResult != NULL) && (strcmp(pcResult, "Ruth") == 0));

   strcpy(pc, "");
   pcResult = mystrcat(pc, "");
   ASSURE(pcResult != NULL);
   ASSURE(pcResult == pc);
   ASSURE((pcResult != NULL) && (strcmp(pcResult, "") == 0));
}


int main() // Testing my functions to show that they work
{
   testmystrlen();
   testmystrcmp();
   testmystrcpy();
   testmystrcat();

   printf("If no any error outputs, your program passes all the tests. The End.\n");

   return 0;
}

// Program output:
// If no any error outputs, your program passes all the tests. The End.
