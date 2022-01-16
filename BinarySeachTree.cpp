#include<iostream>
using namespace std;
#define GLOBALSPACE 5
class treenode
{
   public:
   	int data;
   	treenode *left;
   	treenode *right;
   	treenode()
   	{
   		data=0;
   		left=NULL;
   		right=NULL;
   	}
   	treenode(int val)
   	{
   		data=val;
   		left=NULL;
   		right=NULL;
   	}
};
class BST
{
  public:
  	treenode *root;
  	BST()
  	{
  		root=NULL;
  	}
  	treenode* MinValue(treenode *node)
  	{
  		treenode *current=node;
  		/* Loops Down to find the lowest value*/
  		while(current->left!=NULL)
  		{
  			current=current->left;
  		}
  		return current;
  	}
  	void insertNode(treenode *newnode)
  	{
  		if(root==NULL)
  		{
  			root=newnode;
  			cout<<"Root Node inserted"<<endl;
  		}
  		else
  		{
  			treenode *temp=root;
  			while(temp!=NULL)
  			{
  				if(newnode->data==temp->data)
  				{
  					cout<<"Value exists,Insert another node"<<endl;
  					return ;
  				}
  				else if(newnode->data<temp->data && temp->left==NULL)
  				{
  					temp->left=newnode;
  					cout<<"Node inserted to the left"<<endl;
  					break;
  				}
  				else if(newnode->data<temp->data)
  				{
  					temp=temp->left;
  				}
  				else if(newnode->data>temp->data && temp->right==NULL)
  				{
  					temp->right=newnode;
  					cout<<"Node inserted to the right"<<endl;
  					break;
  				}
  				else 
  				{
  					temp=temp->right;
  				}
  			}
  		}
  	}
  	treenode * deletenode(treenode *r,int val)
  	{
  		if(r==NULL)
  		{
  			return r;
  		}
  		else if(val>r->data)
  		{
  			r->right=deletenode(r->right,val);
  		}
  		else if(val<r->data)
  		{
  			r->left=deletenode(r->left,val);
  		}
  		else
  		{
  			if(r->left==NULL)
  			{
  				treenode* temp=r->right;
  				delete r;
  				return temp;
  			}
  			else if(r->right==NULL)
  			{
  				treenode* temp=r->left;
  				delete r;
  				return temp;
  			}
  			else
  			{
  				treenode* temp=MinValue(r->right);
  				r->data=temp->data;
  				r->right=deletenode(r->right,temp->data);
  			}
  		}
  	  return r;
  	}
  	void TraversePreOrder(treenode *r)
  	{
  		if(r==NULL)
  		{
  			return;
  		}
  		cout<<r->data<<" ";
  		TraversePreOrder(r->left);
  		TraversePreOrder(r->right);
  	}
  	void TraverseInOrder(treenode *r)
  	{
  		if(r==NULL)
  		{
  			return;
  		}  		
  		TraverseInOrder(r->left);
  		cout<<r->data<<" ";
  		TraverseInOrder(r->right);
  	}
  	void TraversePostOrder(treenode *r)
  	{
  		if(r==NULL)
  		{
  			return;
  		}  		
  		TraversePostOrder(r->left);
  		TraversePostOrder(r->right);
  		cout<<r->data<<" ";
  	    
  	}
  	treenode* IterativeSearch(int val)
  	{
  		cout<<"Inside iterative search"<<endl;
  		if(root==NULL)
  		{
  			return root;
  		}
  		else
  		{
  			treenode *temp=root;
  			while(temp!=NULL)
  			{
  				if(val==temp->data)
  			{
  				return temp;
  			}
  			else if(val<temp->data)
  			{
  				temp=temp->left;
  			}
  			else
  			{
  				temp=temp->right;
  			}

  			}
  		}
  		return NULL;
  	}
  	void Print2DTree(treenode *r,int space)
  	{
  		if(r==NULL)
  			return ;
  		space+=GLOBALSPACE;
  		Print2DTree(r->right,space);
  		cout<<endl;
  		for(int i=GLOBALSPACE;i<space;i++)
  		{
  			cout<<" ";
  		}
  		cout<<r->data<<endl;
  		Print2DTree(r->left,space);
  	}
  int HeightBST(treenode *r)
  {
	  int lheight,rheight;
	  if(r==NULL)
	  {
		return -1;
	  }
	  else
	  {
        lheight=HeightBST(r->left);
		rheight=HeightBST(r->right);
		if(lheight>rheight)
		{
			return (lheight+1);
		}
		else
		{
			return (rheight+1);
		}
          
	  }
  }
  void PrintLevelBst(treenode *r)
  {
	  int h=HeightBST(r);
	  for(int i=0;i<=h;i++)
	  {
		  printGivenLevel(r,i);
	  }
  }
  void printGivenLevel(treenode *r,int level)
  {
	  if(r==NULL)
	  return;
	  else if(level==0)
	  {
		  cout<<r->data<<" ";
	  }
	  else
	  {
		  printGivenLevel(r->left,level-1);
		  printGivenLevel(r->right,level-1);
	  }
  }
};
int main()
{
    BST s;
    int option,val;
    do
    {  cout<<"---------------------------------------"<<endl;
       cout<<"Enter the operations to be performed"<<endl;
       cout<<"0:Exit"<<endl;
       cout<<"1:Insertion"<<endl;
       cout<<"2:Deletion"<<endl;
       cout<<"3:Search"<<endl;
       cout<<"4:Traverse"<<endl;
       cout<<"5:Displaying The tree"<<endl;
	   cout<<"6:Height of the binary tree"<<endl;
	   cout<<"7:(BFS)Level Order Traversal"<<endl;
       cout<<"---------------------------------------"<<endl;
       cout<<endl;
       cin>>option;
       treenode* newnode=new treenode();
       switch(option)
       {
       	case 0:
       	{
       		break;
       	}
       	case 1:
       	{
       		cout<<"Enter the elements to be inserted"<<endl;
       		cin>>val;
       		newnode->data=val;
            s.insertNode(newnode);
            cout<<"---------------------------------------"<<endl;
            cout<<endl;
       		break;
       	}
       	case 2:
       	{
       		int value;
       		cout<<"Enter the value to be deleted"<<endl;
       		cin>>value;
       		newnode=s.deletenode(s.root,value);
       		if(newnode==NULL)
       		{
       			cout<<"Value not found"<<endl;
       		}
       		cout<<"---------------------------------------"<<endl;
       		cout<<endl;
       		break;
       	}
       	case 3:
       	{
       		treenode *t;
       		cout<<"Enter the elements to be Searched"<<endl;
       		cin>>val;
            t=s.IterativeSearch(val);
            if(t!=NULL)
            {
            	cout<<"Data Found :"<<t->data<<endl;
            }
            else
            {
            	cout<<"Data Not Found"<<endl;
            }
            cout<<"---------------------------------------"<<endl;
            cout<<endl;
       		break;
       	}
       	case 4:
       	{
       		cout<<"---------------------------------------"<<endl;
       		cout<<"Displaying the Pre-Order sequence :";
            s.TraversePreOrder(s.root);
			cout<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<endl;
            cout<<"Displaying the In-Order sequence :";
            s.TraverseInOrder(s.root);
			cout<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<endl;
            cout<<"Displaying the Post-Order sequence :";
            s.TraversePostOrder(s.root);
			cout<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<endl;
       		break;
       	}
       	case 5:
       	{
       		cout<<"---------------------------------------"<<endl;
            s.Print2DTree(s.root,GLOBALSPACE);
            cout<<"---------------------------------------"<<endl;
       		break;
       	}
		case 6:
		{
			int h;
			h=s.HeightBST(s.root);
			cout<<"---------------------------------------"<<endl;
			cout<<"Height of the BST is: "<<h<<endl;
			cout<<"---------------------------------------"<<endl;
			break;
		 }
		 case 7:
		{
			cout<<"---------------------------------------"<<endl;
			cout<<"Level order traversal: ";
			s.PrintLevelBst(s.root);
			cout<<endl;
			cout<<"---------------------------------------"<<endl;
			break;
		}
       }  
    }while(option!=0);
	cout<<"THANK YOU"<<endl;
	return 0;
}