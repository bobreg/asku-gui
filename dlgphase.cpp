#include <QMessageBox>
#include "globalvar.h"
#include "dlgphase.h"
#include "../common/module.h"
#include "../common/logger.h"

//-------------------------------------------------------------------------------
DlgPhase::DlgPhase(QWidget *parent) : AskuDialog("dialog_phase", parent, Qt::Window)
{
	ui.setupUi(this);

	m_selectors.clear();
	setActive(false);

	ui.comboSelectPrd->clear();
	ui.comboSelectModule->clear();
	ui.tablePhase1->setRowCount(0);
	ui.tablePhase2->setRowCount(0);
}

//-------------------------------------------------------------------------------
DlgPhase::~DlgPhase()
{
}

//-------------------------------------------------------------------------------
void DlgPhase::refreshSelectors()
{
	QVariantList list;

	ui.comboSelectPrd->blockSignals(true);
	ui.comboSelectModule->blockSignals(true);

	ui.comboSelectPrd->clear();
	ui.comboSelectPrd->setEnabled(true);

	list = m_selectors["SelectPrd"].toList();
	foreach(QVariant values, list)
	{
		QStringList text = values.toStringList();
		if(!text.isEmpty())
			ui.comboSelectPrd->addItem(text.first(), text.last());
	}

	ui.comboSelectModule->clear();
	ui.comboSelectModule->setEnabled(true);

	list = m_selectors["SelectUmi"].toList();
	foreach(QVariant values, list)
	{
		QStringList text = values.toStringList();
		if(!text.isEmpty())
			ui.comboSelectModule->addItem(text.first(), text.last());
	}

	ui.comboSelectPrd->setCurrentIndex(0);
	ui.comboSelectModule->setCurrentIndex(0);

	ui.comboSelectPrd->blockSignals(false);
	ui.comboSelectModule->blockSignals(false);
}

//-------------------------------------------------------------------------------
void DlgPhase::prepareTables()
{
	for(int i = 0; i < m_selectors["N_PRD"].toInt(); i++)
	{
		QTableWidget *table;
		int row, col;

		if(i==0)
			table = ui.tablePhase1;
		else if(i==1)
			table = ui.tablePhase2;
		else
			continue;

		table->setRowCount(m_selectors["N_UMI"].toInt());
		table->setSelectionMode(QAbstractItemView::NoSelection);

		QStringList labelModules;
		for(row = 0; row < table->rowCount(); row++)
			labelModules << QString("УМИ-%1").arg(row + 1);
		table->setVerticalHeaderLabels(labelModules);

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
//		table->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
//		table->horizontalHeader()->setClickable(false);
//		table->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
//		table->verticalHeader()->setClickable(false);
#else
//		table->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
		table->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
		table->horizontalHeader()->setClickable(false);
//		table->verticalHeader()->setResizeMode(QHeaderView::Fixed);
		table->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
		table->verticalHeader()->setClickable(false);
#endif

		table->blockSignals(true);

		for(row = 0; row < table->rowCount(); row++)
			for(col = 0; col < table->columnCount(); col++)	
			{
				QTableWidgetItem *item = new QTableWidgetItem();

				Qt::ItemFlags flags = Qt::NoItemFlags;
				if(col == 3 || col == 4)//code phase, phase
					flags |= Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled;
				else
					flags |= Qt::ItemIsEnabled;

				item->setFlags(flags);

				table->setItem(row, col, item);
			}

		table->blockSignals(false);

		table->setMinimumWidth(490);
	}
}

//-------------------------------------------------------------------------------
void DlgPhase::sendAction(QString command, QStringList parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "canalasku";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Parameters"] = parameters;
	emit action(data);
}

//-------------------------------------------------------------------------------
void DlgPhase::sendActionMap(QString command, QVariantMap parameters)
{
	QVariantMap data;
	data["ModuleTo"] = "canalasku";
	data["ModuleFrom"] = objectName();
	data["Command"] = command;
	if(!parameters.isEmpty())
		data["Map"] = parameters;
	emit action(data);
}

//-------------------------------------------------------------------------------
void DlgPhase::showEvent(QShowEvent * event)
{
	if(m_selectors.isEmpty())
		sendAction("refreshPhase");
	else
	{
		sendAction("refreshPhaseValues");
		sendAction("startMonitorPhase");
	}
	event->accept();
}

//-------------------------------------------------------------------------------
void DlgPhase::hideEvent(QHideEvent * event)
{
	sendAction("stopMonitorPhase");
	event->accept();
}

//-------------------------------------------------------------------------------
void DlgPhase::on_pushRefresh_clicked()
{
	if(m_selectors.isEmpty())
		sendAction("refreshPhase");
	sendAction("refreshPhaseValues");
}

//-------------------------------------------------------------------------------
void DlgPhase::on_pushClose_clicked()
{
	hide();
}

//-------------------------------------------------------------------------------
void DlgPhase::on_pushMeasure_clicked()
{
	sendAction("startPhasing", actionParameters());
	emit activateAction(rlsName() + "act_dialog_measure_show");
}

// ------------------------------------------------------------------
QStringList DlgPhase::actionParameters()
{
	QStringList params;
	params << ui.comboSelectPrd->itemData(ui.comboSelectPrd->currentIndex()).toString();
	params << ui.comboSelectModule->itemData(ui.comboSelectModule->currentIndex()).toString();
	params << QString::number((int)ui.checkBoxAuto->isChecked());
	return params;
}

//-------------------------------------------------------------------------------
qint32 DlgPhase::checkPhaseCode(QString text, quint32 * phaseCode)
{
	if(text.isEmpty())
		return -1;

	bool ok = false;
	int value = text.toUInt(&ok,10);

	if(!ok)
		return -2;
	else if(value < 0 || value > 63)
		return -3;
	else
	{
		if(phaseCode)
			*phaseCode = value;
		return 0;
	}
}

//-------------------------------------------------------------------------------
qint32 DlgPhase::checkPhaseValue(QString text, double * phaseValue)
{
	if(text.isEmpty())
		return -1;

	bool ok = false;
	double value = text.toDouble(&ok);

	if(!ok)
		return -2;
	else if(value < -180.0 || value > 180.0)
		return -3;
	else
	{
		if(phaseValue)
			*phaseValue = value;
		return 0;
	}
}

//-------------------------------------------------------------------------------
QVariantList DlgPhase::phaseCodes(QTableWidget * table, qint32 * errorCode)
{
	QVariantList list;
	qint32 counter = 0;

	for(qint32 row = 0; row < table->rowCount(); row++)
	{
		qint32 col = 3;
		quint32 value = 0;
		QString text = table->item(row,col)->text();
		qint32 error = checkPhaseCode(text, &value);

		if(error == 0)
		{
			list << value;
			counter++;
		}
		else if(error == -1)
		{
			list << QVariant();
		}
		else
		{
			if(error == -2)
				QMessageBox::critical(this,"Ошибка!", "Значение поправки кода фазы некорректно");

			if(error == -3)
				QMessageBox::critical(this, "Ошибка!", "Значение поправки кода фазы должно быть в диапазоне 0...63");

			if(error < 0)
			{
				table->setFocus();
				table->setCurrentCell(row,col);
				table->scrollToItem(table->item(row,col));
				*errorCode = error;
				return QVariantList();
			}
		}
	}

	*errorCode = counter > 0 ? 0 : -1;
	return list;
}

//-------------------------------------------------------------------------------
QVariantList DlgPhase::phaseValues(QTableWidget * table, qint32 * errorCode)
{
	QVariantList list;
	qint32 counter = 0;

	for(qint32 row = 0; row < table->rowCount(); row++)
	{
		qint32 col = 4;
		double value = 0;
		QString text = table->item(row,col)->text();
		qint32 error = checkPhaseValue(text, &value);

		if(error == 0)
		{
			list << value;
			counter++;
		}
		else if(error == -1)
		{
			list << QVariant();
		}
		else
		{
			if(error == -2)
				QMessageBox::critical(this,"Ошибка!", "Значение фазы некорректно");

			if(error == -3)
				QMessageBox::critical(this, "Ошибка!", "Значение фазы должно быть в диапазоне -180...180");

			if(error < 0)
			{
				table->setFocus();
				table->setCurrentCell(row,col);
				table->scrollToItem(table->item(row,col));
				*errorCode = error;
				return QVariantList();
			}
		}
	}

	*errorCode = counter > 0 ? 0 : -1;
	return list;
}

//-------------------------------------------------------------------------------
void DlgPhase::on_pushApply_clicked()
{
	QVariantMap map;

	qint32 error1 = 0;
	qint32 error2 = 0;

	QVariantList list1 = phaseCodes(ui.tablePhase1, &error1);
	if(error1 < -1) return;

	QVariantList list2 = phaseCodes(ui.tablePhase2, &error2);
	if(error2 < -1) return;

	if((error1 == -1 && error2 == -1) || (list1.isEmpty() && list2.isEmpty()))
	{
		QMessageBox::critical(this, "Ошибка!", "Нет значений коды фазы!");
		return;
	}

	if(!list1.isEmpty())
		map["prd1"] = list1;

	if(!list2.isEmpty())
		map["prd2"] = list2;

	sendActionMap("setPhaseMap", map);
}

//-------------------------------------------------------------------------------
void DlgPhase::on_pushClear1_clicked()
{
	for(int row = 0; row < ui.tablePhase1->rowCount(); row++)
		ui.tablePhase1->item(row, 3)->setText("");
}

//-------------------------------------------------------------------------------
void DlgPhase::on_pushClear2_clicked()
{
	for(int row = 0; row < ui.tablePhase2->rowCount(); row++)
		ui.tablePhase2->item(row, 3)->setText("");
}

//-------------------------------------------------------------------------------
void DlgPhase::on_tablePhase1_cellChanged(int row, int col)
{
	QTableWidget *table = ui.tablePhase1;
	if(col == 4)//set phase value
	{
		qDebug("1 phase value changed (%d,%d)=%s", row, col, qPrintable(table->item(row, col)->text()));

		int col_cd = 3;
		table->blockSignals(true);
		table->item(row,col_cd)->setText("");
		table->blockSignals(false);
	}
	else if(col == 3)//set code phase value
	{
		qDebug("1 phase code changed (%d,%d)=%s", row, col, qPrintable(table->item(row, col)->text()));

		int col_ph = 4;
		table->blockSignals(true);
		table->item(row,col_ph)->setText("");
		table->blockSignals(false);
	}
}

//-------------------------------------------------------------------------------
void DlgPhase::on_tablePhase2_cellChanged(int row, int col)
{
	QTableWidget *table = ui.tablePhase2;
	if(col == 4)//set phase value
	{
		qDebug("2 phase value changed (%d,%d)=%s", row, col, qPrintable(table->item(row, col)->text()));

		int col_cd = 3;
		table->blockSignals(true);
		table->item(row,col_cd)->setText("");
		table->blockSignals(false);
	}
	else if(col == 3)//set code phase value
	{
		qDebug("2 phase code changed (%d,%d)=%s", row, col, qPrintable(table->item(row, col)->text()));

		int col_ph = 4;
		table->blockSignals(true);
		table->item(row,col_ph)->setText("");
		table->blockSignals(false);
	}
}

//-------------------------------------------------------------------------------
double DlgPhase::targetPhaseValue(QLineEdit * line, qint32 * error)
{
	QString textTarget = line->text();
	if(textTarget.isEmpty())
	{
		line->setFocus();
		QMessageBox::critical(this, "Ошибка!", "Значение целевой фазы не задано");
		*error = -1;
		return 0;
	}

	bool ok = false;
	double value = textTarget.toDouble(&ok);
	if(!ok)
	{
		line->setFocus();
		QMessageBox::critical(this, "Ошибка!", "Значение целевой фазы не корректно");
		*error = -2;
		return 0;
	}
	else if(value < -180.0 || value > 180.0)
	{
		line->setFocus();
		QMessageBox::critical(this, "Ошибка!", "Значение целевой фазы должно быть в диапазоне -180...180");
		*error = -3;
		return 0;
	}

	qDebug("target=%3.3f",(float)value);
	*error = 0;
	return value;
}

//-------------------------------------------------------------------------------
quint32 DlgPhase::calc_phase_code(double target, double phase, quint32 nowcode)
{
	quint32 code = 0;
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

//-------------------------------------------------------------------------------
void DlgPhase::updatePhaseCodes(QTableWidget *table, double phaseTarget, QVariantList list)
{
	if(table->rowCount() != list.count())
	{
		qDebug("DlgPhase: updatePhaseCodes rowCount!=listCount");
		return;
	}

	table->blockSignals(true);

	for(qint32 row = 0; row < table->rowCount(); row++)
	{
		int col_cd = 3;
		bool ok = false;
		double phvalue = list[row].toDouble(&ok);
		if(ok)
		{
			qDebug("phase=%3.3f",(float)phvalue);
			unsigned int cdvalue = 0;
			unsigned int phcode = calc_phase_code(phaseTarget, phvalue, cdvalue);
			table->item(row,col_cd)->setText(QString("%1").arg(phcode));
		}
	}

	table->blockSignals(false);
}

//-------------------------------------------------------------------------------
double DlgPhase::calc_middle_value(QVariantList list)
{
	double sum = 0.0;
	quint32 counter = 0;

	for(qint32 i = 0; i < list.count(); i++)
	{
		bool ok = false;
		double phvalue = list[i].toDouble(&ok);
		if(ok)
		{
			sum += phvalue;
			counter++;
		}
	}

	if(counter)
		sum /= counter;

	return sum;
}

//-------------------------------------------------------------------------------
void DlgPhase::on_pushPhase_clicked()
{
	qint32 error = 0;
	double phaseTarget = targetPhaseValue(ui.lineEditPhase, &error);
	if(error < 0) return;

	qint32 error1 = 0;
	QVariantList list1 = phaseValues(ui.tablePhase1, &error1);
	if(error1 < -1) return;

	qint32 error2 = 0;
	QVariantList list2 = phaseValues(ui.tablePhase2, &error2);
	if(error2 < -1) return;

	if((error1 == -1 && error2 == -1) || (list1.isEmpty() && list2.isEmpty()))
	{
		QMessageBox::critical(this, "Ошибка!", "Нет значений фазы!");
		return;
	}

	updatePhaseCodes(ui.tablePhase1, phaseTarget, list1);
	updatePhaseCodes(ui.tablePhase2, phaseTarget, list2);
}

//-------------------------------------------------------------------------------
void DlgPhase::on_pushMiddle_clicked()
{
	qint32 error1 = 0;
	QVariantList list1 = phaseValues(ui.tablePhase1, &error1);
	if(error1 < -1) return;

	qint32 error2 = 0;
	QVariantList list2 = phaseValues(ui.tablePhase2, &error2);
	if(error2 < -1) return;

	if((error1 == -1 && error2 == -1) || (list1.isEmpty() && list2.isEmpty()))
	{
		QMessageBox::critical(this, "Ошибка!", "Нет значений фазы!");
		return;
	}

	double phaseMiddle = calc_middle_value(list1 + list2);
	ui.lineEditPhase->setText(QString("%1").arg(phaseMiddle, 0, 'f', 3));
}

//-------------------------------------------------------------------------------
void DlgPhase::updateModuleInfo(int n_prd, int n_module, bool valid, QString serial, int phase, int sv_phase)
{
//	qDebug("updateModule: prd=%d module=%d valid=%d serial=%s phase=%d", n_prd, n_module, valid, qPrintable(serial), phase);
	QTableWidget *table;

	if(n_prd == 0)
		table = ui.tablePhase1;
	else if(n_prd == 1)
		table = ui.tablePhase2;
	else
		return;

	if(n_module < 0 || n_module > (table->rowCount() - 1))
		return;

	if(!valid)
	{
		QString invalidText = QString("---");
		table->item(n_module, 0)->setText(invalidText);
		table->item(n_module, 1)->setText(invalidText);
		table->item(n_module, 2)->setText(invalidText);
	}
	else
	{
		table->item(n_module, 0)->setText(serial);
		table->item(n_module, 1)->setText(QString("%1").arg(sv_phase));
		table->item(n_module, 2)->setText(QString("%1").arg(phase));
	}
}

//-------------------------------------------------------------------------------
void DlgPhase::updatePhaseValue(int n_prd, int n_module, double value)
{
	qDebug("setPhaseValue: prd=%d module=%d phase=%3.1f", n_prd, n_module, value);
	QTableWidget *table;

	if(n_prd == 0)
		table = ui.tablePhase1;
	else if(n_prd == 1)
		table = ui.tablePhase2;
	else
		return;

	if(n_module < 0 || n_module > (table->rowCount() - 1))
		return;

	int col_cd = 3;
	int col_ph = 4;
	table->item(n_module, col_ph)->setText(QString("%1").arg(value,0,'f',3));
	table->item(n_module, col_cd)->setText("");
}

//-------------------------------------------------------------------------------
void DlgPhase::on_pushClearPhase1_clicked()
{
	for(int row = 0; row < ui.tablePhase1->rowCount(); row++)
		ui.tablePhase1->item(row, 4)->setText("");
}

//-------------------------------------------------------------------------------
void DlgPhase::on_pushClearPhase2_clicked()
{
	for(int row = 0; row < ui.tablePhase2->rowCount(); row++)
		ui.tablePhase2->item(row, 4)->setText("");
}

//-------------------------------------------------------------------------------
qint32 DlgPhase::processInfo(QVariantMap data)
{
	qint32 result = AskuModule::CommandNotFound;

	if(data.isEmpty())
	{
		LogError("DlgPhase: empty info data!");
		return result;
	}

	QString infoType = data["InfoType"].toString();
	if(infoType == "PHASE_MESSAGE")//unused
	{
		QString message = data["Message"].toString();

		if(message.isEmpty())
		{
			LogError("DlgPhase: empty message");
			return result;
		}

		result = AskuModule::CommandSuccess;
	}
	else if(infoType == "ASKU_CONTROL_PRD_SELECTORS")
	{
		if(data.contains("Selectors"))
		{
			QVariantMap values = data["Selectors"].toMap();

			m_selectors = values;

			refreshSelectors();
			prepareTables();

			setActive(true);

			sendAction("refreshPhaseValues");
			sendAction("startMonitorPhase");
		}

		result = AskuModule::CommandSuccess;
	}
	else if(infoType == "PHASE_MODULES_INFO")
	{
		QVariantList info = data["Info"].toList();

		if(info.isEmpty())
		{
			LogError("DlgPhase: empty info");
			return result;
		}

		updateModuleInfo(info);

		result = AskuModule::CommandSuccess;
	}

	return result;
}

//-------------------------------------------------------------------------------
void DlgPhase::updateModuleInfo(QVariantList & prds)
{
	qint32 n_prd = 0;

	foreach(QVariant vmods, prds)
	{
		qint32 n_module = 0;

		QVariantList mods = vmods.toList();

		foreach(QVariant vmod, mods)
		{
			QVariantMap module = vmod.toMap();

			if(module.contains("valid"))
			{
				bool valid = module["valid"].toBool();
				QString serial = module["serial"].toString();
				quint32 phase = module["phase_set"].toUInt();
				quint32 sv_phase = module["phase_def"].toUInt();

				updateModuleInfo(n_prd, n_module, valid, serial, phase, sv_phase);
			}

			n_module++;
		}

		n_prd++;
	}
}

//-------------------------------------------------------------------------------
void DlgPhase::connectedRls()
{
	setActive(false);
	if(isVisible())
		sendAction("refreshPhase");
}

//-------------------------------------------------------------------------------
void DlgPhase::disconnectedRls()
{
	setActive(false);
	m_selectors.clear();
}

//-------------------------------------------------------------------------------
void DlgPhase::setActive(bool on)
{
	QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
	foreach(QPushButton* button, buttons)
	{
		if(button != ui.pushClose)
			button->setEnabled(on);
	}

	QList<QComboBox*> combos = this->findChildren<QComboBox*>();
	foreach(QComboBox* combo, combos)
		combo->setEnabled(on);

	QList<QCheckBox*> checks = this->findChildren<QCheckBox*>();
	foreach(QCheckBox* check, checks)
		check->setEnabled(on);

	QList<QLineEdit*> lines = this->findChildren<QLineEdit*>();
	foreach(QLineEdit* line, lines)
		line->setEnabled(on);
}

//-------------------------------------------------------------------------------
void DlgPhase::on_pushCalculate_clicked()
{
	calcPhaseCodes(ui.tablePhase1);
	calcPhaseCodes(ui.tablePhase2);
}

//-------------------------------------------------------------------------------
void DlgPhase::calcPhaseCodes(QTableWidget *table)
{
	for(qint32 row = 0; row < table->rowCount(); row++)
	{
		int col_def = 1;
		int col_set = 2;
		int col_cod = 3;

		quint32 value_def = 0;
		quint32 value_set = 0;
		qint32 value_cod = 0;

		qint32 error_def = checkPhaseCode(table->item(row,col_def)->text(), &value_def);
		qint32 error_set = checkPhaseCode(table->item(row,col_set)->text(), &value_set);

		if(error_def == 0 && error_set == 0)
		{
			value_cod = (qint32)value_set - (qint32)value_def;
			if(value_cod < 0)
				value_cod += 64;
			table->item(row,col_cod)->setText(QString("%1").arg(value_cod));
		}
	}
}

//-------------------------------------------------------------------------------
