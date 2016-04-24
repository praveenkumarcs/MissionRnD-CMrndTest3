/*
Given a Tree which consists of operands and operators ,Solve the Tree and return the result
The tree will have special nodes of type enode which will have 3 fields
data => String of 5 chars .which can be either a operator or operand 
If its a operator its values will be one of the 3 following strings "+" , "-" , "*".
If its a operand its values will be any number from -9999 to 99999 in its respective string format;
Left and Right pointers will point to either NULL or another enode
Only the leaf nodes will have operand values .

Example 1:
    +
   / \
  4   5 
The Result expression is : 4+5 ,Ans is 9

Example 2:
        *
       / \
      -   5
     / \
    7   2

The Result expression is : (7-2) * 5  ,Ans is 25

Example 3:
       +
     /   \
    *     -  
   / \   / \
  7   2  4  *
           / \
          2   1
  
The Result expression is : (7*2) + (4-(2*1)) =>14+2 =>16 ,Ans is 16 

Constraints : 
Total number of enodes will be <=20 for 50% of Test cases
Data value will only have "0"<=data<="99999" values for 50% of cases .
Data value for operators will have sign as first character and \0 as next character .

Input :
Root node of a Tree of type enode
Output :
Return Final answer or -1 for Null inputs

Note :
->Dont Create an Extra Array/String ,or else your solution would receive 20%-40% Cut in the Marks you got .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

//data can be accessed using root->data;
struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};
typedef struct enode *tptr;
char postfix[100];

long operands[500] = { 0 };
int  top = -1;;
#define maxsize 500

struct stack{
	char c;
	long data;
};

struct stack s[maxsize] = {0};

void addstack(char ch){
	top++;
	s[top].c = ch;
}

long delstack(){
	long res; 
	res = s[top].c;
	top--;
	return res;
}

void addData(int dat){
	top++;
	s[top].data = dat;
}





int isOperator(char *data){
	return 0;
}
int isOperand(char *data){
	return 0;
}
int getOperand(char *data){
	//converts data string to an integer "123" => 123
	long sum = 0;
	int i = 0;
	if (data[i] = '-')
		i = 1;
	else
		i = 0;
	while (data[i] != '\0'){
		sum = sum * 10 + (data[i] - 48);
		i++;
	}

	if (data[i] == '-')
		return sum*-1;
	else
		return sum;
}
int k = 0;
void   convertOperands(tptr root){

	if (root != NULL){
		convertOperands(root->left);
		if (root->left == NULL && root->right == NULL)
			operands[k++] = getOperand(root->data);
		convertOperands(root->right);
	}

}




int i = 0;
int j = 0;

void convertToPostfix(tptr root){

	if (root != NULL){
		convertToPostfix(root->left);
		convertToPostfix(root->right);
		if (root->left == NULL && root->right == NULL)
			postfix[i++] = j++;
		else
			postfix[i++] = root->data[0];
	}
	postfix[i] = '\0';
}


//Helper Functions end
int solve_tree(struct enode *root){

	long i, op1, op2, res;
	int k = 0;

	if (root == NULL)
    return -1;

	convertOperands(root);
	convertOperands(root);

	top = -1;
	i = 0;
	while (postfix[i] != '\0'){
		if (postfix[i] != '-' || postfix[i] != '*' || postfix[i] != '+')
			addData(operands[k++]);
		else{
			switch (postfix[i])
			{
			case '+':
				op2 = delstack();
				op1 = delstack();
				res = op1 + op2;
				break;
			case '-':
				op2 = delstack();
				op1 = delstack();
				res = op1 - op2;
				break;
			case '*':
				op2 = delstack();
				op1 = delstack();
				res = op1 * op2;
				break;

			default:
				break; 
			}
			addData(res);
		}
		i++;
	}
	res = delstack();
	return res;

}

