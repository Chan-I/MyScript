#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int i,j,num;
long long k = 0;
char str[]="NBASJLKHopiuywqtsakxPOIWQE";

int main()
{

        char data1[10][9];
        for( i=0;i<10;i++)
        {
        for(j=0;j<8;j++)
                    data1[i][j]=str[(i+j)%26];
                    data1[i][8]='\0';
        }
	FILE *fp;
	fp=fopen("indomain_data5kw.csv","w");
	long long n=1;
	long long m;
	for(m=100000000001;m<=100050000000;m++)
	{
		if(m%5000==0)
		{
			
			k=10000000*n;
			n++;
			num=m%7;

                	fprintf(fp,"%ld",k);

                	fputc(',',fp);

                	fwrite(data1[num],sizeof(char),8,fp);

                	fputc(',',fp);

                	fwrite(data1[num+1],sizeof(char),8,fp);

                	fputc(',',fp);

                	fwrite(data1[num+2],sizeof(char),8,fp);

                	fputc(',',fp);

                	fwrite(data1[num+3],sizeof(char),8,fp);

                	fputc('\n',fp);
		}
		else
 		{
			
		
			num=m%7;
		
			fprintf(fp,"%ld",m);

                	fputc(',',fp);

                	fwrite(data1[num],sizeof(char),8,fp);
        
                	fputc(',',fp);

                	fwrite(data1[num+1],sizeof(char),8,fp);

                	fputc(',',fp);

                	fwrite(data1[num+2],sizeof(char),8,fp);

                	fputc(',',fp);

                	fwrite(data1[num+3],sizeof(char),8,fp);

                	fputc('\n',fp);
 		}
	}
	fclose(fp);	
	
        return 0;
}
