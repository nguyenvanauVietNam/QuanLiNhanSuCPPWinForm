#include "pch.h"
#include "NhanVien.h"
#pragma once
//Constructor
NhanVien::NhanVien()
{
	m_Manhanvien = "";
	m_HoVaTen = "";
	m_ChucVu = "";
	m_GioiTinh = "";
	m_LuongCoBan =0;
	m_Thuong = 0;
	m_NgayVaoCongTy = "";
	m_NgayThangNamSinh = "";
	m_soNgayLamViec = 0;
}

//Destructor
NhanVien::~NhanVien()
{
	m_Manhanvien = "";
	m_HoVaTen = "";
	m_ChucVu = "";
	m_GioiTinh = "";
	m_LuongCoBan = 0;
	m_Thuong = 0;
	m_NgayVaoCongTy = "";
	m_NgayThangNamSinh = "";
}

//Mã nhân viên
void NhanVien::SetMaNhanVien(std::string MaNhanVien)
{
	m_Manhanvien = MaNhanVien;
}
std::string NhanVien::GetMaNhanVien()
{
	return m_Manhanvien;
}
//Họ và tên
void NhanVien::SetHoVaTen(std::string HoVaTen)
{
	m_HoVaTen = HoVaTen;
}
std::string NhanVien::GetHoVaTen()
{
	return m_HoVaTen;
}
//Chức vụ
void NhanVien::SetChucVu(std::string ChucVu)
{
	m_ChucVu = ChucVu;
}
std::string NhanVien::GetChucVu()
{
	return m_ChucVu;
}
//Giới tính
void NhanVien::SetGioiTinh(std::string GioiTinh)
{
	m_GioiTinh = GioiTinh;
}
std::string NhanVien::GetGioiTinh()
{
	return m_GioiTinh;
}
//Luong
void NhanVien::SetLuongCanBan(std::int32_t LuongCanBan)
{
	m_LuongCoBan = LuongCanBan;
}
std::int32_t NhanVien::GetLuongCanBan()
{
	return m_LuongCoBan;
}
//Thưởng
void NhanVien::SetThuong(std::int32_t Thuong)
{
	m_Thuong = Thuong;
}
std::int32_t NhanVien::GetThuong()
{
	return m_Thuong;
}
//Ngày vào công ty
void NhanVien::SetNgayThangNamVaoCongTy(std::string NgayVaoCongTy)
{
	m_NgayVaoCongTy = NgayVaoCongTy;
}
std::string NhanVien::GetNgayThangNamVaoCongTy()
{
	return m_NgayVaoCongTy;
}
// Ngày tháng năm sinh
void NhanVien::SetNgayThangNamSinh(std::string NgayThangNamSinh)
{
	//Check ngay hop le
	m_NgayThangNamSinh = NgayThangNamSinh;
}
std::string NhanVien::GetNgayThangNamSinh()
{
	return m_NgayThangNamSinh;
}

// So ngay lam viec
void NhanVien::SetSoNgayLamviec(std::int32_t SoNgayLamViec)
{
	m_soNgayLamViec = SoNgayLamViec;
}
std::int32_t NhanVien::GetSoNgayLamViec()
{
	return m_soNgayLamViec;
}
//Tổng lương
void NhanVien::SetTongLuong(std::int32_t TongLuong)
{
	m_TongLuong = TongLuong;
}
std::int32_t NhanVien::GetTongLuong()
{
	return m_TongLuong;
}

bool NhanVien::Empty()
{
	if (
		m_Manhanvien =="" ||
		m_HoVaTen == "" ||
		m_ChucVu == "" ||
		m_GioiTinh == "" ||
		m_LuongCoBan == 0 ||
		m_Thuong == 0 ||
		m_NgayVaoCongTy == "" ||
		m_NgayThangNamSinh == "" ||
		m_soNgayLamViec == 0 ||
		m_TongLuong == 0 )
	{
		return true;
	}

	return false;
}