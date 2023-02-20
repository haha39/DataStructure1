#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*2-2�ثe���Q�k�O�q�W�@�����r���q���A�k�}�l�]   �]���u��2-1�����n�����V�쵲�ҥH�o���ΰ}�C�ոլ�,
�����w�G�L�}�C�]��    abs�O�����*/
/* 
void print_PLATFORM(int arr[])//���ե� 
{
	int i;
	printf("\n");
	for(i=0;i<20;i++)
		printf("%c ",arr[i]);
	printf("\n");
}*/ 
/////////////////////////////////////////���ʨ��� ////////////////////////////////////////////////// 
void up_shift(int arr[],int last)//���W�] 
{
	if(arr[last]=='Z')
	{
		arr[last]=' ';
		return;	//���X�禡 
	}
	if(arr[last]==' ')
	{
		arr[last]='A';
		return;
	}
	arr[last]++;	
}
void down_shift(int arr[],int last)//���U�] 
{
	if(arr[last]==' ')
	{
		arr[last]='Z';
		return;
	}
	if(arr[last]=='A')
	{
		arr[last]=' ';
		return;
	}
	arr[last]--;
}
//////////////////////////////////////////////////// ���ʤ�x ////////////////////////////////////////////////// 
void left_shift(int* last)//������x 
{
	if(*last==0)//�{�b�O0 
	{
		*last=19;
		return ;
	}
	(*last)--;
}
void right_shift(int* last)
{
	if(*last==19)//�{�b�O19 
	{
		*last=0;
		return ;
	}
	(*last)++;
}
//////////////////////////////////////////////////// �ݨ����Z�����̵u ////////////////////////////////////////////////// 
int ranges(int plat[],int index,int c)//�e�@�Ӧr���A�{�b�r��Ӥ� 
{
	if(plat[index]==c)//�@�� 
		return 0;
	int p_count[1]={plat[index]};//���쪺�F��A�s����]�A�|�Ψ�+:position 
	int n_count[1]={plat[index]};
	int i;
	for(i=1;i<=20;i++)//���J��{�b�r���Areturn �Ӽ� 
	{
		up_shift(p_count,0);
		down_shift(n_count,0);
		if(p_count[0]==c)
			return i;
		if(n_count[0]==c)
			return -i;		
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
FILE *p1;
int main() 
{
	int i;
    int *plat=malloc(20*sizeof(int));
    for(i=0;i<20;i++)//�����]�Ů� 
        plat[i]=' ';
////////////////////////////////////////// /////Ū��////////////////////////////////////////////////////////// 
	p1 = fopen("test1.txt","r");
    if(p1==NULL)
	{
        printf("Open failure");
        return 1;
    }	
	else
	{
		char c;
		int i,min_range_station,min_range_platform=0,last=0,ct=0;//  last of platform  count 
		while(1)
		{
			c=fgetc(p1);//Ū�s�r��
			if(c == EOF)//Ū�쩳 
				break;
			min_range_station=ranges(plat,last,c);//��l�ơA��W���@�ˤ�x 
			min_range_platform=0;
			if(min_range_station==0)//�o���M�W���r���@�� 
			{
				printf(".");
				ct++;
				continue;//�^��while 
			}
			//���k��x�]
			for(i=1;i<=20;i++)//���F�^����A���]20�� 
			{
				right_shift(&last);
//				print_PLATFORM(plat);
				if(i>11)//���t�@��]�@�w��� 
					continue;
				if( abs(ranges(plat,last,c))+i < min_range_station )
				{
					min_range_station=abs(ranges(plat,last,c) )+i ;
					min_range_platform=i;
				}
			}
			//������x�]
			for(i=1;i<=20;i++)//���F�^����A���]20�� 
			{
				left_shift(&last);
//				print_PLATFORM(plat);
				if(i>11)//���t�@��]�@�w��� 
					continue;
				if( abs(ranges(plat,last,c) )+i < min_range_station )
				{
					min_range_station=abs(ranges(plat,last,c) )+i;
					min_range_platform=-i;
				}
			}				
			//���̤p�A�}�l�ʤ�x
			for(i=1;i<=abs(min_range_platform);i++)
			{
				if(min_range_platform!=0)
				{
					if(min_range_platform>0)
					{
						right_shift(&last);
						printf(">");
					}
					else
					{
						left_shift(&last);
						printf("<");
					}
				}
			}
			ct+=abs(min_range_platform);
			//���̤p�A�}�l�ʨ���
			int d=ranges(plat,last,c);//distance
			for(i=0;i<abs(d);i++)
			{
					if(d>0)
					{
						up_shift(plat,last);
						printf("+");
					}
					else 
					{
						down_shift(plat,last);
						printf("-");
					}
			}
			ct=ct+abs(d);	 
			printf(".");
			ct++;	
		}
		printf("\nlength:%d\n",ct);
	}
	fclose(p1);
	return 0;
}

