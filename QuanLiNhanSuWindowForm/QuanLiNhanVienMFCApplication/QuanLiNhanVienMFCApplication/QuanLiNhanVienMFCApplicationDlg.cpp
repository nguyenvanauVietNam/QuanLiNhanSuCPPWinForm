
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
#define Nam "Nam"
#define Nu  "Nu"

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
CQuanLiNhanVienMFCApplicationDlg::~CQuanLiNhanVienMFCApplicationDlg()
{
	//Lưu file
	CList <NhanVien, NhanVien&> l_DanhSachNhanVien;
	m_DanhSachNhanVien->LayDanhSachNhanVien(l_DanhSachNhanVien);
	m_DanhSachNhanVien->GhiDanhSachNhanVienVaoFile(l_DanhSachNhanVien);
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
	DDX_Control(pDX, IDC_EDIT_Ho_Va_Ten, m_HoVaTen);
	DDX_Control(pDX, IDC_EDIT_Ma_Nhan_Vien2, m_MaNVCanXoa);
}

BEGIN_MESSAGE_MAP(CQuanLiNhanVienMFCApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_Them, &CQuanLiNhanVienMFCApplicationDlg::OnBnClickedBtnThem)
	ON_BN_CLICKED(IDC_BTN_Cap_nhat, &CQuanLiNhanVienMFCApplicationDlg::OnBnClickedBtnCapnhat)
	ON_BN_CLICKED(IDC_BTN_Xoa, &CQuanLiNhanVienMFCApplicationDlg::OnBnClickedBtnXoa)
	ON_CBN_SELCHANGE(IDC_COMBOC_CHUC_VU, &CQuanLiNhanVienMFCApplicationDlg::OnCbnSelchangeCombocChucVu)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER_NGAY_VAO_CONG_TY, &CQuanLiNhanVienMFCApplicationDlg::OnDtnDatetimechangeDatetimepickerNgayVaoCongTy)
	ON_NOTIFY(NM_DBLCLK, IDC_Danh_sach_nhan_vien, &CQuanLiNhanVienMFCApplicationDlg::OnNMDblclkDanhsachnhanvien)
END_MESSAGE_MAP()


// CQuanLiNhanVienMFCApplicationDlg message handlers

BOOL CQuanLiNhanVienMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//init window
	m_DanhSachNhanVien = new DanhSachNhanVien();
	InitCbx_Chuc_Vu();
	InitListDanh_sach_nhan_vien();
	InitRadioButton();

	m_Date_NTNS.SetFormat(_T("yyyyMMdd"));
	m_Ngay_vao_cong_ty.SetFormat(_T("yyyyMMdd"));
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
//Khởi tạo radiobutton
// Combobox chức vụ
void CQuanLiNhanVienMFCApplicationDlg::InitRadioButton()
{
	m_RadioNu.SetCheck(true);
	m_Radio_Nam.SetCheck(false);
}

//Tạo data với XML
// Combobox chức vụ



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

	UpdateDanhSachNhanVien();
	UpdateData(false);
}
//Update danh sach nhan vien
void CQuanLiNhanVienMFCApplicationDlg::UpdateDanhSachNhanVien()
{
	//Xóa hêt cái cũ
	m_Danh_sach_nhan_vien.DeleteAllItems();
	//Hiển thị danh sách nhân viên
	NhanVien l_NhanVienTemp;
	std::int32_t l_SoThuTuNhanVien{ 0 };
	CList <NhanVien, NhanVien&> l_DanhSachNhanVien;
	m_DanhSachNhanVien->LayDanhSachNhanVien(l_DanhSachNhanVien);

	for (POSITION pos = l_DanhSachNhanVien.GetHeadPosition(); pos; )
	{
		l_NhanVienTemp = l_DanhSachNhanVien.GetNext(pos);
		l_SoThuTuNhanVien++;
		CString l_STT, l_HovaTen, l_GioiTinh, l_ChucVu, l_NgayThangNaminh, l_ThamNien, l_LuongCanBan, l_Thuong, l_TongThuNhap;
		l_STT = l_NhanVienTemp.GetMaNhanVien().c_str();
		l_HovaTen = l_NhanVienTemp.GetHoVaTen().c_str();
		l_GioiTinh = l_NhanVienTemp.GetGioiTinh().c_str();
		l_ChucVu = l_NhanVienTemp.GetChucVu().c_str();
		l_NgayThangNaminh = l_NhanVienTemp.GetNgayThangNamSinh().c_str();
		l_LuongCanBan = l_NhanVienTemp.GetLuongCanBan().ToString();
		l_Thuong = l_NhanVienTemp.GetThuong().ToString();
		l_TongThuNhap = l_NhanVienTemp.GetTongLuong().ToString();

		int ThamNien = NamHienTai - (std::stoi(l_NhanVienTemp.GetNgayThangNamVaoCongTy().c_str()) / 10000);
		l_ThamNien = ThamNien.ToString();
		///
		int l_MyItem = m_Danh_sach_nhan_vien.InsertItem(l_SoThuTuNhanVien, l_STT);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem, 0, l_STT);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem, 1, l_HovaTen);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem, 2, l_GioiTinh);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem, 3, l_ChucVu);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem, 4, l_NgayThangNaminh);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem, 5, l_ThamNien);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem, 6, l_LuongCanBan);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem, 7, l_Thuong);
		m_Danh_sach_nhan_vien.SetItemText(l_MyItem, 8, l_TongThuNhap);
	}
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



void CQuanLiNhanVienMFCApplicationDlg::OnBnClickedBtnThem()
{
	// TODO: Add your control notification handler code here
	//m_DanhSachNhanVien->ThemNhanVien();
	NhanVien l_NhanVienTemp;

	//Lẫy mã nhân viên
	CString  l_MaNhanVien;
	m_EditBox_Ma_Nhan_Vien.GetWindowTextW(l_MaNhanVien);
	std::string l_strMaNhanVien = CStringA(l_MaNhanVien);
	l_NhanVienTemp.SetMaNhanVien(l_strMaNhanVien);

	//Lấy họ và tên nhân viên
	CString  l_HoVaTen;
	m_HoVaTen.GetWindowTextW(l_HoVaTen);
	std::string l_strHoVaTen = CStringA(l_HoVaTen);
	l_NhanVienTemp.SetHoVaTen(l_strHoVaTen);

	//Lây giới tính
	std::string l_strGioiTinh;
	if (m_RadioNu.GetCheck() == true)
	{
		l_strGioiTinh = Nam;
	}
	else
	{
		l_strGioiTinh = Nu;
	}
	l_NhanVienTemp.SetGioiTinh(l_strGioiTinh);

	//Lấy chức vụ
	CString l_ChucVu;
	m_ComboBoxChucVu.GetLBText(m_ComboBoxChucVu.GetCurSel(), l_ChucVu);
	std::string l_strChucVu = CStringA(l_ChucVu);
	l_NhanVienTemp.SetChucVu(l_strChucVu);

	//Ngày tháng năm sinh
	CString l_NgayThangNamSinh;
	m_Date_NTNS.GetWindowTextW(l_NgayThangNamSinh);
	std::string l_strNgayThangNamSinh = CStringA(l_NgayThangNamSinh);
	l_NhanVienTemp.SetNgayThangNamSinh(l_strNgayThangNamSinh);

	//Ngày vào công ty
	CString l_NgayVaoCongTy;
	m_Ngay_vao_cong_ty.GetWindowTextW(l_NgayVaoCongTy);
	std::string l_strNgayVaoCongTy = CStringA(l_NgayVaoCongTy);
	l_NhanVienTemp.SetNgayThangNamVaoCongTy(l_strNgayVaoCongTy);

	//Lấy lương cơ bản
	CString  l_LuongCoBan;
	m_Luong_Co_Ban.GetWindowTextW(l_LuongCoBan);
	std::string l_strLuongCoBan = CStringA(l_LuongCoBan);
	l_NhanVienTemp.SetLuongCanBan(std::stoi(l_strLuongCoBan));

	//Lấy thưởng
	CString  l_Thuong;
	m_Thuong.GetWindowTextW(l_Thuong);
	std::string l_strThuong = CStringA(l_Thuong);
	l_NhanVienTemp.SetThuong(std::stoi(l_strThuong));
	l_NhanVienTemp.SetSoNgayLamviec(20); //Mặc định 20 ngày

	//Lấy thực nhận
	CString  l_ThucNhan;
	m_Thuc_nhan.GetWindowTextW(l_ThucNhan);
	std::string l_strThucNhan = CStringA(l_ThucNhan);
	l_NhanVienTemp.SetTongLuong(std::stoi(l_strThucNhan));

	//thêm
	m_DanhSachNhanVien->ThemNhanVien(l_NhanVienTemp);
	UpdateDanhSachNhanVien();
}


void CQuanLiNhanVienMFCApplicationDlg::OnBnClickedBtnCapnhat()
{
	// TODO: Add your control notification handler code here

}


void CQuanLiNhanVienMFCApplicationDlg::OnBnClickedBtnXoa()
{
	// TODO: Add your control notification handler code here
	//Lẫy mã nhân viên
	CString  l_MaNhanVien;
	m_MaNVCanXoa.GetWindowTextW(l_MaNhanVien);
	std::string l_strMaNhanVien = CStringA(l_MaNhanVien);
	
	//Xoa
	m_DanhSachNhanVien->XoaNhanVien(l_strMaNhanVien);
	
	//Update danh sách
	UpdateDanhSachNhanVien();


}


void CQuanLiNhanVienMFCApplicationDlg::OnCbnSelchangeCombocChucVu()
{
	// TODO: Add your control notification handler code here
	
	
}




void CQuanLiNhanVienMFCApplicationDlg::OnDtnDatetimechangeDatetimepickerNgayVaoCongTy(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	CString l_NgayVaoCongTy;
	m_Ngay_vao_cong_ty.GetWindowTextW(l_NgayVaoCongTy);
	int ThamNien = NamHienTai - (_wtoi(l_NgayVaoCongTy) / 10000);

	m_ThamNien.SetWindowTextW((CString)(std::to_wstring(ThamNien).c_str()));

}


void CQuanLiNhanVienMFCApplicationDlg::OnNMDblclkDanhsachnhanvien(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	int row = m_Danh_sach_nhan_vien.GetSelectionMark();
	if (row < 0)
	{
		return;
	}
	CString  l_MaNhanVien, l_HoVaTen, l_GioiTinh, l_ChucVu, l_NgayThangNamSinh, l_ThamNien, l_NgayVaoCongTy, l_LuongCoBan, l_Thuong, l_ThucNhan;
	//Nhân viên
	l_MaNhanVien = m_Danh_sach_nhan_vien.GetItemText(row, 0);
	l_HoVaTen = m_Danh_sach_nhan_vien.GetItemText(row, 1);
	l_GioiTinh = m_Danh_sach_nhan_vien.GetItemText(row, 2);
	l_ChucVu = m_Danh_sach_nhan_vien.GetItemText(row, 3);
	l_NgayThangNamSinh = m_Danh_sach_nhan_vien.GetItemText(row, 4);
	l_ThamNien = m_Danh_sach_nhan_vien.GetItemText(row, 4);
	l_NgayVaoCongTy = m_Danh_sach_nhan_vien.GetItemText(row, 5);
	l_LuongCoBan = m_Danh_sach_nhan_vien.GetItemText(row, 6);
	l_Thuong = m_Danh_sach_nhan_vien.GetItemText(row, 7);
	l_ThucNhan = m_Danh_sach_nhan_vien.GetItemText(row, 8);

	//Set lại thuộc tính
	//Mã số nhân viên
	m_EditBox_Ma_Nhan_Vien.SetWindowTextW(l_MaNhanVien);
	//họ và tên
	m_HoVaTen.SetWindowTextW(l_HoVaTen);
	//Giới tính
	if (l_GioiTinh == "Nam")
	{
		m_Radio_Nam.SetCheck(true);
		m_RadioNu.SetCheck(false);
	}
	else
	{
		m_Radio_Nam.SetCheck(false);
		m_RadioNu.SetCheck(true);
	}
	//Chức vụ
	if (l_ChucVu == "Nhan Vien")
	{
		m_ComboBoxChucVu.SetCurSel(0);
	}
	else if (l_ChucVu == "Quan li")
	{
		m_ComboBoxChucVu.SetCurSel(1);
	}
	else
	{
		m_ComboBoxChucVu.SetCurSel(2);
	}
	//Ngày tháng năm sinh
	m_Date_NTNS.SetWindowTextW(l_NgayThangNamSinh);

	//Thâm niên
	int ThamNien = NamHienTai - (_wtoi(l_ThamNien) / 10000);
	m_ThamNien.SetWindowTextW((CString)(std::to_wstring(ThamNien).c_str()));

	//Ngày vào công ty
	m_Ngay_vao_cong_ty.SetWindowTextW(l_NgayVaoCongTy);

	//Lương cơ bản
	m_Luong_Co_Ban.SetWindowTextW(l_LuongCoBan);

	//Thuong
	m_Thuong.SetWindowTextW(l_Thuong);

	//Thực nhận
	m_Thuc_nhan.SetWindowTextW(l_ThucNhan);
}
