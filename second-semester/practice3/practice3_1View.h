
// practice3_1View.h : интерфейс класса Cpractice3_1View
//

#pragma once

#include <math.h> // using for abs()

class Cpractice3_1View : public CView
{
protected: // создать только из сериализации
	Cpractice3_1View();
	DECLARE_DYNCREATE(Cpractice3_1View)

// Атрибуты
public:
	Cpractice3_1Doc* GetDocument() const;

// Операции
public:

	void CreateMinus(CDC* pDC) // create sign minus on the screen
	{
		CPen MyPen;
	
		pDC->SelectObject(MyPen);
		pDC->MoveTo(325, 225);
		pDC->LineTo(375, 225);

		DeleteObject(MyPen);
	};
	void CreateEqual(CDC* pDC) // create sign equal on the screen
	{
		CPen MyPen;
	
		pDC->SelectObject(MyPen);
		pDC->MoveTo(575, 215);
		pDC->LineTo(625, 215);
		pDC->MoveTo(575, 235);
		pDC->LineTo(625, 235);
	
		DeleteObject(MyPen);
	};

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~Cpractice3_1View();
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

#ifndef _DEBUG  // отладочная версия в practice3_1View.cpp
inline Cpractice3_1Doc* Cpractice3_1View::GetDocument() const
   { return reinterpret_cast<Cpractice3_1Doc*>(m_pDocument); }
#endif

// USER CLASS
class square
{
	long x, y, length; // coordinates (x, y) and length of square
    int rgb[3]; // color of squares
    
	public:
	void SetCoordinates(int x, int y, int length) // set coordinates and length of square
	{
		this->x = x;
		this->y = y;
		this->length = length;
	};
    void SetColor(int r = 255, int g = 255, int b = 255) // set color of square
    {
        rgb[0] = r;
        rgb[1] = g;
        rgb[2] = b;
    };
	square(long x = 240, long y = 320, long length = 25) // constructor
	{
		SetCoordinates(x, y, length);
		SetColor();
	};
	void CreateSquare(CDC *pDC) // create square
	{
		CBrush MyBrush(RGB(rgb[0], rgb[1], rgb[2]));
        
        pDC->SelectObject(MyBrush);
		pDC->Rectangle(x - length/2, y - length/2, x + length/2, y + length/2);
        
		DeleteObject(MyBrush);
	};
	friend square& operator -(square& A, square& B); // operation minus relatively color of squares
};
/*class square
{
	long x, y, length; // coordinates (x, y) and length of square
    int rgb[3]; // color of squares
    
	public:
	void SetCoordinates(int x, int y, int length);
    void SetColor(int r = 255, int g = 255, int b = 255);
	square(long x = 240, long y = 320, long length = 25);
	void CreateSquare(CDC *pDC);
	friend square& operator -(square& A, square& B);
};*/