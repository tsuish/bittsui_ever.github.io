//编码解码程序V1.0 
//加密类型：ASCII+666
//21:32 2019/10/21

//出现bug：对ASCII码越界错误未做处理 
 
//我的幸运数字：6 
#define lucky_num 6
//密码默认最大长度 
#define lock_longth 20
#include <stdio.h>
//加密密码函数
void encode();
//解密密码函数
void decode();
//编码解码选择函数
void selector();

int main(){
	selector();
	return 0;
}
//加密密码函数
void encode(){
	int i;
	printf("请输入要加密的密码:\n");
	//lock_longth：我的密码
	char mylock[lock_longth];
	scanf("%s",&mylock);
	for(i=0;i<lock_longth;i++){
		if(mylock[i]=='\0'){
			break;
		}else{
			mylock[i]+=lucky_num;
		}
	}
	printf("加密后的密码:\n");
	printf("---%s---\n",mylock);
}
//解密密码函数
void decode(){
	int i;
	printf("请输入要解密的密码:\n");
	//lock_longth：我的密码
	char mylock[lock_longth];
	scanf("%s",&mylock);
	for(i=0;i<lock_longth;i++){
		if(mylock[i]=='\0'){
			break;
		}else{
			mylock[i]-=lucky_num;
		}
	}
	printf("解密后的密码:\n");
	printf("---%s---\n",mylock);
}
//编码解码选择函数
void selector(){
	int selector_num;
	while(1){
		printf("欢迎来到编码解码程序V1.0，此程序有以下操作：\n");
		printf("1、编码\n");
		printf("2、解码\n");
		printf("3、退出\n");
		printf("请输入对应数字：\n");
		scanf("%d",&selector_num);
		if(selector_num==3){
			printf("退出成功");
			break;
		}else if(selector_num==1){
			encode();
		}else if(selector_num==2){
			decode();
		}else{
			printf("输入有误！\n");
		}
	}
} 
