#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	short int vert,horiz;
}offsets;
//////////////////////////////////////////////////////
typedef struct
{
	short int row,col;//dir�O���q���� 
}element;
//////////////////////////////////////////////////////
element queue[1000];
int rear = -1;
int front = -1;

void addq(element item){
    if(rear==100000-1){
        printf("queue is full");;
    }
    queue[++rear] = item;
}
element deleteq(){
    if(front==rear){
        printf("queue is empty");
    }
    return queue[++front];
}
/////////////////////////////////////////////////////////////////////////////////maze[1][2]=>	maze[1*n+2];
int bfs(char *maze,int *d,int n)////maze�O��l�a��  d �O��bfs��̵u���| 
{
//	printf("haha\n");
	int row,col,nr,nc,i,j;
	element position;
	offsets move[4];
	move[0].vert =-1;move[0].horiz = 0;
	move[1].vert = 0;move[1].horiz = 1;
	move[2].vert = 1;move[2].horiz = 0;
	move[3].vert = 0;move[3].horiz =-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			d[i*n+j]=401;
			if(maze[i*n+j]=='S')
			{
				d[i*n+j] = 0;
			}
		}
	}

	while(front!=rear)
	{

		position = deleteq();
		row=position.row;
		col=position.col;
		if(maze[row*n+col] == 'F')//�����I 
			return 1;
		for(i=0;i<4;i++)
		{

			nr = row + move[i].vert;
			nc = col + move[i].horiz;	
			if(maze[nr*n+nc] != 'X' && d[nr*n+nc] > d[row*n+col]+1)//�J��DX,��u���|
			{

					d[nr*n+nc]	=  d[row*n+col]+1;
					position.row = nr;
					position.col = nc;
					addq(position);					
			}	
		}
	}
	return 0;
}


//bfs(&maze[0][0]);
FILE *p1;
//////////////////////////////////////////////////
int main() {
	char a[1000]={};//Ū�� 
	int x=0,i=0,j=0,n=0,row=0,col=0;//i,j forŪ��� ; nŪ�Ĥ@��	
	p1=fopen("test.txt","r");
	if(p1==NULL)
	{
		printf("p1 error");
	}	
	fscanf(p1,"%d\n",&n);//Ū�Ĥ@��:n
	for(i=0; i<n*n ;i++)//�@��@��Ū 
	{
		a[i]=fgetc(p1);
		fgetc(p1);//��Ū�Ů� 
		if(i%n==n-1) 
			fgetc(p1);//��Ū���� 
	}
	char maze[n+2][n+2],mark[n+2][n+2];//maze�O��l�a��  mark�O�аO���� 
	int num_maze[n+2][n+2];//num_maze�O��bfs��̵u���| 
	element position;
	
	for(i =0;i<n+2;i++)//���� 
	{
		for( j=0;j<n+2;j++) 
		{
			if(i == 0  || i == n+1 || j == 0  || j == n+1 )
			{
				mark[i][j] = 'X';
				maze[i][j] = 'X';
			}
			else
			{
				mark[i][j] = a[x];
				maze[i][j] = a[x];
				x++;				
			}
		} 
	}

	for(i=0; i<n+2 ;i++)//��_�I 
	{
		for( j=0;j<n+2;j++) 
		{
			if(mark[i][j]== 'S')
			{
				mark[i][j] = '*';
				position.row = i;
				position.col = j;
				addq(position);
				row = position.row;
				col = position.col;
			}
		}
	}
	int temprow,tempcol,count=0;	
	offsets move[4];
	move[0].vert =-1;move[0].horiz = 0;
	move[1].vert = 0;move[1].horiz = 1;
	move[2].vert = 1;move[2].horiz = 0;
	move[3].vert = 0;move[3].horiz =-1;
	
	
	
	if(bfs(&maze[0][0],&num_maze[0][0],n+2)==1)
	{
		printf("hw1 success\n");
	}
	else{
		printf("not path ");
	}

	for(i=0;i<n+2;i++)
	{
		for(j=0;j<n+2;j++)
		{
			if(maze[i][j] == 'F' )
			{
				temprow = i;
				tempcol = j;
				mark[i][j] = '*';
			}
				
		}
	}

	while( num_maze[temprow][tempcol] != 0  ) 
	{ 
		for(i=0;i<4;i++)//�аOmark 
		{
			if(num_maze[temprow][tempcol]-1 == num_maze[temprow+move[i].vert][tempcol+move[i].horiz] )
			{
				mark[temprow+move[i].vert][tempcol+move[i].horiz] = '*';
				temprow = temprow+move[i].vert;
				tempcol = tempcol+move[i].horiz;
				i=4;
				count++;
			}
		}
	} 
		
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			printf("%3c ", mark[i][j]);
		}
		printf("\n");
	}
	printf("�̵u���|�� : %d",count); 

	free(p1);
	return 0;
}



