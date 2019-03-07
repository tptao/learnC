#include<stdio.h>

struct student
{
    char name[10];
    int score;
};

int main()
{
    int num=0,choice=0,i=0,j=0;
    struct student temp,stu[100];
    int res=0;
    res = scanf("&d &d",&num,&choice);
    printf("res:%d\n",res);
    getchar();
    printf("--input num,input order--:\n");
    while(scanf("&d &d",&num,&choice) == 2)
    {
        for(i=0; i< 5; i++)
        {
            //scanf("%s%d",stu[i].name,&stu[i].score);
            printf("--input next--:\n");
        }
        //printf("--please waiting--:\n");
        if(choice==0)// 升序
        {
            //写一个稳定的排序，希堆快选稳定，用插入排序
            for(i=1;i<num-1;i++)
            {
                temp = stu[i];
                for(j=i;j>0;j--)
                {
                    if(stu[j].score < stu[j-1].score)
                        stu[j] = stu[j-1]; //后挪
                    else
                    {
                        stu[j] = temp;//归位
                    }
                    
                }
            }
        }
        if(choice==1)//降序
        {
            for(i=1;i<num-1;i++)
            {
                temp = stu[i];
                for(j=i;j>0;j--)
                {
                    if(stu[j].score > stu[j-1].score)
                        stu[j] = stu[j-1]; //后挪
                    else
                    {
                        stu[j] = temp;//归位
                    }
                    
                }
            }
        }

        for(i=0; i<num-1; i++)
        {
            printf("%s %d\n",stu[i].name,stu[i].score);
        }
    }


    return 0;
}