#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define N 8//��Ȩֵ��Ҷ�ӽڵ�����������Ҫ������ַ���
#define M 2*N-1//N����Ҷ�ڵ㹹��Ĺ���������2N-1�����

#define MAX 10000

typedef char TElemType;


//˳��洢�ṹ

typedef struct{
	TElemType data;
	unsigned int weight;//Ȩֵֻ��������
	int parent;
	int lchild;
	int rchild;
}HTNode;   //*Huffmantree


typedef HTNode HuffmanTree[M + 1];//0�úŵ�Ԫ��ʹ��
//�洢ÿ���ַ��Ĺ������������¼��Ӧ���ַ�ֵch�����볤��len

typedef struct
{
	char ch;
	char bits[N + 1];//����
	int len;
}CodeNode;
typedef CodeNode HuffmanCode[N + 1];//0�ŵ�Ԫ��ʹ��
//�����������

void createHuffmanTree(HuffmanTree HT, HuffmanCode HC, int* w, int n, char str[])
{
	int i;
	void select(HuffmanTree HT, int k, int &s1, int &s2);//select��������
	if (n <= 1)
		return;
	//��������ֵ
	for (i = 1; i <= n; i++)
	{
		//HTǰn�������洢Ҷ�ӽڵ㣬���Ǿ�����Ȩֵ
		HT[i].weight = w[i];
		HT[i].lchild = 0;
		HT[i].parent = 0;
		HT[i].rchild = 0;
	}
	for (i = n + 1; i <= M; i++)
	{
		//HT��m-n�������洢�м�ڵ㣬���һ��������Ȼ���������ĸ����
		HT[i].weight = 0;
		HT[i].lchild = 0;
		HT[i].parent = 0;
		HT[i].rchild = 0;
	}

	//��ʼ��������������������HT��m-n���ڵ�Ĺ��̣�ֱ�����������ڵ㡣�ù������㷨
	for (i = n + 1; i < M; i++)
	{
		int s1, s2;
		select(HT, i - 1, s1, s2);/*��HT[1...i-1]��ѡ��parentΪ0����Ȩֵ��С��2�Ľڵ㣬����ŷֱ�Ϊs1,s2��parent
								  ��Ϊ0˵���ýڵ��Ѿ������˹����ˣ��ʲ����ٿ���*/
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	for (i = 0; i <= n; i++)
		HC[i].ch = str[i];//�����Ӧ�����ַ�
}


//��HT[1...k]��ѡ��parentΪ0����Ȩֵ��С��2��㣬����ŷֱ�Ϊs1,s2,parent��Ϊ0
//˵���ýڵ��Ѿ����빹���ˣ��ʲ����ٿ���

void select(HuffmanTree HT, int k, int &s1, int &s2)
{
	//����s1��Ӧ��Ȩֵ����<=s2��Ӧ��Ȩֵ
	unsigned int tmp = MAX, tmpi = 0;
	int i;
	for (i = 1; i <= k; i++)
	{
		if (!HT[i].parent)
		{
			//parent����Ϊ0
			if (tmp > HT[i].weight)
			{
				tmp = HT[i].weight;//tmp���Ϊ��С��weight
				tmpi = i;
			}
		}
	}
	s1 = tmpi;
	tmp = MAX;
	tmpi = 0;
	for (i = 1; i <= k; i++)
	{
		if ((!HT[i].parent) && i != s1)
		{
			//parentΪ0
			if (tmp > HT[i].weight)
			{
				tmp = HT[i].weight;
				tmpi = i;
			}
		}
	}
	s2 = tmpi;
}

//��ӡ���������洢�ṹ
void printHuffmanTree(HuffmanTree HT, char ch[])
{
	printf("\n");
	printf("data,weifht,parent,lchilde,rchild\n");
	for (int i = 1; i <= M; i++)
	{
		if (i > N)
		{
			printf("   _,%5d,%5d,%5d,%5d\n", HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
		}
		else
		{
			printf("   %c,%5d,%5d,%5d,%5d\n", HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);

		}
	}
	printf("\n");
}

//�������������Ҷ�����������ÿ���ַ��Ĺ���������
void encodingHuffmanCode(HuffmanTree HT, HuffmanCode HC)
{
	char tmp[N];
	tmp[N - 1] = '\0';//����Ľ�����
	int start, c, f;
	for (int i = 1; i <= N; i++)
	{
		//���ڵ�i���������ַ����ڸ�Ȩֵ����Ҷ�ڵ�
		start = N - 1;//�������ɺ�start��ָ��������ʼλ��
		c = i;
		f = HT[i].parent;
		while (f)//f!=0,��f���Ǹ��ĸ��ڵ�
		{
			if (HT[f].lchild == c)
			{
				tmp[--start] = '0';
			}
			else
			{
				//HT[f].rchild==c,ע�⣺���ڹ���������ֻ����Ҷ�ӽڵ�Ͷ�Ϊ2�Ľڵ㣬���Գ���Ҷ�ӽڵ㣬�ڵ�һ��������2����֧
				tmp[--start] = '1';
			}
			c = f;
			f = HT[f].parent;
		}
		strcpy(HC[i].bits, &tmp[start]);//��tmp�ĺ�n-start��Ԫ�طָ�H[i]ָ����ַ���
		HC[i].len = N - start;
	}
}

//��ӡ�����������

void printfHuffmanCoding(HuffmanCode HC, char ch[])
{
	printf("\n");
	for (int i = 1; i <= N; i++)
	{
		printf("%c:%s\n", ch[i], HC[i].bits);
	}
	printf("\n");
}

//������ĵ��Ľ��б���

void coding(HuffmanCode HC, char* str)
{
	int i;
	while (*str)
	{
		//�Ե������ַ���һ���ɱ���
		for (i = 1; i <= N; i++)
		{
			if (HC[i].ch == *str)
			{
				printf("%s", HC[i].bits);
				break;
			}

		}
		str++;
	}
	printf("\n");
}

void decodingHuffmanCode(HuffmanTree HT, char* ch, char testDecodingStr[], int len, char* result)
{
	int p = M;
	int i = 0;
	int j = 0;
	while (i < len)
	{
		if (testDecodingStr[i] == '0')
		{
			p = HT[p].lchild;
		}
		if (testDecodingStr[i] == '1')
		{
			p = HT[p].lchild;
		}
		if (p <= N)
		{
			result[j] = ch[p];
			j++;
			p = M;
		}
		i++;
	}
	result[j] = '\0';
}


int main()
{
	HuffmanTree HT;
	TElemType ch[N + 1];
	int W[N + 1];
	printf("������%d���ַ��Լ����ַ���Ӧ��Ȩֵ�磨��a��5��\n", N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%c,%d", &ch[i], &W[i]);
		getchar();
	}

	HuffmanCode HC;
	createHuffmanTree(HT, HC, W, N, ch);
	printHuffmanTree(HT, ch);

	encodingHuffmanCode(HT, HC);
	printfHuffmanCoding(HC, ch);

	char* str = "abaccda";
	printf("%s�ı����ǣ�", str);
	coding(HC, str);
	char testDecodingStr[] = "00011000011110111011110001";
	int testDecodingStrLen = 26;
	printf("����%s��Ӧ���ַ����ǣ�", testDecodingStr);
	char result[30];
	decodingHuffmanCode(HT, ch, testDecodingStr, testDecodingStrLen, result);
	printf("%s\n", result);
	system("pause");
	return 0;
}
