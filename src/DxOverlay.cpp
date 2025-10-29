#include "DXOverlay.h"

DxOverlay::DxOverlay(QWidget* parent) : QLayout(parent)
{
}

DxOverlay::~DxOverlay()
{
	for (auto item : m_items)
	{
		delete item;
	}
}

QSize DxOverlay::sizeHint() const
{
	return m_hint;
}

void DxOverlay::addItem(QLayoutItem*)
{
}

QLayoutItem* DxOverlay::itemAt(int index) const
{
	return nullptr;
}

QLayoutItem* DxOverlay::takeAt(int index)
{
	return nullptr;
}

int DxOverlay::count() const
{
	return 0;
}

void DxOverlay::setGeometry(const QRect& region)
{
	QSize overlaySize;

	for (int i = 0; i < m_items.size(); ++i)
	{
		DxOverlayItem* item = m_items[i];
		if (!item)
			continue;
		QSize hint = item->sizeHint();

		if (item->alignment() & Qt::AlignLeft)
		{
			int left = item->m_margin.left();
			item->m_Geom.setLeft(left);
		}
		else if (item->alignment() & Qt::AlignHCenter)
		{
			int left = (region.width() - hint.width()) >> 1;
			item->m_Geom.setLeft(left);
		}
		else if (item->alignment() & Qt::AlignRight)
		{
			int left = region.width() - hint.width() - item->m_margin.right();
			item->m_Geom.setLeft(left);
		}
		item->m_Geom.setRight(item->m_Geom.left() + hint.width());
		overlaySize.setWidth(std::max(overlaySize.width(), item->m_Geom.right()));

		if (item->alignment() & Qt::AlignTop)
		{
			int top = item->m_margin.top();
			item->m_Geom.setTop(top);
		}
		else if (item->alignment() & Qt::AlignVCenter)
		{
			int top = (region.height() - hint.height()) >> 1;
			item->m_Geom.setTop(top);
		}
		else if (item->alignment() & Qt::AlignBottom)
		{
			int top = region.height() - hint.height() - item->m_margin.bottom();
			item->m_Geom.setTop(top);
		}
		item->m_Geom.setBottom(item->m_Geom.top() + hint.height());
		overlaySize.setHeight(std::max(overlaySize.height(), item->m_Geom.bottom()));

	}

	m_hint = overlaySize;

	for (int i = 0; i < m_items.size(); ++i)
	{
		DxOverlayItem* item = m_items[i];
		item->setGeometry(item->m_Geom);
	}
}

void DxOverlay::addWidget(QWidget* w)
{
	addChildWidget(w);
	addWidget(w, Qt::AlignCenter, DxMargin());
}

void DxOverlay::addWidget(QWidget* w, Qt::Alignment alig, DxMargin margin)
{
	DxOverlayItem* pitem = CreateItem(w, alig, margin);
	if (pitem)
	{
		m_items.push_back(pitem);
		QLayout::invalidate();
	}
}

DxOverlayItem* DxOverlay::CreateItem(QWidget* w, Qt::Alignment alig, DxMargin margin)
{
	DxOverlayItem* pitem = new DxOverlayItem(w, alig, margin);
	return pitem;
}

DxOverlayItem::DxOverlayItem(QWidget* widget, Qt::Alignment alig, DxMargin margin) : QWidgetItem(widget)
{
	align = alig;
	m_margin = margin;
}

DxMargin::DxMargin(int left, int top, int right, int bottom)
{
	setLeft(left);
	setTop(top);
	setRight(right);
	setBottom(bottom);
}
