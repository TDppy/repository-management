/**
 * ��Ʒ(������� ���ݱ�� ������λ���� ���ֿ⡢��λ ������� ������)
 * ���ܣ�
 *     1.���
 *     2.����嵥
 *     3.����ѯ(���ݵ��ݱ�š������ˡ�������ڽ��в�ѯ)
 */
#include <bits/stdc++.h>
using namespace std;
//���ڳԵ��ո� 
char t;
//�ܼ�¼��
int COUNT=0; 
struct COM{
	//������� 
	char date[15];
	//���ݱ�� 
	char code[30];
	//������λ����
	char orga[15] ;
	//���ֿ����λ 
	char repo[10];
	//�������
	int count;
	//������ 
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
		printf("                              �˵���                 \n");
		printf("               **************************************\n");
		printf("               *****        1.¼����Ʒ        *******\n");
		printf("               *****        2.����ѯ        *******\n");
		printf("               *****        3.����嵥        *******\n");
		printf("               *****        4.�˳�ϵͳ        *******\n");
		printf("               **************************************\n");
		int flag;
		scanf("%d",&flag);
        switch(flag){
		    case 1:input();continue;
		    case 2:find();continue;
			case 3:findAll();continue;
		    case 4:{ printf("ϵͳ���˳���\n"); exit(0);}
	    } 
	}
	return 0;
}
bool findByID(){
	bool isEmpty=true;
	printf("�����뵥�ݱ��:\n");
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
	printf("�������������:\n");
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
	printf("�����뾭����:\n");
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
	    printf("               *****        1.����Ų�ѯ        *******\n");
		printf("               *****        2.���������        *******\n");
		printf("               *****        3.�������˲�ѯ      *******\n");
     	printf("               ****************************************\n");	
		scanf("%d",&flag);
		switch(flag){
			case 1:{if(findByID())printf("�����޴˱�ţ�\n");break;}
			case 2:{if(findByDate())printf("�����޴����ڣ�\n");break;}
			case 3:{if(findByName())printf("�����޴˾����ˣ�\n");break;}
		}
}
void findAll(){
	printf("��ǰ���:\n");
	printf("�������    ���ݱ��      ������λ����        �ֿ�-��λ      �������       ������\n");
	for(int i=1;i<=COUNT;i++){
		//printf("������ڣ�%s ���ݱ�ţ�%s ������λ���ƣ�%s �ֿ�-��λ��%s ���������%d �����ˣ�%s\n",com[i].date,com[i].code,com[i].orga,com[i].repo,com[i].count,com[i].name);
	printf(
	"%s %s    %s           %s      %d          %s\n",
	com[i].date,com[i].code,com[i].orga,com[i].repo,com[i].count,com[i].name);
	}
}
void file_input(){
	FILE *fp;
	if((fp=fopen("data.txt","r+"))==NULL){
		printf("�޷����ļ�!�����Ƿ��������ļ���\n"); 
	}else{
		printf("�ļ��򿪳ɹ�����ʼ����...\n");
		int i=1;
		while(~fscanf(fp,"%s%c%s%c%s%c%s%c%d%c%s",
		com[i].date,&t,com[i].code,&t,com[i].orga,&t,com[i].repo,&t,&com[i].count,&t,com[i].name)){
			printf("��%d��¼��ɹ�\n",i);
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
	printf("��������Ҫ¼�������:\n");
	int cnt;
	scanf("%d",&cnt);
	for(int i=1;i<=cnt;i++){
		printf("��¼���%d��\n",i);
		scanf("%s%c%s%c%s%c%s%c%d%c%s",com[i].date,&t,com[i].code,&t,com[i].orga,&t,com[i].repo,&t,&com[i].count,&t,com[i].name);
		COUNT++;
	}
}
void input(){
	int flag;
	printf("��ѡ��¼����Ʒ��ʽ:\n");
	printf("1.�ֹ�¼��   2.�ļ�����\n");
	scanf("%d",&flag);
	if(flag==1){
		hand_input();	
	}else{
		file_input();
	}
}
