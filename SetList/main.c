#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node* nodeptr;

typedef struct node{
int data;
nodeptr link;
}Node;

typedef Node* Set;

Set initialize();
void display(Set s);
Set add(Set s,int elem);
int contains(Set s, int elem);
void getUnion(Set result, Set s1, Set s2);
void intersection(Set result, Set s1, Set s2);
int main(int argc, char *argv[]) {
	int ch;
	int elem;
	Set s;
	Set s1,s2,result;
	while(1){
		system("cls");
		printf("Set list operations:\n");
		printf("1.Initialize:\n");
		printf("2.Display:\n");
		printf("3.Add:\n");
		printf("4.Contains:\n");
		printf("5.getUnion:\n");
		printf("6.Intersection:\n");
		printf("Choice :\n");
		scanf("%d",&ch);
		
		switch(ch){
		    case 1: s = initialize();
					break;
			case 2: display(s);
					break;
			case 3: s = add(s,elem);
					break;
			case 4: switch(contains(s,elem)){
						case 1: printf("Item found\n");
								break;
						case 0: printf("No such element\n");
								break;
						case -1: printf("Set is empty\n");
								break;
					}
					break;
			case 5: getUnion(result,s1,s2);
					break;
			case 6: intersection(result,s1,s2);
			}
		system("\npause");
		}
		return 0;	
	}
	

Set initialize(){
	return NULL;
}
void display(Set s){
	nodeptr temp;
	temp = s;
	if(temp == NULL){
		printf("There is no data to display.");
	}
	else{
		printf("{ ");
		while(temp != NULL){
			
			if(temp->link != NULL)printf("%d, ",temp->data);
			else printf("%d }",temp->data);
			temp = temp->link;
		}
		printf("\n\n");
	}
}
Set add(Set s,int elem){
	nodeptr temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->link = NULL;
	temp->data = elem;
	if(s == NULL){
		 s = temp;
	}
	else{
		nodeptr p;
		p = s;
		while(p->link != NULL){
			p = p->link;
		}
		p->link = temp;
		
	}
	return s;
}
int contains(Set s, int elem){
	printf("What value are you looking for?: ");
	scanf("%d",&elem);
	
	if(s == NULL){
		return -1;
	}
	else{
		nodeptr p;
		p = s;
		do{
			if(p->data == elem){
				return 1;
			}
			p = p->link;
		}while(p->link != NULL);
	}
	return 0;
}
void getUnion(Set result, Set s1, Set s2){
	int z = 1;
	int elem;
	printf("Initialize first set:\n");
	s1 = initialize();
	while(z){
		printf("Enter a number: ");
		scanf("%d",&elem);
		s1 = add(s1,elem);
		printf("Would you like to add another one\nyes(1)/no(0)?\n");
		scanf("%d",&z);
	}
	printf("Initialize second set:\n");
	z=1;
	s2 = initialize();
	while(z){
		printf("Enter a number: ");
		scanf("%d",&elem);
		s2 = add(s2,elem);
		printf("Would you like to add another one\nyes(1)/no(0)?\n");
		scanf("%d",&z);
	}
	
	system("cls\n");

	result = initialize();
	
	nodeptr temp1 = s1;
	nodeptr temp2 = s2;
	nodeptr temp3=result;
	
	int res = 1;

	while(temp1 != NULL){
		res=1;
		temp3 = result;
		elem = temp1->data;
		
		if(temp3 == NULL){
			result = add(result,elem);
		}
		else{
			while(temp3 != NULL){
				if(temp3->data == temp1->data) res = 0;
				temp3 = temp3->link;
				}
			if(res == 1){
				result = add(result, elem);
			}
		}
		temp1 = temp1->link;
	}
	
	while(temp2 != NULL){
		res=1;
		temp3 = result;
		elem = temp2->data;

			while(temp3 != NULL){
				if(temp3->data == temp2->data) res = 0;
				temp3 = temp3->link;
				}
			if(res == 1){
				result = add(result, elem);
			}

		temp2 = temp2->link;
	}
	display(result);
	return;
}
void intersection(Set result, Set s1, Set s2){
	int z = 1;
	int elem;
	printf("Initialize first set:\n");
	s1 = initialize();
	while(z){
		printf("Enter a number: ");
		scanf("%d",&elem);
		s1 = add(s1,elem);
		printf("Would you like to add another one\nyes(1)/no(0)?\n");
		scanf("%d",&z);
	}
	printf("Initialize second set:\n");
	z=1;
	s2 = initialize();
	while(z){
		printf("Enter a number: ");
		scanf("%d",&elem);
		s2 = add(s2,elem);
		printf("Would you like to add another one\nyes(1)/no(0)?\n");
		scanf("%d",&z);
	}
	
	system("cls\n");

	result = initialize();
	
	nodeptr temp1 = s1;
	nodeptr temp2 = s2;
	nodeptr temp3=result;
	int res = 1;
	while(temp1 != NULL){
		res=0;
		temp2 = s2;
		while(temp2 != NULL){
			temp3 = result;
			if(temp1->data == temp2->data){
				while(temp3 != NULL){
					if(temp3->data == temp1->data){
						res=0;
					}
					temp3 = temp3->link;
				}
				elem = temp1->data;
				if(res==1) result=add(result,elem);
			}
			temp2 = temp2->link;	
		}
	
		temp1 = temp1->link;
	}
	display(result);
	return;
}
void difference(Set result, Set s1, Set s2);
void symmetricdifference(Set result, Set s1, Set s2);
int subset(Set s1, Set s2);
int disjoint(Set s1, Set s2);
int equal(Set s1, Set s2);

