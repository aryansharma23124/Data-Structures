#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;

};
void printlist(Node *n){
	while(n!=NULL){
		cout<<n->data;
		n=n->next;
	}
}

void insert_head(Node **head,int data_){
	Node *insert_head=new Node;
	insert_head->data=data_;
	insert_head->next=*head;
	*head=insert_head;
}

void insert_after_given_node(Node *given,int data){
	Node *new_middle=new Node;
	new_middle->data=data;
	new_middle->next=given->next;
	given->next=new_middle;
}

void insert_end(Node **head,int data){
	Node *last_new=new Node;
	last_new->data=data;
	last_new->next=NULL;
	//*end=last_new;
	Node *temp=*head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=last_new;
}

void delete_a_node(Node **head,int data_){
	Node *temp=*head,*temp2;
	if(temp->data=data_){
		*head=temp->next;
	}
	else{
		while(temp->data!=data_){
			temp2=temp;
			temp=temp->next;
		}
		temp2->next=temp->next;
	}
}

void delte_particular_pos(Node **head,int pos){
	Node *temp=*head,*temp2;
	int counter=0;
	if(pos==0){
		*head=temp->next;
	}
	else{
		while(counter!=pos){
			temp2=temp;
			temp=temp->next;
			counter++;
		}
		temp2->next=temp->next;
		free(temp);
	}
}

void delete_a_linked_list(Node **head){
	Node *temp=*head,*temp2;
	while(temp->next!=NULL){
		temp2=temp->next;
		free(temp);
		temp=temp2;
	}


}



void search_element_iterative(Node **head,int data_){
	Node *temp=*head,*temp2;
	while(temp->data!=data_){
		temp2=temp;
		temp=temp->next;
	}
	cout<<temp2->next<<endl;
	cout<<temp->data<<endl;
}

void search_element_recursive(Node **head,int data_){
	Node *temp=*head,*temp2;
	int data2=data_;
	if(temp->data==data_){
		cout<<temp->data<<endl;

	}
	else{
		temp=temp->next;
		search_element_recursive(&temp,data2);
	}
}
void count_iterative(Node **head){
	int counter=0;
	Node *temp=*head;
	while(temp!=NULL){
		temp=temp->next;
		counter++;
	}
	cout<<counter<<endl;
}

int count_recursive(Node *head,int co){
	int c2=co+1;
	if(head==NULL){
		return 0;
	}
	else if(head->next!=NULL){
		head=head->next;
		count_recursive(head,c2);
	}
	else{
		cout<<c2;
	}
}


int count_recursive_gfg(Node *head){
	if(head==NULL){
		return 0;
	}
	else{
		return 1+count_recursive_gfg(head->next);
	}
}


int search_element_recursive_gfg(Node *head,int data_){
	if(head==NULL){
		return 0;
	}
	if(head->data==data_){
		return 1;
	}
	return search_element_recursive_gfg(head->next,data_);
}
//get nth node iteratively
int nth_Node(Node *head,int counter){
	int count=0;
	while(count<counter){
		count++;
		head=head->next;
	}
	cout<<head->data;
}

//get nth node recursively
int get_nth_node_recursive(Node *head,int index){
	int count=1;
	if(count==index){
		return head->data;
	}
	return (get_nth_node_recursive(head->next,index-1));


}
int get_nth_node_behind(Node *head,int index){
	//count the linked list;
	int count=0;
	Node *temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	Node *temp2=head;
	int find=count-index;
	while(find>0){
		temp2=temp2->next;
		find--;
	}
	cout<<temp2->data;

}
int get_nth_node_behind_gfg(Node *head,int index){
	Node *temp=head,*temp2=head;
	while(index>1){
		temp=temp->next;
		index--;
	}
	while(temp->next!=NULL){
		temp2=temp2->next;
		temp=temp->next;
	}
	cout<<temp2->data;
}

int get_middle_node(Node *head){
	Node *temp=head,*temp2=head;
	while(temp->next!=NULL){
		temp=temp->next;
		if(temp->next!=NULL){
			temp=temp->next;
			temp2=temp2->next;
		}
		else{
			break;
		}
	}cout<<temp2->data;
}

int detect_loop_linked_list(Node *head){
	Node *temp=head,*temp2=head;
	while(temp->next!=NULL){
		temp=temp->next;temp=temp->next;
		temp2=temp2->next;
		if(temp==temp2){
			return 1;
			
		}
		else{
			continue;
		}
	}
	return 0;
}

int find_length_loop_linked_list(Node *head){
	Node *temp=head,*temp2=head;
	while(temp->next!=NULL){
		temp=temp->next;
		temp=temp->next;
		temp2=temp2->next;
		if(temp==temp2){
			int count=1;
			temp2=temp2->next;
			while(temp!=temp2){
				count++;
				temp2=temp2->next;
			}
			cout<<count;
			break;
		}
		else{
			continue;
		}
	}

}

int reverse_linked_list(Node **head){
	Node *temp=*head,*temp2=*head;
	*head=NULL;
	while(temp!=NULL){

		insert_head(head,temp->data);
		temp=temp->next;
	}
	temp2->next=NULL;
}

int reverse_linked_list_between_two_nodes(Node *head,int index1,int index2){
 	Node *temp1=head,*temp2=head,*prev=head;
 	int counter1=0,counter2=0;

	while(counter1<index1){
 		temp1=temp1->next;
 		counter1++;
 		if(counter1<index1){
 			prev=prev->next;
 		}
 	}


 	while(counter2<index2){
 		temp2=temp2->next;
 		counter2++;
 	}
 	int total=index2-index1;
 	int c=0;
 	while(c<total){
 		insert_after_given_node(temp2,temp1->data);
 		temp1=temp1->next;
 		c++;
 	}
 	prev->next=temp2;



}


int check_palindrome(Node *head){
	
	Node *temp1=head,*middle=head;int index1=0,index2=0;
	while(temp1->next!=NULL){
		temp1=temp1->next;
		if(temp1->next!=NULL){
		temp1=temp1->next;
		index1+=2;index2+=1;
		middle=middle->next;
		}
		else{
			index1+=1;
			break;
		}
	}
	//cout<<index1<<index2;
	reverse_linked_list_between_two_nodes(head,index2+1,index1);
	temp1=head;
	//cout<<middle->data;
	while(middle->next!=NULL){
		middle=middle->next;
		//cout<<middle->data<<temp1->data;
		if(temp1->data==middle->data){
			//continue;
			//cout<<"hi";
			int a=0;
		}
		else{
			//cout<<"o";
			return 0;
		}
		//middle=middle->next;
		temp1=temp1->next;
	}
	return 1;

}

int main(){
	Node *head=new Node;
	Node *second=new Node;
	Node *third=new Node;
	Node *fourth=new Node;
	Node *five=new Node;
	Node *final=new Node;
	//Node *n_head=new Node;

	head->data=1;
	head->next=second;

	second->data=2;
	second->next=third;


	third->data=4;
	third->next=fourth;


	fourth->data=3;
	fourth->next=five;

	five->data=2;
	five->next=final;

	final->data=1;
	final->next=NULL;
	//insert_after_given_node(second,7);
	//insert_end(&head,8);
	//delete_a_node(&head,1);
	//delte_particular_pos(&head,0);
	//delete_a_linked_list(&head);
	//search_element_iterative(&head,3);
	//search_element_recursive(&head,3);
	//count_iterative(&head);
	//count_recursive(head,0);
	// int count_rec_gfg=count_recursive_gfg(head);
	// cout<<count_rec_gfg;
	// cout<<endl;
	// int search_element_recursive_var_gfg=search_element_recursive_gfg(head,3);
	// cout<<search_element_recursive_var_gfg<<endl;
	//nth_Node(head,1);
	//get_nth_node_behind_gfg(head,2);
	//get_middle_node(head);
	// int detect =detect_loop_linked_list(head);
	// cout<<detect;
	//cout<<
	//find_length_loop_linked_list(head);
	//reverse_linked_list(&head);
	reverse_linked_list_between_two_nodes(head,3,5);
	//cout<<check_palindrome(head);
	//cout<<endl;
	printlist(head);
	
	//b = *a;
	//printlist(head);
}