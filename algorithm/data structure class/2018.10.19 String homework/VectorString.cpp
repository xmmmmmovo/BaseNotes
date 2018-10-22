#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int datatype;

//˳��洢�ַ���ͷ�ļ���ʵ��
typedef struct seqstring
{
    char str[MAXSIZE];
	int length;//����ʵ�ʳ���
}seq;

//�ÿձ�
seq *init(seq *p)
{
	p->length =0;
	return p;
}
//�ַ����������

void display(seq *p)
{
	int i;
	if(p->length ==0)
		printf("�գ�");
	for(i=0;i<p->length ;i++)
	{
		putchar(p->str [i]);
	}
}

//˳�򴮵Ĵ���

seq* great(seq *p)
{
	p->length =0;
    char ch;
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		ch=getchar();
		if(ch!='\n')
		{
			p->str [p->length ]=ch;
			p->length ++;
		}
		else
			break;
	}
	p->str [p->length ]='\0';
	return p;
}
//˳�򴮵Ĳ���

seq *append(seq *p,int i,seq *T)
{
	int k;
	//�Ƿ���������
	if(i<1||i>p->length ||p->length +T->length >MAXSIZE-1)
		printf("cannot insert!\n");
	else
	{
		for(k=p->length -1;k>=i-1;k--)
			p->str [T->length +k]=p->str [k];
		for(k=0;k<T->length ;k++)
			p->str [i+k-1]=T->str [k];
		p->length =p->length +T->length ;
		p->str [p->length ]='\0';
	}
	return p;
}

//˳�򴮵�ɾ��

seq * dele(seq *q,int dele_head,int dele_length)
{
	if(dele_head<1||dele_head>q->length||dele_head+dele_length-1>q->length  )
	{
		printf("�Ƿ���");
		return (NULL);
	}
	int k;
	//��dele_head+dele_length-1��ʼÿ��Ԫ����ǰ��һλ
	for(k=dele_head+dele_length-1;k<q->length ;k++)
		q->str [k-dele_length]=q->str [k];
	q->length =q->length -dele_length;
	q->str [q->length ]='\0';
	return q;
}

//˳�򴩵�����

seq* strconcat(seq *s1,seq *s2)
{
	int i,j;
	seq *p;
	if(s1->length +s2->length >MAXSIZE)
	{
		printf("cannot strconcat!\n");
		return NULL;
	}
	else
	{
		p=(seq*)malloc(sizeof(seq));
		p->length =0;
		for(i=0;i<s1->length ;i++)
		{
			p->str [p->length ]=s1->str [i];
			p->length ++;
		}
		for(j=0;j<s2->length ;j++)
		{
			p->str [p->length ]=s2->str [j];
			p->length ++;
		}
		p->length =s1->length +s2->length ;
		p->str [p->length ]='\0';
	}
	return p;
}

//���Ӵ�

seq *substring(seq *p,int i,int len)
{
		seq *q;
		q=(seq*)malloc(sizeof(seq));
		int k;
	if(i<1||i>p->length ||i+len-1>p->length )
	{
		printf("cannot substring!");
		return NULL;
	}
	else
	{
		for(k=0;k<len;k++)
			q->str [k]=p->str [i+k-1];
		q->length =len;
		q->str [q->length ]='\0';
	}
	return q;
}

int main()
{
	seq *p;
	seq *r;
	seq *p1,*p2;
	p=(seq*)malloc(sizeof(seq));
	r=(seq*)malloc(sizeof(seq));
	p1=(seq*)malloc(sizeof(seq));
	p2=(seq*)malloc(sizeof(seq));
	int x;
	int dele_head,dele_lan;
	int sub_head,sub_lan;
	p=init(p);
	r=init(r);
	p1=init(p1);
	p2=init(p2);
	printf("\n������Ҫ�������ַ��������س�������\n");
	p=great(p);
	printf("\n�����ɹ����������ַ���Ϊ��\n");
	display(p);
	printf("\n������Ҫ������ַ���\n");
	r=great(r);
	printf("\n������Ҫ�����λ�ã�\n");
	scanf("%d",&x);
	p=append(p,x,r);
	printf("\n����ɹ����������ַ���Ϊ��\n");
	display(p);
	printf("\n������Ҫɾ���ĵ�һ��Ԫ�ص�λ�ã�\n");
	scanf("%d",&dele_head);
	printf("\n������Ҫɾ���ĳ��ȣ�\n");
	scanf("%d",&dele_lan);
	p=dele(p,dele_head,dele_lan);
	printf("\nɾ���ɹ���ɾ�����˳��Ϊ��\n");
	display(p);
	printf("\n�����봮1\n");
    getchar();
	p1=great(p1);
	printf("\n�����봮2\n");
	p2=great(p2);
	p1=strconcat(p1,p2);
	printf("���ӳɹ������Ӻ��˳��Ϊ��\n");
	display(p1);
	printf("\n�����������ִ�����λ\n");
	scanf("%d",&sub_head);
	printf("\n�����������ִ��ĳ���\n");
	scanf("%d",&sub_lan);
	p=substring(p,sub_head,sub_lan);
	printf("\n�����ִ�Ϊ��\n");
	display(p);
	system("pause");
	return 0;
}
