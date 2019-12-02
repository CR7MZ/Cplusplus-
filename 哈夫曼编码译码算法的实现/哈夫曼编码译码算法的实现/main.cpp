#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define N 8//带权值的叶子节点数或者是需要编码的字符数
#define M 2*N-1//N个子叶节点构造的哈夫曼数有2N-1个结点

#define MAX 10000

typedef char TElemType;


//顺序存储结构

typedef struct{
	TElemType data;
	unsigned int weight;//权值只能是正数
	int parent;
	int lchild;
	int rchild;
}HTNode;   //*Huffmantree


typedef HTNode HuffmanTree[M + 1];//0好号单元不使用
//存储每个字符的哈夫曼码表，并记录对应的字符值ch及编码长度len

typedef struct
{
	char ch;
	char bits[N + 1];//编码
	int len;
}CodeNode;
typedef CodeNode HuffmanCode[N + 1];//0号单元不使用
//构造哈夫曼树

void createHuffmanTree(HuffmanTree HT, HuffmanCode HC, int* w, int n, char str[])
{
	int i;
	void select(HuffmanTree HT, int k, int &s1, int &s2);//select函数声明
	if (n <= 1)
		return;
	//对树赋初值
	for (i = 1; i <= n; i++)
	{
		//HT前n个分量存储叶子节点，他们均带有权值
		HT[i].weight = w[i];
		HT[i].lchild = 0;
		HT[i].parent = 0;
		HT[i].rchild = 0;
	}
	for (i = n + 1; i <= M; i++)
	{
		//HT后m-n个分量存储中间节点，最后一个分量显然是整棵树的跟结点
		HT[i].weight = 0;
		HT[i].lchild = 0;
		HT[i].parent = 0;
		HT[i].rchild = 0;
	}

	//开始构建哈夫曼树，即创建HT的m-n个节点的过程，直至创建出根节点。用哈夫曼算法
	for (i = n + 1; i < M; i++)
	{
		int s1, s2;
		select(HT, i - 1, s1, s2);/*在HT[1...i-1]里选择parent为0的且权值最小的2的节点，其序号分别为s1,s2，parent
								  不为0说明该节点已经参与了构造了，故不许再考虑*/
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	for (i = 0; i <= n; i++)
		HC[i].ch = str[i];//保存对应编码字符
}


//在HT[1...k]里选择parent为0的且权值最小的2结点，其序号分别为s1,s2,parent不为0
//说明该节点已经参与构造了，故不许再考虑

void select(HuffmanTree HT, int k, int &s1, int &s2)
{
	//假设s1对应的权值总是<=s2对应的权值
	unsigned int tmp = MAX, tmpi = 0;
	int i;
	for (i = 1; i <= k; i++)
	{
		if (!HT[i].parent)
		{
			//parent必须为0
			if (tmp > HT[i].weight)
			{
				tmp = HT[i].weight;//tmp最后为最小的weight
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
			//parent为0
			if (tmp > HT[i].weight)
			{
				tmp = HT[i].weight;
				tmpi = i;
			}
		}
	}
	s2 = tmpi;
}

//打印哈夫曼树存储结构
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

//创建编码表，从子叶到根逆向求解每个字符的哈夫曼编码
void encodingHuffmanCode(HuffmanTree HT, HuffmanCode HC)
{
	char tmp[N];
	tmp[N - 1] = '\0';//编码的结束符
	int start, c, f;
	for (int i = 1; i <= N; i++)
	{
		//对于第i个待编码字符即第个权值的子叶节点
		start = N - 1;//编码生成后，start将指向编码的起始位置
		c = i;
		f = HT[i].parent;
		while (f)//f!=0,即f不是根的父节点
		{
			if (HT[f].lchild == c)
			{
				tmp[--start] = '0';
			}
			else
			{
				//HT[f].rchild==c,注意：由于哈夫曼树中只存在叶子节点和度为2的节点，所以除开叶子节点，节点一定有左右2个分支
				tmp[--start] = '1';
			}
			c = f;
			f = HT[f].parent;
		}
		strcpy(HC[i].bits, &tmp[start]);//将tmp的后n-start个元素分给H[i]指向的字符串
		HC[i].len = N - start;
	}
}

//打印哈夫曼编码表

void printfHuffmanCoding(HuffmanCode HC, char ch[])
{
	printf("\n");
	for (int i = 1; i <= N; i++)
	{
		printf("%c:%s\n", ch[i], HC[i].bits);
	}
	printf("\n");
}

//对输入的电文进行编码

void coding(HuffmanCode HC, char* str)
{
	int i;
	while (*str)
	{
		//对电文中字符逐一生成编码
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
	printf("请输入%d个字符以及该字符对应的权值如（：a，5）\n", N);
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
	printf("%s的编码是：", str);
	coding(HC, str);
	char testDecodingStr[] = "00011000011110111011110001";
	int testDecodingStrLen = 26;
	printf("编码%s对应的字符串是：", testDecodingStr);
	char result[30];
	decodingHuffmanCode(HT, ch, testDecodingStr, testDecodingStrLen, result);
	printf("%s\n", result);
	system("pause");
	return 0;
}
