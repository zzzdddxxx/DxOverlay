#pragma once
#include <QLayout>
#include <vector>

class DxOverlayItem;

class DxMargin : public QRect
{
public:
	DxMargin(int left = 5, int top = 5, int right = 5, int bottom = 5);
};

class DxOverlay : public QLayout
{
	Q_OBJECT

public:
	DxOverlay(QWidget* parent = nullptr);
	~DxOverlay();

	virtual QSize sizeHint() const override;
	virtual void addItem(QLayoutItem*) override;
	virtual QLayoutItem* itemAt(int index) const override;
	virtual QLayoutItem* takeAt(int index) override;
	virtual int count() const override;

	virtual void setGeometry(const QRect&) override;

	void addWidget(QWidget* w);
	void addWidget(QWidget* w, Qt::Alignment alig, DxMargin margin = DxMargin());

private:
	
	DxOverlayItem* CreateItem(QWidget* w, Qt::Alignment alig = Qt::AlignCenter, DxMargin margin = DxMargin());

private:
	std::vector<DxOverlayItem*> m_items;
	QSize m_hint;
};

class DxOverlayItem : public QWidgetItem
{
public:
	DxOverlayItem(QWidget* widget, Qt::Alignment alig, DxMargin margin);

	QRect m_Geom;
	DxMargin m_margin;
};