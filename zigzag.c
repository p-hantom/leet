#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* str, int row) {
    int num=strlen(str),col,x;
    if(row==1)
    	col=num;
    else if(num<=2*row-2){
    	if(num<=row)
    		col=1;
    	else 
    		col=1+num-row;
	}
		
    else{	
		col=num/(2*row-2)*(row-1);
		x=num%(2*row-2);
		if(x!=0){	
			if(x<=row)
				col++;
			else
				col+=1+(x-row);
		}
	}
	//char a[row][20];


	char *p=(char *)malloc(row*col*sizeof(char));
	
	int i,j,k;
	
	//initialize
	for(i=0;i<row*col;i++){
		p[i]=' ';
	}
	
	int flag=1;//which represents that the next character can be put downwards
	i=0;
	j=0;
	for(k=0;k<num;k++){
		//a[i][j]=str[k];
		
		//printf("\n");
		p[i*col+j]=str[k];
		printf("%c i=%d,j=%d\n",p[i*col+j],i,j);
		if(row==1){
			j++;
		}
		else{		
			if(flag){
				i++;
				if(i==(row-1)){
					flag=0;
				}
			}
			else{
				i--;
				j++;
				if(i==0)
					flag=1;	
			}
		}
	}
//
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
		//	printf("%c ",a[i][j]);
			printf("%c ",p[i*col+j]);
		}
		printf("\n");
	}
//	printf("%s\n",p);
//	printf("%s\n",str);
	j=0;
	char *s;
	s=(char*)malloc((1+strlen(str))*sizeof(char));
	for(i=0;i<row*col;i++){
		if(p[i]!=' '){
			s[j]=p[i];
			j++;
		}
	}
	s[j]='\0';
	free(p);
	return s;
}

int main(){
	int row,col;
	char *pstr;
	//scanf("%s",str);
	//scanf("%d",&row);
	pstr=convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.",2);
	printf("%s\n\n",pstr);

	pstr=convert("abcdefghijklmn",5);
	printf("%s\n\n",pstr);
	
	//free(str);
	
	return 0;
}


