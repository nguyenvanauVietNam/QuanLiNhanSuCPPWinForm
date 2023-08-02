
// QuanLiNhanVienMFCApplicationDlg.h : header file
//
#include "DanhSachNhanVien.h"
#pragma once


// CQuanLiNhanVienMFCApplicationDlg dialog
class CQuanLiNhanVienMFCApplicationDlg : public CDialogEx
{
// Construction
public:
	CQuanLiNhanVienMFCApplicationDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUANLINHANVIENMFCAPPLICATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	void InitCbx_Chuc_Vu();
	void InitListDanh_sach_nhan_vien();
public:
	// Combobox chức vụ
	// Combobox chức vụ
	CComboBox m_ComboBoxChucVu;
	// Ngày tháng năm sinh
	CDateTimeCtrl m_DateNTNS;
	CButton m_Radio_Nam;
	// Radio Nữ
	CButton m_RadioNu;
	// Text box mã nhân viên
	CEdit m_EditBox_Ma_Nhan_Vien;
	// Thâm niên
	CStatic m_ThamNien;
	// Lương cơ bản
	// Lương cơ bản
	CEdit m_Luong_Co_Ban;
	// Nút thêm nhân viên
	// Nút thêm nhân viên
	CButton m_btn_Them_nhan_vien;
	// Xóa nhân viên
	CButton m_btn_Xoa;
	// Sửa nhân viên
	CButton m_Sua_nhan_vien;
	// Ngày tháng năm sinh
	CDateTimeCtrl m_Date_NTNS;
	// Ngày vào công ty
	CDateTimeCtrl m_Ngay_vao_cong_ty;
	// Thưởng
	CEdit m_Thuong;
	// Thực nhận
	CEdit m_Thuc_nhan;

	// Hiển thị danh sách nhân viên
	CListCtrl m_Danh_sach_nhan_vien;

	DanhSachNhanVien *m_DanhSachNhanVien;
};
