/*×ñÞóôïò ÆÞóêáò 2014030191*/

#include <stdio.h>
#include <stdlib.h>

struct list
{
	int data;					/*Prototipo listas*/
	struct list *next;
}*start=NULL;
																	/*Prototipa sinartiseon*/
struct list* recursive(struct list* ptr1);

void freeList(struct list *node);

int main()
{
	struct list *current,*new_node,*n1,*result;	
	int count_of_nodes,i,flag=0,menu_answer;			/*Dilosi metavliton*/
	n1=result=NULL;/*Arxikopoihsh deikton*/
	
	
	printf("Welcome to the 2nd Project!\n\n");
	
	while(flag==0)
	{
		printf("1.Activate Program\n");
		printf("2.Exit\n\n");					/*Menu- 1 gia energopoihsh tou programmatos- 2 gia exodo*/
		printf("Choose your answer('1' to activate,'2' for exit): ");
		scanf(" %d", &menu_answer);
		printf("\n\n");
		
		
		if(menu_answer==1)		/*Gia apantisi 1*/
		{				
			printf("\nEnter the count of nodes do you want in your list: ");	/*Diavazete o arithmos ton komvon pou epithimei o xristis*/
			scanf("%d", &count_of_nodes);
			printf("\n");
			i=0;
			
			while(i<count_of_nodes)
			{
				new_node=(struct list*)malloc(sizeof(struct list));		/*Desmeusi mnimis pou apaiteite gia ton pointer oste na apothikeuei ta dedomena*/
				
				printf("\nEnter the data of the node(%d) :",i);
				scanf("%d", &new_node->data);					/*Ekxorisi timis sth metavliti data */
				new_node->next=NULL;				/*O deiktis new_node ton ekxoroume na min dixnei pouthena afou dn iparxei kati gia na deixei*/
				
				
				
				if(start==NULL)									/*o deiktis start prepei na dixnei sth prwth thesi ths lista*/
				{
					start=new_node;									/*An den dixnei pouthena prepei na dixnei sth prwth thesi p exei dimiourgithi diladi sth thesi tou new_node*/
					n1=new_node;										
					current=new_node;
				}
			
				
				else
				{
					current->next=new_node;		/*Voithitiki metavliti gia na sindeuete kathe komvos me ton epomeno*/
					current=new_node;
				}
				i++;
					
			}
			if(count_of_nodes<=2)				/*An iparxoun ligoteroi apo 2 komvoi tote theoroume oti ikanopoihte to kritirio*/
				printf("Your list satisfies the condition!\n\n");
			else
				result=recursive(n1);				/*An iparxoun parapano tote energopoihte h sinartisi recursive*/
			
			if(result==NULL)									/*Gia result=null simeni oti h lista ikanopoiei to kritirio*/
				printf("Timi epistrofis tis sinartishs: %s\n\n",result);
			else
				printf("Timi epistrofis tis sinartishs %d kai %p\n\n",result->data,result);
			free(new_node);/*Apodesmeusi mnimis*/
			start=NULL;		
			
			
		}
		if(menu_answer==2)	/*Gia apantisi tou xristi 2 tote to programma termatizete*/
		{
			flag=1;
			printf("\nYou have just selected the output mode.\nEnjoy your work.\nHave a nice day!\n\n");
		}
	
	}
	return 0;
}

struct list* recursive(struct list* ptr1)	/*Sinartisi gia elegxo tis lista an ikanopoiei ti zhtoumenh sxesi*/
{
       struct list *s;
       s=NULL;
       
       
       if(ptr1->next->next==NULL)			/*An isxuei h sxesi kai ginei null tote shmenei oti ftasame sto telos ths listas kai dn exei vrethei kapoia timh*/
       {									/*sth lista pou na mn ikanopoiei th sxesi*/
           printf("\nYour list satisfies the condition!\n\n\n");
           return NULL;
		}
       
       if((ptr1->data)<(ptr1->next->data*ptr1->next->next->data))		/*h zitoumenh sxesi*/
       {
        	recursive(ptr1->next);	/*Anadromiki klisi ths sinartisis*/
        }
       else
       {	
           s=ptr1;					/*An dn ikanopoieite h sxesi tote epistrefete deiktis pou dixnei ston prwto arithmo*/
           printf("\nYour list doesnt satisfies the condition!");			/*apo thn triada pou dn ikanopoiei th sinthiki*/
           printf("\nThe first number of the 3 consecutive numbers %d %d %d is %d", ptr1->data,ptr1->next->data,ptr1->next->next->data,s->data);
           printf("\n\n\n");
           return s;
    }
}

void freeList(struct list *node){		/*Sinartisi apodesmeusi mnimis tis listas*/
	struct list *tmp = node;			/*Xrisimopoieite voithitiki metavliti gia na mn xanonte oi proigoumenoi komvoi*/
    
    while(tmp != NULL){
		node = node->next;
		free(tmp);
		tmp = node;
    }
}
