#include<iostream>
#include<vector>
using namespace std;
namespace bite
{
	template<class T,class Container=vector<T>,class compare =less<T>>
	class priority_queue
	{
	public:
		priority_queue()
			:con()
		{}
		template<class Iterator>
		priority_queue(Iterator first, Iterator last)//������con�е����ݵ����ɶѣ�����������
			: con(first,last)
		{
		   int root = ((con.size() -2)>>1);//��Ϊ��Ҫ�������������������Ϊ�ѣ���Ҫ�������������϶��Ƕѣ����Դ����һ����Ҷ�ӽڵ㿪ʼ���µ�����
			//�����((con.size() -2)>>1)�������ͨ��con�����һ�����ݵ��±����ҵ��丸�ڵ㡣���ʽ��ʵ�����ǣ�((con.size()-1)-1)/2
		   for (; root >= 0; root--)//�����һ����Ҷ�ӽڵ㿪ʼ����ڵ���������ν�����������
			{
				AdjustDown(root);
			}
		}
		void push(const T& data)//������������һ��Ԫ�أ�Ϊ�˲��ƻ���ѻ���С�ѵĽṹ��
			//�����һ������ʼ����һ����������
		{
			con.push_back(data);
			AdjustUp(con.size()-1);
		}
		void pop()//ɾ����һ��Ԫ�ء���Ϊ�ײ��õ���vector�����Բ���ֱ��ɾ����Ӧ��ͷԪ�غ����һ��Ԫ�ؽ�����
			//�ٽ��������βɾ��������Ϊɾ����ı��˶ѣ����ԴӸ��ڵ������������
		{
			if (empty())
				return;
			swap(con.front(), con.back());
			con.pop_back();
			AdjustDown(0);
		}
		size_t size()const
		{
			return con.size();
		}
		bool empty()const 
		{
			return con.empty();
		}
		const T& top()const
		{
			return con.front();
		}
	private:
		void AdjustDown(int parent)//�ѵ����µ�����
		{
			int child = (parent * 2) + 1;
			while (child < size())
			{
				if (child + 1 < size() && com(child, child + 1))
					child += 1;
				if (com(con[parent], con[child]))
				{
					swap(con[parent], con[child]);
					parent = child;
					child = (parent * 2) + 1;
				}
				else
					break;
			}
		}
		void AdjustUp(int child) // �ѵ����ϵ�����
		{
			int parent = ((child - 1) >> 1);
			while (child)
			{
				if (com(con[parent], con[child]))
				{
					swap(con[parent], con[child]);
					child = parent;
					parent = ((child - 1) >> 1);
				}
				else
					return;
			}	
		}
	private:
		Container con;
		compare com;
	};
}
void Testpriority_queue()
{
	int arr[] = { 8 , 1 , 9 , 3 , 6 , 4 , 5 , 0 };
	bite::priority_queue<int> Pq(arr,arr+sizeof(arr)/sizeof(arr[0]));
	cout << Pq.top() << endl;
	Pq.pop();
	cout << Pq.top() << endl;
	Pq.push(10);
	cout << Pq.top() << endl;
}
int main()
{
	Testpriority_queue();
	system("pause");
	return 0;
}