#include <QMessageBox>
#include "globalvar.h"
#include "dlgmeasure.h"
#include "../common/module.h"
#include "../common/logger.h"

//-------------------------------------------------------------------------------
DlgMeasure::DlgMeasure(QWidget *parent) : AskuDialog("dialog_measure", parent)
{
	ui.setupUi(this);
}

//-------------------------------------------------------------------------------
DlgMeasure::~DlgMeasure()
{
}

//-------------------------------------------------------------------------------
void DlgMeasure::on_pushSetPhase_clicked()
{
	bool ok = false;
	double flPhase = ui.linePhase->text().toDouble(&ok);

	if(!ok || flPhase < -180.0 || flPhase > 180.0)
	{
		ui.textPhase->setText("");
		QMessageBox::warning(this, "Ошибка!", "Некорректное значение фазы.\nФаза модуля = -180....180 градусов");
	}
	else
	{
		ui.textPhase->setText(QString("%1").arg(flPhase,0,'f',3));
		ui.pushNext->setEnabled(true);
	}
}

//-------------------------------------------------------------------------------
void DlgMeasure::on_pushNext_clicked()
{
//	qint32 n_prd = ui.textPrd->text().toInt();
//	qint32 n_module = ui.textModule->text().toInt();
//	double value = ui.linePhase->text().toDouble();
//	emit sigNext(n_prd, n_module, value);
}

//-------------------------------------------------------------------------------
void DlgMeasure::on_pushCancel_clicked()
{
//	emit sigCancel();
}

//-------------------------------------------------------------------------------
void DlgMeasure::setUpdate(qint32 n_prd, qint32 n_module, bool avto)
{
	ui.textPrd->setText(n_prd ? QString::number(n_prd) : "");
	ui.textModule->setText(n_module ? QString::number(n_module) : "");
	ui.textPhase->setText("");
	ui.linePhase->setText("");

	if(!avto && n_prd && n_module)
		ui.linePhase->setFocus();
}

//-------------------------------------------------------------------------------
void DlgMeasure::setProgress(qint32 value)
{
	ui.progressBar->setValue(value);
}

//-------------------------------------------------------------------------------
void DlgMeasure::setStatus(qint32 value, QString text)
{
	if(value == 2)
	{
		ui.pushCancel->setText("Закрыть");
	}
	else
	{
		ui.pushCancel->setText("Отмена");
	}
	if(value == 4)
	{
		ui.pushNext->setText("Закрыть");
	}
	else
	{
		ui.pushNext->setText("Далее");
	}

	if(value == 0)
	{
		ui.pushNext->setEnabled(false);
		ui.pushCancel->setEnabled(true);
		ui.pushSetPhase->setEnabled(false);
		ui.linePhase->setEnabled(false);
	}
	else if(value == 1)
	{
		ui.pushNext->setEnabled(false);
		ui.pushCancel->setEnabled(true);
		ui.pushSetPhase->setEnabled(false);
		ui.linePhase->setEnabled(false);
	}
	else if(value == 2)
	{
		ui.pushNext->setEnabled(false);
		ui.pushCancel->setEnabled(true);
		ui.pushSetPhase->setEnabled(false);
		ui.linePhase->setEnabled(false);
	}
	else if(value == 3)
	{
		ui.pushNext->setEnabled(false);
		ui.pushCancel->setEnabled(true);
		ui.pushSetPhase->setEnabled(true);
		ui.linePhase->setEnabled(true);
	}
	else if(value == 5)
	{
		ui.pushNext->setEnabled(true);
		ui.pushCancel->setEnabled(true);
		ui.pushSetPhase->setEnabled(false);
		ui.linePhase->setEnabled(false);
	}
	else if(value == 6)
	{
		ui.pushNext->setEnabled(false);
		ui.pushCancel->setEnabled(true);
		ui.pushSetPhase->setEnabled(false);
		ui.linePhase->setEnabled(false);
	}

	ui.textStatus->setText(text);
}

//-------------------------------------------------------------------------------
void DlgMeasure::setOscPhase(double value, bool valid)
{
	Q_UNUSED(valid);
	ui.textPhase->setText(QString("%1").arg(value,0,'f',3));
}

//-------------------------------------------------------------------------------
void DlgMeasure::setAvtoMode(bool avto)
{
	if(avto)
	{
		ui.pushNext->hide();
		ui.pushSetPhase->hide();
		ui.linePhase->hide();
	}
	else
	{
		ui.pushNext->show();
		ui.pushSetPhase->show();
		ui.linePhase->show();
	}
}

//-------------------------------------------------------------------------------
