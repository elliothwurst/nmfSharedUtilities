

//============================================================================
// Name        : nmfVarFishMortModel.cpp
// Author      : Ron Klasky
// Version     :
// Copyright   : NOAA - National Marine Fisheries Service
// Description : This is the model for the Variable Fishing Mortality table in Forecast Tab4.
//============================================================================

#include "nmfVarFishMortModel.h"

//#define NMF_CONSTANTS
//#include "nmfConstants.h"

#include <iostream>


nmfVarFishMortModel::nmfVarFishMortModel()
{
    //std::cout << "nmfVarFishMortModel constructor" << std::endl;
}



int
nmfVarFishMortModel::count()
{
    return model_data.count();
}


bool
nmfVarFishMortModel::removeRows(int row, int nrows, const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(), row, row+nrows-1);

    for (int theRow = 0; theRow < nrows; ++theRow) {
        model_data.removeAt(row);
    }

    endRemoveRows();
    return true;
}


QVariant
nmfVarFishMortModel::data(const QModelIndex &index, int role) const
{
    int flagVCenterLeft  = Qt::AlignVCenter |  Qt::AlignLeft;
    int flagVCenterRight = Qt::AlignVCenter |  Qt::AlignRight;

    if (role == Qt::TextAlignmentRole) {
        if (index.column() == 0)
            return (flagVCenterLeft);
        else
            return (flagVCenterRight);
    }

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant {};

    const nmfVarFishMort &varFishMort = model_data[index.row()];

    switch (index.column()) {
        case 0:
            return varFishMort.PredName();
        case 1:
            return varFishMort.Linf();
        case 2:
            return varFishMort.GrowthK();
        case 3:
            return varFishMort.TZero();
        case 4:
            return varFishMort.LWAlpha();
        case 5:
            return varFishMort.LWBeta();
        default:
            return QVariant {};
    };

}

QVariant
nmfVarFishMortModel::headerData(int section, Qt::Orientation orientation, int role) const
{
     // Leave off row numbers for now. They don't really add anything.
     if (0) // (role == Qt::DisplayRole && orientation == Qt::Vertical)
        return section + 1;
     else {
        if (orientation != Qt::Horizontal)
            return QVariant { };
        if (role != Qt::DisplayRole)
            return QVariant { };

        switch (section) {
            case 0:
                return "PredName";
            case 1:
                return "Linf";
            case 2:
                return "GrowthK";
            case 3:
                return "TZero";
            case 4:
                return "LWAlpha";
            case 5:
                return "LWBeta";
            default:
                return QVariant { };
        }
    }
}

Qt::ItemFlags
nmfVarFishMortModel::flags(const QModelIndex &index) const
{

    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;

}

void
nmfVarFishMortModel::append(const nmfVonBert & vonBert)
{
   beginInsertRows(QModelIndex{}, model_data.count(), model_data.count());
   model_data.append(vonBert);
   endInsertRows();
}


bool nmfVarFishMortModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {

        int row = index.row();
        int col = index.column();

        QString currPredName = model_data[row].PredName();
        float currLinf       = model_data[row].Linf();
        float currGrowthK    = model_data[row].GrowthK();
        float currTZero      = model_data[row].TZero();
        float currLWAlpha    = model_data[row].LWAlpha();
        float currLWBeta     = model_data[row].LWBeta();

        float validatedValue = value.toFloat();

        if (col == 1)         // change Linf
            model_data[row] = nmfVonBert {currPredName, validatedValue, currGrowthK, currTZero, currLWAlpha, currLWBeta };
        else if (col == 2)    // change GrowthK
            model_data[row] = nmfVonBert {currPredName, currLinf, validatedValue, currTZero, currLWAlpha, currLWBeta };
        else if (col == 3)    // change TZero
            model_data[row] = nmfVonBert {currPredName, currLinf, currGrowthK, validatedValue, currLWAlpha, currLWBeta };
        else if (col == 4)    // change LWAlpha
            model_data[row] = nmfVonBert {currPredName, currLinf, currGrowthK, currTZero, validatedValue, currLWBeta };
        else if (col == 5)    // change LWBeta
            model_data[row] = nmfVonBert {currPredName, currLinf, currGrowthK, currTZero, currLWAlpha, validatedValue };

        emit dataChanged(index,index);

        return true;
    }

    return false;
}
