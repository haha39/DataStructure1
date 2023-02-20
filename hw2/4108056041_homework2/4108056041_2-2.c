#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*2-2目前的想法是從上一次的字元從左，右開始跑   因為只有2-1有說要用雙向鏈結所以這次用陣列試試看,
說不定二微陣列也行    abs是絕對值*/
/* 
void print_PLATFORM(int arr[])//測試用 
{
	int i;
	printf("\n");
	for(i=0;i<20;i++)
		printf("%c ",arr[i]);
	printf("\n");
}*/ 
/////////////////////////////////////////移動車站 ////////////////////////////////////////////////// 
void up_shift(int arr[],int last)//往上跑 
{
	if(arr[last]=='Z')
	{
		arr[last]=' ';
		return;	//跳出函式 
	}
	if(arr[last]==' ')
	{
		arr[last]='A';
		return;
	}
	arr[last]++;	
}
void down_shift(int arr[],int last)//往下跑 
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
//////////////////////////////////////////////////// 移動月台 ////////////////////////////////////////////////// 
void left_shift(int* last)//往左月台 
{
	if(*last==0)//現在是0 
	{
		*last=19;
		return ;
	}
	(*last)--;
}
void right_shift(int* last)
{
	if(*last==19)//現在是19 
	{
		*last=0;
		return ;
	}
	(*last)++;
}
//////////////////////////////////////////////////// 看車站距離的最短 ////////////////////////////////////////////////// 
int ranges(int plat[],int index,int c)//前一個字元，現在字原來比 
{
	if(plat[index]==c)//一樣 
		return 0;
	int p_count[1]={plat[index]};//有趣的東西，存往後跑，會用到+:position 
	int n_count[1]={plat[index]};
	int i;
	for(i=1;i<=20;i++)//先遇到現在字元，return 個數 
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
    for(i=0;i<20;i++)//先都設空格 
        plat[i]=' ';
////////////////////////////////////////// /////讀檔////////////////////////////////////////////////////////// 
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
			c=fgetc(p1);//讀新字元
			if(c == EOF)//讀到底 
				break;
			min_range_station=ranges(plat,last,c);//初始化，跟上次一樣月台 
			min_range_platform=0;
			if(min_range_station==0)//這次和上次字元一樣 
			{
				printf(".");
				ct++;
				continue;//回到while 
			}
			//往右月台跑
			for(i=1;i<=20;i++)//為了回到原位，都跑20次 
			{
				right_shift(&last);
//				print_PLATFORM(plat);
				if(i>11)//往另一邊跑一定更少 
					continue;
				if( abs(ranges(plat,last,c))+i < min_range_station )
				{
					min_range_station=abs(ranges(plat,last,c) )+i ;
					min_range_platform=i;
				}
			}
			//往左月台跑
			for(i=1;i<=20;i++)//為了回到原位，都跑20次 
			{
				left_shift(&last);
//				print_PLATFORM(plat);
				if(i>11)//往另一邊跑一定更少 
					continue;
				if( abs(ranges(plat,last,c) )+i < min_range_station )
				{
					min_range_station=abs(ranges(plat,last,c) )+i;
					min_range_platform=-i;
				}
			}				
			//找到最小，開始動月台
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
			//找到最小，開始動車站
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

