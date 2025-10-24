#pragma once
#include <QLayout>
#include <vector>

class DxOverlayItem;

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
	void addWidget(QWidget* w, Qt::Alignment alig);

private:
	
	DxOverlayItem* CreateItem(QWidget* w, Qt::Alignment alig = Qt::AlignCenter);

private:
	std::vector<DxOverlayItem*> m_items;
	QSize m_hint;
};

class DxOverlayItem : public QWidgetItem
{
public:
	DxOverlayItem(QWidget* widget, Qt::Alignment alig);

	QRect m_Geom;
};