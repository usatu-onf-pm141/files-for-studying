
// practice3_1View.cpp : ���������� ������ Cpractice3_1View
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "practice3_1.h"
#endif

#include "practice3_1Doc.h"
#include "practice3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cpractice3_1View

IMPLEMENT_DYNCREATE(Cpractice3_1View, CView)

BEGIN_MESSAGE_MAP(Cpractice3_1View, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cpractice3_1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ��������/����������� Cpractice3_1View

Cpractice3_1View::Cpractice3_1View()
{
	// TODO: �������� ��� ��������

}

Cpractice3_1View::~Cpractice3_1View()
{
}

BOOL Cpractice3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� Cpractice3_1View
square& operator -(square&A, square& B)
{
	square C;
	for (int i = 0; i < 3; i++)
		C.rgb[i] = abs(A.rgb[i] - B.rgb[i])%256;
	return C;
};
void Cpractice3_1View::OnDraw(CDC* pDC)
{
	Cpractice3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������

	square Square_1(225, 225, 150); // create the first square
	Square_1.SetColor(100, 100, 0);
	Square_1.CreateSquare(pDC);

	square Square_2(475, 225, 150); // create the second square
	Square_2.SetColor(0, 50, 255);
	Square_2.CreateSquare(pDC);
	
	CreateMinus(pDC);
	CreateEqual(pDC);
	
	square Square_3; // create the third square
	Square_3 = Square_1 - Square_2; // operation minus relatively color
	Square_3.SetCoordinates(725, 225, 150);
	Square_3.CreateSquare(pDC);
}


// ������ Cpractice3_1View


void Cpractice3_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cpractice3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void Cpractice3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void Cpractice3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}

void Cpractice3_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cpractice3_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� Cpractice3_1View

#ifdef _DEBUG
void Cpractice3_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cpractice3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cpractice3_1Doc* Cpractice3_1View::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cpractice3_1Doc)));
	return (Cpractice3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� Cpractice3_1View