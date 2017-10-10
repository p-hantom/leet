#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode{
	int val;
	struct ListNode *next;
};typedef struct ListNode NODE;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
int convert(NODE *head);
NODE* CreatList(); 
NODE* test();
void Display(NODE* Created);
 
int main(){
	NODE *l1=test();
	NODE *l2=test();
	Display(addTwoNumbers(l1,l2));
	
	return 0;

}
 
NODE* test(){
	NODE *head,*tail,*pnew;
	head=(NODE*)malloc(sizeof(NODE));
	if(head==NULL)
		return;
	head->next=NULL;
	tail=head;
	
	int num;
	printf("enter some vals");
	while(1){
		scanf("%d",&num);
		if(num<0)
			break;
		pnew=(NODE*)malloc(sizeof(NODE));
		pnew->val=num;
		pnew->next=NULL;
		
		tail->next=pnew;
		tail=pnew;
	}
	Display(head);
	
	return head;
}

void Display(NODE* Created){
	NODE* p;
	
	for(p=Created->next;p!=NULL;p=p->next){
		printf("%d ",p->val);
	}
	printf("\n");
}
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int num1,num2;
    num1=convert(l1);
    num2=convert(l2);
    int total=num1+num2;
    CreatList(total);
    
    return CreatList(total);
}

NODE* CreatList(int total){
	NODE *head,*tail,*pnew;
	head=(NODE*)malloc(sizeof(NODE));
	if(head==NULL){
		return (NULL);
	}
	head->next=NULL;
	tail=head;
	
	int a;
	while(total!=0){
		pnew=(NODE*)malloc(sizeof(NODE));
		if(pnew==NULL)
			return (NULL);
		pnew->val=total%10;
		pnew->next=NULL;
		
		total/=10;
		tail->next=pnew;
		tail=pnew;
	}
	
	return head;
}

int convert(NODE *head){
	int num=0;
	NODE *p=head->next;
	int weight=1;
	while(p!=NULL){
		num+=p->val*weight;
		p=p->next;
		weight*=10;
	}
	//printf("%d\n",num);
	
	return num;
}
