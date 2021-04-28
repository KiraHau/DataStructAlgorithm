#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> test;//定义int类的vector容器test
	vector<int>::iterator it;//定义指向Int类vector的迭代器it
	test.push_back(7);//push_back()在vector容器的后面进行元素的添加
	it = test.begin();//begin()指向vector容器的首地址
	cout << test[0] << " " << *(it + 0) << endl;//vector[i]与*(vi.begin()+i)是等价的
	test.pop_back();//删除vector的尾元素
	test.size();//返回vector的元素个数
	test.clear();//清空vector中的元素，时间复杂度为O（n)
	test.insert(it, 1);//在迭代器it处插入元素1
	test.erase();//删除迭代器It处的元素
}