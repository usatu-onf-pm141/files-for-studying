
// example_projectView.cpp : реализаци€ класса Cexample_projectView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "example_project.h"
#endif

#include "example_projectDoc.h"
#include "example_projectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexample_projectView

IMPLEMENT_DYNCREATE(Cexample_projectView, CView)

BEGIN_MESSAGE_MAP(Cexample_projectView, CView)
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cexample_projectView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// создание/уничтожение Cexample_projectView

Cexample_projectView::Cexample_projectView()
{
	// TODO: добавьте код создани€

}

Cexample_projectView::~Cexample_projectView()
{
}

BOOL Cexample_projectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование Cexample_projectView
void Cexample_projectView::DrawMyObject(CDC* pDC, CRect rectClient, CPoint Start, CPoint End)
{
	CPen MP;
	CPen SP;
	CPen WP;
	
	static int num = 8;

	TCHAR mystr[5] = _T("  ");
	pDC->TextOutW(195, 195, mystr);

	MP.CreatePen(PS_SOLID | PS_COSMETIC, 1, RGB(0, 0, 255));
	SP.CreatePen(PS_SOLID | PS_COSMETIC, 2, RGB(255, 0, 0));
	WP.CreatePen(PS_SOLID | PS_COSMETIC, 2, RGB(255, 255, 255));

	pDC->SelectObject(&WP);
	pDC->Arc(rectClient, Start, End);
	pDC->Arc(rectClient, End, Start);

	pDC->SelectObject(&MP);
	pDC->Arc(rectClient, Start, End);

	pDC->SelectObject(&SP);
	pDC->Arc(rectClient, End, Start);

	pDC->SetTextColor(RGB(0, 0, 0));

	_itow_s(num, mystr, 10);
	pDC->TextOutW(195, 195, mystr);
}
void Cexample_projectView::MyDraw(CDC* pDC)
{
	CPen penBlue;
	penBlue.CreatePen(PS_SOLID | PS_COSMETIC, 1, RGB(0, 0, 255));
	pDC->SelectObject(&penBlue);
	pDC->Rectangle(100, 100, 300, 300);
}

void Cexample_projectView::OnDraw(CDC* pDC)
{
	Cexample_projectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
	CRect rectClient;
	CPoint StartPoint, EndPoint;
	rectClient.left = 100;
	rectClient.right = 300;
	rectClient.top = 100;
	rectClient.bottom = 300;
	CPen penBlue;
	CPen penRed;
	CPen* pOldPen;

	penBlue.CreatePen(PS_SOLID | PS_COSMETIC, 1, RGB(0, 0, 255));
	penRed.CreatePen(PS_SOLID | PS_COSMETIC, 1, RGB(255, 0, 0));
	pOldPen = pDC->SelectObject(&penBlue);

	MyDraw(pDC);

	int mydelay = 1000;

	CPoint PLeft, PRight, PTop, PBottom;

	PLeft.x = rectClient.left;
	PLeft.y = rectClient.CenterPoint().y;

	PRight.x = rectClient.right;
	PRight.y = rectClient.CenterPoint().y;

	PTop.x = rectClient.CenterPoint().x;
	PTop.y = rectClient.top;

	PBottom.x = rectClient.CenterPoint().x;
	PBottom.y = rectClient.bottom;

	for(int i = 1; i < 3; i++)
	{
		DrawMyObject(pDC, rectClient, PRight, PBottom);
		Sleep(mydelay);

		DrawMyObject(pDC, rectClient, PBottom, PLeft);
		Sleep(mydelay);

		DrawMyObject(pDC, rectClient, PLeft, PTop);
		Sleep(mydelay);

		DrawMyObject(pDC, rectClient, PTop, PRight);
		Sleep(mydelay);
	}
	
	for (int i = 4; i < 1000; i++)
	{
		int j = i%3;
		switch (j)
		{
			case 1: pDC->SetTextColor(RGB(255, 0, 0)); break;
			case 2: pDC->SetTextColor(RGB(0, 255, 0)); break;
			default: pDC->SetTextColor(RGB(0, 0, 255));
		}
		pDC->TextOutW(170, 195, _T("Hello!"));
		Sleep(10);
	}
	pDC->SelectObject(pOldPen);

}


// печать Cexample_projectView


void Cexample_projectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cexample_projectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void Cexample_projectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void Cexample_projectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void Cexample_projectView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cexample_projectView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// диагностика Cexample_projectView

#ifdef _DEBUG
void Cexample_projectView::AssertValid() const
{
	CView::AssertValid();
}

void Cexample_projectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexample_projectDoc* Cexample_projectView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexample_projectDoc)));
	return (Cexample_projectDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений Cexample_projectView
