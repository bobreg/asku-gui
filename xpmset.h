#ifndef __XPMSET_H__
#define __XPMSET_H__

#include "QPixmap"
#include "QMap"

//----------------------------------------------------------------------------------------------------------------

class AskuPixmapSet : public QMap<QString, QPixmap>
{
public:
	AskuPixmapSet();
	~AskuPixmapSet();

	bool init();
};

//----------------------------------------------------------------------------------------------------------------

extern AskuPixmapSet m_pixmaps;

//----------------------------------------------------------------------------------------------------------------

#endif // __XPMSET_H__
