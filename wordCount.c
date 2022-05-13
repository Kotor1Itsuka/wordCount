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
		printf("字符数:%d ",countc-1); 
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
			else if (aword)	//当aword=1且 character不为字母时，其为符号 ，前方是被隔开的一个单词 
			{
				 aword=0;countw++;
			} 
		} 
		fclose(f); 
		printf("单词数:%d ",countw); 
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




