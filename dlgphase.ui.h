/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

#include <qmessagebox.h>
#include <qfiledialog.h>
#include "globalvar.h"
#include "canalasku.h"

void DlgPhase::init()
{
	comboSelectPrd->clear();
	comboSelectPrd->insertItem(trKOI8R("ВСЕ"));
	for(int t = 0; t < CA_N_TRANSMITTERS(); t++)
		comboSelectPrd->insertItem(QString::number(t+1));

	comboSelectModule->clear();
	comboSelectModule->insertItem(trKOI8R("ВСЕ УМИ"));
	for(int m = 0; m < CA_N_MODULES(); m++)
		comboSelectModule->insertItem(trKOI8R("УМИ-")+QString::number(m+1));
	if(ASKU_TYPE()==ASKU_TYPE_OBSERVER)
	{
		comboSelectModule->insertItem(trKOI8R("УМИ1-16"));
		comboSelectModule->insertItem(trKOI8R("УМИ17-32"));
	}
	
	for(int i = 0; i < CA_N_TRANSMITTERS(); i++)
	{
		QTable *table;
		int row, col;

		if(i==0)
			table = tablePhase1;
		else if(i==1)
			table = tablePhase2;
		else
			continue;

		table->setNumRows(CA_N_MODULES());

		table->setSelectionMode(QTable::NoSelection);

		for(row = 0; row < table->numRows(); row++)
			table->verticalHeader()->setLabel(row, QString(trKOI8R("УМИ-%1")).arg(row+1));

		table->horizontalHeader()->setResizeEnabled(FALSE);
		table->horizontalHeader()->setClickEnabled(FALSE);

		table->verticalHeader()->setResizeEnabled(FALSE);
		table->verticalHeader()->setClickEnabled(FALSE);

		for(row = 0; row < table->numRows(); row++)
			for(col = 0; col < table->numCols(); col++)	
			{
				QTableItem::EditType et = QTableItem::Never;

				if(col == 3 || col == 4)//code phase, phase
					et = QTableItem::OnTyping;

				QTableItem *item = new QTableItem(table, et);
				table->setItem(row,col,item);
			}

		table->adjustColumn(0);
		table->adjustColumn(1);
		table->adjustColumn(2);
		table->adjustColumn(3);
	
//		table->setMinimumHeight(32 + 20 * table->numRows());
		table->setMinimumWidth(490);
	}
}


void DlgPhase::showDlg()
{
	emit sigRefresh();
	show();
}


void DlgPhase::pushOpen_clicked()
{
	int i;
	QByteArray values[2];
	bool success = true;

    QString fileName = QFileDialog::getOpenFileName(m_setup.pathPhase,"Phase files (*.phf)",this,0,trKOI8R("Выберите файл фазировки передатчика..."));
    while(!fileName.isNull())
	{
		qDebug("selected=%s", fileName.ascii());
		QFile phf(fileName);
		if(phf.open(IO_ReadOnly))
		{
            QTextStream phfs(&phf);
			for(i = 0; i < 2; i++)
			{
				QString str = phfs.readLine();
				if(str.isNull())
				{
					success = false;
					break;
				}

				QStringList list = QStringList::split(":", str);
				if(list.count() != 2)
				{
					success = false;
					break;
				}

				if(!((i == 0 && list[0] == "PRD1") || (i == 1 && list[0] == "PRD2")))
				{
					success = false;
					break;
				}

				QStringList vlist = QStringList::split(",",list[1]);
				if((int)vlist.count() != CA_N_MODULES())
				{
					success = false;
					break;
				}

				values[i].resize(vlist.count());

				for(unsigned int k = 0; k < vlist.count(); k++)
				{
					vlist[k] = vlist[k].simplifyWhiteSpace();
					if(!vlist[k].isEmpty())
					{
						bool ok = false;
						unsigned int value = vlist[k].toUInt(&ok,10);
						if(!ok)
						{
							success = false;
							values[i].at(k) = -1;
						}
						else
						{
							values[i].at(k) = value;
						}
					}
					else
					{
						success = false;
						values[i].at(k) = -1;
					}
				}
			}
		}
		break;
	}

	if(!fileName.isNull())
	{
		if(!success)
			QMessageBox::information(this,QString(trKOI8R("Ошибка!")),trKOI8R("Ошибка файла!"));
		else
		{
			for(i = 0; i < 2; i++)
			{
				QTable *table;

				if(i==0)
					table = tablePhase1;
				else if(i==1)
					table = tablePhase2;

				for(unsigned int row = 0; row < values[i].count(); row++)
				{
					int col_cd = 3, col_ph = 4;

					table->item(row,col_ph)->setText("");
					table->updateCell(row, col_ph);

					table->item(row,col_cd)->setText(QString("%1").arg(values[i].at(row),0,10));
					table->updateCell(row, col_cd);
				}
			}

			QMessageBox::information(this,QString(trKOI8R("Фазировка ПРД")),trKOI8R("Файл успешно загружен!"));
		}
	}
}


void DlgPhase::pushSave_clicked()
{
	int i;
	QByteArray values[2];
	int count = 0;

	for(i = 0; i < CA_N_TRANSMITTERS(); i++)
	{
		QTable *table;
		int row, col;

		if(i==0)
			table = tablePhase1;
		else if(i==1)
			table = tablePhase2;
		else
			continue;

		values[i].resize(table->numRows());

		for(row = 0; row < table->numRows(); row++)
		{
			col = 3;
			QString text = table->item(row,col)->text();
			if(!text.isEmpty())
			{
				bool ok = false;
				int value = text.toUInt(&ok,10);
				if(!ok)
				{
					QMessageBox::critical(this,QString(trKOI8R("Ошибка - ПРД-%1 УМИ-%2")).arg(i+1).arg(row+1),trKOI8R("Значение кода фазы некорректно"));
					table->setFocus();
					table->setCurrentCell(row,col);
					table->ensureCellVisible(row,col);
					return;
				}
				else if(value < 0 || value > 63)
				{
					QMessageBox::critical(this,QString(trKOI8R("Ошибка - ПРД-%1 УМИ-%2")).arg(i+1).arg(row+1),trKOI8R("Значение кода фазы должно быть в диапазоне 0...63"));
					table->setFocus();
					table->setCurrentCell(row,col);
					table->ensureCellVisible(row,col);
					return;
				}
				else
				{
					values[i][row] = value;
				}
			}
			else
			{
				QMessageBox::critical(this,QString(trKOI8R("Ошибка - ПРД-%1 УМИ-%2")).arg(i+1).arg(row+1),trKOI8R("Значение кода фазы не задано"));
				table->setFocus();
				table->setCurrentCell(row,col);
				table->ensureCellVisible(row,col);
				return;
			}
		}
	}

	QString fileName = QFileDialog::getSaveFileName(m_setup.pathPhase,"Phase files (*.phf)",this,0,trKOI8R("Задайте имя файла фазировки передатчика..."));
    if(!fileName.isNull())
	{
		qDebug("selected=%s", fileName.ascii());
		if((fileName.length() < 4) || (fileName.right(4) != QString(".phf")))
			fileName += QString(".phf");
		QFile phf(fileName);
		if(phf.open(IO_WriteOnly))
		{
            QTextStream phfs(&phf);
			for(i = 0; i < 2; i++)
			{
				phfs << QString("PRD%1: ").arg(i+1);
				for(unsigned int j = 0; j < values[i].count(); j++)
				{
					phfs << QString("%1").arg(values[i].at(j),2,10);
					if(j == values[i].count() - 1)
						 phfs << endl;
					else
						 phfs << ", ";
				}
			}
			phf.close();

			QMessageBox::information(this,QString(trKOI8R("Фазировка ПРД")),trKOI8R("Файл сохранен успешно!"));
		}
	}
}


void DlgPhase::pushRefresh_clicked()
{
	emit sigRefresh();
}


void DlgPhase::pushApply_clicked()
{
	int i;
	unsigned int j;
	QByteArray values[2];
	int count = 0;

	for(i = 0; i < CA_N_TRANSMITTERS(); i++)
	{
		QTable *table;
		int row, col;

		if(i==0)
			table = tablePhase1;
		else if(i==1)
			table = tablePhase2;
		else
			continue;

		values[i].resize(table->numRows());

		for(row = 0; row < table->numRows(); row++)
		{
			col = 3;
			QString text = table->item(row,col)->text();
			if(!text.isEmpty())
			{
				bool ok = false;
				int value = text.toUInt(&ok,10);
				if(!ok)
				{
					QMessageBox::critical(this,QString(trKOI8R("Ошибка - ПРД-%1 УМИ-%2")).arg(i+1).arg(row+1),trKOI8R("Значение кода фазы некорректно"));
					table->setFocus();
					table->setCurrentCell(row,col);
					table->ensureCellVisible(row,col);
					return;
				}
				else if(value < 0 || value > 63)
				{
					QMessageBox::critical(this,QString(trKOI8R("Ошибка - ПРД-%1 УМИ-%2")).arg(i+1).arg(row+1),trKOI8R("Значение кода фазы должно быть в диапазоне 0...63"));
					table->setFocus();
					table->setCurrentCell(row,col);
					table->ensureCellVisible(row,col);
					return;
				}
				else
				{
					values[i][row] = value;
				}
			}
			else
			{
				values[i][row] = -1;
			}
		}
	}

	for(i = 0; i < CA_N_TRANSMITTERS(); i++)
	{
		if(i < 2)
		{
			for(j = 0; j < values[i].count(); j++)
			{
				if(values[i].at(j) >= 0 && values[i].at(j) <= 63)
				{
					emit sigSetPhase(values[i].at(j),i+1,j+1);
					count++;
				}
			}
		}
	}

	if(!count)
		QMessageBox::critical(this,QString(trKOI8R("Ошибка")),trKOI8R("Нет значений коды фазы!"));
	else
		emit sigPhaseApply(true);
}


void DlgPhase::pushClose_clicked()
{
	emit sigClosed();
	hide();
}


void DlgPhase::slotUpdateModule( int n_prd, int n_module, bool valid, QString serial, int phase, int sv_phase )
{
//	qDebug("slotUpdateModule: prd=%d module=%d valid=%d serial=%s phase=%d",n_prd,n_module,valid,serial.ascii(),phase);
	QTable *table;

	if(n_prd == 0)
		table = tablePhase1;
	else if(n_prd == 1)
		table = tablePhase2;
	else
		return;

	if(n_module < 0 || n_module > (table->numRows() - 1))
		return;

	if(!valid)
	{
		QString invalidText = QString("---");
		table->setText(n_module,0,invalidText);
		table->setText(n_module,1,invalidText);
		table->setText(n_module,2,invalidText);
	}
	else
	{
		table->setText(n_module,0,serial);
		table->setText(n_module,1,QString("%1").arg(sv_phase));
		table->setText(n_module,2,QString("%1").arg(phase));
	}
}


void DlgPhase::pushClear1_clicked()
{
	for(int row = 0; row < tablePhase1->numRows(); row++)
		tablePhase1->setText(row,3,"");
}


void DlgPhase::pushClear2_clicked()
{
	for(int row = 0; row < tablePhase2->numRows(); row++)
		tablePhase2->setText(row,3,"");
}


void DlgPhase::tablePhase1_valueChanged( int row, int col )
{
	QTable *table = tablePhase1;
	if(col == 4)//set phase value
	{
		qDebug("1 phase value changed (%d,%d)=%s", row, col, table->item(row, col)->text().ascii());

		int col_cd = 3;
		table->item(row,col_cd)->setText("");
		table->updateCell(row, col_cd);
	}
	else if(col == 3)//set code phase value
	{
		qDebug("1 phase code changed (%d,%d)=%s", row, col, table->item(row, col)->text().ascii());

		int col_ph = 4;
		table->item(row,col_ph)->setText("");
		table->updateCell(row, col_ph);
	}
}


void DlgPhase::tablePhase2_valueChanged( int row, int col )
{
	QTable *table = tablePhase2;
	if(col == 4)//set phase value
	{
		qDebug("2 phase value changed (%d,%d)=%s", row, col, table->item(row, col)->text().ascii());

		int col_cd = 3;
		table->item(row,col_cd)->setText("");
		table->updateCell(row, col_cd);
	}
	else if(col == 3)//set code phase value
	{
		qDebug("2 phase code changed (%d,%d)=%s", row, col, table->item(row, col)->text().ascii());

		int col_ph = 4;
		table->item(row,col_ph)->setText("");
		table->updateCell(row, col_ph);
	}
}


void DlgPhase::pushMeasure_clicked()
{
	emit sigMeasure(comboSelectPrd->currentItem(), comboSelectModule->currentItem(), checkBoxAuto->state() == QButton::On);
}


void DlgPhase::pushPhase_clicked()
{
	int i;
	QValueVector<double> values[2];
	int count = 0;
	double phaseTarget = 0;


	QString textTarget = lineEditPhase->text();
	if(!textTarget.isEmpty())
	{
		bool ok = false;
		double value = textTarget.toDouble(&ok);
		if(!ok)
		{
			lineEditPhase->setFocus();
			QMessageBox::critical(this,trKOI8R("Ошибка - Значение целевой фазы"),trKOI8R("Значение Фцел не корректно"));
			return;
		}
		else if(value < -180.0 || value > 180.0)
		{
			lineEditPhase->setFocus();
			QMessageBox::critical(this,trKOI8R("Ошибка - Значение целевой фазы"),trKOI8R("Значение Фцел должно быть в диапазоне -180...180"));
			return;
		}
		else
		{
			phaseTarget = value;
			qDebug("target=%3.3f",(float)phaseTarget);
		}
	}
	else
	{
		lineEditPhase->setFocus();
		QMessageBox::critical(this,trKOI8R("Ошибка - Значение целевой фазы"),trKOI8R("Значение Фцел не задано"));
		return;
	}


	for(i = 0; i < CA_N_TRANSMITTERS(); i++)
	{
		QTable *table;
		int row, col_ph;

		if(i==0)
			table = tablePhase1;
		else if(i==1)
			table = tablePhase2;
		else
			continue;

		values[i].resize(table->numRows());

		for(row = 0; row < table->numRows(); row++)
		{
			col_ph = 4;
			QString text = table->item(row,col_ph)->text();
			if(!text.isEmpty())
			{
				bool ok = false;
				double value = text.toDouble(&ok);
				if(!ok)
				{
					QMessageBox::critical(this,QString(trKOI8R("Ошибка - ПРД-%1 УМИ-%2")).arg(i+1).arg(row+1),trKOI8R("Значение фазы некорректно"));
					table->setFocus();
					table->setCurrentCell(row,col_ph);
					table->ensureCellVisible(row,col_ph);
					return;
				}
				else if(value < -180.0 || value > 180.0)
				{
					QMessageBox::critical(this,QString(trKOI8R("Ошибка - ПРД-%1 УМИ-%2")).arg(i+1).arg(row+1),trKOI8R("Значение фазы должно быть в диапазоне -180...180"));
					table->setFocus();
					table->setCurrentCell(row,col_ph);
					table->ensureCellVisible(row,col_ph);
					return;
				}
				else
				{
					values[i][row] = value;
					count++;
				}
			}
			else
			{
				values[i][row] = -360.0;
			}
		}
	}

	for(i = 0; i < CA_N_TRANSMITTERS(); i++)
	{
		QTable *table;
		int row, col_cd;

		if(i==0)
			table = tablePhase1;
		else if(i==1)
			table = tablePhase2;
		else
			continue;

		if(i < 2)
		{
			for(row = 0; row < table->numRows(); row++)
			{
				col_cd = 3;
				double phvalue = values[i].at(row);
				if(phvalue >= -180.0 && phvalue <= 180.0)
				{
					qDebug("phase=%3.3f",(float)phvalue);
					unsigned int cdvalue = 0;
					unsigned int phcode = calc_phase_code(phaseTarget, phvalue, cdvalue);
					table->item(row,col_cd)->setText(QString("%1").arg(phcode));
					table->updateCell(row, col_cd);
					count++;
				}
			}
		}
	}

	if(!count)
		QMessageBox::critical(this,QString(trKOI8R("Ошибка")),trKOI8R("Нет значений фазы!"));
}


void DlgPhase::slotPhaseValue( int n_prd, int n_module, double value )
{
	qDebug("slotPhaseValue: prd=%d module=%d phase=%3.1f",n_prd,n_module,value);
	QTable *table;

	if(n_prd == 0)
		table = tablePhase1;
	else if(n_prd == 1)
		table = tablePhase2;
	else
		return;

	if(n_module < 0 || n_module > (table->numRows() - 1))
		return;

	int col_cd = 3;
	int col_ph = 4;
	table->setText(n_module, col_ph, QString("%1").arg(value,0,'f',3));
	table->updateCell(n_module, col_ph);
	table->setText(n_module, col_cd, "");
	table->updateCell(n_module, col_cd);
}


unsigned int DlgPhase::calc_phase_code(double target, double phase, unsigned int nowcode)
{
	unsigned int code = 0;
	double delta = phase - target;

	qDebug("delta=%3.3f", delta);

	if(delta == 0.0)
	{
		code = nowcode;
	}
	else if(delta < 0.0)
	{
		code = nowcode + myRound((360.0 + delta) / 5.625);
		if(code >= 64)
			code -= 64;
	}
	else if(delta > 0.0)
	{
		code = nowcode + myRound(delta / 5.625);
		if(code >= 64)
			code -= 64;
	}

	qDebug("code=%d",code);

	return code;
}


void DlgPhase::pushMiddle_clicked()
{
	int i;
	int count = 0;
	double phaseMiddle = 0.0;

	for(i = 0; i < CA_N_TRANSMITTERS(); i++)
	{
		QTable *table;
		int row, col_ph;

		if(i==0)
			table = tablePhase1;
		else if(i==1)
			table = tablePhase2;
		else
			continue;

		for(row = 0; row < table->numRows(); row++)
		{
			col_ph = 4;
			QString text = table->item(row,col_ph)->text();
			if(!text.isEmpty())
			{
				bool ok = false;
				double value = text.toDouble(&ok);
				if(!ok)
				{
					QMessageBox::critical(this,QString(trKOI8R("Ошибка - ПРД-%1 УМИ-%2")).arg(i+1).arg(row+1),trKOI8R("Значение фазы некорректно"));
					table->setFocus();
					table->setCurrentCell(row,col_ph);
					table->ensureCellVisible(row,col_ph);
					return;
				}
				else if(value < -180.0 || value > 180.0)
				{
					QMessageBox::critical(this,QString(trKOI8R("Ошибка - ПРД-%1 УМИ-%2")).arg(i+1).arg(row+1),trKOI8R("Значение фазы должно быть в диапазоне -180...180"));
					table->setFocus();
					table->setCurrentCell(row,col_ph);
					table->ensureCellVisible(row,col_ph);
					return;
				}
				else
				{
					phaseMiddle += value;
					count++;
				}
			}
		}
	}

	if(!count)
		QMessageBox::critical(this,QString(trKOI8R("Ошибка")),trKOI8R("Нет значений коды фазы!"));
	else
	{
		lineEditPhase->setText(QString("%1").arg(phaseMiddle/count,0,'f',3));
	}
}


void DlgPhase::pushClearPhase1_clicked()
{
	for(int row = 0; row < tablePhase1->numRows(); row++)
		tablePhase1->setText(row,4,"");
}


void DlgPhase::pushClearPhase2_clicked()
{
	for(int row = 0; row < tablePhase2->numRows(); row++)
		tablePhase2->setText(row,4,"");
}
