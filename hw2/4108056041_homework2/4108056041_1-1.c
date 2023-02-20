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
//////////////////////搞queue////////////////////////////////////////////////
typedef struct queueNode* QueueNodePtr;
typedef struct queueNode
{
    node* nodelink;//存樹節點 
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
//////////////////////開種////////////////////////////////////////////////
creattree(int a,int b)//a左b右 
{
//	printf("haha\n");
//	printf("a=%d  b=%d\n",a,b);
	//fnode接父節點
	node* fnode;
	fnode=(node*)malloc(sizeof(node) );
	fnode->left=NULL;	fnode->right=NULL;//為了讓葉節點指標可以直接連到null 
	fnode->data=1;	
	//tempr當新右節點 
	node*  tempr;
	tempr=(node*)malloc(sizeof(node) );	
	tempr->left=NULL;	tempr->right=NULL;
	//tempr當新左節點
	node*  templ;
	templ=(node*)malloc(sizeof(node) );		
	templ->left=NULL;	templ->right=NULL;
	//非root
	fnode = deleteq();
	if( a == 0 )//用queue讓父節點可以存現在的節點位址 ，左子節點有值 
	{		
		templ->data = 1;
		fnode->left = templ;
		addq(templ);
	}	
	if( a == 1 )//讓父節點存左子節點null 
	{	
		fnode->left = NULL;
	}
	if( b == 0 )//右子節點有值 
	{			
		tempr->data = 1;
		fnode->right = tempr;
		addq(tempr);
	}	
	if( b == 1 )//讓父節點存右子節點null 
	{	
		fnode->right = NULL;
	}
}
/////////////////////////建堡壘/////////////////////////////////////
/*	printf("hahaha\n");
	子節點是葉節點:return 1	 子節點是堡壘 :return 2
	自己是堡壘或被保護，變Null的同類:return 3	自己是null:return 4 
*/
int ct=0,i=0;
int postorder(TreeNodePtr ptr) //LRV......吧 
{
/////////////////////上往下////////////////////////////////////////////////
//	printf("ptr : %p\n",ptr);
	int x=0,y=0;
	//父親是葉節點 
	if(ptr==NULL)
	{
//		printf("this is the end \n\n");
		return 4; 
	}	
	//見底，自己是葉節點 
	if(ptr->left == NULL) //左空右空，左空右安全 
	{
		if( ptr->right ==NULL || ptr->right->data ==3 || ptr->right->data ==2)
		{
			ptr->data=3;
			return 1;
		}
	}		
	else if( ptr->left->data == 3  )//左安全右空，左安全右安全
	{
		if( ptr->right ==NULL || ptr->right->data ==3 || ptr->right->data == 2 )
		{
			ptr->data=3;
			return 1;
		}
	}
/////////////////////下往上////////////////////////////////////////////////
//	printf("ptr->left : %p\n\n",ptr->left);
	x=postorder(ptr->left);
//	printf("x = %d \n",x);
	//左null->找右邊?????????????????????????????????????????
	if( x==4) 
	{
//		printf("ptr->right : %p\n\n",ptr->right);
		y=postorder(ptr->right);
//		printf("x=4,y = %d \n",y);
	}
	// 左子是葉節點，蓋堡壘 
	if(  x == 1 )//子節點是葉
	{
		if(ptr->data == 100)//自己是根結點 
		{
			ptr->data=2;//2是堡壘本來是1 
			ct++;
//			printf("建立了堡壘,ct= %d，往右走,ptr->right : %p\n\n",ct,ptr->right);
			y=postorder(ptr->right);
//			printf("x=1, ct=%d, return y = %d \n\n",ct,y);		
			return ct;	
		}
		else
		{
			if( ptr->data!=2 )  
			{
				ptr->data=2;//2是堡壘本來是1 
				ct++;
//				printf("建立了堡壘,ct= %d，往右走,ptr->right : %p\n\n",ct,ptr->right);
				y=postorder(ptr->right);
//				printf("x=1, ct=%d, return y = %d \n\n",ct,y);//y=1,2,3,4,不管右子節點是甚麼都沒差 
				return 2;
			}			
		}
		return 2;	
	}
	//右子是葉節點，蓋堡壘
	if( y==1 )
	{
//		printf("y = %d \n",y);
		if(ptr->data!=2)
		{
			ptr->data=2;//2是堡壘本來是1 
			ct++;		
//			printf("ct= %d ,y = %d \n\n",ct,y);
			return 2;
		}
		return 2;
	}
	// 左子節點是堡壘，自己被保護到了
	if( x == 2 ) 
	{
//		printf("x=2 \n");
		if(ptr->data == 100)//如果是根結點
		{
//			printf("根被保護，往右走:ptr->right : %p\n\n",ptr->right);
			y=postorder(ptr->right);//////////////////??
			if( y==1 )//如果右邊是葉節點 ，根結點蓋堡壘 
			{
				ptr->data=2;//2是堡壘本來是1
				ct++;
//				printf("ct : %d \n\n",ct);	
			} 
		}
		else
		{
			ptr->data=3;//3是被保護本來是1 
			y=postorder(ptr->right);//向右走 
			if(y==1)//如果柚子節點是葉 
			{
				ptr->data=2;//2是堡壘本來是1
				ct++;
//				printf("左子節點是堡壘，右子節點是葉節點，建自己ct : %d \n\n",ct);
				return 2; 
			}
			else
				return 3;
		}
	}
	// 右子節點是堡壘，自己被保護到了
	if( y==2 ) 
	{
		if(ptr->data == 100)//如果是根結點
		{
//			printf("根被保護，結束了\n\n");
		}
		else
		{
//			printf("y=2 \n");
			ptr->data=3;//3是被保護本來是1 
			return 3;
		} 
	}	
	//左子被保護
	if( x == 3  )
	{
//		printf("x=3\n");
		if(ptr->data == 100)//根節點
		{
//			printf("左子節點被保護，自己是根節點，向右走，ct = %d \n\n",ct);
			y=postorder(ptr->right);
//			printf("y= %d ",y);
			if( y==1 || y==3 || y==4 )//////////////////??
			{
				ptr->data=2;//2是堡壘本來是1
				ct++;
//				printf("ct : %d \n\n",ct);	
				return ct;			
			}
		}
		else//還可以往右走 
		{
			y=postorder(ptr->right);
//			printf("x=3,左子被保護,向右下走, ct = %d ,return y = %d \n\n",ct,y);
			if( y== 1 )//右子節點是葉節點，自己建堡壘 
			{
				ptr->data=2;//2是堡壘本來是1
				ct++;
//				printf("ct : %d \n\n",ct);
				return 2;				
			}
			else if( y==2 )//右子節點是堡壘，爽， 自己被保護 
			{
				ptr->data=3;
				return 3;
			} 
			else if( y== 3 )//右子節點是被保護，等於左右子節點是null 
			{
				return 1;				
			} 			
			else if( y== 4 )//右子節點是null， 等於左右子節點是null 
			{
//				printf("me 呢\n"); 
				return 1;				
			}
		}
	}
	//柚子節點被保護 
	if( y==3 )
	{
//		printf("y=3\n");
		if(ptr->data = 1)//自己是葉節點的感覺 
		{
			return 1;				
		}			
		else if(ptr->data = 2)//自己是堡壘 ，沒差 
		{
			return 2;
		} 
		else if(ptr->data = 3)//自己被保護 
		{
			return 3;
		}	
		else if(ptr->data = 100)//根節點自己蓋堡壘保護自己  //////////////////??
		{
			ptr->data=2;//2是堡壘本來是1
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
	//讀檔+種樹 
	char c;
	int a,b,i;//a=0如果有節點，a=1如果讀Null ,b也是,a左b右
	p1 = fopen("test3.txt","r");
    if(p1==NULL)
	{
        printf("Open failure");
        return 1;
    }	
	else
	{
		fgetc(p1);//不讀[
		c=fgetc(p1);//不讀第一個0
		if(c=='n')//沒有樹 
			printf("ans : 0");
		else
		{
			fgetc(p1);//不讀它的,
			//直接存根 
			node* root;
			root=(node*)malloc(sizeof(node) );
			root->data=100;
			treePtr = root;						//指向根，好蓋堡壘 
			addq(root);
			while(1)//一次讀兩個 
			{
				a=1;b=1;
				if( (c=fgetc(p1)) == ']')
					break;
				if(c == 'n')//不讀ull
				{			//printf("c=%c  \n\n",c);
					fgetc(p1);fgetc(p1);fgetc(p1);
					a=1;
				}
				if(c == '0')
				{			//printf("c=%c  \n\n",c);
					a=0;
				}	
				//讀第2個 
				if( (c=fgetc(p1)) == ']')
				{
					creattree(a,b);
					break;
				}
				if(c==',')//再讀一次 
					c=fgetc(p1);
					
				if(c == 'n')//把ull吃掉 
				{
							//printf("c=%c  \n\n",c);
					fgetc(p1);fgetc(p1);fgetc(p1);
					b=1;
				}
				if(c == '0')
				{			//printf("c=%c  \n\n",c);
					b=0;
				}		
				c=fgetc(p1);//不讀,
				
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

