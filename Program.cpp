#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std;

#include "BinarySearchTree_2014468.h"
#include "ThuVien_2014468.h"
#include "Menu_2014468.h"

void ChayChuongTrinh()
{
	int stt, soMenu = 6;
	BSTree root = nullptr;
	do
	{
		stt = ChonMenu(soMenu);
		XuLyMenu(stt, root);
	} while (stt > 0);

}
int main()
{
	ChayChuongTrinh();
	return 0;
}