#include <stdio.h>
#include <stdlib.h>
#define MAX_NNUMBER 50000
#define MAX_RANGE 10000
/*���_���u�q��

*/
typedef struct TreeNode* TreeNodePtr;
struct TreeNode {
    int sum,right_sum,max_sum,left_sum;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode node;
typedef struct p_node {
    int sum,right_sum,max_sum,left_sum;
}p_node;
//////////////////////��̤j////////////////////////////////////////////////
int just_find_max(int a,int b) 
{
	int max=a;
	if(b>max)
		max=b;
//	printf("\njust_find_max,max:%d\n",max);
	return max;
}
///////////////////////////////////////////like a �A���t//////////////////////////////////////////////////////////////////////////////
//int ct;
node* create_tree(int arr[],int n) //�`�N��n�ӼƦr�A����Oarr[0]-arr[n-1] 
{
//	printf("\n\n�����s�ơA��%d�ӼƦr\n",n); 
	int i;
	node* temp;
	temp=(node*)malloc(sizeof(node) );
//	temp->left_bound=arr[0];	temp->right_bound=arr[n-1];
	temp->left=NULL;	
	temp->right=NULL;	
	if(n!=1)//�D���`�I 
	{
//		ct++;
//		printf(" �D���`�I�A ");
		if(n%2==1)//��ƭӼƦr 
		{
//			printf(" ���ƭӼƦr,n�ܦ� : %d\n ",n);
			n=n/2;//ex:4=9/2
			int *arr_left=(int*)malloc( (n+1)*sizeof(int) );//5,4
			int *arr_right=(int*)malloc(n*sizeof(int) );
			for(i=0;i<=n;i++) { arr_left[i]=arr[i]; 	/*printf("%d : %d ",i,arr_left[i]);*/ }//0-4
			for(i=n+1;i<=n*2;i++) { arr_right[i-n-1]=arr[i];  /*printf("	%d : %d",i,arr_right[i-n-1]);*/	}//5-8			
			temp->left=create_tree(arr_left,n+1);
			temp->right=create_tree(arr_right,n);
			temp->sum=temp->left->sum+temp->right->sum;
			temp->left_sum=just_find_max(temp->left->left_sum,temp->left->sum+temp->right->left_sum);
			temp->right_sum=just_find_max(temp->right->right_sum,temp->right->sum+temp->left->right_sum);
			temp->max_sum=just_find_max(just_find_max(temp->left->max_sum,temp->right->max_sum),temp->left->right_sum+temp->right->left_sum );
//			printf("\n�ۤv�O��%d�Ӹ��`�I\n",ct);
//			printf("\nsum: %d  left sum:%d  right sum:%d  max sum:%d \n",temp->sum,temp->left_sum,temp->right_sum,temp->max_sum);
		}	
		else//���ƭӼƦr 
		{
			n=n/2;//ex:4=8/2
//			printf(" ���ƭӼƦr,n�ܦ� : %d\n ",n);
			int *arr_left=(int*)malloc(n*sizeof(int) );
			int *arr_right=(int*)malloc(n*sizeof(int) );//4,4
			for(i=0;i<n;i++) { arr_left[i]=arr[i]; 	/*printf("%d : %d ",i,arr_left[i]);*/ }//0-3
			for(i=n;i<n*2;i++) { arr_right[i-n]=arr[i]; /*printf("	%d : %d",i,arr_right[i-n]);*/	}//4-7			
			temp->left=create_tree(arr_left,n);
			temp->right=create_tree(arr_right,n);
			temp->sum=temp->left->sum+temp->right->sum;
			temp->left_sum=just_find_max(temp->left->left_sum,temp->left->sum+temp->right->left_sum);
			temp->right_sum=just_find_max(temp->right->right_sum,temp->right->sum+temp->left->right_sum);
			temp->max_sum=just_find_max(just_find_max(temp->left->max_sum,temp->right->max_sum),temp->left->right_sum+temp->right->left_sum );
//			printf("\n�ۤv�O��%d�Ӹ��`�I\n",ct);			
//			printf("\nleft sum:%d  right sum:%d  max sum:%d \n",temp->left_sum,temp->right_sum,temp->max_sum);
		}
	}
	else//���`�I
	{
//		ct++;
		temp->left_sum=arr[0];
		temp->right_sum=arr[0];	
		temp->max_sum=arr[0];	
		temp->sum=arr[0];
//		printf("�ۤv�O��%d�Ӹ��`�I\n",ct);
//		printf("�X�O:%d  ���j�O : %d�A�k�j�O : %d�A��j��j�O:%d\n",temp->sum,temp->left_sum,temp->right_sum,temp->max_sum);
	}
	return temp;
}
///////////////////////////////////////////////���O/////////////////////////////////////////////////////////////////////////////////////////
void m_comm(int n_th,int change_to,int now_left,int now_right,node *ptr)//ex�ĤT�ӡA�@�K�� 3,1-8          m_comm(x,y,1,int_number,root); 
{
//	node *temp=ptr;
	int i;
	if(now_left==now_right)//�q�����I��� 
	{
//		printf("m���O�A�q�ڶ}�l��\n"); 
		ptr->left_sum=change_to;
		ptr->right_sum=change_to;	
		ptr->max_sum=change_to;	
		ptr->sum=change_to;
//		printf("�X�O:%d  ���j�O : %d�A�k�j�O : %d�A��j��j�O:%d\n",ptr->sum,ptr->left_sum,ptr->right_sum,ptr->max_sum);	
	}
	else
	{ 
		int mid=(now_right+now_left)/2;
		if(n_th<=mid)//3<4,���� 
		{
//			printf("����\n");
			m_comm(n_th,change_to,now_left,mid,ptr->left);
		}
		else//�k�� 
		{
//			printf("�k��\n");
			m_comm(n_th,change_to,mid+1,now_right,ptr->right);
		}	
		//��D���`�I 
		ptr->sum=ptr->left->sum+ptr->right->sum;
		ptr->left_sum=just_find_max(ptr->left->left_sum,ptr->left->sum+ptr->right->left_sum);
		ptr->right_sum=just_find_max(ptr->right->right_sum,ptr->right->sum+ptr->left->right_sum);
		ptr->max_sum=just_find_max(just_find_max(ptr->left->max_sum,ptr->right->max_sum),ptr->left->right_sum+ptr->right->left_sum );
//		printf("\nleft sum:%d  right sum:%d  max sum:%d \n",ptr->left_sum,ptr->right_sum,ptr->max_sum);		
	}
}
p_node p_comm(int start,int end,int now_left,int now_right,node *ptr)//1-6->1-4,5-6	 			�{�b�b���Ӱ϶�   p_comm(x,y,1,int_number,root ); 
{
	p_node pnode;
	if(start==now_left&&end==now_right)
	{
		pnode.left_sum=ptr->left_sum;
		pnode.max_sum=ptr->max_sum;
		pnode.right_sum=ptr->right_sum;
		pnode.sum=ptr->sum; 
		return pnode;
	}
	else
	{
		int mid=(now_right+now_left)/2;
		if(end<=mid)//�����l�] 
		{
			pnode=p_comm(start,end,now_left,mid,ptr->left);
		}
/**/		else if(start>mid)//���c�l�] 
		{
			pnode=p_comm(start,end,mid+1,now_right,ptr->right);
		}
		else if(start<=mid && end>mid)  //1-8  2-7->1,2-4   5-7,8 
		{
			p_node left,right;
			left=p_comm(start,mid,now_left,mid,ptr->left);
			right=p_comm(mid+1,end,mid+1,now_right,ptr->right);
			pnode.left_sum=just_find_max(left.left_sum,left.sum+right.left_sum);
			pnode.right_sum=just_find_max(right.right_sum,right.sum+left.right_sum);
			pnode.max_sum=just_find_max(just_find_max(left.max_sum,right.max_sum),left.right_sum+right.left_sum);
			pnode.sum=left.sum+right.sum;
		}
		return pnode;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
FILE *p1,*p2;
int main(int argc, char *argv[]) 
{
	//Ū�� 
	p1 = fopen("test3.txt","r");
    if(p1==NULL)
	{
        printf("Open p1 failure");
        return 1;
    }	
	else
	{	
		int time,int_number,com_number,i,j,k,x,y;//1-5	1-MAX_NNUMBER	1-MAX_NNUMBER
		char comm;//�������O 
		fscanf(p1,"%d\n",&time);//�r�Ķ]�X�� 
//		printf("�]�X��:%d\n",time);
		p2 = fopen("output.txt","w");
   	    if(p2==NULL)
		{
 	    	printf("Open p2 failure");
        	return 1;
    	}
		for(i=0;i<time;i++)//�]time�� 
		{
/////////////remember to use jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj	'
//			ct=0;
//			printf("\n\n�ĴX��:%d\n",i);		
			fscanf(p1,"%d\n",&int_number);//�W���X�ӼƦr 
//			printf("���X�ӼƦr:%d\n",int_number);		
			int *save_int=malloc(int_number*sizeof(int));
			for(j=0;j<int_number;j++)//Ū���X�ӼƦr 
			{
				fscanf(p1,"%d",&save_int[j]);
				fgetc(p1);//�Y�Ů� �򴫦� 
			}
/*		for(j=0;j<int_number;j++) 
			{
				printf("���X�ӼƦr %d ",save_int[j]);
			}
*/			//���ؾ� 
			node *root;//
			root=create_tree(save_int,int_number);
//			printf("\n\n\n�����ؾ� haha\n\n\n\n");
			fscanf(p1,"%d\n",&com_number);// Ū�X�ի��O 
//			printf("�X�ի��O  %d\n",com_number);	
			p_node ans;//��p���O���̫�^�Ǫ� 
			for(j=0;j<com_number;j++)//�]com_number�� , �i�禡�B�z 
			{			
				comm=fgetc(p1);//Ū���O
				fgetc(p1);//�Y�Ů�
				fscanf(p1,"%d",&x);// Ū1
				fgetc(p1);//�Y�Ů�
				fscanf(p1,"%d",&y);// Ū2 
				fgetc(p1);//�Y����	
				if(comm=='P')
				{
					ans=p_comm(x,y,1,int_number,root );
//					printf("%c �_�I:%d ���I:%d �̤j��:%d\n",comm,x,y,ans.max_sum);
					fprintf(p2,"%d\n",ans.max_sum);
				}
				else if(comm=='M')
				{
					
					m_comm(x,y,1,int_number,root);
//					printf("%c ��ĴX��:%d �令:%d \n",comm,x,y);
				}
			}
		} 
	}
	return 0;
}

