//����������V1.1
//�������ͣ�
//	1��������������任
//  2����ĸ����ĸ��任���Ҵ�Сд����ͨ
//  3������'.'�ͷ���'!'���б任
//time��16:04 2019/10/23
 
//�ҵ��������֣�6 
//���������ֿ��ǵ�Խ�����⣬����̫�� 
#define lucky_num 6
//����Ĭ����󳤶ȣ�20 
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
		}else if(mylock[i]>='0'&&mylock[i]<='9'){
		//�����ֵı���		
			mylock[i]+=lucky_num;
			//Խ����ѭ����0			
			if(mylock[i]>'9'){
				mylock[i] = mylock[i]-('9'-'0'+1);
			} 
		}else if(mylock[i]>='a'&&mylock[i]<='z'){
		//��Сд��ĸ�ı���
			int locked_num = mylock[i]-'a'+lucky_num;
			if(locked_num>'z'-'a'){
				locked_num -= 'z'-'a'+1;
			}
			mylock[i] = locked_num+'a';
		}else if(mylock[i]>='A'&&mylock[i]<='Z'){
		//�Դ�д��ĸ�ı���
			mylock[i]+=lucky_num;
			//Խ����ѭ����A	
			if(mylock[i]>'Z'){
				mylock[i] = mylock[i]-1-'Z'+'A';
			}
		}else if(mylock[i]=='.'){
		//���ַ�'.'�ı���
			mylock[i]='!';
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
		}else if(mylock[i]>='0'&&mylock[i]<='9'){
		//�����ֵĽ���
			mylock[i]-=lucky_num;
			//Խ����ѭ����9		
			if(mylock[i]<'0'){
				mylock[i] = mylock[i]+('9'-'0'+1);
			} 
		}else if(mylock[i]>='a'&&mylock[i]<='z'){
		//��Сд��ĸ�Ľ���
			int unlocked_num = mylock[i]-'a'-lucky_num;
			if(unlocked_num<'a'-'a'){
				unlocked_num += 'z'-'a'+1;
			}
			mylock[i] = unlocked_num+'a';
		}else if(mylock[i]>='A'&&mylock[i]<='Z'){
		//�Դ�д��ĸ�Ľ���
			mylock[i]-=lucky_num;
			//Խ����ѭ����Z	
			if(mylock[i]<'A'){
				mylock[i] = mylock[i]+('Z'-'A'+1);
			}
		}else if(mylock[i]=='!'){
		//���ַ�'!'�ı���
			mylock[i]='.';
		}
	}
	printf("���ܺ������:\n");
	printf("---%s---\n",mylock);
}
//�������ѡ����
void selector(){
	char selector_num;
	while(1){
		printf("===============================================\n");
		printf("��ӭ��������������V1.1���˳��������²�����\n");
		printf("1������\n");
		printf("2������\n");
		printf("3���˳�\n");
		printf("�������Ӧ���֣�\n");
		scanf("%c",&selector_num);
		if(selector_num=='\n'){
			scanf("%c",&selector_num);
		} 
		if(selector_num=='3'){
			printf("�˳��ɹ�");
			break;
		}else if(selector_num=='1'){
			encode();
		}else if(selector_num=='2'){
			decode();
		}else{
			printf("������������������1��2��3\n");
		}
	}
} 
