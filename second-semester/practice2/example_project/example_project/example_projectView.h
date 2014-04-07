
// example_projectView.h : интерфейс класса Cexample_projectView
//

#pragma once


class Cexample_projectView : public CView
{
protected: // создать только из сериализации
	Cexample_projectView();
	DECLARE_DYNCREATE(Cexample_projectView)

// Атрибуты
public:
	Cexample_projectDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	void DrawMyObject(CDC* pDC, CRect rectClient, CPoint Start, CPoint End);
	void MyDraw(CDC* pDC);
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~Cexample_projectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в example_projectView.cpp
inline Cexample_projectDoc* Cexample_projectView::GetDocument() const
   { return reinterpret_cast<Cexample_projectDoc*>(m_pDocument); }
#endif

