//����������V1.0 
//�������ͣ�ASCII+666
//21:32 2019/10/21

//����bug����ASCII��Խ�����δ������ 
 
//�ҵ��������֣�6 
#define lucky_num 6
//����Ĭ����󳤶� 
#define lock_longth 20
#include <stdio.h>
//�������뺯��
void encode();
//�������뺯��
void decode();
//�������ѡ����
void selector();

int main(){
	selector();
	return 0;
}
//�������뺯��
void encode(){
	int i;
	printf("������Ҫ���ܵ�����:\n");
	//lock_longth���ҵ�����
	char mylock[lock_longth];
	scanf("%s",&mylock);
	for(i=0;i<lock_longth;i++){
		if(mylock[i]=='\0'){
			break;
		}else{
			mylock[i]+=lucky_num;
		}
	}
	printf("���ܺ������:\n");
	printf("---%s---\n",mylock);
}
//�������뺯��
void decode(){
	int i;
	printf("������Ҫ���ܵ�����:\n");
	//lock_longth���ҵ�����
	char mylock[lock_longth];
	scanf("%s",&mylock);
	for(i=0;i<lock_longth;i++){
		if(mylock[i]=='\0'){
			break;
		}else{
			mylock[i]-=lucky_num;
		}
	}
	printf("���ܺ������:\n");
	printf("---%s---\n",mylock);
}
//�������ѡ����
void selector(){
	int selector_num;
	while(1){
		printf("��ӭ��������������V1.0���˳��������²�����\n");
		printf("1������\n");
		printf("2������\n");
		printf("3���˳�\n");
		printf("�������Ӧ���֣�\n");
		scanf("%d",&selector_num);
		if(selector_num==3){
			printf("�˳��ɹ�");
			break;
		}else if(selector_num==1){
			encode();
		}else if(selector_num==2){
			decode();
		}else{
			printf("��������\n");
		}
	}
} 
