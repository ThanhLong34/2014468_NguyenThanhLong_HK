#pragma once
struct NhanVien
{
	// Key
	char mNV[8];
	char ho[12];
	char tenLot[12];
	char ten[12];
	unsigned int namSinh;
	long luong;
};
typedef NhanVien DataType;
struct BSNode
{
	DataType info;
	BSNode* pLeft;
	BSNode* pRight;
};
typedef BSNode* BSTree;

// Prototype
BSNode* CreateBSNode(DataType info);
void CreateBSTree(BSTree& root);
bool IsEmpty(BSTree root);
int CountNode(BSTree root);
void AddNode(BSTree& root, BSNode* p);
void NhapDuLieuTuFile(BSTree& root);
void XuatKeNgang(char kytu);
void XuatTieuDe();
void XuatNhanVien(DataType info);
void XuatThongBao(int tong);
void XuatCay_PreOrder(BSTree root);
bool IsExist(BSTree root, char* mNV);




// Function
/// <summary>
/// Tạo node mới
/// </summary>
/// <param name="info">dữ liệu cho node mới</param>
/// <returns></returns>
BSNode* CreateBSNode(DataType info)
{
	BSNode* p = new BSNode;
	if (p == nullptr)
		return nullptr;
	else
	{
		p->info = info;
		p->pLeft = nullptr;
		p->pRight = nullptr;
		return p;
	}
}
/// <summary>
/// Tạo cây nhị phân tìm kiếm rỗng
/// </summary>
/// <param name="root"></param>
void CreateBSTree(BSTree& root)
{
	root = nullptr;
}
/// <summary>
/// Kiểm tra xem cây nhị phân có rỗng không?
/// </summary>
/// <param name="root"></param>
/// <returns></returns>
bool IsEmpty(BSTree root)
{
	if (root == nullptr)
		return true;
	return false;
}
/// <summary>
/// Đếm số lượng node trong cây
/// </summary>
/// <param name="root"></param>
/// <returns></returns>
int CountNode(BSTree root)
{
	if (IsEmpty(root))
		return 0;
	return 1 + CountNode(root->pLeft) + CountNode(root->pRight);
}
/// <summary>
/// Thêm 1 node mới vào cây
/// </summary>
/// <param name="root"></param>
/// <param name="p"></param>
void AddNode(BSTree& root, BSNode* p)
{
	if (IsEmpty(root))
		root = p;
	else
	{
		if (_strcmpi(p->info.mNV, root->info.mNV) > 0)
			AddNode(root->pRight, p);
		else if (_strcmpi(p->info.mNV, root->info.mNV) < 0)
			AddNode(root->pLeft, p);
	}
}
/// <summary>
/// Nhập dữ liệu từ file
/// </summary>
/// <param name="root"></param>
void NhapDuLieuTuFile(BSTree& root)
{
	ifstream nhap("bangluong.txt");
	CreateBSTree(root);
	DataType info;
	while (!nhap.eof())
	{
		nhap >> info.mNV;
		nhap >> info.ho;
		nhap >> info.tenLot;
		nhap >> info.ten;
		nhap >> info.namSinh;
		nhap >> info.luong;
		BSNode* p = CreateBSNode(info);
		AddNode(root, p);
	}
	nhap.close();
}
/// <summary>
/// Xuất kẽ ngang
/// </summary>
/// <param name="kytu">ký tự</param>
void XuatKeNgang(char kytu)
{
	cout << "|";
	for (int i = 0; i < 80; i++)
		cout << kytu;
	cout << "|";
}
/// <summary>
/// Xuất tiêu đề
/// </summary>
void XuatTieuDe()
{
	XuatKeNgang('=');
	cout << "\n|" << setiosflags(ios::left)
		<< setw(15) << "Ma nhan vien" << '|'
		<< setw(12) << "Ho" << '|'
		<< setw(12) << "Ten lot" << '|'
		<< setw(12) << "Ten" << '|'
		<< setw(12) << "Nam sinh" << '|'
		<< setw(12) << "Luong" << "|\n";
	XuatKeNgang('=');
}
/// <summary>
/// Xuất thông tin 1 nhân viên
/// </summary>
/// <param name="info"></param>
void XuatNhanVien(DataType info)
{
	cout << "\n|" << setiosflags(ios::left)
		<< setw(15) << info.mNV << '|'
		<< setw(12) << info.ho << '|'
		<< setw(12) << info.tenLot << '|'
		<< setw(12) << info.ten << '|'
		<< setw(12) << info.namSinh << '|'
		<< setw(12) << info.luong << "|\n";
	XuatKeNgang('-');
}
/// <summary>
/// Xuất thông báo cho danh sách
/// </summary>
/// <param name="tong"></param>
void XuatThongBao(int tong)
{
	cout << "\n|" << setiosflags(ios::left)
		<< setw(25) << "Tong nhan vien trong danh sach: "
		<< setw(48) << tong << "|\n";
	XuatKeNgang('=');
}
/// <summary>
/// Xuất cây nhị phân - NLR
/// </summary>
/// <param name="root"></param>
void XuatCay_PreOrder(BSTree root)
{
	if (!IsEmpty(root))
	{
		XuatNhanVien(root->info);
		XuatCay_PreOrder(root->pLeft);
		XuatCay_PreOrder(root->pRight);
	}
}

/// <summary>
/// Xuất cây nhị phân - LNR
/// </summary>
/// <param name="root"></param>
void XuatCay_InOrder(BSTree root)
{
	if (!IsEmpty(root))
	{
		XuatCay_InOrder(root->pLeft);
		XuatNhanVien(root->info);
		XuatCay_InOrder(root->pRight);
	}
}
/// <summary>
/// Kiểm tra xem mã học viên truyền vào có trong cây nhị phân không?
/// </summary>
/// <param name="root"></param>
/// <param name="mNV"></param>
/// <returns></returns>
bool IsExist(BSTree root, char* mNV)
{
	if (!IsEmpty(root))
	{
		if (_strcmpi(root->info.mNV, mNV) == 0)
			return true;
		else
		{
			// duyệt nhánh phải
			if (_strcmpi(mNV, root->info.mNV) > 0)
			{
				if (root->pRight == nullptr)
					return false;
				IsExist(root->pRight, mNV);
			}
			else
			{
				// duyệt nhánh trái
				if (root->pLeft == nullptr)
					return false;
				IsExist(root->pLeft, mNV);
			}
		}
	}
}



