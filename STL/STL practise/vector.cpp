#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> test;//����int���vector����test
	vector<int>::iterator it;//����ָ��Int��vector�ĵ�����it
	test.push_back(7);//push_back()��vector�����ĺ������Ԫ�ص����
	it = test.begin();//begin()ָ��vector�������׵�ַ
	cout << test[0] << " " << *(it + 0) << endl;//vector[i]��*(vi.begin()+i)�ǵȼ۵�
	test.pop_back();//ɾ��vector��βԪ��
	test.size();//����vector��Ԫ�ظ���
	test.clear();//���vector�е�Ԫ�أ�ʱ�临�Ӷ�ΪO��n)
	test.insert(it, 1);//�ڵ�����it������Ԫ��1
	test.erase();//ɾ��������It����Ԫ��
}