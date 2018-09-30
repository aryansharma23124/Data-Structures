#include<bits/stdc++.h>
using namespace std;




struct Listnode
{
	int data;
	struct Listnode *next;
};


void insert_data(Listnode **head,int data){
	Listnode *temp=*head;
	//cout<<temp->data;
	Listnode *ins=new Listnode;
	ins->data=data;
	ins->next=*head;
	if(*head==NULL){
		//ins->data=data;
		ins->next=ins;
	}
	else{
		while(temp->next!=*head){
			temp=temp->next;
		}
		temp->next=ins;
	}
	*head=ins;
}
//print from tail

void printlist(Listnode *head){
	Listnode *temp1=head,*temp2=head;
	if(temp1!=NULL and temp1->next!=NULL){
		do{
			cout<<temp1->next->data;
			temp1=temp1->next;
		}
		while(temp1!=temp2);
	}
	else{
		cout<<"NULL HERE";
	}
}


//Last node insertion when the pointer points at last node

int insert_in_an_emptylist_lnode(Listnode **last,int data){
	Listnode *temp1=new Listnode;
	if(*last!=NULL)
		return 0;
	else{
		temp1->data=data;
		temp1->next=temp1;
		*last=temp1;
		//cout<<last->data;
		//last=temp1;
		return  1;
	}
}

int  inserting_a_node_begining_using_lnode(Listnode *last,int data){
	if(last==NULL){
		return (insert_in_an_emptylist_lnode(&last,data));
	}
	else{
		Listnode *insert=new Listnode;
		insert->data=data;
		insert->next=last->next;
		last->next=insert;
		return 1;
	}
}
int insert_node_end_using_lastnode(Listnode **last,int data){
	if(last==NULL){
		return (insert_in_an_emptylist_lnode(last,data));
	}
	else{
		Listnode *temp=*last;
		Listnode *insert=new Listnode;
		insert->data=data;
		insert->next=temp->next;
		temp->next=insert;
		*last=insert;
	}
	//cout<<last->data;
}

int insert_between_two_nodes(Listnode **last,int data,int item){
	Listnode *pointer=*last;
	if(last==NULL){
		return 0;
	}
	else{
		Listnode *new_node=new Listnode;
		Listnode *temp=*last;
		if(temp->data==item){
			new_node->data=data;
			new_node->next=temp->next;
			temp->next=new_node;
			*last=new_node;
		}
		else{
			while(pointer->data!=item){
				pointer=pointer->next;
			}
			new_node->data=data;;
			new_node->next=pointer->next;
			pointer->next=new_node;
			pointer=new_node;

		}

	}
	//return 1;
}
void printlist_head(Listnode *head){
	Listnode *temp1=head,*temp2=head;
	if(temp1!=NULL and temp1->next!=NULL){
		do{
			cout<<temp1->data;
			temp1=temp1->next;
		}
		while(temp1!=temp2);
	}
	else{
		cout<<"NULL HERE";
	}
}


int split_circular_list_two_halves(Listnode *last,Listnode **ll1,Listnode **ll2){
	Listnode *head=last->next;
	Listnode *temp1=head,*temp2=head;
	while(temp2->next!=head){
		temp2=temp2->next;
		if(temp2->next!=head){
			temp2=temp2->next;
			temp1=temp1->next;
		
		}
	}
	temp2->next=temp1->next;
	*ll2=temp2->next;
	temp1->next=head;
	*ll1=temp1->next;
	printlist_head(*ll1);
	cout<<endl;
	printlist_head(*ll2);


}

int insert_node_in_sorted_circular_linkedlist(Listnode *last,int data){
	Listnode *head=last->next,*pointer_head=last->next;
	if(last->next->data>data){
		Listnode *new_node=new Listnode;
		new_node->data=data;
		new_node->next=last->next;
		head=new_node;
		last->next=head;
		printlist_head(head);
	

	}
	else if(last->data<data){
		Listnode *new_node= new Listnode;
		new_node->data=data;
		new_node->next=last->next;
		last->next=new_node;
		last=new_node;
		head=last->next;
		printlist_head(head);
	}
	else{
		while(head->next->data<data){
			head=head->next;
		}
		Listnode *new_node=new Listnode;
		new_node->data=data;
		new_node->next=head->next;
		head->next=new_node;
		printlist_head(pointer_head);
	}
	return 0;
}

void delete_begin(Listnode **last){
	Listnode *temp=*last;
	Listnode *head=temp->next;
	Listnode *head_next=head->next;
	temp->next=head_next;
	free(head);
	printlist(*last);
}
void delete_last_node(Listnode **last){
	Listnode *temp=*last;
	Listnode *head=temp->next;
	Listnode *last_node=temp;
	Listnode *traversal_pointer=temp->next;
	while(traversal_pointer->next!=temp){
		traversal_pointer=traversal_pointer->next;
	}
	last_node=traversal_pointer->next;
	free(last_node);
	traversal_pointer->next=temp->next;
	*last=traversal_pointer;
	printlist(*last);


}

void swap_first_last_node(Listnode **last){
	Listnode *temp=*last;Listnode *temp2=*last;
	Listnode *traversal_pointer =temp->next;
	while(traversal_pointer->next!=temp){
		traversal_pointer=traversal_pointer->next;
	}
	temp->next=traversal_pointer->next;
	traversal_pointer->next=temp2->next;
	//traversal_pointer=temp->next;
	//*last=traversal_pointer->next;
	printlist(temp);
}


int main(){
	Listnode *last =new Listnode;
	last=NULL;

	Listnode *linked_list1 =new Listnode;
	linked_list1=NULL;

	Listnode *linked_list2 =new Listnode;
	linked_list2=NULL;
	//head = NULL;

	// insert_data(&head,3);

	// insert_data(&head,4);

	// insert_data(&head,5);
	insert_in_an_emptylist_lnode(&last,4);
	inserting_a_node_begining_using_lnode(last,3);
	insert_node_end_using_lastnode(&last,6);
	//cout<<last->data;

	//insert_between_two_nodes(&last,7,3);
	insert_between_two_nodes(&last,9,6);
	//split_circular_list_two_halves(last,&linked_list1,&linked_list2);
	//insert_node_in_sorted_circular_linkedlist(last,11);

	//delete_begin(&last);
	//delete_last_node(&last);
	swap_first_last_node(&last);


	//cout<<last->data;
	//cout<<head->data;
	//printlist(last);
	//todo insert begin end betwee sorted insert delete begin end exchange first and last
}