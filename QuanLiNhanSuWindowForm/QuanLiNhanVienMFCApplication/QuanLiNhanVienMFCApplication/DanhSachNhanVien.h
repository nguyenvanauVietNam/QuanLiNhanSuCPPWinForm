#include "NhanVien.h"
#include <afxtempl.h>
#pragma once
using System::String;

class DanhSachNhanVien
{
public:
	DanhSachNhanVien();
	~DanhSachNhanVien();

	void ThemNhanVien(NhanVien nhanvien);
	void SuaNhanVien(NhanVien nhanvien);
	void XoaNhanVien(NhanVien nhanvien);
	void MarshalString(String^ s, std::string& os);
	int SoluongNhanVien();
	void LayDanhSachNhanVien(CList<NhanVien, NhanVien&> &ListData);
private:
	CList<NhanVien,NhanVien &> m_DanhSachNhanVien;
};

