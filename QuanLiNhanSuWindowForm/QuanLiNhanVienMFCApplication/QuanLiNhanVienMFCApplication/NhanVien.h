#include <string>
#pragma once
class NhanVien
{
public:
	 NhanVien();
	 ~NhanVien();

	//Mã nhân viên
	void SetMaNhanVien(std::string MaNhanVien);
	std::string GetMaNhanVien();
	// Họ và tên
	void SetHoVaTen(std::string HoVaTen);
	std::string GetHoVaTen();

	// Chúc vụ
	void SetChucVu(std::string ChucVu);
	std::string GetChucVu();

	// Giới tính
	void SetGioiTinh(std::string GioiTinh);
	std::string GetGioiTinh();

	// Lương căn bản
	void SetLuongCanBan(std::int32_t LuongCanBan);
	std::int32_t GetLuongCanBan();

	// Thưởng
	void SetThuong(std::int32_t Thuong);
	std::int32_t GetThuong();

	// Ngày tháng năm sinh
	void SetNgayThangNamSinh(std::string gayThangNamSinh);
	std::string GetNgayThangNamSinh();

	// Ngày tháng năm vào công ty
	void SetNgayThangNamVaoCongTy(std::string NgayVaoCongTy);
	std::string GetNgayThangNamVaoCongTy();

	// Số ngày làm việc
	void SetSoNgayLamviec(std::int32_t SoNgayLamViec);
	std::int32_t GetSoNgayLamViec();

	// Số ngày làm việc
	void SetTongLuong(std::int32_t TongLuong);
	std::int32_t GetTongLuong();

	bool Empty();
private:
	std::string m_Manhanvien;
	std::string m_HoVaTen;
	std::string m_ChucVu;
	std::string m_GioiTinh;
	std::int32_t m_LuongCoBan;
	std::int32_t m_Thuong;
	std::string m_NgayVaoCongTy;
	std::string m_NgayThangNamSinh;
	std::int32_t m_soNgayLamViec;
	std::int32_t m_TongLuong;
};

