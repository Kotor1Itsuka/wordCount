#include <stdio.h>
#include <string.h> 

int charactercount(char *file)
{   FILE *f;
    f = fopen(file, "r");
    char character;
    int countc=0;
    if(f==NULL)
    {
        printf("file is NULL");
    }
    else
	{
		while (!feof(f)) 
		{ 
			character=fgetc(f); 
				countc++; 
		} 
		fclose(f);
		printf("�ַ���:%d ",countc-1); 
	}
}


int wordcount(char *file)
{   FILE *f;
    f=fopen(file,"r");
    char character;
	int countw=0,aword=0;
    if(f==NULL)
    {
     printf("file is NULL");
    }
    else
	{
		while(!feof(f)) 
		{ 
			character=fgetc(f);
			if((character >= 'a'&&character <= 'z')||(character>='A'&&character<='Z')||character=='_') 
				aword=1; 
			else if (aword)	//��aword=1�� character��Ϊ��ĸʱ����Ϊ���� ��ǰ���Ǳ�������һ������ 
			{
				 aword=0;countw++;
			} 
		} 
		fclose(f); 
		printf("������:%d ",countw); 
	}
}


int main(int argc,char **argv )
{
	if(strcmp(argv[1],"-c")==0)
	{
		charactercount(argv[2]);
	}
	else if(strcmp(argv[1],"-w")==0)
	{
		wordcount(argv[2]);
	}
	return 0;
}




