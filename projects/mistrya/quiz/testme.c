#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char myString[5] = "abcde";

char inputChar()
{
    // TODO: rewrite this function
	//Declare variables.
	char myArray[34] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' , 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                       'x', 'y', 'z', '[' , ']', '{', '}', '(', ')', ' ', '\0'};
	int r;
	
	// Generating one positive random numbers for myArray[]
	r = ( rand() % 34);
	//printf("Random number is: %d\n", r);
	//printf("Random element is: %c\n", myArray[r]);
    return myArray[r];
}

char *inputString()
{
    // TODO: rewrite this function
	//Declare variables.
	char myArray[34] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' , 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                         'x', 'y', 'z', '[' , ']', '{', '}', '(', ')', ' ', '\0'};
	int r;
	int i;
	
	// Generating 5 positive random numbers for myString[]
	// Generate random number 5 times.
	for (i = 0; i < 5; i++){
	   r = ( rand() % 34);
	   
	   //replce each charecter in string with random number
	   myString[i] = myArray[r];
	//printf(" After string is: %s\n", myString);
		
	}
	return myString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  time_t startTime, endTime;
  double executionTime;
  
  startTime = time (NULL);
  //printf(ctime(&startTime));
  
  while (1)
  {
	
    tcCount++;
    c = inputChar();
    s = inputString();
    //printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error\n");
      exit(200);
    }
	endTime = time (NULL);
	
	executionTime = difftime(endTime, startTime);
	
	
	if(executionTime > 300){
		//printf(ctime(&endTime));
		//printf("The finalTime is:%f\n", executionTime);
		return;
	}
	
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
