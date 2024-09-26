//C program to create a nfa for L={w/w ends with 01 over{0,1}
#include<stdio.h>
enum states {q0, q1, qf};
enum states delta(enum states s, char ch) {
	enum states curr_state;
	switch(s) {
		case q0:
			if(ch=='0') {
				curr_state = q1;
			}
			break;
		case q1:
			if(ch=='1') {
				curr_state = qf;
			}
		    break;
		case qf:
			if(ch=='0') {
				curr_state = qf;
			} else {
				curr_state = qf;
			}
	}
	return curr_state;
}
int main() {
	char input[20];
	enum states curr_state=q0;
	int i=0;
	printf("Enter the string\n");
	gets(input);
	char ch=input[++i];
	while(ch!='\0') {
		curr_state=delta(curr_state,ch);
		ch=input[++i];
	} if(curr_state==qf) {
		printf("Accepted");
	} else {
		printf("Rejected");
	}
	return 0;
}
