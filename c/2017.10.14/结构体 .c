# include<stdio.h>

int main(void)
{
	struct stu
{
	char name[20];
	int age;
	int number;
};
	
	struct stu st = {"maaaa", 18, 1707004539};
	struct stu *pst = &st;
	
	printf("%s, %d, %d", st.name, st.age, st.number);
	
	(*pst).age = 188;
	
	return 0;
}
