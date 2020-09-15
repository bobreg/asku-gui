#ifndef __GLOBALVAR_H__
#define __GLOBALVAR_H__

#include <QHostAddress>
#include <QString>
#include "../common/global.h"

//��������� ����������

typedef struct tagMAIN
{
	quint32 id;
	quint32 shema;
	quint32 terminate;
}SetupMAIN;

typedef struct tagPATH
{
	QString config;
	QString level;
	QString scheme;
	QString media;
	QString dialog;
}SetupPATH;

typedef struct tagSetupDataUI
{
	QString file;
	qint32 scale_x;
	qint32 scale_y;
}SetupDataUI;

typedef struct tagMedia
{
	QString fileAvar;
	QString fileError;
	QString fileNot;
}SetupMedia;

typedef struct tagGPR
{
	QHostAddress ip1;
	QHostAddress ip2;
	quint16 port;
}SetupGPR;

typedef struct tagSetupData
{
	SetupMAIN main;
	SetupPATH path;
	SetupDataUI ui;
	SetupMedia media;
}SetupData;

#define IDGPR1 0
#define IDGPR2 1
#define IDPPV 2
#define IDRMO 3
#define IDURM 4

#define MAX_ACTIVE_GPR 2

#define MYID() (m_setup.main.id)
#define ISGPR() (m_setup.main.id < IDPPV)
#define ISGPR1() (m_setup.main.id == IDGPR1)
#define ISGPR2() (m_setup.main.id == IDGPR2)
#define ISPPV() (m_setup.main.id == IDPPV)
#define ISRMO() (m_setup.main.id == IDRMO || m_setup.main.id > IDURM)
#define ISURM() (m_setup.main.id == IDURM)

extern SetupData m_setup;

#endif // __GLOBALVAR_H__
