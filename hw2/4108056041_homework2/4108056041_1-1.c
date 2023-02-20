#include <stdio.h>
#include <stdlib.h>
#define MAX 15000
typedef struct TreeNode* TreeNodePtr;
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode node;
TreeNodePtr treePtr;
//////////////////////�dqueue////////////////////////////////////////////////
typedef struct queueNode* QueueNodePtr;
typedef struct queueNode
{
    node* nodelink;//�s��`�I 
    QueueNodePtr nextPtr;
}queueNode;
QueueNodePtr front=NULL,rear;

//enqueue
void addq(node* item)
{ 
	QueueNodePtr newPtr;
	newPtr = (QueueNodePtr)malloc(sizeof (queueNode));
	newPtr->nodelink = item;
	newPtr->nextPtr = NULL;
	if (front)												
		rear->nextPtr = newPtr;
	else 
		front = newPtr;
	rear = newPtr; 
}
//deleteq
node* deleteq()
{	
	node* item;
    QueueNodePtr tempPtr=front;
    if(!tempPtr)
	{
		item->data=-1;
	    item->left=NULL;
	    item->right=NULL;
	    return item;
    }
    item = tempPtr->nodelink;
    front=tempPtr->nextPtr;
    free(tempPtr);
    return item;
}
//////////////////////�}��////////////////////////////////////////////////
creattree(int a,int b)//a��b�k 
{
//	printf("haha\n");
//	printf("a=%d  b=%d\n",a,b);
	//fnode�����`�I
	node* fnode;
	fnode=(node*)malloc(sizeof(node) );
	fnode->left=NULL;	fnode->right=NULL;//���F�����`�I���Хi�H�����s��null 
	fnode->data=1;	
	//tempr��s�k�`�I 
	node*  tempr;
	tempr=(node*)malloc(sizeof(node) );	
	tempr->left=NULL;	tempr->right=NULL;
	//tempr��s���`�I
	node*  templ;
	templ=(node*)malloc(sizeof(node) );		
	templ->left=NULL;	templ->right=NULL;
	//�Droot
	fnode = deleteq();
	if( a == 0 )//��queue�����`�I�i�H�s�{�b���`�I��} �A���l�`�I���� 
	{		
		templ->data = 1;
		fnode->left = templ;
		addq(templ);
	}	
	if( a == 1 )//�����`�I�s���l�`�Inull 
	{	
		fnode->left = NULL;
	}
	if( b == 0 )//�k�l�`�I���� 
	{			
		tempr->data = 1;
		fnode->right = tempr;
		addq(tempr);
	}	
	if( b == 1 )//�����`�I�s�k�l�`�Inull 
	{	
		fnode->right = NULL;
	}
}
/////////////////////////�س��S/////////////////////////////////////
/*	printf("hahaha\n");
	�l�`�I�O���`�I:return 1	 �l�`�I�O���S :return 2
	�ۤv�O���S�γQ�O�@�A��Null���P��:return 3	�ۤv�Onull:return 4 
*/
int ct=0,i=0;
int postorder(TreeNodePtr ptr) //LRV......�a 
{
/////////////////////�W���U////////////////////////////////////////////////
//	printf("ptr : %p\n",ptr);
	int x=0,y=0;
	//���ˬO���`�I 
	if(ptr==NULL)
	{
//		printf("this is the end \n\n");
		return 4; 
	}	
	//�����A�ۤv�O���`�I 
	if(ptr->left == NULL) //���ťk�šA���ťk�w�� 
	{
		if( ptr->right ==NULL || ptr->right->data ==3 || ptr->right->data ==2)
		{
			ptr->data=3;
			return 1;
		}
	}		
	else if( ptr->left->data == 3  )//���w���k�šA���w���k�w��
	{
		if( ptr->right ==NULL || ptr->right->data ==3 || ptr->right->data == 2 )
		{
			ptr->data=3;
			return 1;
		}
	}
/////////////////////�U���W////////////////////////////////////////////////
//	printf("ptr->left : %p\n\n",ptr->left);
	x=postorder(ptr->left);
//	printf("x = %d \n",x);
	//��null->��k��?????????????????????????????????????????
	if( x==4) 
	{
//		printf("ptr->right : %p\n\n",ptr->right);
		y=postorder(ptr->right);
//		printf("x=4,y = %d \n",y);
	}
	// ���l�O���`�I�A�\���S 
	if(  x == 1 )//�l�`�I�O��
	{
		if(ptr->data == 100)//�ۤv�O�ڵ��I 
		{
			ptr->data=2;//2�O���S���ӬO1 
			ct++;
//			printf("�إߤF���S,ct= %d�A���k��,ptr->right : %p\n\n",ct,ptr->right);
			y=postorder(ptr->right);
//			printf("x=1, ct=%d, return y = %d \n\n",ct,y);		
			return ct;	
		}
		else
		{
			if( ptr->data!=2 )  
			{
				ptr->data=2;//2�O���S���ӬO1 
				ct++;
//				printf("�إߤF���S,ct= %d�A���k��,ptr->right : %p\n\n",ct,ptr->right);
				y=postorder(ptr->right);
//				printf("x=1, ct=%d, return y = %d \n\n",ct,y);//y=1,2,3,4,���ޥk�l�`�I�O�ƻ򳣨S�t 
				return 2;
			}			
		}
		return 2;	
	}
	//�k�l�O���`�I�A�\���S
	if( y==1 )
	{
//		printf("y = %d \n",y);
		if(ptr->data!=2)
		{
			ptr->data=2;//2�O���S���ӬO1 
			ct++;		
//			printf("ct= %d ,y = %d \n\n",ct,y);
			return 2;
		}
		return 2;
	}
	// ���l�`�I�O���S�A�ۤv�Q�O�@��F
	if( x == 2 ) 
	{
//		printf("x=2 \n");
		if(ptr->data == 100)//�p�G�O�ڵ��I
		{
//			printf("�ڳQ�O�@�A���k��:ptr->right : %p\n\n",ptr->right);
			y=postorder(ptr->right);//////////////////??
			if( y==1 )//�p�G�k��O���`�I �A�ڵ��I�\���S 
			{
				ptr->data=2;//2�O���S���ӬO1
				ct++;
//				printf("ct : %d \n\n",ct);	
			} 
		}
		else
		{
			ptr->data=3;//3�O�Q�O�@���ӬO1 
			y=postorder(ptr->right);//�V�k�� 
			if(y==1)//�p�G�c�l�`�I�O�� 
			{
				ptr->data=2;//2�O���S���ӬO1
				ct++;
//				printf("���l�`�I�O���S�A�k�l�`�I�O���`�I�A�ئۤvct : %d \n\n",ct);
				return 2; 
			}
			else
				return 3;
		}
	}
	// �k�l�`�I�O���S�A�ۤv�Q�O�@��F
	if( y==2 ) 
	{
		if(ptr->data == 100)//�p�G�O�ڵ��I
		{
//			printf("�ڳQ�O�@�A�����F\n\n");
		}
		else
		{
//			printf("y=2 \n");
			ptr->data=3;//3�O�Q�O�@���ӬO1 
			return 3;
		} 
	}	
	//���l�Q�O�@
	if( x == 3  )
	{
//		printf("x=3\n");
		if(ptr->data == 100)//�ڸ`�I
		{
//			printf("���l�`�I�Q�O�@�A�ۤv�O�ڸ`�I�A�V�k���Act = %d \n\n",ct);
			y=postorder(ptr->right);
//			printf("y= %d ",y);
			if( y==1 || y==3 || y==4 )//////////////////??
			{
				ptr->data=2;//2�O���S���ӬO1
				ct++;
//				printf("ct : %d \n\n",ct);	
				return ct;			
			}
		}
		else//�٥i�H���k�� 
		{
			y=postorder(ptr->right);
//			printf("x=3,���l�Q�O�@,�V�k�U��, ct = %d ,return y = %d \n\n",ct,y);
			if( y== 1 )//�k�l�`�I�O���`�I�A�ۤv�س��S 
			{
				ptr->data=2;//2�O���S���ӬO1
				ct++;
//				printf("ct : %d \n\n",ct);
				return 2;				
			}
			else if( y==2 )//�k�l�`�I�O���S�A�n�A �ۤv�Q�O�@ 
			{
				ptr->data=3;
				return 3;
			} 
			else if( y== 3 )//�k�l�`�I�O�Q�O�@�A���󥪥k�l�`�I�Onull 
			{
				return 1;				
			} 			
			else if( y== 4 )//�k�l�`�I�Onull�A ���󥪥k�l�`�I�Onull 
			{
//				printf("me �O\n"); 
				return 1;				
			}
		}
	}
	//�c�l�`�I�Q�O�@ 
	if( y==3 )
	{
//		printf("y=3\n");
		if(ptr->data = 1)//�ۤv�O���`�I���Pı 
		{
			return 1;				
		}			
		else if(ptr->data = 2)//�ۤv�O���S �A�S�t 
		{
			return 2;
		} 
		else if(ptr->data = 3)//�ۤv�Q�O�@ 
		{
			return 3;
		}	
		else if(ptr->data = 100)//�ڸ`�I�ۤv�\���S�O�@�ۤv  //////////////////??
		{
			ptr->data=2;//2�O���S���ӬO1
			ct++;
//			printf("ct : %d \n\n",ct);
		}				 
	}
//	printf("it's the final countdown : %d\n\n",ct);
	return ct;
}
////////////////////////////////////////////////////////////////////////////////
FILE *p1;
int main() 
{
	//Ū��+�ؾ� 
	char c;
	int a,b,i;//a=0�p�G���`�I�Aa=1�p�GŪNull ,b�]�O,a��b�k
	p1 = fopen("test3.txt","r");
    if(p1==NULL)
	{
        printf("Open failure");
        return 1;
    }	
	else
	{
		fgetc(p1);//��Ū[
		c=fgetc(p1);//��Ū�Ĥ@��0
		if(c=='n')//�S���� 
			printf("ans : 0");
		else
		{
			fgetc(p1);//��Ū����,
			//�����s�� 
			node* root;
			root=(node*)malloc(sizeof(node) );
			root->data=100;
			treePtr = root;						//���V�ڡA�n�\���S 
			addq(root);
			while(1)//�@��Ū��� 
			{
				a=1;b=1;
				if( (c=fgetc(p1)) == ']')
					break;
				if(c == 'n')//��Ūull
				{			//printf("c=%c  \n\n",c);
					fgetc(p1);fgetc(p1);fgetc(p1);
					a=1;
				}
				if(c == '0')
				{			//printf("c=%c  \n\n",c);
					a=0;
				}	
				//Ū��2�� 
				if( (c=fgetc(p1)) == ']')
				{
					creattree(a,b);
					break;
				}
				if(c==',')//�AŪ�@�� 
					c=fgetc(p1);
					
				if(c == 'n')//��ull�Y�� 
				{
							//printf("c=%c  \n\n",c);
					fgetc(p1);fgetc(p1);fgetc(p1);
					b=1;
				}
				if(c == '0')
				{			//printf("c=%c  \n\n",c);
					b=0;
				}		
				c=fgetc(p1);//��Ū,
				
				creattree(a,b);
				if(c==']')
				{
					break; 
				}
			}
			printf("ans : %d  ",postorder(treePtr));
		}
	}
	fclose(p1);
	return 0;
}

