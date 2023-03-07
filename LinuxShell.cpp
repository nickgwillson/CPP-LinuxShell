#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

int main() {

char *str1[80];
char str2[200];
char *token;
int i = 0;
while (true)
{
cout << "Enter lines of command #";
cin.getline(str2, 200);				//store lines of code into str2


pid_t pid;
pid = fork();					//birth a child

if (pid < 0){
	cout << "fork has failed: "<< endl;	//error has occured
	return 1;
}
else if (pid == 0){ 				//child process	
	token = strtok(str2, " ");

while (token != NULL) 
{
str1[i] = token;
token = strtok(NULL, " ");			//extracting tokens to token
i++;
}
str1[i] = token;				//putting tokens into str1	
	execvp(str1[0], str1);			//executing the commands
}
else {
wait(NULL);
cout << " process complete" << endl;
}


}						//end of while loop
return 0;
} 						// end of program
