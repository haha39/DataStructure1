#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���B�ĥ�[hei][row][col]�g�k !
typedef struct
{
    short int hei;	
    short int row;
    short int col;
    short int dir;//�O���q���� 
} element;
//////////////////////////////////////////////////////
element stack[3000];
int top = -1;

void push(element item)
{
	if(top>=(3000-1) )
		printf("stack is full");
	stack[++top] = item;
}
	
element pop()
{
	if(top == -1)
		printf("stack is empty");
	return stack[top--];
}
////////////////queue///////////////////////////////
element queue[3000];
int rear = -1;
int front = -1;

void addq(element item){
    if(rear==3000-1){
        printf("queue is full");
    }
    queue[++rear] = item;
}
element deleteq(){
    if(front==rear){
        printf("queue is empty");
    }
    return queue[++front];
}
////////////////���Ӥ�V///////////////////////////////////// 
typedef struct{
    short int vert;
    short int horiz;
    short int hei;
}offsets;
offsets move[6];
/////////////////bfs//////////////////////////////////////
int min=10;//�D�̵u���|�� 																									? 
int bfs(char *maze,int *d,int sr,int sc,int sh,int n)// n*n*hei+n*row+col  ex  d[i*n*n+j*n+k]
{
//	printf("%d\n",n);
    rear=-1;front=-1;	
    int arrive=0;//�ˬd���S������I��return
    //�����_�l��m
    element position;
    position.hei = sh;//i    
    position.row = sr;//j
    position.col = sc;//k		
    addq(position);//�N�_�I��iqueue
    //��l��d 
    int i,j,k;
    for(i=0;i<(n-2)/2+1;i++)
	{
        for(j=0;j<n;j++)
		{
            for(k=0;k<n;k++)
			{
                if(i==sh && j==sr &&k==sc){
                	d[i*n*n+j*n+k]=0;
				}
				else d[i*n*n+j*n+k]=500;
            }
        }
    }
  	d[sh*n*n+sr*n+sc]=0;
////////////////////////////////////////////////////////////
    int nr,nc,nh;//next
    int row,col,hei;//now
    while(rear!=front)
	{
		for(i=0; i<(n-2)/2+1 ;i++)
				{
	                for(j=i+1;j<n-i-1;j++)
					{
	                    for(k=i+1;k<n-i-1;k++)
						{
	                    	printf("%3d ",d[i*n*n+j*n+k] );
	                    }
	                    printf("\n");
	                }
	            	printf("\n");
	            }
        position = deleteq();
        row = position.row;
        col = position.col;
        hei = position.hei;
        if(maze[n*n*hei+n*row+col]=='F')//    �J��F
		{
            if(min>d[n*n*hei+n*row+col])
                min = d[n*n*hei+n*row+col];///�O���Umin
            arrive=1;
        }
		else if(maze[n*n*hei+n*row+col]=='U' || maze[n*n*hei+n*row+col]=='D')//		�J��U or D                                             x if?
		{
			int uord = -1;//  up or down �����O���W�٬O���U,���]�U 
            if(maze[n*n*hei+n*row+col]=='U')//�Y���W�� 
                uord=1;		
			nh = hei+uord;		
            nr = row;
            nc = col;
            if(nh>=0)
			{
                if (maze[n*n*nh+n*nr+nc]!='X' && d[n*n*nh+n*nr+nc]>d[n*n*hei+n*row+col]+1)//�J��DX,��u���|
				{
                    d[n*n*nh+n*nr+nc]=d[n*n*hei+n*row+col]+1;//�U�Ӧ�m���Z���O�{�b��m�Z��+1
                    if(maze[n*n*nh+n*nr+nc]=='T')
                        d[n*n*nh+n*nr+nc]=d[n*n*nh+n*nr+nc]+2;//�W���[1�L�F 
                    element nextposition;
                    nextposition.hei=nh;
                    nextposition.row=nr;
					nextposition.col=nc;
                    addq(nextposition);
                }
            }    				
		}

		//O D U���i��4�ظ��| 
        for(i=0;i<4;i++)
		{
            nr = row+move[i].vert;
            nc = col+move[i].horiz;
            if (maze[n*n*nh+n*nr+nc]!='X' && d[n*n*nh+n*nr+nc]>d[n*n*hei+n*row+col]+1)
			{   
                d[n*n*nh+n*nr+nc]=d[n*n*hei+n*row+col]+1;
                if(maze[n*n*nh+n*nr+nc]=='T')
                    d[n*n*nh+n*nr+nc]=d[n*n*nh+n*nr+nc]+2;//�W���[1�L�F 
                element nextposition;
                nextposition.row=nr;nextposition.col=nc;nextposition.hei=nh;
                addq(nextposition);
                
            }
        }
        		
    }
    return arrive;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void path(int *d,char *maze,char *mark,int fr,int fc,int fh,int n)//�Х�mark,�@�˱q���I���^�� 
{
	int row=fr;
	int col=fc;
	int hei=fh;
	int i,j,k,nr,nc,nh;
	mark[n*n*hei+n*row+col] = '*';
	while(maze[n*n*hei+n*row+col]!='S')
	{
    	if (  (d[n*n*hei+n*(row+1)+col]==d[n*n*hei+n*row+col]-1&& maze[n*n*hei+n*row+col]!='T') || (d[n*n*hei+n*(row+1)+col]==d[n*n*hei+n*row+col]-3 && maze[n*n*hei+n*row+col]=='T')  )//���ݤU��
            row++;
        else if (    (d[n*n*hei+n*(row-1)+col]==d[n*n*hei+n*row+col]-1&& maze[n*n*hei+n*row+col]!='T') || (d[n*n*hei+n*(row-1)+col]==d[n*n*hei+n*row+col]-3 && maze[n*n*hei+n*row+col]=='T')   )//�ݤW��
            row--;
        else if (   (d[n*n*hei+n*row+col+1]==d[n*n*hei+n*row+col]-1&& maze[n*n*hei+n*row+col]!='T') || (d[n*n*hei+n*row+col+1]==d[n*n*hei+n*row+col]-3 && maze[n*n*hei+n*row+col]=='T')   )//�k��
            col++;
        else if ((d[n*n*hei+n*row+col-1]==d[n*n*hei+n*row+col]-1&& maze[n*n*hei+n*row+col]!='T') || (d[n*n*hei+n*row+col-1]==d[n*n*hei+n*row+col]-3 && maze[n*n*hei+n*row+col]=='T') )//����
            col--;

    	else if(maze[n*n*(hei-1)+n*row+col]=='U' && ( (d[n*n*(hei-1)+n*row+col]==d[n*n*hei+n*row+col]-1&& maze[n*n*hei+n*row+col]!='T') || (d[n*n*(hei-1)+n*row+col]==d[n*n*hei+n*row+col]-3 && maze[n*n*hei+n*row+col]=='T') )  )//��
    		hei--;
		else if(maze[n*n*(hei+1)+n*row+col]=='U' &&((d[n*n*(hei+1)+n*row+col]==d[n*n*hei+n*row+col]-1&& maze[n*n*hei+n*row+col]!='T') || (d[n*n*(hei+1)+n*row+col]==d[n*n*hei+n*row+col]-3 && maze[n*n*hei+n*row+col]=='T') ))//��
    		hei++;
    	mark[n*n*hei+n*row+col]='*';
	}
	  		printf("--------------------------\n");
        for(i=0;i<(n-2)/2+1;i++)//  �L�ݬ�
		{
	        for(j=0;j<n;j++)
			{
	            for(k=0;k<n;k++)
				{
					printf("%c  ",mark[i*n*n+j*n+k]);
				}
				printf("\n");
			}
			printf("\n\n\n");
		} 
		printf("--------------------------\n");
	
}

FILE *p1,*p2;

int main() 
{	
	move[0].vert=-1;   move[0].horiz=0;    move[0].hei=0;//head
    move[1].vert=0;    move[1].horiz=1;    move[1].hei=0;//right
    move[2].vert=1;    move[2].horiz=0;    move[2].hei=0;//back
    move[3].vert=0;    move[3].horiz=-1;   move[3].hei=0;//left
    move[4].vert=0;    move[4].horiz=0;    move[4].hei=1;//up
    move[5].vert=0;    move[5].horiz=0;    move[5].hei=-1;//down
/////////////////////////////Ū��////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
	int fn,n;//fn�ɮ׼�   n  Ūbottom�Ĥ@��r���� 
	char name[50]={},b[50]={};//name readfilename  b read bottom�Ĥ@�C 
	for(fn=1;fn<=100;fn++)
	{
		
		min=10000;//�C����l�Ƴ̵u���|��																						
        sprintf(name,"test%d.txt",fn);
        p1 = fopen(name,"r");
        if(NULL==p1)
		{
            printf("Open failure");
            return 1;
        }	
		else
		{
			printf("reading %s\n",name);
			n=0;
			b[n] = fgetc(p1);
			while(b[n] != '\n')//����  ���X�j�� 
			{
				fgetc(p1);//��Ū�Ů�
				b[++n] = fgetc(p1);
			}
		}
//		printf("%d \n",n);
		char maze[n/2+1][n+2][n+2],mark[n/2+1][n+2][n+2];//maze�O��l�a�� mark�O�аO���� 	n/2+1�h 
		int num_maze[n/2+1][n+2][n+2];//num_maze�O��bfs��̵u���| 
		element position;        	   
		int len=0;//�]���n���Ҧ��G�L�}�C�|���T�����P �ҥH�W�h���}�C�|�hlen���e��
        int i,j,k,sh,sr,sc,fh,fr,fc;//hei row col   start  final
//        int jojo=1;
		for(i=0;i<n/2+1;i++)//  n/2+1�O����
		{
	        for(j=0;j<n+2;j++)
			{
	            for(k=0;k<n+2;k++)
				{
//					printf("%d\n",jojo);jojo++;
					//���� 
	                if(j==0 || k==0 || j==n+1 || k==n+1)
	                    maze[i][j][k]='X';
	                else if(i==0 && j==1)//�@�ӲĤ@�C�ƻsb[]
                    	maze[i][j][k]=b[k-1];//�a�Ϧ��j����ҥH�O�q1�}�l��	�o��k = 1 
	                else if(j > len && j <= n-len && k > len && k <= n-len)
	                    fscanf(p1,"%c ",&maze[i][j][k]);//len+1~n-len  *  len+1~n-len���O�n��J���a��
	                else
	                	maze[i][j][k]='X';//�D���h�h�F�e�׬�len������

	                //START POSITION
	                if(maze[i][j][k]=='S')
					{
	                    sh=i;
	                    sr=j;
	                    sc=k;
	                    num_maze[sh][sr][sc] = 0;
	                }
	                //final position
	                if(maze[i][j][k]=='F')
					{
	                	fh=i;
	                    fr=j;
	                    fc=k;
	                }
	                mark[i][j][k]=maze[i][j][k];
	            }
	        }
	        len++;
        }
        
        

/////////////////////////////��X�ɮ�///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
        sprintf(name,"test%d_ans.txt",fn);
        p2 = fopen(name,"w");
        if( NULL == p2 )
		{
            printf( "open failure" );
            return 1;
        }
        else
		{
			printf("end");
        	if( bfs(&maze[0][0][0],&num_maze[0][0][0],sr,sc,sh,n+2) )//�p�G����
			{
				for(i=0; i<n/2+1 ;i++)
				{
	                for(j=i+1;j<n+2-i-1;j++)
					{
	                    for(k=i+1;k<n+2-i-1;k++)
						{
	                    	printf("%3d ",num_maze[i][j][k] );
	                    }
	                    printf("\n");
	                }
	            	printf("\n");
	            }
	printf("end");
	            fprintf(p2,"Path length: %d\n",min);
	            printf("end");
	            path(&num_maze[0][0][0],&maze[0][0][0],&mark[0][0][0],fr,fc,fh,n+2);
	            fprintf(p2,"=====outMaze=====\n");
	            for(i=0; i<n/2+1 ;i++)
				{
	                for(j=i+1;j<n+2-i-1;j++)
					{
	                    for(k=i+1;k<n+2-i-1;k++)
						{
	                    	fprintf(p2,"%c ",mark[i][j][k] );
	                    }
	                    fprintf(p2,"\n");
	                }
	            	fprintf(p2,"\n");
	            }
        	}
            else 
				fprintf(p2,"The maze does not have a path\n" );
        printf("end");
		}
        printf("end");
	}
	free(p1);
	free(p2); 	
	return 0;
}

