#include <stdio.h>
#include <stdlib.h>
/*
1.讀起點2.讀終點3.讀數字建陣列4.讀&存forbidden
5.建陣列[0000-9999],起點0終點1錯的-1, 
6.while跑八種可能，對就break;錯就不理;其他存佇列，
每新一輪就指向父節點7.empty就imposible;對就加入stack倒出stack給出路徑 
*/
typedef struct TreeNode
{
	int val;
	struct TreeNode *ptr;
};
typedef  struct TreeNode node;
/////////////////////////queue///////////////////////////////////////////////////////
typedef struct QueueNode* QueueNodePtr;
typedef struct QueueNode
{
	node* nodelink;
	QueueNodePtr nextPtr;
}QueueNode;
QueueNodePtr front=NULL,rear;
//enqueue
void addq(node* item)
{
//	printf("addqqqqqqqqqqqqqqqqqqqqq,item is : %d\n",item->val);
	QueueNodePtr newptr;
	newptr = (QueueNodePtr)malloc(sizeof (QueueNode));
	newptr->nodelink=(node*)malloc(sizeof(node));
	newptr->nodelink = item;
	newptr->nextPtr = NULL;
//	printf("fhaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaais : %d\n",newptr->nodelink->val);
	if(front==NULL)
	{
		front = newptr;
//		printf("frontTTTTTTTTTTTTTTTTTTTTT is : %d\n",front->nodelink->val);
	}
	else
	{
		rear->nextPtr = newptr;
//		printf("YOOOOOOOOOOOOOOOOOOOOOOOOOADDQ is : \n");
	}
//	printf("frontTTTTTTTTTTTTTTTTTTTTT is : %d\n",front->nodelink->val);
	rear=newptr;	
}
//
node* deleteq()
{
//	printf("deleteqqqqqqqqqqqqqqqqqqqq\n");
	node* item;
	QueueNodePtr tempptr=front;
	if(!tempptr)
	{
		
		item->ptr=NULL;
		item->val=-100;
//		printf("it's emptyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy%d\n",item->val);
		return item;
	}
	item = tempptr->nodelink;
//	printf("item is : %d\n",item->val);
	front=tempptr->nextPtr;
	free(tempptr);
	return item;
}
/////////////////////////find///////////////////////////////////////////////////////////
int ans[30]={0},ct=1;
void find_ans(node *pptr)
{
	int i;
	for(i=0;pptr->ptr!=NULL;i++)
	{
		ans[i] = pptr->val;
		pptr = pptr->ptr;
		ct=i;
//		printf("\n\nfuckkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk %d: %d\n",ct,ans[i]); 
	}
//	printf("\n\n : %d\n",ct);
//	for(i=ct;i>=0;i--)
//	{
//		printf("\n\nansssssssssssssssssssssssssssssssssssss %d : %d\n",i,ans[i]); 
//	}	
}
/////////////////////////bfs///////////////////////////////////////////////////////////
int password[10000]={0};
int bfs()//有趣,試試看 
{
		if(front==NULL)
		return 0;
//	printf("call bfs \n");
//	printf("in bfs, start is %d%d%d%d,end is %d%d%d%d\n",start[0],start[1],start[2],start[3],end[0],end[1],end[2],end[3]);
//	printf("%d",password[11]);
	int be[8],i, start[4],temp,find=0;
//	memset(be, start[0]*1000+start[1]*100+start[2]*10+start[3], sizeof(be) );
	node *fnode;
	fnode = (node*)malloc(sizeof(node) );
	fnode->ptr=NULL;
	fnode = deleteq();
	if(fnode->val==-100)
	{
//		printf("ohohohohohoh%d,find is %d",fnode->val,find);
		return find;
	}
	else
	{

		temp = fnode->val;
	//	printf("\n\nfnode->val : %d,%d\n",fnode->val,temp);
		start[0]=temp/1000;temp%=1000;
		start[1]=temp/100;temp%=100;
		start[2]=temp/10;temp%=10;
		start[3]=temp;			
		//初始成起點 
		for(i=0;i<8;i++)
		{
			be[i] = start[0]*1000+start[1]*100+start[2]*10+start[3];
	//		printf("haha%d : %d\n",i,be[i]);
		}
	//	printf("\n\n\n\n",i,be[i]);
		if(start[0]==0){ be[0]+=1000; be[1]+=1000; be[4]+=9000; be[5]+=9000; }
		else if(start[0]==9){ be[0]-=9000; be[1]-=9000; be[4]-=1000; be[5]-=1000; }
		else if(start[0]!=0 && start[0]!=9){ be[0]+=1000; be[1]+=1000; be[4]-=1000; be[5]-=1000; }
		
		if(start[1]==0){ be[0]+=100; be[1]+=100; be[2]+=100; be[4]+=900; be[5]+=900; be[6]+=900; }
		else if(start[1]==9){ be[0]-=900; be[1]-=900; be[2]-=900; be[4]-=100; be[5]-=100; be[6]-=100; }
		else if(start[1]!=0 && start[1]!=9){ be[0]+=100; be[1]+=100; be[2]+=100; be[4]-=100; be[5]-=100; be[6]-=100; }	
		
		if(start[2]==0){ be[1]+=10; be[2]+=10; be[3]+=10; be[5]+=90; be[6]+=90; be[7]+=90; }
		else if(start[2]==9){ be[1]-=90; be[2]-=90; be[3]-=90; be[5]-=10; be[6]-=10; be[7]-=10; }
		else if(start[2]!=0 && start[2]!=9){ be[1]+=10; be[2]+=10; be[3]+=10; be[5]-=10; be[6]-=10; be[7]-=10; }	
		
		if(start[3]==0){ be[2]+=1; be[3]+=1; be[6]+=9; be[7]+=9; }
		else if(start[3]==9){ be[2]-=9; be[3]-=9; be[6]-=1; be[7]-=1; }
		else if(start[3]!=0 && start[3]!=9){ be[2]+=1; be[3]+=1; be[6]-=1; be[7]-=1; }
		
	//	for(i=0;i<8;i++)
	//	{
	//		printf("haha%d : %d\n",i,be[i]);
	//	}
		//確認質
		for(i=0;i<8;i++)
		{
			if ( password[ be[i] ] == -1 || password[ be[i] ] == 2)//爆炸，走過 
			{
	//			printf("爆炸走過,不理\n"); 
			}
			else
			{		
				node *newnode;
				newnode=(node*)malloc(sizeof(node) );
	//			newnode->ptr=NULL;		
				if( password[ be[i] ] == 1)//終點
				{
	//				printf("ya轉到了,終點是 : %d\n",password[ be[i] ]);
					newnode->val=be[i];
					newnode->ptr=fnode;
					find=1;
					find_ans(newnode);
					return find;
				}
				else
				{
	//				printf("嘗試中,質是 : %d,指向父節點,存入queue,繼續bfs\n", be[i] );
					newnode->val=be[i];
					newnode->ptr=fnode;			
					password[ be[i] ] = 2; 
					addq(newnode);
				}
			}
		}
		
	}
	
//	int x=bfs();
//	printf("%d ",x);
	return bfs();
}
////////////////////////main////////////////////////////////////////////////////////
FILE *p1,*p2;
int main() 
{
	//讀檔
	p1=fopen("test1.txt","r");
	if(p1==NULL)
	{
		printf("open f1 failure");
		return 1;
	}
	else
	{ 
		int start[4],end[4],forbid[4],num,i/*,password[10000]={0}*/;
//		char f[2];f[0]='h';f[1]='a';
		fscanf(p1,"%d %d %d %d\n",&start[0],&start[1],&start[2],&start[3]);//讀起點
		node *first;
		first=(node*)malloc(sizeof(node) );
		first->ptr = NULL;
		first->val = start[0]*1000+start[1]*100+start[2]*10+start[3] ;
		addq(first);		
		fscanf(p1,"%d %d %d %d\n",&end[0],&end[1],&end[2],&end[3]);//讀終點 
		password[ end[0]*1000+end[1]*100+end[2]*10+end[3] ] = 1;
		fscanf(p1,"%d\n",&num);//讀幾個 
//		printf("start is : %d\n", first->val );		
//		printf("end is : %d\n",  end[0]*1000+end[1]*100+end[2]*10+end[3]  );
//		printf("num is : %d\n",num );
//		printf("forbid is : %c%c! \n",f[0],f[1] );
		for(i=0;i<num;i++)
		{
			fscanf(p1,"%d %d %d %d\n",&forbid[0],&forbid[1],&forbid[2],&forbid[3]);//讀錯的 
			password[ forbid[0]*1000+forbid[1]*100+forbid[2]*10+forbid[3] ] = -1;
		}
		//呼叫bfss 
		
		p2=fopen("output1.txt","w");
		if(p2==NULL)
		{
			printf("open f2 failure");
			return 1;
		}
		else
		{
			if(bfs() == 0)
			{
				printf("impossible");
//				printf("impossible");
			}
			else if(bfs()==1)
			{
				ct++;
				printf("%d\n",ct);
				ct--;
				for(i=ct;i>=0;i--)
				{
					if(ans[i]<10)
						printf("000%d\n",ans[i]);
					else if(ans[i]>=10 && ans[i]<100)
						printf("00%d\n",ans[i]);
					else if(ans[i]>=100 && ans[i]<1000)
						printf("0%d\n",ans[i]);
					else					
						printf("%d\n",ans[i]); 
				}	
			}
//			printf("haha");
		}
	}
	return 0;
}
/* 
		printf("%d",password[1]);
		printf("%d",password[101]);
		
		for(i=0;i<400;i++)
		{
			printf("%d",password[i]);
		}
		

	if(p2==NULL)
	{
		printf("open f1 failure");
		return 1;
	}


memset(password, 0, sizeof(password) );
*/
