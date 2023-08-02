
// QuanLiNhanVienMFCApplicationDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "QuanLiNhanVienMFCApplication.h"
#include "QuanLiNhanVienMFCApplicationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define NamHienTai 2023  //năm hiện tại

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CQuanLiNhanVienMFCApplicationDlg dialog



CQuanLiNhanVienMFCApplicationDlg::CQuanLiNhanVienMFCApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUANLINHANVIENMFCAPPLICATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQuanLiNhanVienMFCApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOC_CHUC_VU, m_ComboBoxChucVu);
	DDX_Control(pDX, IDC_RADIO_Nam, m_Radio_Nam);
	DDX_Control(pDX, IDC_RADIO_Nu, m_RadioNu);
	DDX_Control(pDX, IDC_EDIT_Ma_Nhan_Vien, m_EditBox_Ma_Nhan_Vien);
	DDX_Control(pDX, IDC_STATIC_Tham_Nien, m_ThamNien);
	DDX_Control(pDX, IDC_EDIT_Luong_co_ban, m_Luong_Co_Ban);
	DDX_Control(pDX, IDC_BTN_Them, m_btn_Them_nhan_vien);
	DDX_Control(pDX, IDC_BTN_Xoa, m_btn_Xoa);
	DDX_Control(pDX, IDC_BTN_Cap_nhat, m_Sua_nhan_vien);
	DDX_Control(pDX, IDC_DATETIMEPICKER_NGAY_THANG_NAM_SINH, m_Date_NTNS);
	DDX_Control(pDX, IDC_DATETIMEPICKER_NGAY_VAO_CONG_TY, m_Ngay_vao_cong_ty);
	DDX_Control(pDX, IDC_EDIT_Thuong, m_Thuong);
	DDX_Control(pDX, IDC_EDIT_Thuc_nhan, m_Thuc_nhan);
	DDX_Control(pDX, IDC_Danh_sach_nhan_vien, m_Danh_sach_nhan_vien);
}

BEGIN_MESSAGE_MAP(CQuanLiNhanVienMFCApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CQuanLiNhanVienMFCApplicationDlg message handlers

BOOL CQuanLiNhanVienMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//init window
	m_DanhSachNhanVien = new DanhSachNhanVien();
	InitCbx_Chuc_Vu();
	InitListDanh_sach_nhan_vien();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	ShowWindow(SW_MINIMIZE);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}
// Combobox chức vụ
void CQuanLiNhanVienMFCApplicationDlg::InitCbx_Chuc_Vu()
{
	m_ComboBoxChucVu.AddString(L"Nhân viên");
	m_ComboBoxChucVu.AddString(L"Trưởng nhóm");
	m_ComboBoxChucVu.AddString(L"Quản li");
	m_ComboBoxChucVu.SetCurSel(0);
}

//Danh sách nhân viên
void CQuanLiNhanVienMFCApplicationDlg::InitListDanh_sach_nhan_vien()
{
	m_Danh_sach_nhan_vien.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_REPORT);
	m_Danh_sach_nhan_vien.InsertColumn(0, _T("Mã nhân viên"),LVCFMT_CENTER,100);
	m_Danh_sach_nhan_vien.InsertColumn(1, _T("Họ và tên"), LVCFMT_CENTER, 200);
	m_Danh_sach_nhan_vien.InsertColumn(2, _T("Giới tính"), LVCFMT_CENTER, 75);
	m_Danh_sach_nhan_vien.InsertColumn(3, _T("Chức vụ"), LVCFMT_CENTER, 100);
	m_Danh_sach_nhan_vien.InsertColumn(4, _T("Ngày tháng năm sinh"), LVCFMT_CENTER, 100);
	m_Danh_sach_nhan_vien.InsertColumn(5, _T("Thâm niên"), LVCFMT_CENTER, 75);
	m_Danh_sach_nhan_vien.InsertColumn(6, _T("Lương cơ bản"), LVCFMT_CENTER, 150);
	m_Danh_sach_nhan_vien.InsertColumn(7, _T("Thưởng"), LVCFMT_CENTER, 150);
	m_Danh_sach_nhan_vien.InsertColumn(8, _T("Tổng thu nhập"), LVCFMT_CENTER, 200);

	//Hiển thị danh sách nhân viên
	NhanVien l_NhanVienTemp;
	std::int32_t l_SoThuTuNhanVien{ 0 };
	CList <NhanVien, NhanVien&> l_DanhSachNhanVien;
	m_DanhSachNhanVien->LayDanhSachNhanVien(l_DanhSachNhanVien);

	for (POSITION pos = l_DanhSachNhanVien.GetHeadPosition(); pos; )
	{
		l_NhanVienTemp = l_DanhSachNhanVien.GetNext(pos);
		l_SoThuTuNhanVien++;
		CString l_STT,l_HovaTen,l_GioiTinh,l_ChucVu,l_NgayThangNaminh, l_ThamNien,l_LuongCanBan,l_Thuong,l_TongThuNhap;
		l_STT = l_NhanVienTemp.GetMaNhanVien().c_str();
		l_HovaTen = l_NhanVienTemp.GetHoVaTen().c_str();
		l_GioiTinh = l_NhanVienTemp.GetGioiTinh().c_str();
		l_ChucVu = l_NhanVienTemp.GetChucVu().c_str();
		l_NgayThangNaminh= l_NhanVienTemp.GetNgayThangNamSinh().c_str();
		l_LuongCanBan = l_NhanVienTemp.GetLuongCanBan().ToString();
		l_Thuong = l_NhanVienTemp.GetThuong().ToString();
		l_TongThuNhap = l_NhanVienTemp.GetTongLuong().ToString();

		int ThamNien = NamHienTai - (std::stoi(l_NhanVienTemp.GetNgayThangNamVaoCongTy().c_str())/ 10000);
		l_ThamNien = ThamNien.ToString();
		///
		int l_MyItem = m_Danh_sach_nhan_vien.InsertItem(l_SoThuTuNhanVien, l_STT);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem, 0, l_STT);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem,1, l_HovaTen);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem,2, l_GioiTinh);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem, 3,l_ChucVu);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem,4, l_NgayThangNaminh);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem,5, l_ThamNien);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem,6, l_LuongCanBan);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem,7, l_Thuong);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem,9, l_TongThuNhap);
	}
	UpdateData(false);

}
void CQuanLiNhanVienMFCApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQuanLiNhanVienMFCApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQuanLiNhanVienMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

