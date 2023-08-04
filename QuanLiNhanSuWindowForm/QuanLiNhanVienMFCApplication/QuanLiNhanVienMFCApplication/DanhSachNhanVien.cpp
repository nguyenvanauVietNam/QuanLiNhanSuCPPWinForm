#include "pch.h"
#using <mscorlib.dll>
#using <System.xml.dll>
#include "DanhSachNhanVien.h"
#include <tchar.h>
using namespace std;
using namespace System;
using namespace System::Xml;

#define FileXMLDanhSachNhanVien "DuLieuNhanVien.xml"
#define FileXMLDanhSachNhanVien1 "DuLieuNhanVien1.xml"

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
	m_DanhSachNhanVien.RemoveAll();  //Xóa hết các phần tử nếu danh sách không rỗng
}

//Init Danh sách Nhân viên
void DanhSachNhanVien::InitDataFromXML()
{
	//Đọc từ file xml lên
	if (true == m_DanhSachNhanVien.IsEmpty())
	{
		m_DanhSachNhanVien.RemoveAll();  //Xóa hết các phần tử nếu danh sách không rỗng
	}
	try
	{
		XmlTextReader^ reader = gcnew XmlTextReader(FileXMLDanhSachNhanVien);
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
		reader->Close();
	}
	catch (CException* e)
	{
		throw;
	}
}



//Ghi Danh Sach nhân viên
void DanhSachNhanVien::GhiDanhSachNhanVienVaoFile(CList<NhanVien, NhanVien&>& DanhSachNhanVien)
{
	XmlTextWriter^ writer = gcnew XmlTextWriter(FileXMLDanhSachNhanVien, System::Text::Encoding::UTF8);
	writer->Formatting = Formatting::Indented;

	writer->WriteStartElement("QuanLiNhanVien");
	writer->WriteString("\n");//dấu xuống dòng
	NhanVien l_NhanVienTemp;
	for (POSITION pos = m_DanhSachNhanVien.GetTailPosition(); pos; )
	{
		l_NhanVienTemp = m_DanhSachNhanVien.GetPrev(pos);
		//Add Nhân viên
		writer->WriteStartElement("NhanVien");
		//Ghi thuộc tính

		//MaSoNhanVien
		String^ l_MaNhanVien = gcnew String(l_NhanVienTemp.GetMaNhanVien().data());
		writer->WriteAttributeString("MaSoNhanVien", l_MaNhanVien);
		delete l_MaNhanVien;
		//TenNhanVien
		String^ l_HoVaTen = gcnew String(l_NhanVienTemp.GetHoVaTen().data());
		writer->WriteAttributeString("TenNhanVien", l_HoVaTen);
		delete l_HoVaTen;

		//GioiTinh
		String^ l_GioiTinh = gcnew String(l_NhanVienTemp.GetGioiTinh().data());
		writer->WriteAttributeString("GioiTinh", l_GioiTinh);
		delete l_GioiTinh;

		//ChucVu
		String^ l_ChucVu = gcnew String(l_NhanVienTemp.GetChucVu().data());
		writer->WriteAttributeString("ChucVu", l_ChucVu);
		delete l_ChucVu;
		//NgayThangNamSinh
		String^ l_NgayThangNamSinh = gcnew String(l_NhanVienTemp.GetNgayThangNamSinh().data());
		writer->WriteAttributeString("NgayThangNamSinh", l_NgayThangNamSinh);
		delete l_NgayThangNamSinh;
		//NgayThangNamVaoCty
		String^ l_NgayThangNamVaoCty = gcnew String(l_NhanVienTemp.GetNgayThangNamVaoCongTy().data());
		writer->WriteAttributeString("NgayThangNamVaoCty", l_NgayThangNamVaoCty);
		delete l_NgayThangNamVaoCty;
		//LuongCanBan
		String^ l_LuongCanBan = gcnew String(l_NhanVienTemp.GetLuongCanBan().ToString());
		writer->WriteAttributeString("LuongCanBan", l_LuongCanBan);
		delete l_LuongCanBan;
		//SoNgayLamViec
		String^ l_SoNgayLamViec = gcnew String(l_NhanVienTemp.GetSoNgayLamViec().ToString());
		writer->WriteAttributeString("SoNgayLamViec", l_SoNgayLamViec);
		delete l_SoNgayLamViec;
		//Thuong
		String^ l_Thuong = gcnew String(l_NhanVienTemp.GetThuong().ToString());
		writer->WriteAttributeString("Thuong", l_SoNgayLamViec);
		delete l_Thuong;

		writer->WriteEndElement();
		writer->WriteString("\n");//dấu xuống dòng
	}
	writer->WriteEndElement();

	writer->Close();
}
DanhSachNhanVien::DanhSachNhanVien()
{
	InitDataFromXML();
}

void DanhSachNhanVien::ThemNhanVien(NhanVien nhanvien)
{
	if (nhanvien.Empty() == false) //nếu nhân viên không rỗng
	{
		m_DanhSachNhanVien.AddTail(nhanvien); //thêm vào cuối danh sách
	}
	else
	{
		MessageBox(NULL, L"Nhân viên đang rỗng", L"Thông báo", MB_ICONWARNING );
	}
}

void DanhSachNhanVien::XoaNhanVien(std::string masohanvien)
{
	if (masohanvien != "") //Nếu danh sách nhân viên không rỗng
	{
		NhanVien l_NhanVienTemp;
		bool result = false;
		//Kiểm tra hợp lệ
		for (POSITION pos = m_DanhSachNhanVien.GetHeadPosition(); pos; l_NhanVienTemp = m_DanhSachNhanVien.GetNext(pos))
		{
			NhanVien l_NhanVienTemp2 = m_DanhSachNhanVien.GetAt(pos);
			
			if (l_NhanVienTemp2.GetMaNhanVien() == masohanvien)
			{
				m_DanhSachNhanVien.RemoveAt(pos);
				result = true;
				break;
			}
		}
		if (result == false)
		{
			MessageBox(NULL, L"Không tìm thấy nhân viên", L"Thông báo", MB_ICONWARNING);
		}
		else
		{
			//todo
		}
	}
	else
	{
		MessageBox(NULL, L"Mã số nhân viên không rỗng", L"Thông báo", MB_ICONWARNING);
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