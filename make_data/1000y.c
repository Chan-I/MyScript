#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#define N 10				  //N为进程数，也是最后数据生成的个数
#define Num (100000000000/N)
#define BUFFER_SIZE (1024*1024*1024)	  //开辟的内存空间
int i,j,num;
long long k = 0;
char str[]="qwertuiopasdfghjklzxcvbnmy";  //字符串可以自己设定

int main()
{
	//这里生成的是char(8)型的字符串
        char data1[10][9];
        for( i=0;i<10;i++)
        {
        for(j=0;j<8;j++)
                    data1[i][j]=str[(i+j)%26];
                    data1[i][8]='\0';
        }
	pid_t pid[N+1];
	for(i=0;i<N;i++)
        {
		pid[i]=fork();
		if(pid[i]==0)
		{
			FILE *fp;
			char file[24];
			char *buffer = (char *)malloc( sizeof(char) * BUFFER_SIZE);
			sprintf(file, "indomain_data_%d.csv", i);
        		fp=fopen(file,"w");
			if (fp == NULL || buffer == NULL)
			{
				printf("  ERROR!\n");
				return 0;
			}
			long long tmp = k;
			long long m = 0;
        		for(k;k<tmp+Num;k++)
        		{

                		num=k%6;
				m+=sprintf(buffer+m,"%ld,",k+1);
				m+=sprintf(buffer+m,"%s,",data1[num]);
				m+=sprintf(buffer+m,"%s,",data1[num+1]);
				m+=sprintf(buffer+m,"%s,",data1[num+2]);
				m+=sprintf(buffer+m,"%s\n",data1[num+3]);
			
				if(m>=BUFFER_SIZE-1024 * 1024||k==tmp+Num-1)
				{
					fwrite(buffer, sizeof(char), m, fp);
					m = 0;
				}
        		}

			fclose(fp);
			free(buffer);
			_exit(0);
		}
		
		else
		{
			k = k + Num;
		}
	}
	
	for ( i = 0; i < N; i++)
	{
		do {
			pid_t pid_child = waitpid(pid[i], NULL, WNOHANG);
			if (pid_child == pid[i])
			{	
				printf("job %d done\n!", i);
				break;
			}
			
			else if(pid_child == 0)
			{
				continue;
			}
		   }while (1);
	}

        return 0;
}
