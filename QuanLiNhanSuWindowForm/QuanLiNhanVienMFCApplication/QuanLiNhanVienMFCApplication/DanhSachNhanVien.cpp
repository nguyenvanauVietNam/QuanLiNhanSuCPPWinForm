#include "pch.h"
#using <mscorlib.dll>
#using <System.xml.dll>
#include "DanhSachNhanVien.h"
#include <tchar.h>


using namespace System;
using namespace System::Xml;

//Chuyển String thành std::string
void DanhSachNhanVien::MarshalString(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}
DanhSachNhanVien::~DanhSachNhanVien()
{

}
DanhSachNhanVien::DanhSachNhanVien()
{
	//Đọc từ file xml lên
	if (true == m_DanhSachNhanVien.IsEmpty())
	{
		m_DanhSachNhanVien.RemoveAll();  //Xóa hết các phần tử nếu danh sách không rỗng
	}
	try
	{
		XmlTextReader ^ reader = gcnew XmlTextReader("DuLieuNhanVien.xml");
	   if (reader == nullptr) return;
	   else
	   {

		   while (reader->Read())
		   {

			   switch (reader->NodeType)
			   {
			   case XmlNodeType::Element:
				   NhanVien _Temp_NhanVien;
				   while (reader->MoveToNextAttribute())
				   {
					   std::string ThuocTinh;
					   std::string GiaTri;
					   MarshalString(reader->Name->ToString(), ThuocTinh);
					   //MaSoNhanVien
					   if (ThuocTinh == "MaSoNhanVien")
					   {
						   MarshalString(reader->Value->ToString(), GiaTri);
						   _Temp_NhanVien.SetMaNhanVien(GiaTri);
					   }
					   //TenNhanVien
					   else if (ThuocTinh == "TenNhanVien")
					   {
						   MarshalString(reader->Value->ToString(), GiaTri);
						   _Temp_NhanVien.SetHoVaTen(GiaTri);
					   }
					   //ChucVu
					   else if (ThuocTinh == "ChucVu")
					   {
						   MarshalString(reader->Value->ToString(), GiaTri);
						   _Temp_NhanVien.SetChucVu(GiaTri);
					   }
					   //GioiTinh
					   else if (ThuocTinh == "GioiTinh")
					   {
						   MarshalString(reader->Value->ToString(), GiaTri);
						   _Temp_NhanVien.SetGioiTinh(GiaTri);
					   }
					   //NgayThangNamSinh
					   else if (ThuocTinh == "NgayThangNamSinh")
					   {
						   MarshalString(reader->Value->ToString(), GiaTri);
						   _Temp_NhanVien.SetNgayThangNamSinh(GiaTri);
					   }
					   //NgayThangNamVaoCty
					   else if (ThuocTinh == "NgayThangNamVaoCty")
					   {
						   MarshalString(reader->Value->ToString(), GiaTri);
						   _Temp_NhanVien.SetNgayThangNamVaoCongTy(GiaTri);
					   }
					   //LuongCanBan
					   else if (ThuocTinh == "LuongCanBan")
					   {
						   MarshalString(reader->Value->ToString(), GiaTri);
						   std::int32_t l_LuongCoban = std::stoi(GiaTri);
						   _Temp_NhanVien.SetLuongCanBan(l_LuongCoban);
					   }
					   //SoNgayLamViec
					   else if (ThuocTinh == "SoNgayLamViec")
					   {
						   MarshalString(reader->Value->ToString(), GiaTri);
						   std::int32_t l_SoNgayLamViec = std::stoi(GiaTri);
						   _Temp_NhanVien.SetSoNgayLamviec(l_SoNgayLamViec);
					   }
					   //Thuong
					   else if (ThuocTinh == "Thuong")
					   {
						   MarshalString(reader->Value->ToString(), GiaTri);
						   std::int32_t l_Thuong = std::stoi(GiaTri);
						   _Temp_NhanVien.SetThuong(l_Thuong);
					   }
					   else
					   {
						   //Ghi Log
					   }

				   }
				   std::int32_t TongLuong = _Temp_NhanVien.GetLuongCanBan() * (float)_Temp_NhanVien.GetSoNgayLamViec() / 20 + _Temp_NhanVien.GetThuong();
				   _Temp_NhanVien.SetTongLuong(TongLuong);
				   if (_Temp_NhanVien.Empty() != true)
				   {
					   m_DanhSachNhanVien.AddHead(_Temp_NhanVien);
				   }

				   break;
			   }
		   }
	   }
	}catch(CException* e)
	{
		throw;
	}
}

void DanhSachNhanVien::ThemNhanVien(NhanVien nhanvien)
{
	if (!nhanvien.Empty())
	{
		//Kiểm tra hợp lệ

		//Thêm nhân viên vào danh sách
		
	}
}

void DanhSachNhanVien::XoaNhanVien(NhanVien nhanvien)
{
	if (!nhanvien.Empty())
	{
		//Kiểm tra hợp lệ

		//Thêm nhân viên vào danh sách
		
	}
}
void DanhSachNhanVien::SuaNhanVien(NhanVien nhanvien)
{
	if (!nhanvien.Empty())
	{
		//Kiểm tra hợp lệ

		//Thêm nhân viên vào danh sách
		

	}
}

//Số lượng Nhân Viên
int DanhSachNhanVien::SoluongNhanVien()
{
	if (m_DanhSachNhanVien.IsEmpty() == false)
	{
		return m_DanhSachNhanVien.GetCount();
	}
	return 0;
}

//Lấy danh sách nhân viên
void DanhSachNhanVien::LayDanhSachNhanVien(CList<NhanVien, NhanVien&>& ListData)
{
	for (POSITION pos = m_DanhSachNhanVien.GetHeadPosition(); pos; )
	{
		NhanVien item = m_DanhSachNhanVien.GetNext(pos);
		ListData.AddHead(item);
	}
}