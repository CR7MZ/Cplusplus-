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
		priority_queue(Iterator first, Iterator last)//将输入con中的数据调整成堆，用向下排序法
			: con(first,last)
		{
		   int root = ((con.size() -2)>>1);//因为想要将数组中无序的数，变为堆，就要满足树从下往上都是堆，所以从最后一个非叶子节点开始向下调整。
			//这里的((con.size() -2)>>1)代表的是通过con中最后一个数据的下标来找到其父节点。这个式子实际上是：((con.size()-1)-1)/2
		   for (; root >= 0; root--)//从最后一个非叶子节点开始向根节点遍历，依次进行向下排序。
			{
				AdjustDown(root);
			}
		}
		void push(const T& data)//在数组后面插入一个元素，为了不破坏大堆或者小堆的结构，
			//从最后一个数开始进行一遍向上排序。
		{
			con.push_back(data);
			AdjustUp(con.size()-1);
		}
		void pop()//删除第一个元素。因为底层用的是vector，所以不能直接删除，应将头元素和最后一个元素交换，
			//再进行数组的尾删操作，因为删除后改变了堆，所以从根节点进行向下排序。
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
		void AdjustDown(int parent)//堆的向下调整法
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
		void AdjustUp(int child) // 堆的向上调整法
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