#pragma once

// Prototype
void CapNhatNamSinhTheoMaNhanVien(BSTree root, char* mNV, unsigned int namSinh);
void XuatNhanVienTheoMaNhanVien(BSTree root, char* mNV);

// Function
/// <summary>
/// Cập nhật năm sinh theo mã nhân viên
/// </summary>
/// <param name="root"></param>
/// <param name="mNV"></param>
/// <param name="namSinh"></param>
void CapNhatNamSinhTheoMaNhanVien(BSTree root, char* mNV, unsigned int namSinh)
{
	BSNode* i = root;
	while (i != nullptr)
	{
		if (_strcmpi(i->info.mNV, mNV) == 0)
		{
			i->info.namSinh = namSinh;
			// break chỗ này rất quan trọng, cập nhật xong rồi thì thoát vòng lặp luôn
			break;
		}
		else
		{
			if (_strcmpi(mNV, i->info.mNV) > 0)
				i = i->pRight;
			else
				i = i->pLeft;
		}
	}
}
/// <summary>
/// Xuất nhân viên theo mã nhân viên
/// </summary>
/// <param name="root"></param>
/// <param name="mNV"></param>
void XuatNhanVienTheoMaNhanVien(BSTree root, char* mNV)
{
	if (!IsEmpty(root))
	{
		if (_strcmpi(root->info.mNV, mNV) == 0)
		{
			XuatNhanVien(root->info);
			return;
		}
		XuatNhanVienTheoMaNhanVien(root->pRight, mNV);
		XuatNhanVienTheoMaNhanVien(root->pLeft, mNV);
	}
}

