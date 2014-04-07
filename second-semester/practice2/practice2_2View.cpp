
// practice2_2View.cpp : implementation of the Cpractice2_2View class
//

#include "stdafx.h"
#include <stdlib.h> // for srand()
#include <time.h> // for time()
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "practice2_2.h"
#endif

#include "practice2_2Doc.h"
#include "practice2_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cpractice2_2View

IMPLEMENT_DYNCREATE(Cpractice2_2View, CView)

BEGIN_MESSAGE_MAP(Cpractice2_2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cpractice2_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cpractice2_2View construction/destruction

Cpractice2_2View::Cpractice2_2View()
{
	// TODO: add construction code here

}

Cpractice2_2View::~Cpractice2_2View()
{
}

BOOL Cpractice2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cpractice2_2View drawing

void Cpractice2_2View::OnDraw(CDC* pDC)
{
	Cpractice2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	srand(time(NULL)); // for rand()

	// limit of radius: 20..60
	// limit of coordinates: (0+60..640-250, 0+60..480-250); rand() % (640 - 250) + 60
	// limit of color: (0..255, 0..255, 0..255)

	const int N = 6; // the number of smiles on the screen
	smile* objects[N];


	for (int i = 0; i < N; i++)
	{
		int k = 100; // width of placement
		int rad = rand() % (60 - 20) + 20; // random radius of smile
		objects[i] = new smile(rad, rand()%(k - 2*rad) + i*k + rad, rand() % (480 - 150) + 60);
		objects[i]->setColor(rand() % 256, rand() % 256, rand() % 256); // set the color of lines
	};

	for (int i = 0; i < N; i++)
		objects[i]->createBase(pDC); // create the base of smile

	int delay = 500; // for Sleep()
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < N; k++)
		{
			objects[k]->choose_lips = rand() % 4 + 1;
			objects[k]->createLips(pDC); // set the "smiles" of smile
		};

		Sleep(delay);
		
		for (int k = 0; k < N; k++)
			objects[k]->deleteLips(pDC); // delete the "smiles" of smile
	};
	
	for (int i = 0; i < N; i++)
		objects[i]->deleteBase(pDC); // delete the base of smile

	exit(0);
}


// Cpractice2_2View printing


void Cpractice2_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cpractice2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cpractice2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cpractice2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cpractice2_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cpractice2_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cpractice2_2View diagnostics

#ifdef _DEBUG
void Cpractice2_2View::AssertValid() const
{
	CView::AssertValid();
}

void Cpractice2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cpractice2_2Doc* Cpractice2_2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cpractice2_2Doc)));
	return (Cpractice2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cpractice2_2View message handlers
