#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void find(char infix[1000],char prefix[1000],int ci){
	char check = prefix[0];
	switch(check){
		case '$': 
		case '*':
		case '/':
		case '+':
		case '-':
		case '&':
		case '|':
		case '!': {
			int count = 0;
			for(int i = 0;i<ci;i++)
				if(infix[i] == check){
					count = i;
					break;	
				}
			//printf("%d\n",count);
			char input[1000] = {'\0'},input2[1000] = {'\0'};
			strncpy(input,infix,count);
			strncpy(input2,prefix+1,count);
			//printf("%s,",input);
			//printf("%s\n",input2);
			find(input,input2,count);
			//printf("%s,",infix+1+count);
			//printf("%s\n",prefix+1+count);
			find(infix+1+count,prefix+1+count,ci-count-1);
			break;
		}
		case '\0':
			return;
		default:
			break;
	}
	printf(" %c", check);
}
int main(){
	char data,buf;
	char infix[1000] = {} ,prefix[1000] = {};
	int ci = 0,i = 0;
	while(buf != '\n'){
		scanf("%c%c",&data,&buf);
		infix[ci] = data;
		ci++;
	}
	buf = '\0';
	while(buf != '\n'){
		scanf("%c%c",&data,&buf);
		prefix[i] = data;
		i++;
	}
//	printf("%s\n",infix);
//	printf("%d",ci);
//	printf("%s\n",prefix);
	printf("INFIX   =>");
	for(i = 0;i<ci;i++)
		printf(" %c",infix[i]);
	printf("\nPREFIX  =>");
	for(i = 0;i<ci;i++)
		printf(" %c",prefix[i]);
	printf("\nPOSTFIX =>");
	find(infix,prefix,ci);		
	printf("\n");
	return 0;
}
