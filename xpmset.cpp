#include "globalvar.h"
#include "xpmset.h"

//----------------------------------------------------------------------------------------------------------------

#include "pixmap/levelup.xpm"
#include "pixmap/base.xpm"
#include "pixmap/zal.xpm"
#include "pixmap/viewer.xpm"
#include "pixmap/hide.xpm"
#include "pixmap/label.xpm"
#include "pixmap/icon.xpm"
#include "pixmap/panel.xpm"
#include "pixmap/panel_prd.xpm"
#include "pixmap/panel_elk.xpm"
#include "pixmap/howl.xpm"
#include "pixmap/time.xpm"
#include "pixmap/rgdv.xpm"
#include "pixmap/sbr_prd.xpm"
#include "pixmap/sbr_prd1.xpm"
#include "pixmap/sbr_prd2.xpm"
#include "pixmap/sbr_prm.xpm"
#include "pixmap/sbr_bep.xpm"
#include "pixmap/sbr_svo.xpm"
#include "pixmap/sbr_comm.xpm"
#include "pixmap/palette.xpm"
#include "pixmap/phase.xpm"
#include "pixmap/rmo.xpm"
#include "pixmap/sektors.xpm"
#include "pixmap/calibrate.xpm"
#include "pixmap/obzor.xpm"
#include "pixmap/gsh.xpm"
#include "pixmap/poi.xpm"
#include "pixmap/scan.xpm"
#include "pixmap/rozi.xpm"
#include "pixmap/antenna.xpm"
#include "pixmap/restart.xpm"
#include "pixmap/exit.xpm"
#include "pixmap/setprm.xpm"
#include "pixmap/skrpilot.xpm"

//----------------------------------------------------------------------------------------------------------------

AskuPixmapSet m_pixmaps;

//----------------------------------------------------------------------------------------------------------------

AskuPixmapSet::AskuPixmapSet()
{
	clear();
}

//----------------------------------------------------------------------------------------------------------------
AskuPixmapSet::~AskuPixmapSet()
{
	clear();
}

//----------------------------------------------------------------------------------------------------------------
bool AskuPixmapSet::init()
{
	insert("levelup.xpm",	QPixmap(levelup_xpm));
	insert("base.xpm",		QPixmap(base_xpm));
	insert("zal.xpm",		QPixmap(zal_xpm));
	insert("viewer.xpm",	QPixmap(viewer_xpm));
	insert("hide.xpm",		QPixmap(hide_xpm));
	insert("label.xpm",		QPixmap(label_xpm));
	insert("icon.xpm",		QPixmap(icon_xpm));
	insert("panel.xpm",		QPixmap(panel_xpm));
	insert("panel_elk.xpm",	QPixmap(panel_elk_xpm));
	insert("panel_prd.xpm",	QPixmap(panel_prd_xpm));
	insert("howl.xpm",		QPixmap(howl_xpm));
	insert("time.xpm",		QPixmap(time_xpm));
	insert("rgdv.xpm",		QPixmap(rgdv_xpm));
	insert("sbr_prd.xpm",	QPixmap(sbr_prd_xpm));
	insert("sbr_prd1.xpm",	QPixmap(sbr_prd1_xpm));
	insert("sbr_prd2.xpm",	QPixmap(sbr_prd2_xpm));
	insert("sbr_prm.xpm",	QPixmap(sbr_prm_xpm));
	insert("sbr_bep.xpm",	QPixmap(sbr_bep_xpm));
	insert("sbr_svo.xpm",	QPixmap(sbr_svo_xpm));
	insert("sbr_comm.xpm",	QPixmap(sbr_comm_xpm));
	insert("rmo.xpm",		QPixmap(rmo_xpm));
	insert("sektors.xpm",	QPixmap(sektors_xpm));
	insert("palette.xpm",	QPixmap(palette_xpm));
	insert("phase.xpm",		QPixmap(phase_xpm));
	insert("calibrate.xpm",	QPixmap(calibrate_xpm));
	insert("obzor.xpm",		QPixmap(obzor_xpm));
	insert("gsh.xpm",		QPixmap(gsh_xpm));
	insert("poi.xpm",		QPixmap(poi_xpm));
	insert("scan.xpm",		QPixmap(scan_xpm));
	insert("rozi.xpm",		QPixmap(rozi_xpm));
	insert("antenna.xpm",	QPixmap(antenna_xpm));
	insert("restart.xpm",	QPixmap(restart_xpm));
	insert("exit.xpm",		QPixmap(exit_xpm));
	insert("setprm.xpm",	QPixmap(setprm_xpm));
	insert("skrpilot.xpm",	QPixmap(skrpilot_xpm));

	return true;
}

//----------------------------------------------------------------------------------------------------------------
