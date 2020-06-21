/**
 * 商品(入库日期 单据编号 往来单位名称 入库仓库、仓位 入库数量 经手人)
 * 功能：
 *     1.入库
 *     2.库存清单
 *     3.库存查询(根据单据编号、经手人、入库日期进行查询)
 */
#include <bits/stdc++.h>
using namespace std;
//用于吃掉空格 
char t;
//总记录数
int COUNT=0; 
struct COM{
	//入库日期 
	char date[15];
	//单据编号 
	char code[30];
	//往来单位名称
	char orga[15] ;
	//入库仓库与仓位 
	char repo[10];
	//入库数量
	int count;
	//经手人 
	char name[10];
}com[200];
void input();
void hand_input();
void file_input();
void find();
void findAll();
bool findByDate();
bool findByName();
bool findById();
int main(){
	while(true){
		printf("                              菜单栏                 \n");
		printf("               **************************************\n");
		printf("               *****        1.录入商品        *******\n");
		printf("               *****        2.库存查询        *******\n");
		printf("               *****        3.库存清单        *******\n");
		printf("               *****        4.退出系统        *******\n");
		printf("               **************************************\n");
		int flag;
		scanf("%d",&flag);
        switch(flag){
		    case 1:input();continue;
		    case 2:find();continue;
			case 3:findAll();continue;
		    case 4:{ printf("系统已退出！\n"); exit(0);}
	    } 
	}
	return 0;
}
bool findByID(){
	bool isEmpty=true;
	printf("请输入单据编号:\n");
	char tempCode[30];
	scanf("%s",tempCode);
	for(int i=1;i<=COUNT;i++){
		if(!strcmp(tempCode,com[i].code))
			printf(
			"%s %s    %s           %s      %d          %s\n",
			com[i].date,com[i].code,com[i].orga,com[i].repo,com[i].count,com[i].name);
			isEmpty=false;
		}
	return isEmpty;
}
bool findByDate(){
	bool isEmpty=true;
	printf("请输入入库日期:\n");
	char tempDate[30];
	scanf("%s",tempDate);
	for(int i=1;i<=COUNT;i++){
		if(!strcmp(tempDate,com[i].date))
			printf(
			"%s %s    %s           %s      %d          %s\n",
			com[i].date,com[i].code,com[i].orga,com[i].repo,com[i].count,com[i].name);
			isEmpty=false;
	}
	return isEmpty;
}
bool findByName(){
	bool isEmpty=true;
	printf("请输入经手人:\n");
	char tempName[30];
	scanf("%s",tempName);
	for(int i=1;i<=COUNT;i++){
		if(!strcmp(tempName,com[i].name))
			printf(
			"%s %s    %s           %s      %d          %s\n",
			com[i].date,com[i].code,com[i].orga,com[i].repo,com[i].count,com[i].name);
			isEmpty=false;
	}
	return isEmpty;
}
void find(){
     	int flag;
		printf("               ****************************************\n");
	    printf("               *****        1.按编号查询        *******\n");
		printf("               *****        2.按入库日期        *******\n");
		printf("               *****        3.按经手人查询      *******\n");
     	printf("               ****************************************\n");	
		scanf("%d",&flag);
		switch(flag){
			case 1:{if(findByID())printf("经查无此编号！\n");break;}
			case 2:{if(findByDate())printf("经查无此日期！\n");break;}
			case 3:{if(findByName())printf("经查无此经手人！\n");break;}
		}
}
void findAll(){
	printf("当前库存:\n");
	printf("入库日期    单据编号      往来单位名称        仓库-仓位      入库数量       经手人\n");
	for(int i=1;i<=COUNT;i++){
		//printf("入库日期：%s 单据编号：%s 往来单位名称：%s 仓库-仓位：%s 入库数量：%d 经手人：%s\n",com[i].date,com[i].code,com[i].orga,com[i].repo,com[i].count,com[i].name);
	printf(
	"%s %s    %s           %s      %d          %s\n",
	com[i].date,com[i].code,com[i].orga,com[i].repo,com[i].count,com[i].name);
	}
}
void file_input(){
	FILE *fp;
	if((fp=fopen("data.txt","r+"))==NULL){
		printf("无法打开文件!请检查是否建立输入文件！\n"); 
	}else{
		printf("文件打开成功，开始读入...\n");
		int i=1;
		while(~fscanf(fp,"%s%c%s%c%s%c%s%c%d%c%s",
		com[i].date,&t,com[i].code,&t,com[i].orga,&t,com[i].repo,&t,&com[i].count,&t,com[i].name)){
			printf("第%d条录入成功\n",i);
			/*
	    	printf(
     	    "%s %s    %s           %s      %d          %s\n",
	        com[i].date,com[i].code,com[i].orga,com[i].repo,com[i].count,com[i].name);
			*/
			COUNT++;
			i++;
		} 
	}
}
void hand_input(){
	printf("请输入需要录入的条数:\n");
	int cnt;
	scanf("%d",&cnt);
	for(int i=1;i<=cnt;i++){
		printf("请录入第%d条\n",i);
		scanf("%s%c%s%c%s%c%s%c%d%c%s",com[i].date,&t,com[i].code,&t,com[i].orga,&t,com[i].repo,&t,&com[i].count,&t,com[i].name);
		COUNT++;
	}
}
void input(){
	int flag;
	printf("请选择录入商品方式:\n");
	printf("1.手工录入   2.文件读入\n");
	scanf("%d",&flag);
	if(flag==1){
		hand_input();	
	}else{
		file_input();
	}
}
