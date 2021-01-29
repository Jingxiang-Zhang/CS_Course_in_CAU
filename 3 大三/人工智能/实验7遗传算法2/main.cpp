#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "time.h"
#include <unistd.h>
#include <bits/stdc++.h>
#define CITY_NUM 30     //城市数，城市编号是0~CITY_NUM-1
#define POPSIZE 100        //种群个体数
#define MAXVALUE 10000000   //路径最大值上限
#define N 100000//需要根据实际求得的路径值修正
unsigned seed=(unsigned)time(0);
double Hash[CITY_NUM+1];
typedef struct CityPosition
{
    double x;
    double y;
}CityPosition;

CityPosition CityPos[100]={
    {11003.611100,42102.500000},{11108.611100,42373.888900},{11133.333300,42885.833300},
	{11155.833300,42712.500000},{11183.333300,42933.333300},{11297.500000,42853.333300},
	{11310.277800,42929.444400},{11416.666700,42983.333300},{11423.888900,43000.277800},
	{11438.333300,42057.222200},{11461.111100,43252.777800},{11485.555600,43187.222200},
	{11503.055600,42855.277800},{11511.388900,42106.388900},{11522.222200,42841.944400},
	{11569.444400,43136.666700},{11583.333300,43150.000000},{11595.000000,43148.055600},
	{11600.000000,43150.000000},{11690.555600,42686.666700},{11715.833300,41836.111100},
	{11751.111100,42814.444400},{11770.277800,42651.944400},{11785.277800,42884.444400},
	{11822.777800,42673.611100},{11846.944400,42660.555600},{11963.055600,43290.555600},
	{11973.055600,43026.111100},{12058.333300,42195.555600},{12149.444400,42477.500000},
	{12286.944400,43355.555600},{12300.000000,42433.333300},{12355.833300,43156.388900},
	
	{11005.611100,42104.500000},{11110.611100,42375.888900},{11135.333300,42887.833300},
	{11157.833300,42714.500000},{11185.333300,42935.333300},{11299.500000,42855.333300},
	{11312.277800,42911.444400},{11418.666700,42985.333300},{11427.888900,43005.277800},
	{11440.333300,42011.222200},{11465.111100,43257.777800},{11488.555600,43184.222200},
	{11505.055600,42857.277800},{11515.388900,42108.388900},{11521.222200,42842.944400},
	{11511.444400,43138.666700},{11588.333300,43155.000000},{11591.000000,43145.055600},
	{11602.000000,43152.000000},{11694.555600,42687.666700},{11719.833300,41838.111100},
	{11753.111100,42816.444400},{11775.277800,42658.944400},{11784.277800,42884.444400},
	{11824.777800,42675.611100},{11849.944400,42667.555600},{11962.055600,43298.555600},
	{11975.055600,43028.111100},{12062.333300,42195.555600},{12140.444400,42472.500000},
	{12288.944400,43377.555600},{12302.000000,42432.333300},{12351.833300,43154.388900},
	
	{11053.611100,42152.500000},{11158.611100,42343.888900},{11123.333300,42845.833300},
	{11115.833300,42752.500000},{11183.333300,42943.333300},{11197.500000,42843.333300},
	{11320.277800,42989.444400},{11446.666700,42983.333300},{11223.888900,43040.277800},
	{11408.333300,42057.222200},{11411.111100,43272.777800},{11485.555600,43187.222200},
	{11513.055600,42815.277800},{11551.388900,42146.388900},{11552.222200,42871.944400},
	{11542.444400,43176.666700},{11583.333300,43110.000000},{11585.000000,43188.055600},
	{11640.000000,43180.000000},{11640.555600,42666.666700},{11745.833300,41896.111100},
	{11781.111100,42844.444400},{11711.277800,42681.944400},{11715.277800,42864.444400},
	{11812.777800,42643.611100},{11856.944400,42880.555600},{11935.055600,43280.555600},
	{11903.055600,43016.111100},{12018.333300,42155.555600},{12159.444400,42487.500000},
	{12206.944400,43325.555600},{12340.000000,42233.333300},{12385.833300,43146.388900},
	{12386.666700,43355.722200}
	
};

double CityDistance[CITY_NUM][CITY_NUM];//城市距离词典

typedef struct{
    int colony[POPSIZE][CITY_NUM+1];//城市种群,默认出发城市编号为0，则城市编号的最后一个城市还应该为0
    double fitness[POPSIZE];// 每个个体的适应值，即1/Distance[POPSIZE]
    double Distance[POPSIZE];//每个个体的总路径
    int BestRooting[CITY_NUM+1];//最优城市路径序列
    double BestFitness;//最优路径适应值
    double BestValue;//最优路径长度
    int BestNum;
}TSP,*PTSP;

/*计算城市距离词典CityDistance[i][j]*/
void CalculatDist()
{
    int i,j;
    double temp1,temp2;
    for(i=0;i<CITY_NUM;i++){
        for(j=0;j<=CITY_NUM;j++){//最后一个城市还应该返回到出发节点
            temp1=CityPos[j].x-CityPos[i].x;
            temp2=CityPos[j].y-CityPos[i].y;
            CityDistance[i][j]=sqrt(temp1*temp1+temp2*temp2);
        }
    }
}
/*数组复制*/
void copy(int a[],int b[])
{
    int i=0;
    for(i=0;i<CITY_NUM+1;i++)
    {
        a[i]=b[i];
    }
}

/*用来检查新生成的节点是否在当前群体中，0号节点是默认出发节点和终止节点*/
bool check(TSP &city,int pop,int num,int k)
{
    int i;
    for(i=0;i<=num;i++){
        if(k==city.colony[pop][i])
            return true;//新生成节点存在于已经生成的路径中
    }
    return false;//新生成节点没有存在于已经生成的路径中
}

/****************种群初始化，即为city.colony[i][j]赋值****************/
void InitColony(TSP &city)
{
    int i,j,r;
    for(i=0;i<POPSIZE;i++){
        city.colony[i][0]=0;
        city.colony[i][CITY_NUM]=0;
        city.BestValue=MAXVALUE;
        city.BestFitness=0;//适应值越大越好
    }

    for(i=0;i<POPSIZE;i++)
    {
        for(j=1;j<CITY_NUM;j++)
        {
            r=rand()%(CITY_NUM-1)+1;//产生1～CITY_NUM-1之间的随机数
            while(check(city,i,j,r))//随机产生城市序号，即为city.colony[i][j]赋值
            {
                r=rand()%(CITY_NUM-1)+1;
            }

            city.colony[i][j]=r;
        }
    }
}

/*计算适应值,考虑应该在这里面把最优选出来*/
void CalFitness(TSP &city)
{
    int i,j;
    int start,end;
    int Best=0;
    for(i=0;i<POPSIZE;i++){//求每个个体的总路径，适应值
        city.Distance[i]=0;
        for(j=1;j<=CITY_NUM;j++){
            start=city.colony[i][j-1];end=city.colony[i][j];
            city.Distance[i]=city.Distance[i]+CityDistance[start][end];//city.Distance[i]每个个体的总路径
        }
        city.fitness[i]=N/city.Distance[i];
        if(city.fitness[i]>city.fitness[Best])//选出最大的适应值，即选出所有个体中的最短路径
            Best=i;
    }
    copy(city.BestRooting,city.colony[Best]);//将最优个体拷贝给city.BestRooting
    city.BestFitness=city.fitness[Best];
    city.BestValue=city.Distance[Best];
    city.BestNum=Best;
}


/****************选择算子：轮盘赌法****************/
void Select(TSP &city)
{
	/*
	//安装线性比例分配 
    int TempColony[POPSIZE][CITY_NUM+1];
    int i,j,t;
    double s;
    double GaiLv[POPSIZE];
    double SelectP[POPSIZE+1];
    double avg;
    double sum=0;
    for(i=0;i<POPSIZE;i++)
    {
        sum+=city.fitness[i];
    }
    for(i=0;i<POPSIZE;i++)
    {
        GaiLv[i]=city.fitness[i]/sum;
    }
    SelectP[0]=0;
    for(i=0;i<POPSIZE;i++)
    {
        SelectP[i+1]=SelectP[i]+GaiLv[i]*RAND_MAX;
    }
    memcpy(TempColony[0],city.colony[city.BestNum],sizeof(TempColony[0]));//void *memcpy(void *dest, const void *src, size_t n)从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中
    for(t=1;t<POPSIZE;t++)
    {
        double ran = rand() % RAND_MAX + 1;
        s= (double) ran / 100.0;
        for(i=1;i<POPSIZE;i++)
        {
            if(SelectP[i]>=s)
                break;
        }
        memcpy(TempColony[t],city.colony[i-1],sizeof(TempColony[t]));
    }
    for(i=0;i<POPSIZE;i++)
    {
        memcpy(city.colony[i],TempColony[i],sizeof(TempColony[i]));
    }
    */

	//安装平方比例分配 
    int TempColony[POPSIZE][CITY_NUM+1];
    int i,j,t;
    double s;
    double GaiLv[POPSIZE];
    double SelectP[POPSIZE+1];
    double avg;
    double sum=0;
    for(i=0;i<POPSIZE;i++)
    {
        sum+=city.fitness[i]*city.fitness[i];
    }
    for(i=0;i<POPSIZE;i++)
    {
        GaiLv[i]=city.fitness[i]*city.fitness[i]/sum;
    }
    SelectP[0]=0;
    for(i=0;i<POPSIZE;i++)
    {
        SelectP[i+1]=SelectP[i]+GaiLv[i]*RAND_MAX;
    }
    memcpy(TempColony[0],city.colony[city.BestNum],sizeof(TempColony[0]));//void *memcpy(void *dest, const void *src, size_t n)从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中
    for(t=1;t<POPSIZE;t++)
    {
        double ran = rand() % RAND_MAX + 1;
        s= (double) ran / 100.0;
        for(i=1;i<POPSIZE;i++)
        {
            if(SelectP[i]>=s)
                break;
        }
        memcpy(TempColony[t],city.colony[i-1],sizeof(TempColony[t]));
    }
    for(i=0;i<POPSIZE;i++)
    {
        memcpy(city.colony[i],TempColony[i],sizeof(TempColony[i]));
    }
    
}

/****************交叉：头尾不变，中间打乱顺序交叉****************/
void Cross(TSP &city,double pc)//交叉概率是pc
{
    int i,j,t,l;
    int a,b,ca,cb;
    int Temp1[CITY_NUM+1],Temp2[CITY_NUM+1];
    for(i=0;i<POPSIZE;i++)
    {
        double s=((double)(rand()%RAND_MAX))/RAND_MAX;
        if(s<pc)
        {
            cb=rand()%POPSIZE;
            ca=cb;
            if(ca==city.BestNum||cb==city.BestNum)//如果遇到最优则直接进行下次循环
                continue;

            l=rand()%(CITY_NUM/2)+1;  //1-19
            a=rand()%(CITY_NUM-l)+1; //1-37

            memset(Hash,0,sizeof(Hash));//void *memset(void *s, int ch, size_t n);将s中当前位置后面的n个字节 用 ch 替换并返回 s 。
            Temp1[0]=Temp1[CITY_NUM]=0;
            for(j=1;j<=l;j++)//打乱顺序即随机，选出来的通过Hash标记为1
            {
                Temp1[j]=city.colony[cb][a+j-1]; //a+L=2~38 20~38
                Hash[Temp1[j]]=1;
            }
            for(t=1;t<CITY_NUM;t++)
            {
                if(Hash[city.colony[ca][t]]==0)
                {
                    Temp1[j++]=city.colony[ca][t];
                    Hash[city.colony[ca][t]]=1;
                }
            }
            memcpy(city.colony[ca],Temp1,sizeof(Temp1));
        }
    }

}

/****************变异****************/
double GetFittness(int a[CITY_NUM+1])
{
    int i,start,end;
    double Distance=0;
    for(i=0;i<CITY_NUM;i++)
    {
        start=a[i];   end=a[i+1];
        Distance+=CityDistance[start][end];
    }
    return N/Distance;
}
/*对换变异*/
void Mutation(TSP &city,double pm)//变异概率是pm
{
	
	//两点之间对换
    int i,k,m;
    int Temp[CITY_NUM+1];
    for(k=0;k<POPSIZE;k++)
    {
        double s=((double)(rand()%RAND_MAX))/RAND_MAX;//随机产生概率0~1间
        i=rand()%POPSIZE;//随机产生0~POPSIZE之间的数
        if(s<pm&&i!=city.BestNum)//i!=city.BestNum，即保证最优的个体不变异
        {
            int a,b,t;
            a=(rand()%(CITY_NUM-1))+1;
            b=(rand()%(CITY_NUM-1))+1;
            copy(Temp,city.colony[i]);
            if(a>b)//保证让b>=a
            {
                t=a;
                a=b;
                b=t;
            }
            for(m=a;m<(a+b)/2;m++)
            {
                t=Temp[m];
                Temp[m]=Temp[a+b-m];
                Temp[a+b-m]=t;
            }

            if(GetFittness(Temp)<GetFittness(city.colony[i]))
            {
                a=(rand()%(CITY_NUM-1))+1;
                b=(rand()%(CITY_NUM-1))+1;
                //copy(Temp,city.colony[i]);
                memcpy(Temp,city.colony[i],sizeof(Temp));
                if(a>b)
                {
                    t=a;
                    a=b;
                    b=t;
                }
                for(m=a;m<(a+b)/2;m++)
                {
                    t=Temp[m];
                    Temp[m]=Temp[a+b-m];
                    Temp[a+b-m]=t;
                }

                    if(GetFittness(Temp)<GetFittness(city.colony[i]))
                    {
                        a=(rand()%(CITY_NUM-1))+1;
                        b=(rand()%(CITY_NUM-1))+1;
                        //copy(Temp,city.colony[i]);
                        memcpy(Temp,city.colony[i],sizeof(Temp));
                        if(a>b)
                        {
                            t=a;
                            a=b;
                            b=t;
                        }
                        for(m=a;m<(a+b)/2;m++)
                        {
                            t=Temp[m];
                            Temp[m]=Temp[a+b-m];
                            Temp[a+b-m]=t;
                        }
                    }

            }
            memcpy(city.colony[i],Temp,sizeof(Temp));
        }
    }
    
    /*
    //仅两点互换
    int i,k,m;
    int Temp[CITY_NUM+1];
    for(k=0;k<POPSIZE;k++)
    {
        double s=((double)(rand()%RAND_MAX))/RAND_MAX;//随机产生概率0~1间
        i=rand()%POPSIZE;//随机产生0~POPSIZE之间的数
        if(s<pm&&i!=city.BestNum)//i!=city.BestNum，即保证最优的个体不变异
        {
            int a,b,t;
            a=(rand()%(CITY_NUM-1))+1;
            b=(rand()%(CITY_NUM-1))+1;
            copy(Temp,city.colony[i]);
            if(a>b)//保证让b>=a
            {
                t=a;
                a=b;
                b=t;
            }

            t=Temp[a];
            Temp[a]=Temp[b];
            Temp[b]=t;
            
            if(GetFittness(Temp)<GetFittness(city.colony[i]))
            {
                a=(rand()%(CITY_NUM-1))+1;
                b=(rand()%(CITY_NUM-1))+1;
                //copy(Temp,city.colony[i]);
                memcpy(Temp,city.colony[i],sizeof(Temp));
                if(a>b)
                {
                    t=a;
                    a=b;
                    b=t;
                }
             	t=Temp[a];
            	Temp[a]=Temp[b];
            	Temp[b]=t;

                    if(GetFittness(Temp)<GetFittness(city.colony[i]))
                    {
                        a=(rand()%(CITY_NUM-1))+1;
                        b=(rand()%(CITY_NUM-1))+1;
                        //copy(Temp,city.colony[i]);
                        memcpy(Temp,city.colony[i],sizeof(Temp));
                        if(a>b)
                        {
                            t=a;
                            a=b;
                            b=t;
                        }
                        t=Temp[a];
            			Temp[a]=Temp[b];
            			Temp[b]=t;
                    }

            	}
            memcpy(city.colony[i],Temp,sizeof(Temp));
        }
    }
    */
}

void OutPut(TSP &city)
{
    int i,j;
    printf("最佳路径为:\n");
    for(i=0;i<=CITY_NUM;i++)
    printf("%5d",city.BestRooting[i]);
    printf("\n最佳路径值为：%f\n",(city.BestValue));
        printf("\n最佳适应度值为：%f\n",(city.BestFitness));

}


int main()
{

        TSP city;
        double pcross,pmutation;//交叉概率和变异概率
        int MaxEpoc;//最大迭代次数
        int i;
        srand(seed);
        MaxEpoc=20000;
        pcross=0.85; pmutation=0.15;
        CalculatDist();//计算城市距离词典
        InitColony(city);//生成初始种群
        CalFitness(city);//计算适应值,考虑应该在这里面把最优选出来

clock_t start,end;
start=clock();	
        for(i=0;i<MaxEpoc;i++)
        {

            Select(city);//选择(复制)：轮盘赌法
            Cross(city,pcross);//交叉
            Mutation(city,pmutation);//变异
            CalFitness(city);//计算适应值
        }
end=clock();
	double endtime=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"Total time:"<<endtime*1000<<"ms"<<endl;	//ms为单位

       OutPut(city);//输出
    return 0;
}

