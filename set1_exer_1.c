/*×ñÞóôïò ÆÞóêáò 2014030191*/

#include <stdio.h>
#include <stdlib.h>

int recursive(int *array,int size_of_array,int i); /*Prototipo anadromikis*/

int main()
{
	int menu_answer;
	int flag=0,temp;
	int count_of_numbers,i,result;				/*Dilosi metavliton*/
	int *array;								/*Dilosi pinako me simasiologia dikti*/
	
	printf("Welcome to the 1st Project!\n\n");
	
	while(flag==0)
	{
		printf("1.Activate Program\n");
		printf("2.Exit\n\n");
		printf("Choose your answer('1' to activate,'2' for exit): ");
		scanf(" %d", &menu_answer);
		printf("\n");
		
		if(menu_answer==1)
		{
			printf("\nEnter the count of numbers do you want to use: ");
			scanf("%d", &count_of_numbers);		
	
			array=(int*)malloc(count_of_numbers*sizeof(int));								/*Desmeusi mnimis gia na xoresoun oloi oi arithmoi ston pinaka*/
		
			if(array==0)																/*Elegxos an iparxei diathesimi mnimi sto pc*/
			{
				printf("Error! No Memory");
				exit(1);
			}
			
			for(i=0;i<count_of_numbers;i++)											/*Oi deiktes dixnoun stous arithmous pou pliktrologei o xristis*/
			{
					printf("Type the number of your choice: ");
					scanf("%d", array+i);
			}
			
			result=recursive(array,count_of_numbers,0);
			printf("\n");									/*to apotelesma ths anadromikhs apothikeuete se metavliti*/
			if(result==-1)												
			{
				printf("Den iparxei zeugos pou na ikanopoiei th sinthiki!\nTimi epistrofis = %d",result); 		/*Apousia katoptrikou zeugous gia timi ths c=-1*/
				printf("\n\n");	
			}
			else
				printf("\nH thesi tou prwtou stoixeiou tou katoptrikou zeugous einai %d\n\n", result+1); /*Emfanisi th thesis tou prwtou stoixeiou tou katoptrikou zeugous*/	
			free(array); 			/*Apodesmeusi mnimis*/
		}
		
		
		if(menu_answer==2)
		{
			flag=1;
			printf("You have just selected the output mode.\nEnjoy your work.\nHave a nice day!\n\n");
		}
	}
	

	
	system("Pause");
	
	return 0;
}

int recursive(int *array,int size_of_array,int i)								//*Anadromiki Sinartisi*//
{
	if(i==size_of_array)										/*An o diktis ftasei sto telos tou megethous tou pinaka simenei oti dn exei vrethei zeugos*/
		return -1;
		
	if(array[i]+array[size_of_array-1-i]==array[0])				/*An ikanopoieite h sinthiki iparxei toulaxiston ena zeugos pou ikanopoiei th sinthiki*/
	{
		printf("The numbers %d and %d satisfies the condition", *(array+i),*(array+size_of_array-i-1));	
		printf("\n");
		return i;													/*Epistrefete h thesi tou arithmou apo to zeugos pou vriskete prwto*/
	}
	recursive(array,size_of_array,i+1); 							/*Xanakaleite h sinartisi*/
}
