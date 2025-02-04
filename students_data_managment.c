/*
 ============================================================================
 Name        : students_data.c
 Author      : MAriam hassan
 Version     :
 Copyright   : Your copyright notice
 Description : students data program
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* information of student*/
struct student
{
	int ID ;
	char name[50] ;
	int age ;
	float gpa;

};

/* description of node data*/
struct node
{
	struct student data ;
	struct node *next;
};

/* initialization of head by NULL as no node is added yet*/
struct node *head =NULL;

/*declaration of functions*/
void addStudent(const struct student *const ptr);
void display (void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);


int main (void)
{
	/* declaration of struct student to carry information entered by user*/
	struct student new_student;
	/*declaration of integer variables to hold choice and the certain id by user*/
	int choice , id;
	do{
    printf("***************************************\n");
    /* displaying the menu of the program allowing user to choose by entering number of his choice*/
	printf("1-Add the number \n");
	printf("2-Display the data \n");
	printf("3-Search by student ID\n");
	printf("4-Update student by  its ID\n");
	printf("5-Calculate average of gpa \n");
	printf("6-Get the highest gpa\n");
	printf("7-Delete student by ID \n");
	printf("8-Exit program\n");
	printf("***************************************\n");
	printf("Enter the number of your choice:");
	fflush(stdout);
	scanf("%d",&choice);
/* switch is used to call the function according to choice number */
	switch(choice)
	{
	case 1 :
/* here addstudent ask user for enter every data and
   then call addstudent function pass struct student to it by addres */
		printf("Student ID:");
		fflush(stdout);
		scanf("%d",&new_student.ID);
		printf("Student name:");
		fflush(stdout);
		scanf("%s",new_student.name);
		printf("Student age:");
		fflush(stdout);
		scanf("%d",&new_student.age);
		printf("Student gpa:");
		fflush(stdout);
		scanf("%f",&new_student.gpa);
		addStudent(&new_student);
		break;
	case 2:
		/* calling display function that print all student stored*/
		display();
		break;
	case 3:
		/*ask user to enter the id that he want to search for and pass it by value to search function*/
		printf("Enter the student ID:");
		fflush(stdout);
		scanf("%d",&id);
		searchStudentByID(id);
		break;
	case 4:
		/*ask user to enter the id that he want to modify and pass it by value to update function*/
		printf("Enter the student ID:");
		fflush(stdout);
		scanf("%d",&id);
		updateStudent(id);
		break;
	case 5:
		/*print the return of average function */
        printf(" the average is :%0.2f\n",calculateAverageGPA());
        break;
	case 6:
		/*calling function that print the highest gpa if students*/
		searchHighestGPA();
		break;
	case 7:
		/*ask user to enter the id that he want to delete and pass it by value to delete function*/
		printf("enter the student ID :");
		fflush(stdout);
		scanf("%d",&id);
		deleteStudent(id);
		break;
	case 8:
		/* end the program */
		break ;
	default :
		printf("invalid choice\n");
	}

	}while(choice!=8);

}

/* definition of functions */
/*============================================================================================================*/
/* function return void and take the address of struct in constant pointer to constant data*/
void addStudent(const struct student *const ptr)
{
	/* current will loop to list and it initiate by null*/
   struct node *current=NULL;

   /* create link pointer of struct node type to store the void pointer returned by malloc function*/
   struct node*link=(struct node *)malloc(sizeof(struct node));

   /* if link carry NULL it mean that a segmentation error is occur*/
   if (link == NULL)
   {
	   printf("------>error in memory allocation<-----\n");
	   return;
   }
   /* else start to store data passed to your pointer*/
   link->data.ID=ptr->ID;
   strcpy(link->data.name,ptr->name);
   link->data.age=ptr->age;
   /* normal range of GPA 0 TO 4 */
   if (ptr->gpa>=0  && ptr->gpa <=4)
   {
   link->data.gpa=ptr->gpa;
   }else
   {
	printf("GPA rang must between 0 to 4\n");
	return;
   }
   link->next=NULL;

 /* if head == NULL  so it indicate that will be the first node so put link to head*/
   if(head==NULL)
   {
	   head=link;
	   return;
   }

   /* check if the id has been exist before */
   /*from start of list*/
   current=head;
   while (current !=NULL)
   {
	   if(current->data.ID==ptr->ID)
	   {
	   printf("-----> This ID is exist before <-----\n");
	   return;
	   }
	   /* current jump to next address */
	   current =current -> next;

   }
   /* loop by current store the new nodes */
   /*from start of list */
   current =head;
   /* if you reach the last node add the new node at end*/
   while(current->next != NULL)
   {
	   /* jump to next */
	   current =current -> next;
   }
   /*putting the new node at end*/
   current-> next = link;
}

/*============================================================================================================*/
/* function take and return nothing used to print students data */
void display (void)
{
	/* current will loop starting from head */
	struct node *current =head;
	if (head==NULL)
	{
		/*mean no nodes added yet*/
		printf("-----> No students are present<-----\n");
		return;
	}else{

   /* this loop will end when it reach to atfer last node*/
    while (current != NULL)
    {
    	/* print the struct student data*/
    	printf("***************************************\n");
    	printf("student ID :%d\n ",current->data.ID);
    	printf("student name :%s\n ",current->data.name);
    	printf("student age :%d\n ",current->data.age);
    	printf("student gpa :%0.1f\n ",current->data.gpa);

    	printf("\n");
    	/* jump to next one */
    	current=current->next;
    }

	 }
}

/*============================================================================================================*/
/*function return nothing and take the certain id to search for */
void searchStudentByID(int id)
{
	/* current will loop starting from head */
	struct node *current =head;
	if(head==NULL)
	{
		/*mean no nodes added yet*/
		printf("----->No data exist to search<-----\n");
		return;
	}

	/* loop on list until you reach to end*/
	while(current !=NULL)
	{
		/* when getting the match id print its struct student data*/
		if(current->data.ID==id)
		{
			printf("***************************************\n");
			printf("student id : %d\n",current->data.ID);
			printf("student name : %s\n",current->data.name);
			printf("student age : %d\n",current->data.age);
			printf("student gpa : %0.2f\n",current->data.gpa);

			printf("\n");
			return;
		}
		/* jump to next*/
		current=current->next;
	}
	printf("\n");
	/* when we reach here it mean id doesn't exist in list*/
	printf("----->The id is not found<-----\n");

}

/*============================================================================================================*/
/*function return nothing and take the certain id to modify */
void updateStudent(int id)
{
	/* current will loop starting from head */
	struct node *current =head;

	if(head==NULL)
		{
		    /*mean no nodes added yet*/
			printf("----->No data exist to search<-----\n");
			return;
		}
	 /* loop on list until you reach to end*/
		while(current !=NULL)
		{
			/* when getting the match id modify its struct student data*/
			if(current->data.ID==id)
			{
				printf("student name :");
			    fflush(stdout);
				scanf("%s",current->data.name);
				printf("student age :");
				fflush(stdout);
				scanf("%d",&current->data.age);
				printf("student gpa :");
				fflush(stdout);
				scanf("%f",&current->data.gpa);
				return;
			}
			/* jump to next*/
			current=current->next;
		}
	/* when we reach here it mean id doesn't exist in list*/
		printf("----->The id is not found<-----\n");
}

/*============================================================================================================*/
/* function return float average and take nothing*/
float calculateAverageGPA(void)
{
	/* current will loop to list and it initiate by null*/
	struct node * current =NULL;

	/* declaration of size and sum and initialize them by zeros*/
	int size =0;
	float sum=0;

	if (head == NULL)
	{
		/*mean no nodes added yet*/
		printf(" ----->zero size %d<-----",size);
		return size;
	}
	/* loop on list from start*/
	current = head;
	size=1;
	while (current-> next !=NULL )
	{
		/* as long as you jump before reaching the last node increment size by 1*/
		size++;
		/*jump to next*/
		current =current ->next;
	}

/* loop from start again the accumulate the gpa*/
	current=head;
	while (current !=NULL)
	{
		/*as you didn't reach the end accumulate the gpa and jump to next*/
		sum+=current->data.gpa;
		current = current -> next;
	}



/* average = sum of element / no of elements */
	return  sum/size;

}


/*============================================================================================================*/
/* function take and return nothing used to print the highest gpa*/
void searchHighestGPA(void)
{
	/* current will loop to list and it initiate by null*/
	struct node *current =NULL;
	/*declaration of variable to store the max gpa*/
	float max_gpa;

	if (head==NULL)
	{
		/*mean no nodes added yet*/
		printf("----->The list is empty<-----\n");
		return;
	}
	/* start loop from the start*/
	current = head;
	/* store first gpa in max */
	max_gpa=current->data.gpa;
	while (current !=NULL)
	{
		/* as we loop on list till the end if we get gpa greater than max we will replace it with max*/
		if (current->data.gpa>max_gpa)
		{
			max_gpa=current->data.gpa;
		}
		/* jump to next*/
		current=current->next;
	}
	/*finally print the max gpa*/
	printf("------>The highest gpa is :%0.2f <------ \n",max_gpa);
	/* loop from start*/
	current = head;
	while(current !=NULL)
		{
			/* when getting the match maximum gpa print its struct student data*/
			if(current->data.gpa==max_gpa)
			{
				printf("***************************************\n");
				printf("student id : %d\n",current->data.ID);
				printf("student name : %s\n",current->data.name);
				printf("student age : %d\n",current->data.age);
				printf("student gpa : %0.2f\n",current->data.gpa);

				printf("\n");
				return;
			}
			/* jump to next*/
			current=current->next;
		}
}


/*============================================================================================================*/
/*function return nothing and take the certain id to delete its student  */
void deleteStudent(int id)
{
	/* at beginning the three pointer will point to NULL*/
	  struct node *current =NULL;
	  struct node *prev =NULL;
	  struct node *deleted_node =NULL;


	if (head==NULL)
	{
		/*mean no nodes added yet*/
		printf("------>The list is empty<------\n");
		return;
	}

	/* if id exist  at first node */
	if (head->data.ID==id)
	{
		/* store head at deleted_node pointer first */
		deleted_node=head;
		/*jump head to next*/
		head=head->next;
		/* delete the node */
		free(deleted_node);
		return;
	}
	/* prev pointer will point to head and current to address next to it*/
	prev=head;
	current= head->next;
	/* as we loop n list searching for id */
	while (current !=NULL)
	{
		if(current->data.ID==id)
		{
			/* if we find the required id */
			/* store current to deleted node and assign the prev by next jump of current*/
			deleted_node=current;
			prev->next=current->next;
			/* deleted node freely*/
			free(deleted_node);
			printf("----> student deleted successfully<---\n");
			return;
		}
		/*give current to prev and let current point to next */
		prev=current;
		current=current->next;
	}
	/* reaching here mean the id is not exist*/
	printf("------->The ID is not found<-------\n");
}







