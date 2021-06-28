#pragma once

void XuatMenu()
{
	cout << "\n=================== MENU ===================";
	cout << "\n0. Thoat chuong trinh!";
	cout << "\n1. Tao bang luong nhan vien";
	cout << "\n2. Xem bang luong nhan vien theo thu tu giua (LNR)";
	cout << "\n3. Tinh so nut cua cay";
	cout << "\n4. Xuat thong tin nhan vien co ma nhan vien la LD19022";
	cout << "\n5. Sua thong tin nam sinh cua nhan vien co ma nhan vien LD18041 thanh 1990";
	cout << "\n=================== END ====================";
}
int ChonMenu(int soMenu)
{
	int stt;
	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\n>>>Chon chuc nang: ", cin >> stt;
		if (stt >= 0 && stt <= soMenu) break;
	}
	return stt;
}
void XuLyMenu(int stt, BSTree& root)
{
	system("cls");
	cout << "\n=================== CHUONG TRINH DA XU LY XONG ====================";
	switch (stt)
	{
	case 0:
		cout << "\n0. Thoat chuong trinh!";
		return;
	case 1:
	{
		cout << "\n1. Tao bang luong nhan vien";
		NhapDuLieuTuFile(root);
		cout << "\nDa nhap du lieu tu fiel \"bangluong.txt\" thanh cong!";
		break;
	}
	case 2:
	{
		cout << "\n2. Xem bang luong nhan vien theo thu tu giua (LNR)\n";
		XuatTieuDe();
		XuatCay_InOrder(root);
		XuatThongBao(CountNode(root));
		break;
	}
	case 3:
	{
		cout << "\n3. Tinh so nut cua cay";
		cout << "\nSo nut cua cay la: " << CountNode(root);
		break;
	}
	case 4:
	{
		cout << "\n4. Xuat thong tin nhan vien co ma nhan vien la LD19022\n";
		char mNV[100] = "LD19022";
		XuatTieuDe();
		XuatNhanVienTheoMaNhanVien(root, mNV);
		XuatThongBao(1);
		break;
	}
	case 5:
	{
		cout << "\n5. Sua thong tin nam sinh cua nhan vien co ma nhan vien LD18041 thanh 1990";
		char mNV[100] = "LD18041";
		if (IsExist(root, mNV))
		{
			CapNhatNamSinhTheoMaNhanVien(root, mNV, 1990);
			cout << "\nBang diem sau khi cap nhat:\n";
			XuatTieuDe();
			XuatCay_InOrder(root);
			XuatThongBao(CountNode(root));
		}
		else
		{
			cout << "Khong tim thay nhan vien!";
		}
	}
	}
	_getch();
}