#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define crBegin static int state=0; switch(state) { case 0:
#define crReturn(i,x) do { state=i; return x; case i:; } while (0)
#define crFinish }
int func(void) {
    static int i;
    crBegin;
    for (i = 0; i < 10; i++)
    {
    	printf("i=%d\n",i);
    	crReturn(1, i);
    }   
    crFinish;
    return -1;
}
int main(int argc,char** agrv)
{
	int j =0;
	for(j=0;j<20;j++)
	{
		printf("#1:%d,j:%d\n",func(),j);
	}
	printf("#2:%d\n",func());
	printf("#3:%d\n",func());
	printf("#4:%d\n",func());
	printf("#5:%d\n",func());
	printf("#6:%d\n",func());
	return 0;
}
