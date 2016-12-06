#include "List.h"


int main()
{
	List l1;
	l1.insert(11, "HTC");
	l1.insert(22, "Asus");
	l1.insert(33, "Huawei");
	l1.insert(44, "SamSung");
	l1.insert(55, "iPhone");
	cout << l1;

	l1.deleteMostRecent();
	cout << l1;

	system("pause");
	return 0;
}
