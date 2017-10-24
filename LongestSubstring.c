#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LongestSubstring(char * s);
int check(char *sub);
void clear(char *sub,char *s);

int main(){
	char *s="abbsdnmjiii";
	//test
//	char *sub="aabcde";
//	int flag=check(sub);
//	printf("%d\n",flag);
	printf("%d\n",LongestSubstring(s));
	
	return 0;
}

int LongestSubstring(char * s){
	int lenmax=1,lenmax2;
	int len=strlen(s);
	char *sub=(char *)malloc((len+1)*sizeof(char));
	int i,j,cnt=1;
	for(i=0;i<len-1;i++){
		sub[0]=s[i];
		while(cnt<len-i){
			for(j=1;j<=cnt;j++){
				sub[j]=s[i+j];
				printf("s[i+j]=%c\n",s[i+j]);
			}
			sub[j]='\0';
			if(check(sub)){
				lenmax2=strlen(sub);
				if(lenmax2>lenmax){
					lenmax=lenmax2;
				}
			}
			clear(sub,s);
			cnt++;
		}
	} 
	
	return lenmax;
}

int check(char *sub){
	int flag=1,i,j;//flag=1 represents that there's no repeating characters.
	int num=strlen(sub);
	for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			if(sub[i]==sub[j]){
				flag=0;
				return flag;
			}
		}
	}
	
	return flag;
}

void clear(char *sub,char *s){
	int len=strlen(s);
	int i;
	for(i=0;i<len;i++){
		sub[i]='\0';
	}
}
