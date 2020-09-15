#include "globalvar.h"
#include "dlgadvanced.h"

// ------------------------------------------------------------------
DlgAdvanced::DlgAdvanced(QWidget *parent) : AskuDialog("dialog_advanced", parent)
{
	ui.setupUi(this);
}

// ------------------------------------------------------------------
DlgAdvanced::~DlgAdvanced()
{

}
/*
// ------------------------------------------------------------------
void DlgAdvanced::setOY(quint8 command, quint32 nOY)
{
    if(nOY >= CA_N_DEVICES || command < commTest2 || command > commSost)
        return;

    saveCommand = command;
    saveOY = nOY;

    setWindowTitle(QString("������ \""+commands[command-commTest1]+"\" �� "+captions[nOY]));

    QStringList *list = NULL;

    switch(command)
    {
        case commUpr:
            list = &listCommands[nOY];
            break;
        case commTest2:
            list = &listTest2[nOY];
            break;
        case commSost:
            list = &listState[nOY];
            break;
        default:
            return;
    }

    QList<QString>::iterator it = list->begin();
    quint32 row = 0;
    quint32 numByte = 1;
    quint32 numBit = 0;

    QTableWidget *table = ui.tableWidget;
    table->clearContents();
    table->setRowCount(list->count());
    while(it != list->end())
    {
        QString str;
        QTableWidgetItem *item;

        item = table->item(row, 0);
        if(!item)
        {
            table->setItem(row, 0, new QTableWidgetItem(*it));
        }
        else
            item->setText(*it);

        str.sprintf("%d",numByte);
        item = table->item(row, 1);
        if(!item)
        {
            item = new QTableWidgetItem(str);
            item->setTextAlignment(Qt::AlignCenter);
            table->setItem(row, 1, item);

        }
        else
            item->setText(str);

        str.sprintf("%d",numBit);
        item = table->item(row, 2);
        if(!item)
        {
            item = new QTableWidgetItem(str);
            item->setTextAlignment(Qt::AlignCenter);
            table->setItem(row, 2, item);

        }
        else
            item->setText(str);

        str = " ";
        item = table->item(row, 3);
        if(!item)
        {
            item = new QTableWidgetItem(str);
            item->setTextAlignment(Qt::AlignCenter);
            table->setItem(row, 3, item);
        }
        else
            item->setText(str);

        row++;
        numBit++;
        if(numBit>7)
        {
            numBit = 0;
            numByte++;
        }
        it++;
    }
}

// ------------------------------------------------------------------
void DlgAdvanced::setUMI(quint32 nUMI)
{
    if(nUMI >= CA_N_MODULES)
        return;

    saveCommand = commParamUMIType();
    saveUMI = nUMI;

    setWindowTitle(QString("������ \""+commands[commParamUMIv1-commTest1]+"\" �� ���"+QString::number(nUMI+1)));

    QTableWidget *table = ui.tableWidget;
    table->clearContents();
    table->setRowCount(listParamUMI.count() + 8);

    QList<QString>::iterator it1 = listParamUMI.begin();
    QList<QString>::iterator it2 = listParamUMIBits.begin();
    quint32 row = 0;
    quint32 numByte = 1;

    while(1)
    {
        while(it1 != listParamUMI.end() && (numByte-1) != listBitsOffset)
        {
            QString str;
            QTableWidgetItem *item;

            item = table->item(row, 0);
            if(!item)
                table->setItem(row, 0, new QTableWidgetItem(*it1));
            else
                item->setText(*it1);

            str.sprintf("%d",numByte);
            item = table->item(row, 1);
            if(!item)
            {
                item = new QTableWidgetItem(str);
                item->setTextAlignment(Qt::AlignCenter);
                table->setItem(row, 1, item);
            }
            else
                item->setText(str);

            str = " ";
            item = table->item(row, 2);
            if(!item)
            {
                item = new QTableWidgetItem(str);
                item->setTextAlignment(Qt::AlignCenter);
                table->setItem(row, 2, item);
            }
            else
                item->setText(str);

            str = " ";
            item = table->item(row, 3);
            if(!item)
            {
                item = new QTableWidgetItem(str);
                item->setTextAlignment(Qt::AlignCenter);
                table->setItem(row, 3, item);
            }
            else
                item->setText(str);

            row++;
            numByte++;
            it1++;
        }

        if(it1 == listParamUMI.end() && (numByte-1) > listBitsOffset)
        	break;

        quint32 numBit = 0;

        while(it2 != listParamUMIBits.end())
        {
            QString str;
            QTableWidgetItem *item;

            item = table->item(row, 0);
            if(!item)
                table->setItem(row, 0, new QTableWidgetItem(*it2));
            else
                item->setText(*it2);

            str.sprintf("%d",numByte);
            item = table->item(row, 1);
            if(!item)
            {
                item = new QTableWidgetItem(str);
                item->setTextAlignment(Qt::AlignCenter);
                table->setItem(row, 1, item);
            }
            else
                item->setText(str);

            str.sprintf("%d",numBit);
            item = table->item(row, 2);
            if(!item)
            {
                item = new QTableWidgetItem(str);
                item->setTextAlignment(Qt::AlignCenter);
                table->setItem(row, 2, item);
            }
            else
                item->setText(str);

            str = " ";
            item = table->item(row, 3);
            if(!item)
            {
                item = new QTableWidgetItem(str);
                item->setTextAlignment(Qt::AlignCenter);
                table->setItem(row, 3, item);
            }
            else
                item->setText(str);

            row++;
            numBit++;
            if(numBit>7)
            {
                numBit = 0;
                numByte++;
            }
            it2++;
        }
    }
}

// ------------------------------------------------------------------
void DlgAdvanced::_appendEmptyByte(QStringList &list)
{
    _appendEmptyStrings(list,8);
}

// ------------------------------------------------------------------
void DlgAdvanced::_appendEmptyStrings(QStringList &list, quint32 cnt)
{
    for(quint32 i = 0; i < cnt; i++)
        list.append(" ");
}

// ------------------------------------------------------------------
void DlgAdvanced::refresh(quint32 nOY, quint8 c1, quint8 c2, quint8 c3)
{
    if((saveCommand == commUpr) && (saveOY == nOY))
    {
        refreshItemsFromByte(0,0,c1);
        refreshItemsFromByte(0,1,c2);
        refreshItemsFromByte(0,2,c3);
    }
}

// ------------------------------------------------------------------
void DlgAdvanced::refresh(CommunicatorData *data)
{
    switch(saveCommand)
    {
        case commTest2:
            for(quint32 offset = 0; offset < CA_HEADER_TEST2_N_BYTES; offset++)
                refreshItemsFromByte(data->getTest2Error(saveOY),offset,data->getTest2(saveOY,offset));
            break;
        case commSost:
            for(quint32 offset = 0; offset < CA_HEADER_STATE_N_BYTES; offset++)
                refreshItemsFromByte(data->getStateError(saveOY),offset,data->getState(saveOY,offset));
            break;
        case commParamUMIv1:
            for(quint32 offset = 0; offset < CA_HEADER_DC_N_BYTES_V1; offset++)
                refreshUMIFromByte(data->getParamUmiError(saveUMI),offset,data->getParamUmi(saveUMI,offset));
            break;
        case commParamUMIv2:
            for(quint32 offset = 0; offset < CA_HEADER_DC_N_BYTES_V2; offset++)
                refreshUMIFromByte(data->getParamUmiError(saveUMI),offset,data->getParamUmi(saveUMI,offset));
            break;
        case commParamUMIv3:
            for(quint32 offset = 0; offset < CA_HEADER_DC_N_BYTES_V3; offset++)
                refreshUMIFromByte(data->getParamUmiError(saveUMI),offset,data->getParamUmi(saveUMI,offset));
            break;
    }
}

// ------------------------------------------------------------------
void DlgAdvanced::refreshItemsFromByte(quint8 error, quint8 offset, quint8 data)
{
    QString str;
    QTableWidget *table = ui.tableWidget;
    qint32 lineBegin = offset * 8;
    qint32 lineEnd = lineBegin + 8;
    quint8 bitCount = 0;

    if(lineEnd > table->rowCount())
        return;

    for(qint32 line = lineBegin; line < lineEnd; line++)
    {
        QTableWidgetItem *item;

        if(error)
            str = "-";
        else if(data & (1 << bitCount++))
            str = "1";
        else
            str = "0";

        item = table->item(line, 3);
        if(!item)
        {
            item = new QTableWidgetItem(str);
            item->setTextAlignment(Qt::AlignCenter);
            table->setItem(line, 3, item);
        }
        else
            item->setText(str);
    }
}

// ------------------------------------------------------------------
void DlgAdvanced::refreshUMIFromByte(quint8 error, quint8 offset, quint8 data)
{
    QString str;
    QTableWidget *table = ui.tableWidget;
    qint32 lineBegin;
    qint32 lineEnd;
    quint8 bitCount = 0;

    if(offset == listBitsOffset)
    {
        lineBegin = offset;
        lineEnd = lineBegin + 8;

        if(lineEnd > table->rowCount())
            return;

        for(qint32 line = lineBegin; line < lineEnd; line++)
        {
            QTableWidgetItem *item;

            if(error)
                str = "-";
            else if(data & (1 << bitCount++))
                str = "1";
            else
                str = "0";

            item = table->item(line, 3);
            if(!item)
            {
                item = new QTableWidgetItem(str);
                item->setTextAlignment(Qt::AlignCenter);
                table->setItem(line, 3, item);
            }
            else
                item->setText(str);
        }
    }
    else
    {
        if(offset > listBitsOffset)
            lineBegin = lineEnd = offset + 7;
        else
            lineBegin = lineEnd = offset;

        if(lineEnd > table->rowCount())
            return;

        QTableWidgetItem *item;

        if(error)
            str = "-";
        else
            str.sprintf("%02X",data);

        item = table->item(lineBegin, 3);
        if(!item)
        {
            item = new QTableWidgetItem(str);
            item->setTextAlignment(Qt::AlignCenter);
            table->setItem(lineBegin, 3, item);
        }
        else
            item->setText(str);
    }
}

// ------------------------------------------------------------------
*/