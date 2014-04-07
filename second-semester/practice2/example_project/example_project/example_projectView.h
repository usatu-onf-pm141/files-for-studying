
// example_projectView.h : ��������� ������ Cexample_projectView
//

#pragma once


class Cexample_projectView : public CView
{
protected: // ������� ������ �� ������������
	Cexample_projectView();
	DECLARE_DYNCREATE(Cexample_projectView)

// ��������
public:
	Cexample_projectDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	void DrawMyObject(CDC* pDC, CRect rectClient, CPoint Start, CPoint End);
	void MyDraw(CDC* pDC);
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~Cexample_projectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � example_projectView.cpp
inline Cexample_projectDoc* Cexample_projectView::GetDocument() const
   { return reinterpret_cast<Cexample_projectDoc*>(m_pDocument); }
#endif

