# include<stdio.h>

bool judge(char op)
{
	if(op == '*' || op == '/')
		return true;
	else
		return false;
}

float medium1(char op, float a, float b)
{
	float med;
	
	if(op == '+')
		med = a + b;
	else
		med = a - b;
	
	return med;
}

float medium2(char op,float a,float b)
{
	float med;
	
	if(op == '*')
		med = a * b;
	else
		med = a / b;
	
	return med;
}

float answer(char op1, char op2, float a, float b, float c)
{
	float med, result;
	
	med = medium2(op1, a, b);
	switch(op2)
	{
		case '+':
			result =  med + c;
			break;
		case '-':
			result = med - c;
			break;
		case '*':
			result = med * c;
			break;
		default:
			result = med / c;
			break;
	}
	
	return result;
}

float Calculation(float a, char op1, float b, char op2, float c) 
{
	float result = 0;
	float med;
	
	if(judge(op1))
	{
		result = answer(op1, op2, a, b, c);
	}
	else
	{
		if(judge(op2))
		{
			result = answer(op2, op1, b, c, a);
		}
		else
		{
			med = medium1(op1, a, b);
			result = medium1(op2, med, c);
		}
	}
	
	return result;
}

int main(void)
{
	float a, b, c;
	char  op1, op2;
	float result;
	
	scanf("%f%c%f%c%f", &a, &op1, &b, &op2, &c);
	result = Calculation(a, op1, b, op2, c); 
	printf("%.2f", result);
	
	return 0;
} 
/*
	作业18
	未考虑其他字符情况 
	2017.12.01 
*/
