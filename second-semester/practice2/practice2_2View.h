
// practice2_2View.h : interface of the Cpractice2_2View class
//

#pragma once


class Cpractice2_2View : public CView
{
protected: // create from serialization only
	Cpractice2_2View();
	DECLARE_DYNCREATE(Cpractice2_2View)

// Attributes
public:
	Cpractice2_2Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cpractice2_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in practice2_2View.cpp
inline Cpractice2_2Doc* Cpractice2_2View::GetDocument() const
   { return reinterpret_cast<Cpractice2_2Doc*>(m_pDocument); }
#endif

// USER CLASS

class smile
{
	float radius_circle, x_r, y_r; // face of smile
	float radius_left_eye, x_le, y_le; // left eye of smile
	float radius_right_eye, x_re, y_re; // right eye of smile
	POINT pnt_obj[5]; // coordinates for lips
	int rgb[3]; // color of lines

public:
	
	int choose_lips; // choose lips of smile

	smile(float r = 25, float x = 320, float y = 240) // constructor
	{
		radius_circle = r;
		x_r = x;
		y_r = y;
		radius_left_eye = 0.2*r;
		x_le = x - 0.5*r;
		y_le = y - 0.5*r;
		radius_right_eye = 0.2*r;
		x_re = x + 0.5*r;
		y_re = y - 0.5*r;
		for (int i = 0; i < 3; i++)
			rgb[i] = 0;
	};
	void setColor(int r, int g, int b) // set the color of lines
	{
		rgb[0] = r;
		rgb[1] = g;
		rgb[2] = b;
	};
	void createLips(CDC* pDC) // the list of lips (create)
	{
		switch (choose_lips)
		{
		case 1: // the happy lips
		{
			pnt_obj[0].x = x_r - 0.7*radius_circle;
			pnt_obj[0].y = y_r + 0.5*radius_circle;
			pnt_obj[1].x = x_r - 0.3*radius_circle;
			pnt_obj[1].y = y_r + 0.8*radius_circle;
			pnt_obj[2].x = x_r + 0.3*radius_circle;
			pnt_obj[2].y = y_r + 0.8*radius_circle;
			pnt_obj[3].x = x_r + 0.7*radius_circle;
			pnt_obj[3].y = y_r + 0.5*radius_circle;

			CPen* Pen;
			Pen = new CPen(PS_SOLID | PS_COSMETIC, 1, RGB(rgb[0], rgb[1], rgb[2]));
			pDC->SelectObject(Pen);
			pDC->Polyline(pnt_obj, 4);

			delete Pen;

			break;
		};
		case 2: // the serious lips
		{
			pnt_obj[0].x = x_r - 0.7*radius_circle;
			pnt_obj[0].y = y_r + 0.5*radius_circle;
			pnt_obj[1].x = x_r + 0.7*radius_circle;
			pnt_obj[1].y = y_r + 0.5*radius_circle;

			CPen* Pen;
			Pen = new CPen(PS_SOLID | PS_COSMETIC, 1, RGB(rgb[0], rgb[1], rgb[2]));
			pDC->SelectObject(Pen);
			pDC->Polyline(pnt_obj, 2);

			delete Pen;

			break;
		};
		case 3: // the sad lips
		{
			pnt_obj[0].x = x_r - 0.7*radius_circle;
			pnt_obj[0].y = y_r + 0.5*radius_circle;
			pnt_obj[1].x = x_r - 0.3*radius_circle;
			pnt_obj[1].y = y_r + 0.2*radius_circle;
			pnt_obj[2].x = x_r + 0.3*radius_circle;
			pnt_obj[2].y = y_r + 0.2*radius_circle;
			pnt_obj[3].x = x_r + 0.7*radius_circle;
			pnt_obj[3].y = y_r + 0.5*radius_circle;

			CPen* Pen;
			Pen = new CPen(PS_SOLID | PS_COSMETIC, 1, RGB(rgb[0], rgb[1], rgb[2]));
			pDC->SelectObject(Pen);
			pDC->Polyline(pnt_obj, 4);

			delete Pen;

			break;
		};
		case 4: // the psycho lips
		{
			pnt_obj[0].x = x_r - 0.7*radius_circle;
			pnt_obj[0].y = y_r + 0.5*radius_circle;
			pnt_obj[1].x = x_r - 0.3*radius_circle;
			pnt_obj[1].y = y_r + 0.2*radius_circle;
			pnt_obj[2].x = x_r;
			pnt_obj[2].y = y_r + 0.8*radius_circle;
			pnt_obj[3].x = x_r + 0.3*radius_circle;
			pnt_obj[3].y = y_r + 0.2*radius_circle;
			pnt_obj[4].x = x_r + 0.7*radius_circle;
			pnt_obj[4].y = y_r + 0.5*radius_circle;

			CPen* Pen;
			Pen = new CPen(PS_SOLID | PS_COSMETIC, 1, RGB(rgb[0], rgb[1], rgb[2]));
			pDC->SelectObject(Pen);
			pDC->Polyline(pnt_obj, 5);

			delete Pen;

			break;
		};
		};
	};
	void deleteLips(CDC* pDC) // the list of lips (delete)
	{
		switch (choose_lips)
		{
		case 1: // the happy lips
		{
			CPen* Pen;

			Pen = new CPen(PS_SOLID | PS_COSMETIC, 1, RGB(255, 255, 255));
			pDC->SelectObject(Pen);
			pDC->Polyline(pnt_obj, 4);

			delete Pen;

			break;
		};
		case 2: // the serious lips
		{
			CPen* Pen;

			Pen = new CPen(PS_SOLID | PS_COSMETIC, 1, RGB(255, 255, 255));
			pDC->SelectObject(Pen);
			pDC->Polyline(pnt_obj, 2);

			delete Pen;

			break;
		};
		case 3: // the sad lips
		{
			CPen* Pen;

			Pen = new CPen(PS_SOLID | PS_COSMETIC, 1, RGB(255, 255, 255));
			pDC->SelectObject(Pen);
			pDC->Polyline(pnt_obj, 4);

			delete Pen;

			break;
		};
		case 4: // the psycho lips
		{
			CPen* Pen;

			Pen = new CPen(PS_SOLID | PS_COSMETIC, 1, RGB(255, 255, 255));
			pDC->SelectObject(Pen);
			pDC->Polyline(pnt_obj, 5);

			delete Pen;

			break;
		};
		};
	};
	void createBase(CDC* pDC) // create the base of smile
	{
		CPen Pen;
		Pen.CreatePen(PS_SOLID | PS_COSMETIC, 1, RGB(rgb[0], rgb[1], rgb[2]));
		pDC->SelectObject(&Pen);

		pDC->Ellipse(x_r - radius_circle, y_r - radius_circle, x_r + radius_circle, y_r + radius_circle); // make the face of smile
		pDC->Ellipse(x_le - radius_left_eye, y_le - radius_left_eye, x_le + radius_left_eye, y_le + radius_left_eye); // make the left eye
		pDC->Ellipse(x_re - radius_right_eye, y_re - radius_right_eye, x_re + radius_right_eye, y_re + radius_right_eye); // make the right eye

		DeleteObject(Pen);
	};
	void deleteBase(CDC* pDC) // delete the base of smile
	{
		CPen Pen;
		Pen.CreatePen(PS_SOLID | PS_COSMETIC, 1, RGB(255, 255, 255));
		pDC->SelectObject(&Pen);

		pDC->Ellipse(x_r - radius_circle, y_r - radius_circle, x_r + radius_circle, y_r + radius_circle); //fill an area of smile

		DeleteObject(Pen);
	};
};