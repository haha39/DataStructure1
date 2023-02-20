#include <stdio.h>
#include <stdlib.h>
typedef struct list_node *list_pointer;
typedef struct list_node
{
	int val;
	list_pointer linkn;// next記錄下一個節點位置
	list_pointer linkb;//before記錄前一個節點位置
}list_node;
FILE *p1;
int main() 
{	
	char c;
	int i=0;
	list_pointer a,first,next,before;
	//建立車站
	for(i=0; i<20; i++)
	{
		if(i == 0)
		{
			a = (list_pointer) malloc(sizeof(list_node));
			a->val =32;
			first = a;
			next = a;
			before = a;
		}
		else if(i == 19)
		{
			a = (list_pointer) malloc(sizeof(list_node));
			a->val =32;
			a->linkb  = before;
			next->linkn = a;
			a->linkn = first;
			first->linkb = a;
		}
 		else
		{
			a = (list_pointer) malloc(sizeof(list_node));
			a->val =32;
			a->linkb = before;
			next->linkn = a;
			before = a;
			next = a;
		}
	}
////////////////////////////////////////////////讀檔，開始判斷///////////////////////////////////////////////
	p1 = fopen("test.txt","r");
    if(p1==NULL)
	{
        printf("Open failure");
        return 1;
    }	
	else
	{
//		printf("jfjfjsljfa;ndfl;");
		while(1)
		{
			c=fgetc(p1);
			if(c == '+')
			{
				a -> val++;
				if(a->val == 91)
					a->val=32;
				else if(a->val == 33)
					a->val=65;							
			}
			else if(c == '-')
			{
				a->val--;
				if(a->val == 64)
					a->val=32;
				else if(a->val == 31)
					a->val=90;
			}
			else if(c == '>') 
				a=a->linkb;
			else if(c == '<') 
				a=a->linkn;	
			else if(c == '.')
			{
				printf("%c",a->val);
			}		
			else if(c == EOF)
				break;
		}
	}
	fclose(p1);
	return 0;
}

