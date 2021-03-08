
#include<stdio.h>
#include<stdarg.h>
#include <stdlib.h>

				
 
void Myprintf(char *,...); 				
char* convert(unsigned int, int); 		//To convert integer number into octal, hex, etc.
static char Representation[]= "0123456789ABCDEF";
static char buffer[50]; 
 
int main() 
{   float  num1 =  4.5;
    int num0 = 4;
    double num2 = 234.56433;
    char arr[2] = {'a','\0'} ;
    char a = 'a';
	Myprintf(" We are checking this argument \n %c,\n%d\n%i\n%s\n%f\n%f", a,num0,num0,arr,num1,num2); 
	
	return 0;
} 
 
 
void Myprintf(char* format,...) 
{ 
	char *trav; 
	unsigned int i; 
    double d;
	char *s; 
	
	//Module 1: Initializing Myprintf's arguments 
	va_list arg; 
	va_start(arg, format); 
	
	for(trav = format; *trav != '\0'; trav++) 
	{ 
		while( *trav != '%' ) 
		{ 
			putchar(*trav);
			trav++; 
		} 
		
		trav++; 
		
		//Module 2: Fetching and executing arguments
		switch(*trav) 
		{ 
			case 'c' : i = va_arg(arg,int);		//char argument
						putchar(i);
						break; 
						
			case 'd' : i = va_arg(arg,int); 		//Integer argument
						if(i<0) 
						{ 
							i = -i;
							putchar('-'); 
						} 
						puts(convert(i,10));
						break;
            case 'i' : i = va_arg(arg,int); 		//Integer argument
						if(i<0) 
						{ 
							i = -i;
							putchar('-'); 
						} 
						puts(convert(i,10));
						break;  
						
			case 'o': i = va_arg(arg,unsigned int); // Octal representation
						puts(convert(i,8));
						break; 
						
			case 's': s = va_arg(arg,char *); 		//String
						puts(s); 
						break; 

            case 'f': d = va_arg(arg,  double );//Float and Double representation
                sprintf(buffer, "%f", d);
                fputs(buffer,stdout);
                break;
						
			case 'x': i = va_arg(arg,unsigned int); //Hexadecimal representation
						puts(convert(i,16));
						break; 
		}	
	} 
	
	//Module 3: Closing argument list for clean-up
	va_end(arg); 
} 
 
char *convert(unsigned int number, int base) 
{ 
	
	char *ptr; 
	
	ptr = &buffer[49]; 
	*ptr = '\0'; 
	
	do 
	{ 
		*--ptr = Representation[number%base]; 
		number /= base; 
	}while(number != 0); 
	
	return(ptr); 
}