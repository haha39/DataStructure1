#include <stdio.h>
#include <stdlib.h>
/*1.Ū�D��*/
FILE *p1,*p2;
int main() 
{	
/////////////////////Ū��///////////////////////////////////////////////////////////////////////////////////////////////
	p1 = fopen("test.txt","r");
    if(p1==NULL)
	{
        printf("Open p1 failure");
        return 1;
    }	
	else
	{
		int n,i,j,question_word_length=0;
/////////////////////�@��@��Ū/////////////////////////////////////////////////////////////////////////////////////////////
		char c[60];//�̦h60�r�� 
		for(i=0;i<60;i++)//Ū�� 
		{
			c[i] = fgetc(p1);
			if( c[i] == '\n' )
			{
//				c[i]='0';
				break;
			}
			question_word_length++;
//			printf("%c",c[i]) ;
		}	
//		printf("\n%d\n",question_word_length);
///////////////////�d���_���r��A�ഫ /////////////////////////////////////////////////////////v///////////////////
		int question_mos_length=question_word_length*4,k=0;
		char m[question_mos_length];//�̦hquestion_mos_length�ӱK�X 
		for(i=0;i<question_mos_length;i++)
		{
//			k=0;					
//			printf("%c  ",c[i]);
			if(c[i] == '\n'){  break; }
			else if(c[i] == 'A'){	m[k++]='.';	m[k++]='-';	}
			else if(c[i] == 'B'){	m[k++]='-';	m[k++]='.';	m[k++]='.';	m[k++]='.';	}			
			else if(c[i] == 'C'){	m[k++]='-';	m[k++]='.';	m[k++]='-';	m[k++]='.';	}					
			else if(c[i] == 'D'){   m[k++]='-';	m[k++]='.';	m[k++]='.'; }					
			else if(c[i] == 'E'){	m[k++]='.';	}					
			else if(c[i] == 'F'){	m[k++]='.';	m[k++]='.';	m[k++]='-';	m[k++]='.';	}					
			else if(c[i] == 'G'){	m[k++]='-';	m[k++]='-';	m[k++]='.';	}					
			else if(c[i] == 'H'){	m[k++]='.';	m[k++]='.';	m[k++]='.';	m[k++]='.';	}				
			else if(c[i] == 'I'){	m[k++]='.';	m[k++]='.';	}					
			else if(c[i] == 'J'){	m[k++]='.';	m[k++]='-';	m[k++]='-';	m[k++]='-';	}					
			else if(c[i] == 'K'){	m[k++]='-';	m[k++]='.';	m[k++]='-';	}
			else if(c[i] == 'L'){	m[k++]='.';	m[k++]='-';	m[k++]='.';	m[k++]='.';	}
			else if(c[i] == 'M'){	m[k++]='-';	m[k++]='-';	}						
			else if(c[i] == 'N'){	m[k++]='-';	m[k++]='.';	}						
			else if(c[i] == 'O'){	m[k++]='-';	m[k++]='-';	m[k++]='-';	}						
			else if(c[i] == 'P'){	m[k++]='.';	m[k++]='-';	m[k++]='-';	m[k++]='.';	}						
			else if(c[i] == 'Q'){	m[k++]='-';	m[k++]='-';	m[k++]='.';	m[k++]='-';	}						
			else if(c[i] == 'R'){	m[k++]='.';	m[k++]='-';	m[k++]='.';	}					
			else if(c[i] == 'S'){	m[k++]='.';	m[k++]='.';	m[k++]='.';	}						
			else if(c[i] == 'T'){	m[k++]='-';	}									
			else if(c[i] == 'U'){	m[k++]='.';	m[k++]='.';	m[k++]='-';	}					
			else if(c[i] == 'V'){	m[k++]='.';	m[k++]='.';	m[k++]='.';	m[k++]='-';	}					
			else if(c[i] == 'W'){	m[k++]='.';	m[k++]='-';	m[k++]='-';	}					
			else if(c[i] == 'X'){	m[k++]='-';	m[k++]='.';	m[k++]='.';	m[k++]='-';	}					
			else if(c[i] == 'Y'){	m[k++]='-';	m[k++]='.';	m[k++]='-';	m[k++]='-';	}					
			else if(c[i] == 'Z'){	m[k++]='-';	m[k++]='-';	m[k++]='.';	m[k++]='.';	}
		}		
		question_mos_length=k;
/*		printf("kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkey  %d\n",question_mos_length);
			for(i=0;i<question_mos_length;i++)
			{ 
					printf("%d%c",question_mos_length,m[i]);
				
			}*/ 
///////////////////////�A�ݦ��X��////////////////////////////////////////////////////////////////////////////////////////////
		fscanf(p1,"%d\n",&n);
//		printf("%d\n",n);
/////////////////////�̫�P�_///////////////////////////////////////////////////////////////////////////////////////////////
		//��X�ɮ� 
		p2 = fopen("output.txt","w");
        if( NULL == p2 )
		{
            printf( "open p2 failure" );
            return 1;
        }
        else
		{
			int t,ct,mos_ct,char_ct;	//
			char c1[60];
			for(i=0;i<n;i++)//�@��Ū�@�ӳ�r 
			{
				
				t=-1;ct=0;mos_ct=0;char_ct=0;
				ct=0; 
				for(j=0;j<60;j++)
				{
					c1[j] = fgetc(p1);
					ct++;
					if( c1[j] == '\n'  || c1[j] == EOF)
					{
						ct--;
						char_ct = ct;
						break;
					}
				}
//				printf("%d %d\n",i,char_ct);
				char c2[char_ct];//�u�����r���}�C
				for(j=0;j<char_ct;j++)
				{
					if( c1[j] == '\n'  || c1[j] == EOF)
						break;
					c2[j]=c1[j];
				}	
				char m2[char_ct*4];
				//�༯���K�X
				k=0;
				for(j=0;j<char_ct;j++)
				{
					if(c2[j]  == 'A'){	m2[k++]='.';	m2[k++]='-';	 }
					else if(c2[j]  == 'B'){	m2[k++]='-';	m2[k++]='.';	m2[k++]='.';	m2[k++]='.';	 }			
					else if(c2[j]  == 'C'){	m2[k++]='-';	m2[k++]='.';	m2[k++]='-';	m2[k++]='.';	 }					
					else if(c2[j]  == 'D'){ m2[k++]='-';	m2[k++]='.';	m2[k++]='.';  }					
					else if(c2[j]  == 'E'){	m2[k++]='.';	 }					
					else if(c2[j]  == 'F'){	m2[k++]='.';	m2[k++]='.';	m2[k++]='-';	m2[k++]='.';	 }					
					else if(c2[j]  == 'G'){	m2[k++]='-';	m2[k++]='-';	m2[k++]='.';	 }					
					else if(c2[j]  == 'H'){	m2[k++]='.';	m2[k++]='.';	m2[k++]='.';	m2[k++]='.';	 }				
					else if(c2[j]  == 'I'){	m2[k++]='.';	m2[k++]='.';	 }					
					else if(c2[j]  == 'J'){	m2[k++]='.';	m2[k++]='-';	m2[k++]='-';	m2[k++]='-';	 }					
					else if(c2[j]  == 'K'){	m2[k++]='-';	m2[k++]='.';	m2[k++]='-';	 }
					else if(c2[j]  == 'L'){	m2[k++]='.';	m2[k++]='-';	m2[k++]='.';	m2[k++]='.';	}
					else if(c2[j]  == 'M'){	m2[k++]='-';	m2[k++]='-';	 }						
					else if(c2[j]  == 'N'){	m2[k++]='-';	m2[k++]='.';	 }						
					else if(c2[j]  == 'O'){	m2[k++]='-';	m2[k++]='-';	m2[k++]='-';	 }						
					else if(c2[j]  == 'P'){	m2[k++]='.';	m2[k++]='-';	m2[k++]='-';	m2[k++]='.';	 }						
					else if(c2[j]  == 'Q'){	m2[k++]='-';	m2[k++]='-';	m2[k++]='.';	m2[k++]='-';	 }						
					else if(c2[j]  == 'R'){	m2[k++]='.';	m2[k++]='-';	m2[k++]='.';	}					
					else if(c2[j]  == 'S'){	m2[k++]='.';	m2[k++]='.';	m2[k++]='.';	}						
					else if(c2[j]  == 'T'){	m2[k++]='-';	 }									
					else if(c2[j]  == 'U'){	m2[k++]='.';	m2[k++]='.';	m2[k++]='-';	 }					
					else if(c2[j]  == 'V'){	m2[k++]='.';	m2[k++]='.';	m2[k++]='.';	m2[k++]='-';	 }					
					else if(c2[j]  == 'W'){	m2[k++]='.';	m2[k++]='-';	m2[k++]='-';	 }					
					else if(c2[j]  == 'X'){	m2[k++]='-';	m2[k++]='.';	m2[k++]='.';	m2[k++]='-';	 }					
					else if(c2[j]  == 'Y'){	m2[k++]='-';	m2[k++]='.';	m2[k++]='-';	m2[k++]='-';	 }					
					else if(c2[j]  == 'Z'){	m2[k++]='-';	m2[k++]='-';	m2[k++]='.';	m2[k++]='.';	}					
				}
//				printf("%d     %d\n",i,k);
				mos_ct=k;				
				//�P�_
				t=-1;
				if(mos_ct>question_mos_length)//���p�@�A�����S���| 
				{
					for(j=0;j<char_ct;j++)
					{
						fprintf(p2,"%c",c2[j]);
					}				
					fprintf(p2," doesn��t have the same prefix as ");
					for(j=0;j<question_word_length;j++)
					{
						fprintf(p2,"%c",c[j]);
					}				
					fprintf(p2,"\n");		 
					
				}
				//���p�G�A�i��@�˥i��S
				else if(mos_ct==question_mos_length)
				{
//					printf("%d  %d \n ",mos_ct,question_mos_length);
					for(j=0;j<question_mos_length;j++)
					{
						if(m2[j]==m[j])//�����@�� 
						{
							if(j==question_mos_length-1)
								t=1;
						}
						else//���@�� 
						{
							t=-1;
							break;
						}
					} 
					if(t==1)//�L�X�ӧ����@�� 
					{
						for(j=0;j<char_ct;j++)
						{
							fprintf(p2,"%c",c2[j]);
						}				
						fprintf(p2," is the same  as ");
						for(j=0;j<question_word_length;j++)
						{
							fprintf(p2,"%c",c[j]);
						}				
						fprintf(p2,"\n");						
					}
					else if(t==-1)//�L�X�ӥ��@�� 
					{
						for(j=0;j<char_ct;j++)
						{
							fprintf(p2,"%c",c2[j]);
						}				
						fprintf(p2," doesn��t have the same prefix as ");
						for(j=0;j<question_word_length;j++)
						{
							fprintf(p2,"%c",c[j]);
						}				
						fprintf(p2,"\n");							
					}
				}
				//���p�T�A�i��S���|�i��e�Y
				else if(mos_ct<question_mos_length) 
				{
					for(j=0;j<mos_ct;j++)
					{
						if(m2[j]==m[j])
						{
							if(j==mos_ct-1)//�e�Y 
								t=10;
						}
						else//���@�� 
						{
							t=-1;
							break;
						}
					}
					if(t==10)//�L�X�ӫe�Y 
					{
						for(j=0;j<char_ct;j++)
						{
							fprintf(p2,"%c",c2[j]);
						}				
						fprintf(p2," has the same prefix as ");
						for(j=0;j<question_word_length;j++)
						{
							fprintf(p2,"%c",c[j]);
						}				
						fprintf(p2,"\n");						
					}
					else if(t==-1)//�L�X�ӥ��@�� 
					{
						for(j=0;j<char_ct;j++)
						{
							fprintf(p2,"%c",c2[j]);
						}				
						fprintf(p2," doesn��t have the same prefix as ");
						for(j=0;j<question_word_length;j++)
						{
							fprintf(p2,"%c",c[j]);
						}				
						fprintf(p2,"\n");							
					}									
				}
			}
		}
 	}
	fclose(p1);
	return 0;
}

