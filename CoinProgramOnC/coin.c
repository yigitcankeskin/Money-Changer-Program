#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

 struct coin {
	    char name[20] ;
	    int coinValue ; 
	    int array[3];
}person,person2;
int main (void){
	int operation=0;
	while(1){
		int choice =MainScreen();
		char name[20]; 
	switch(choice){
	   case 1:
         printf("Please write the name.\n");
		 scanf("%s",&name);	
		 int resultgetPerson=getPerson(name);
		 if(resultgetPerson==1){
		 	MoneyChange(person.coinValue);
		 	operation=1;
		 }
		
         
       break;
       
       case 2:
       	if(operation==1){
       	   if(checkPerson(person.name)==0){
       	   	WriteCsv(); 
       	   	
			  }
       	   
		   }
       	
     	return 0 ;
     	break;
     	
     	default:
     		printf("You should enter number 1 or 2\n");
	}        
}
    
	
	
	return 0 ;
}

int MainScreen(){
int choice=0;
printf("1. Enter name\n2. Exit \n");
scanf("%d",&choice);

return choice;
}
int getPerson(char name[20]){
	FILE * file;
	int result=0;
	const char * fileName="coin.txt";
	file=fopen(fileName,"r");

	
	if(file==NULL){
		printf("File could not be opened'.");
		return 0;
	}
	
	while(!feof(file)){
	        fscanf(file,"%s",&person.name);
	        fscanf(file,"%d",&person.coinValue);
          	
          	int ret= strcmp(person.name,name);
			  if(ret==0){
			  	result=1;
			  	fclose(file);
			  	return result;
			  }	
          	
	       }
	     if(result==0){
	     	printf("Name : %s\nnot found.\nPlease try again.\n",name);
	     	fclose(file);
	     	return 0;
		 }  
	
}
int MoneyChange(int money){
	int fifty=0,twenty=0, ten=0, five=0;
	
	fifty = money/50;
	money -= 50*fifty;
	
	twenty = money/20;
	money -= 20*twenty;
	
	ten = money/10;
	money -= 10*ten;
	
	five = money/5;
	money -= 5*five;
	
	
	printf("Customer :\n %s %d cent ",person.name,person.coinValue);
	printf("\n%s%d \n%s%d \n%s%d \n%s%d \n\n",
			"- 50 Cent : ", fifty,
			"- 20 Cent :  ", twenty,
			"- 10 Cent :  ", ten,
			"- 5 Cent :  ", five
			);
			person.array[0]=fifty;
			person.array[1]=twenty;
			person.array[2]=ten;
			person.array[3]=five;
	return 0;

}
int WriteCsv(){
	FILE * file;
		
	const char * fileName="change.csv";
	if(file==NULL){
		printf("Can't open file\n");
        return 0;
	}
	else{
	file=fopen(fileName,"a+");	
	}
	fprintf(file,"%s, %d, %d, %d, %d, %d\n",person.name,person.coinValue,person.array[0],person.array[1],person.array[2],person.array[3]);
	printf("Informations has been written\n");
	fclose(file);
	return 0;
}
int checkPerson(char name[20]){
	FILE * file;
	int result=0;
	const char * fileName="change.csv";
	file=fopen(fileName,"r");
    char line[50];
	char *sp;
	
	if(file==NULL){
		printf("The File is Empty- New file Will be created \n ");
	}
	
	while(fgets(line,50,file)!=NULL){
	        sp= strtok(line,",");
	        strcpy(person2.name,sp);
          	
          	sp= strtok(NULL,",");
          	person2.coinValue=atoi(sp);
          	
          	
          	
          	
          	int ret= strcmp(person2.name,name);
			  if(ret==0){
			  	result=1;
			  	printf("There is a same name in the document. You Can't save again.");
			  	fclose(file);
			  	return result;
			  }	
          	
	       }
	     if(result==0){
	     	fclose(file);
	     	return 0;
		 }  
	

}

