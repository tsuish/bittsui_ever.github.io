//编码解码程序V1.1
//加密类型：
//	1、数字在数字里变换
//  2、字母在字母里变换，且大小写不互通
//  3、符号'.'和符合'!'进行变换
//time：16:04 2019/10/23
 
//我的幸运数字：6 
//（幸运数字考虑到越界问题，不能太大） 
#define lucky_num 6
//密码默认最大长度：20 
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
		}else if(mylock[i]>='0'&&mylock[i]<='9'){
		//对数字的编码		
			mylock[i]+=lucky_num;
			//越界则循环到0			
			if(mylock[i]>'9'){
				mylock[i] = mylock[i]-('9'-'0'+1);
			} 
		}else if(mylock[i]>='a'&&mylock[i]<='z'){
		//对小写字母的编码
			int locked_num = mylock[i]-'a'+lucky_num;
			if(locked_num>'z'-'a'){
				locked_num -= 'z'-'a'+1;
			}
			mylock[i] = locked_num+'a';
		}else if(mylock[i]>='A'&&mylock[i]<='Z'){
		//对大写字母的编码
			mylock[i]+=lucky_num;
			//越界则循环到A	
			if(mylock[i]>'Z'){
				mylock[i] = mylock[i]-1-'Z'+'A';
			}
		}else if(mylock[i]=='.'){
		//对字符'.'的编码
			mylock[i]='!';
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
		}else if(mylock[i]>='0'&&mylock[i]<='9'){
		//对数字的解码
			mylock[i]-=lucky_num;
			//越界则循环到9		
			if(mylock[i]<'0'){
				mylock[i] = mylock[i]+('9'-'0'+1);
			} 
		}else if(mylock[i]>='a'&&mylock[i]<='z'){
		//对小写字母的解码
			int unlocked_num = mylock[i]-'a'-lucky_num;
			if(unlocked_num<'a'-'a'){
				unlocked_num += 'z'-'a'+1;
			}
			mylock[i] = unlocked_num+'a';
		}else if(mylock[i]>='A'&&mylock[i]<='Z'){
		//对大写字母的解码
			mylock[i]-=lucky_num;
			//越界则循环到Z	
			if(mylock[i]<'A'){
				mylock[i] = mylock[i]+('Z'-'A'+1);
			}
		}else if(mylock[i]=='!'){
		//对字符'!'的编码
			mylock[i]='.';
		}
	}
	printf("解密后的密码:\n");
	printf("---%s---\n",mylock);
}
//编码解码选择函数
void selector(){
	char selector_num;
	while(1){
		printf("===============================================\n");
		printf("欢迎来到编码解码程序V1.1，此程序有以下操作：\n");
		printf("1、编码\n");
		printf("2、解码\n");
		printf("3、退出\n");
		printf("请输入对应数字：\n");
		scanf("%c",&selector_num);
		if(selector_num=='\n'){
			scanf("%c",&selector_num);
		} 
		if(selector_num=='3'){
			printf("退出成功");
			break;
		}else if(selector_num=='1'){
			encode();
		}else if(selector_num=='2'){
			decode();
		}else{
			printf("输入有误！请输入数字1、2、3\n");
		}
	}
} 
