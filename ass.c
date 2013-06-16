/* 
@title					ascii
@description			Database emulation
@author					Victoria C
@version 				1.0
@ last revised 			02/21/13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
STUD_ID,BK_ID,STUD_NAME,BK_NAME
}
STATUS;

typedef struct
{	
unsigned long sID;
char sName[20];
char sEmail[30];	
} Student;

typedef struct 
{
unsigned long bID;
char bName[30];
char author[20];
short int quantity;	
} Book;

typedef char* string;

void fnAddStudInfo(Student*, int);
void fnPrintStudInfo( Student []);
void fnAddBookInfo(Book*, int);
void fnPrintBookInfo(Book []);
int fnSearchStud(Student*);//function that searches via id and prints that detail
int fnSearchBook(Book*);//funct that searches via book id and prints that struct
void fnReturnSName(Student []);//function that searches via student name and print that struct
void fnReturnTitle(Book []);//funct that searches via title and print that struct


int main(void)
{
int bookindex = 0;
int studindex = 0;
STATUS status;
Book book; //struct type Book named book
Student student; //struct type Student named student
Student studentInfo[10] = {}; //stores 10 student structures all initialized to NULL
Book bookInfo[10] = {}; //store 10 book structures all initialized to NULL
Student* ps = studentInfo;	//pointer to traverse the student array
Book* pb = bookInfo; //pointer to traverse the book array
int i,choice; //for menu loop and swtich statement
string menu[9] = {"1. Add new book\n","2. Add new student\n","3. Print book list\n",
"4. Print student list\n","5. Find student by ID\n","6. Find student by name\n",
"7. Find book by ID\n","8. Find book by name\n","9. Quit\n"};

	for(;;){ //menu loop 
            puts(" ");
			puts("LIBRARY SYSTEM MAIN MENU"); 
            puts("-------------------------------------");
                 for(i = 0; i < 9; i++) {
                    printf("%-10s", menu[i]);
                 }
            printf("SELECT:");
            scanf("%i", &choice);
                if(choice < 1 || choice > 9) {
                     printf("Invalid Option: %i\n", choice);
                     printf("SELECT:");
					 scanf("%i", &choice);
            }
               switch(choice) {
        
    case 1: //add new book function called
    fnAddBookInfo(bookInfo, bookindex);
	bookindex++;
	break;
            
    case 2: //add new student function called
    fnAddStudInfo(studentInfo, studindex);
    studindex++;
	break;
            
    case 3: //print book list function called
    fnPrintBookInfo(bookInfo); //prints all the book structures in the array
	break;
            
	case 4: //print student list function called
	fnPrintStudInfo(studentInfo); //prints all the students structures in the array
	break;
            
    case 5: //find student by student ID function called
    {int j = fnSearchStud(studentInfo);
    if(j != -1) {
		printf("Selected Student detail via student ID\n");
		printf("Student Id: %lu\n",studentInfo[j].sID);
		printf("Student Name: %s\n",studentInfo[j].sName);
		printf("Student Email: %s\n",studentInfo[j].sEmail);
    } 
    else { break;}
    break;} //only prints specified student structure from array via the student ID
            
    case 6: //find student by student name function called
    fnReturnSName(studentInfo);
    break;//only prints specified student structure from array via student name
    
    case 7: //find book by book ID function called
    {int k = fnSearchBook(bookInfo);
    if(k != -1) {
		 printf("Selected Book detail via book ID\n");
		 printf("Book Id: %lu\n", bookInfo[k].bID);
		 printf("Title: %s\n",bookInfo[k].bName);
		 printf("Author: %s\n",bookInfo[k].author);
		 printf("Quantity: %i\n",bookInfo[k].quantity);
	}
	else { break;   }
    break;} //only prints specified book structure from array via book ID
    
    case 8: //find book by book name function called
    fnReturnTitle(bookInfo);
    break; 
    
    case 9: //quit the menu. Will cause it to break out of switch and then after break loop
    break;
            
    }
    if(choice == 9) { //quits the loop
    printf("Exiting Program\n");
        break;
    }
			}
			
return 0;	
}


void fnPrintStudInfo(Student *studentInfo)
{
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		printf("Student ID: %lu\n Name: %s\n Email: %s\n", studentInfo[i].sID, studentInfo[i].sName, studentInfo[i].sEmail);
	} //prints all the students in the array structure
	

}


void fnAddStudInfo(Student *studentInfo, int studindex)
{
	
	
		printf("Enter Student ID:");
		scanf("%lu",&studentInfo[studindex].sID);
		printf("Enter Student name:");
		scanf(" %19[^\n]", studentInfo[studindex].sName);
		while(getchar() != '\n') continue; //ignores the /n 
		printf("Enter Student email:");
		scanf("%29[^\n]", studentInfo[studindex].sEmail);
		while(getchar() != '\n') continue;
		
		
	
}

void fnPrintBookInfo(Book *bookInfo)
{
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		printf("Book ID: %lu\n Title: %s\n Author: %s\n Quantity: %hi\n", bookInfo[i].bID, bookInfo[i].bName, bookInfo[i].author, bookInfo[i].quantity);
	} 
	

}


void fnAddBookInfo(Book *bookInfo, int bookindex)
{
	
		
	 
		printf("Enter Book ID:");
		scanf("%lu",&bookInfo[bookindex].bID);
		printf("Enter Title:");
		scanf(" %29[^\n]",bookInfo[bookindex].bName);
		while(getchar() != '\n') continue; //discards new line
		printf("Enter Author:");
		scanf(" %19[^\n]", bookInfo[bookindex].author);
		while(getchar() != '\n') continue;
		printf("Enter Quantity:");
		scanf("%hi", &bookInfo[bookindex].quantity);
		
	
}

int fnSearchStud(Student* ps) //search via student id
{
	int j;
	unsigned long SID;
	for(j = 0; j < 10; j++){
		printf("Enter student ID:");
		scanf("%lu", &SID);
			if(SID == ps[j].sID) {
		return j;
		}
		else {
			printf("No such ID exists\n");
			return -1;
			}	
	}
	return STUD_ID;
}

int fnSearchBook(Book* pb)
{
	int k;
	unsigned long BID;
	for(k = 0; k < 1; k++){
		printf("Enter book ID:");
		scanf("%lu", &BID);
			if(BID == pb[k].bID) {
				return k;
				
			}
			else {
				printf("No such ID exists\n");
				return -1;
				
				
			}	
	}
	return BK_ID;
}	

void fnReturnSName(Student* studentInfo){ //prints selected student info via name comparison
	int l;
	string Name;
	int i;
	
		printf("Please enter full Student name:");
		scanf(" %[^\n]", Name);
			for(l = 0; l < 10; l++) {
				if(strcmp (Name, studentInfo[l].sName) == 0) {
					printf("Selected Student detail via student name\n");
					printf("Student Id: %lu\n",studentInfo[l].sID);
					printf("Student Name: %s\n",studentInfo[l].sName);
					printf("Student Email: %s\n",studentInfo[l].sEmail);
					}
				else {
					i = 1;
					}
			}
	if(i == 1) {
		 printf("No such Name exists");
		 }
}

void fnReturnTitle(Book* bookInfo) { 

	int m;
	string title;
	int i;
	
	printf("Please enter Title:");
	scanf("%19s[^\n]", title);
	for(m = 0; m < 10; m++) {
		if(strcmp (title, bookInfo[m].bName) == 0) {
			printf("Selected Book detail via book title\n");
			printf("Book Id: %lu\n", bookInfo[m].bID);
			printf("Title: %s\n",bookInfo[m].bName);
			printf("Author: %s\n",bookInfo[m].author);
			printf("Quantity: %i\n",bookInfo[m].quantity);
		}
		else {
			i = 1;	
		}
	}
	if (i == 1) {
		printf("No such title exists \n");
		}
}
	
