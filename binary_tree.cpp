#include<bits/stdc++.h>
using namespace std;

struct node
{
		int data;
		struct node  *left;
		struct node *right;
		struct node *righta;
		
};


struct node *insert_node(int data)
{
	node *temp_node=new node;
	temp_node->data=data;
	temp_node->left=NULL;
	temp_node->right=NULL;
}

void tarverse_binary_tree_inorder(node *root)
{
	if(root==NULL){
		return;
	}
	tarverse_binary_tree_inorder(root->left);
	cout<<root->data<<" ";
	tarverse_binary_tree_inorder(root->right);

	

}

void tarverse_binary_tree_preorder(node *root){
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	tarverse_binary_tree_preorder(root->left);
	tarverse_binary_tree_preorder(root->right);
}

void tarverse_binary_tree_postorder(node *root){
	if(root==NULL){
		return;
	}
	tarverse_binary_tree_postorder(root->left);
	tarverse_binary_tree_postorder(root->right);
	cout<<root->data<<" ";
}

void inorder_traversal_without_recursion(node *root){
	node *temp_node=root;
	stack<node *> s;
	while(temp_node!=NULL or s.empty()==false){
		while(temp_node!=NULL){
			s.push(temp_node);
			temp_node=temp_node->left;
		}
		temp_node=s.top();
		s.pop();
		cout<<temp_node->data;
		temp_node=temp_node->right;
	}
}



void inorder_using_stack(node *root){
	stack<node *>s;
	node *temp=root;
	while(temp!=NULL or s.empty()==false){
		while(temp!=NULL){
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		cout<<temp->data;
		temp=temp->right;
	//	cout<<temp<<" ";
	}

}

void inorder(node *root){
	node *temp=root;
	while(temp->left->left!=NULL){
		temp=temp->left;
	}
	cout<<temp->left->data;
	cout<<temp->data;

}
void inorder_with_stack_n(node *root)
{
	stack<node *>s;
	node *temp=root;node *temp2=NULL;
	while(!s.empty() or temp!=NULL)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		while(temp!=NULL)
		{
			temp=temp->right;
			s.push(temp);
		}
		cout<<temp->data;
		//temp=temp->right;

	}
}


void postorder_stack(node *root)
{
	stack<node *>s;
	node *temp=root;
	while(!s.empty() or temp==NULL)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		temp=temp->right;
	}




}

void level_order(node *root){
	node *temp=root;
	node *temp2=root;
	queue <node *>queue;
	queue.push(temp);
	while(!queue.empty()){
		if(temp==NULL){
			cout<<"\n";
		}
		else{
		queue.push(temp->left);
		queue.push(temp->right);

		temp2=queue.front();
		cout<<temp2->data<<"-";
		queue.pop();
	}
		temp=queue.front();
	}
}


void inorder_without_stack(node *root){
	node *temp=root,*temp2=root;
	while(temp!=NULL){
		if(temp->left==NULL){
			cout<<temp->data;
			temp=temp->right;
		}
		else{
			temp2=temp->left;
			while(temp2->right!=NULL and temp2->right!=temp){
				temp2=temp2->right;
			}
			if(temp2->right==NULL){
				temp2->right=temp;
				temp=temp->left;
			}
			else{
				temp2->right=NULL;
				cout<<temp->data;
				temp=temp->right;
			}

		}
	}
} 


void morris_preorder_traversal(node *root){
	node *temp=root,*temp2=root;
	while(temp!=NULL){
		if(temp->left==NULL){
			cout<<temp->data;
			temp=temp->right;
		}
		else{
			temp2=temp->left;
			while(temp2->right!=NULL and temp2->right!=temp){
				temp2=temp2->right;
			}
			if(temp2->right==temp){
				temp2->right=NULL;
				//cout<<temp->data;
				temp=temp->right;
				
			}
			else{

				cout<<temp->data;
				temp2->right=temp;

				temp=temp->left;
			}
		}
	}

}

int search(int in[],int start,int end,int val)
{
	for(int j=start;j<end;j++)
	{
		if(in[j]==val)
		{
			return j;
		}
	}
}

struct node * construct_tree_using_in_pre(int in[],int pre[],int instrt,int inend)
{
	struct  node *root=new node;
	//static node*prev=NULL;
	//node *temp=new node;
	static int i=0;int j=0;
	root->data=pre[i];
	root->left=NULL;root->right=NULL;
	i++;
	if(instrt==inend)
	{
		return root;
	}
	int index=search(in,instrt,inend,root->data);
	root->left=construct_tree_using_in_pre(in,pre,instrt,index-1);
	root->right=construct_tree_using_in_pre(in,pre,index+1,inend);
	cout<<endl;
	tarverse_binary_tree_inorder(root);	
	return root;
}

void BT_insertion(node *root,int data)
{
	//level_order(root);
	node *temp=root;
	node *temp2=root;
	queue <node *>queue;
	queue.push(temp);
	while(!queue.empty())
	{
		if(temp==NULL)
		{
			cout<<"\n";
		}
		else
		{

			temp2=queue.front();
			//cout<<temp2->data<<"-";
			if(temp2->left==NULL)
			{
				node *temp3=new node;
				temp3->data=data;
				temp2->left=temp3;
				break;
			}
			if(temp2->right==NULL)
			{
				node *temp3=new node;
				temp3->data=data;
				temp2->right=temp3;
				break;
			}
			queue.push(temp->left);
			queue.push(temp->right);

			queue.pop();
		}
		temp=queue.front();
	}
	tarverse_binary_tree_inorder(root);

}

// void postorder_using_inorder_preorder(int in[],int po[]){
// 	node *root=new node;
// 	node  *temp=root;
// 	root->data=po[0];
// 	int i=1;
// 	while(po[i]!='\0'){
// 		cout<<"a";
// 		node *temp2=new node;
// 		temp2->left=NULL;temp2->right=NULL;
// 		if(po[i]!=in[0]){
// 			temp2->data=po[i];
// 			node *prev=root;
// 			root->left=temp2;
// 			cout<<po[i];
// 			i++;
// 		}
// 		else{
// 			//prev->right->data=po[i];
// 			i++;
// 			break;
// 		}
// 		root=temp2;
// 	}
// 	root=temp;
// 	while(temp->left!=NULL){
// 		cout<<temp->data;
// 		temp=temp->left;

// 	}


// }




void BToDLL(node *root, node **head_ref)
{   
    if(root == NULL)
    {
            return;
    }
    
    static node *temp=NULL;
    //struct Node *node =newnode(root->data);
    BToDLL(root->left,head_ref);
    if(temp==NULL)
    {
        *head_ref=root;

    	//temp=root;
        //return;
    }
    else
    {
        root->left=temp;
        temp->right=root;
    }
    temp=root;
    BToDLL(root->right,head_ref);
    
    
}

void print(node *head_ref){
	while(head_ref!=NULL){
		cout<<head_ref->data;
		head_ref=head_ref->right;
	}
}


void binary_tree_deletion(node *root,int data)
{
	node *right_node=root;node *temp=NULL;
	while(right_node->right!=NULL)
	{
		temp=right_node;
		right_node=right_node->right;
	}
	temp->right=NULL;
	node *temp_node=root;
	stack<node *> s;
	while(temp_node!=NULL or s.empty()==false){
		while(temp_node!=NULL){
			s.push(temp_node);
			temp_node=temp_node->left;
		}
		temp_node=s.top();
		s.pop();
		if(temp_node->data==data)
		{
			temp_node->data=right_node->data;
			break;
		}
		//cout<<temp_node->data;
		temp_node=temp_node->right;
	}
	tarverse_binary_tree_inorder(root);

}

void inorder_push(node *root,vector<int>&v)
{
	if(root==NULL)
		return;
	inorder_push(root->left,v);
	v.push_back(root->data);
	inorder_push(root->right,v);
}

void edit(vector<int>&v,vector<int>&v2)
{
	for(int i=0;i<v.size();i++)
	{
		int cal=0;
		if(i==0)
		{
			cal=v[i+1];
			v2.push_back(cal);
		}
		else if(i==v.size()-1)
		{
			cal=v[i-1];
			v2.push_back(cal);
		}
		else
		{
			cal=v[i-1]+v[i+1];
			v2.push_back(cal);
		}
	}
}

void inorder_vector(node *root,vector<int>&v)
{
	static int j=0;
	if(root==NULL)
		return;
	inorder_vector(root->left,v);
	cout<<v[j]<<"  ";root->data=v[j];
	j++;
	inorder_vector(root->right,v);

}
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// vector<vector<int> > Solution::levelOrder(TreeNode* A) 
// {
//     vector<vector<int>>Solution;
//     TreeNode *temp=A;
//     TreeNode *temp2=A;
//     queue<TreeNode *>ele;
//     ele.push(temp);
    
//     while(1)
//     {
//         int node_count=ele.size();
//         if(node_count==0)
//             break;
//         vector<int >tempo;
//         while(node_count>0)
//         {
//             temp2=ele.front();
//             tempo.push_back(temp2->val);
//             ele.pop();
//             if(temp2->left!=NULL)
//                 ele.push(temp2->left);
//             if(temp2->right!=NULL)
//                 ele.push(temp2->right);
//             node_count--;
//         }
//         Solution.push_back(tempo);
//     }
//     return Solution;
// }


void spiral_order(node *root)
{
	node *temp=root;
	queue<node *>element;
	element.push(temp);
	int flag=0;int first_instance=0;
	// while(!element.empty())
	// {
	// 	if(flag==0)
	// 	{
	// 		temp=element.front();
	// 		// element.pop();
	// 		// element.push(temp);
	// 		if(temp->left!=NULL)
	// 		element.push(temp->left);
	// 		if(temp->right!=NULL)
	// 		element.push(temp->right);
	// 		flag=1;
	// 	}
	// 	else
	// 	{

	// 		temp=element.front();
	// 		element.pop();
	// 		element.push(temp);
	// 		if(temp->left!=NULL)
	// 		element.push(temp->right);
	// 		if(temp->right!=NULL)
	// 		element.push(temp->left);
	// 	}
	// 	cout<<temp->data;
	// 	element.pop();

	// }
	// vector<vector<int>>Solution;
 //    TreeNode *temp=A;
 //    TreeNode *temp2=A;
    queue<node *>ele;
    node *temp2=temp;
    ele.push(temp);
    //int flag=0;
    
    while(1)
    {
        int node_count=ele.size();
        if(node_count==0)
            break;
        vector<int >tempo;
        while(node_count>0)
        {
            temp2=ele.front();
            tempo.push_back(temp2->data);
            ele.pop();
            if(temp2->left!=NULL)
                ele.push(temp2->left);
            if(temp2->right!=NULL)
                ele.push(temp2->right);
            node_count--;
        }
        if(first_instance<2)
        {
        	for(int i=0;i<tempo.size();i++)
	        {
	        	cout<<tempo[i];
	        }
	        flag=1;
	        first_instance++;
        }
        else
        {
		    if(flag==0){
		        for(int i=0;i<tempo.size();i++)
		        {
		        	cout<<tempo[i];
		        }
		        flag=1;
		    }
		    else
		    {
		    	for(int i=tempo.size()-1;i>=0;i--)
		    	{
		    		cout<<tempo[i];
		    	}
		    	flag=0;
		    }
		}
    }
}


void reverse_level_order(node *root)
{
	node *temp=root;
	node *temp2=root;
	queue<node *>element;
	element.push(temp);
	stack<int>s;
	while(!element.empty())
	{
		temp2=element.front();
		if(temp2->left!=NULL)
		{
			element.push(temp2->left);
		}
		if(temp2->right!=NULL)
		{
			element.push(temp2->right);
		}
		s.push(temp2->data);
		element.pop();

	}
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}


}

int max_depth(node *root)
{
	if(root==NULL)
		return 0;
	int l_depth=max_depth(root->left);
	int r_depth=max_depth(root->right);
	if(l_depth<r_depth)
		return (l_depth+1);
	else
		return(r_depth+1);
}

void nth_node_inorder_traversal(node *root,int n)
{
	static int count=0;
	if(root==NULL)
		return;
	nth_node_inorder_traversal(root->left,n);
	count++;
	if(count ==n)
	{
		cout<<root->data;
		return;
	}

	nth_node_inorder_traversal(root->right,n);
}

void perfect_binary_tree_specificlevelorder_traversal(node *root)
{
	node *temp=root;
	node *temp2=root;
	queue<node *>element;
	element.push(temp);
	while(1)
	{
		int node_count=element.size();
		if(node_count==0)
		{
			break;
		}
		vector<int> nodes;
		while(node_count>0){
			temp2=element.front();
			element.pop();
			if(temp2->left!=NULL)
			{
				element.push(temp2->left);
			}
			if(temp2->right!=NULL)
			{
				element.push(temp2->right);
			}
			nodes.push_back(temp2->data);
			node_count--;
		}
		int size=nodes.size();
		int count=0;
		for(int i=0;i<size;i++)
		{
			if(count==size)
			{
				break;
			}
			else
			{
				cout<<nodes[i]<<"->"<<nodes[size-1-i];
				count+=2;
			}
		}
		cout<<endl;

	}
}
/*void specific_level_order_traversal_set2(node *root)
{
	node *temp=root;
	node *temp2=root;
	queue<node *>element;
	queue.push(root);
	stack<int> s;
	while(TRUE)
	{
		int node_count=queue.size();
		if(node_count==0)
		{
			break;
		}
		while(node_count>0)
		{
			temp2=element.front();
			if(temp2->left!=NULL)
			{
				queue.push(temp2->left);
			}
			if(temp2->right!=NULL)
			{
				queue.push(temp2->right);
			}

		}
	}



}
*/

int  specific_level_order_traversal_set2_new(node *root)
{
	
	return 0;
}



///ANmol Code 


//sum_predeccor and successor
// void Replace_with_sum_pre_succ(Tree *node, vector<int> &v)
// {
// 	//static Tree *tmp = node;
	
// 	if(node==NULL)
// 		return;

// 	Replace_with_sum_pre_succ(node->left,v);
// 	v.push_back(node->data);
// 	Replace_with_sum_pre_succ(node->right,v);
// }


// vector<int> Manipulate(vector<int> &v,vector<int> &v_new)
// {

// 	for(int i=0;i<v.size();i++)
// 	{
// 		if(i==0)
// 			v_new.push_back(v[i+1]);
// 		else if(i==v.size()-1)
// 			v_new.push_back(v[i-1]);
// 		else
// 			v_new.push_back(v[i-1] + v[i+1]);
// 	}

// 	return v_new;
// }

// void inorder_for_sum(Tree *node, vector<int> &v)
// {
// 	if(node == NULL)
// 		return;
// 	static int i=0;
// 	inorder_for_sum(node->left,v);
// 	node->data = v[i++];
// 	//cout<<node->data<<' ';
// 	inorder_for_sum(node->right,v);
// }


//Replace_with_sum_pre_succ(root,v);
	//vector<int> update = Manipulate(v,v_new);
	//inorder_for_sum(root,update);




//Level Order Traversal 

void print_given_order(node *root,int level,std::vector<int> &v,int boo)
{
	if(root==NULL)
		return ;
	else if(level==1)
	{
		v.push_back(root->data);
	}
	else if(level>1 and boo==0)
	{
		print_given_order(root->left,level-1,v,boo);
		print_given_order(root->right,level-1,v,boo);
		//boo=1;
	}
	else if(level>1 and boo==1)
	{
		//boo=0;
		print_given_order(root->right,level-1,v,boo);
		print_given_order(root->left,level-1,v,boo);	
	}

}



void boundary_tree(std::vector<vector<int>> &v,int height)
{
	vector<int>new_v;
	std::vector<int> low;
	std::vector<int> right;
	for(int i=0;i<v.size();i++)
	{
		if(i==height-1)
		{
			for(int j=0;j<v[i].size();j++)
			{
				//cout<<"in he";
				low.push_back(v[i][j]);
			}
		}
		else
		{
			cout<<"in"<<endl;
			new_v.push_back(v[i][0]);
			int size=v[i].size();
			right.push_back(v[i][size-1]);
		}
	}
	cout<<"boundary_tree"<<endl;
	for(int i=0;i<new_v.size();i++)
	{
		cout<<new_v[i];
	}
	//cout<<endl;
	for(int i=0;i<low.size();i++)
	{
		cout<<low[i];
	}
	//cout<<endl;
	for(int i=right.size()-1;i>0;i--)
	{
		cout<<right[i];
	}
}


void level_order_without_queue(node *root)
{
	int height=max_depth(root);
	vector<vector<int>>v;
	int boo=0;
	for(int i=1;i<=height;i++)
		{
			std::vector<int > b;
			print_given_order(root,i,b,boo);
			v.push_back(b);
			// if(boo==0)
			// 	boo=1;
			// else
			// 	boo=1;
			cout<<endl;
		}

		boundary_tree(v,height);
	// for(int i=0;i<v.size();i++)
	// {
	// 	for(int j=0;j<v[i].size();j++)
	// 	{
	// 		 cout<<v[i][j];
	// 	}
	// }

}

bool ancentors_of_given_node(node *root,int data)
{
	if(root==NULL)
		return false;
	if(root->data==data)
		return true;
	if(ancentors_of_given_node(root->left,data) || ancentors_of_given_node(root->right,data))
	{
		cout<<root->data;
		return true;
	}
	return false;
}

bool reverse_tree_path(node *root,int data,stack<node*> &s_final,queue <node*> &q_final)
{
	if(root==NULL)
		return false;
	if(root->data==data)
		s_final.push(root);
		q_final.push(root);
		return true;
	if(ancentors_of_given_node(root->left,data) || ancentors_of_given_node(root->right,data))
	{
		s_final.push(root);
		q_final.push(root);
		return true;
	}
	return false;
}

void reverse(node *root)
{

	static stack<node *>s_final;
	static queue<node *>q_final;
	static int i=0;
	if(i==0)
		reverse_tree_path(root,5,s_final,q_final);
	i++;
	if(root==NULL)
		return;
	reverse(root->left);
	node *temp=q_final.front();
	if(temp==root)
		{
		q_final.pop();
		cout<<temp->data;
		if(!s_final.empty())
			{	root=s_final.top();
				s_final.pop();
			}
		}
		//cout<<root->data;
	reverse(root->right);
}

void print_in(node *root)
{
	if(root==NULL)
		return;
	print_in(root->left);
	cout<<root->data;
	print_in(root->right);
}

void right_pointers(node *root)
{
	cout<<"right"<<endl;
	node *temp=root;node *temp2;
	queue<node *>q;
	q.push(temp);
	while(true)
	{
		int count=q.size();
		if(count==0)
			break;
		while(count>0)
		{
			temp=q.front();
		
			if(count==1)
		 	{
		 		temp->righta=NULL;
		 		q.pop();
		 	}
		 	else
		 	{
		 		q.pop();
		 		temp2=q.front();
		 		temp->righta=temp2;
		 		if(temp->righta)
		 			cout<<temp->righta->data;
		 	}

			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			cout<<temp->data<<"da";
			// q.pop();
			// temp2=q.front();
			// temp->righta=temp2;
			// if(temp->righta)
			// cout<<temp->righta->data;

			count--;
		}
		cout<<endl;
	}
}
void leafnodes(node *root)
{
	//terminal leaf nodes
	if(root==NULL)
		return;
	if(root->left==NULL and root->right==NULL)
		cout<<root->data;
	if(root->left)
		leafnodes(root->left);
	if(root->right)
		leafnodes(root->right);
}


void boundary_tree_optimize(node *root)
{
	//find left boundary
	node *temp=root,temp2;
	cout<<temp->data;
	while(true)
	{
		if(temp->left)
			temp=temp->left;
		else if(temp->left==NULL and temp->right)
			temp=temp->right;
		else
			break;
		cout<<temp->data;
	}
	cout<<"Low"<<endl;
	leafnodes(root);
	cout<<endl;

	temp=root;
	vector<int>right;
	//find right boundary
	while(true)
	{
		if(temp->right)
			temp=temp->right;
		else if(temp->right==NULL and temp->left)
			temp=temp->left;
		else
			break;
		right.push_back(temp->data);
	}
	for(int i=right.size()-2;i>=0;i--)
	{
		cout<<right[i];
	}

}

void left_subtree(node *root)
{

}
void right_subtrr(node *root)
{

}

void boundary_tree_gfg(node *root)
{

}


void vertical_tree(node *root)
{
	node *temp=root;
	queue<node *>q;
	q.push(root);
	while(true)
	{
		int count=q.size();
		int counter=0;
		int c_l,r_l;
		if(count==0)
			break;
		while(count>0)
		{
			temp=q.front();
			if(temp->left)
			{	
				q.push(temp->left);
				c_l=counter-1;
			}
			if(temp->right)
			{
				q.push(temp->right);
				r_l=counter+1;
			}
			cout<<temp->data;
			q.pop();
		}
	}
}


void vertical_tree_final(node *root)
{
	//node *temp=root;
	map <int,vector<int> > m;
	int hd=0;
	queue<pair<node *,int> >q;
	q.push(make_pair(root,hd));
	while(!q.empty())
	{
		pair<node *,int>temp=q.front();
		q.pop();
		hd=temp.second;
		node *temp2=temp.first;
		m[hd].push_back(temp2->data);
		if(temp2->left)
			q.push(make_pair(temp2->left,hd-1));
		if(temp2->right)
			q.push(make_pair(temp2->right,hd+1));
	}
	map<int,vector<int>>::iterator it;
	vector<vector<int>>main_vector;
	for(it=m.begin();it!=m.end();it++)
	{
		vector<int> v;
		for(int i=0;i<it->second.size();++i)
		{
			v.push_back(it->second[i]);
		}
		main_vector.push_back(v);
	}

}

int min_depth(node *root)
{
	if(root==NULL)
		return 0;
	if(!root->left and !root->right)
		return 1;
	if(!root->left)
		return min_depth(root)+1;
	if(!root->right)
		return min_depth(root)+1;
	return min(min_depth(root->left),min_depth(root->right)+1);
	
}


int main()

{	struct node *root=insert_node(1);
	struct node *head_ref=new node;
	
	//root->right=insert_node(3);
	root->left=insert_node(2);

	root->left->left=insert_node(4);
	root->left->right=insert_node(5);

	// root->left->right->left=insert_node(9);
	// root->left->right->right=insert_node(10);
		
	//root->right->left=insert_node(6);
	//root->right->right=insert_node(7);
	tarverse_binary_tree_inorder(root);
	cout<<endl;
	// cout<<"preorder"<<endl;
	// tarverse_binary_tree_preorder(root);
	// //cout<<endl;
	// //tarverse_binary_tree_postorder(root);
	// //getchar();
	// //cout<<endl;
	// //inorder_traversal_without_recursion(root);
	// cout<<endl;
	// //inorder_using_stack(root);
	// cout<<endl;
	// //level_order(root);
	// cout<<"Morris"<<endl;
	// inorder_without_stack(root);
	// cout<<endl;
	// morris_preorder_traversal(root);
	// cout<<endl;
	// // cout<<"Postorder"<<endl;
	//  int ar[]={4,10,12,15,18,22,24,25,31,35,44,50,66,70,90};
	// int br[]={25,15,10,4,12,22,18,24,50,35,31,44,70,66,90};
	// //postorder_using_inorder_preorder(ar,br);
	// construct_tree_using_in_pre(ar,br,0,14);
	// BToDLL(root,&head_ref);
	// print(head_ref);
	// cout<<endl;
	// cout<<"hello";
	// inorder_with_stack_n(root);
	//BT_insertion(root,20);
	//binary_tree_deletion(root,9);
	//sum_predeccor_successor(root);
	// vector<int>v;
	// vector<int>v2;
	// inorder_push(root,v);

	// edit(v,v2);
	// cout<<endl;
	// cout<<"V2";

	// for(int i=0;i<v2.size();i++)
	// {
	// 	cout<<v2[i]<<" ";
	// }
	// cout<<endl;
	// inorder_vector(root,v2);
	// cout<<endl<<"Main";
	// tarverse_binary_tree_inorder(root);
	//spiral_order(root);
	//reverse_level_order(root);
	//nth_node_inorder_traversal(root,2);
	//perfect_binary_tree_specificlevelorder_traversal(root);
	// cout<<max_depth(root);
	// level_order_without_queue(root);
	// cout<<endl;
	// cout<<"ancentors_of_given_node";
	ancentors_of_given_node(root,5);
	//reverse_tree_path(root,4);
	//reverse(root);
	//right_pointers(root);
	boundary_tree_optimize(root);
	//min_depth(root,0);
	//vertical_tree_final(root);



}


/*

 bool ancenstors(TreeNode *A,int data,vector<int> &v)
 {
     if(!A)
        return false;
    if(A->val==data)
        return true;
    if(ancenstors(A->left,data,v) or ancenstors(A->right,data,v))
    {
        v.push_back(A->val);
        return true;
    }
    return false;
    
 }
 
 void leafnodes(TreeNode *A,vector<TreeNode*> &v)
 {
     if(!A)
        return;
    if(!A->left and !A->right)
    {
        v.push_back(A);
        //A->val=-4;
        return;
    }
    if(A->left)
        leafnodes(A->left,v);
    if(A->right)
        leafnodes(A->right,v);
 }
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) 
{
    TreeNode *temp1=A;
    vector<vector<int>>main_vector;
    if(!A)
        return main_vector;
    vector<TreeNode *>leaf_nodes;
    leafnodes(temp1,leaf_nodes);
    //cout<<leaf_nodes.size();
    //cout<<"A";
    for(int i=0;i<leaf_nodes.size();i++)
    {
        //cout<<leaf_nodes[i];
        TreeNode *temp2=A;
        vector<int> anc;
        TreeNode *temp3=leaf_nodes[i];
        cout<<temp3->val;
        ancenstors(temp2,temp3->val,anc);
        int sum=0;
        //cout<<anc.size();
        for(int j=0;j<anc.size();j++)
        {
            //cout<<anc[j]<<" ";
            sum+=anc[j];
            
        }
        //cout<<endl;
        sum+=temp3->val;
        //cout<<sum<<endl;
        if(sum==B)
            main_vector.push_back(anc);
            
        
        
    }
    return main_vector;
    
}


*/
