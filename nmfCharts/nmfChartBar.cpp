
#include "nmfChartBar.h"


nmfChartBar::nmfChartBar()
{
}


void
nmfChartBar::populateChart(
        QChart *chart,
        std::string &type,
        const boost::numeric::ublas::matrix<double> &ChartData,
        const QStringList &RowLabels,
        const QStringList &ColumnLabels,
        std::string &MainTitle,
        std::string &XTitle,
        std::string &YTitle,
        const std::vector<bool> &GridLines,
        const int Theme)
{
    QBarSet    *newSet = NULL;
    QBarSeries *series = NULL;

    // Set current theme
    chart->setTheme(static_cast<QChart::ChartTheme>(Theme));
    //chart->removeAllSeries();

    if (type == "StackedBar") {
        QStackedBarSeries *series = new QStackedBarSeries();

        // Load data into series and then add series to the chart
        for (unsigned int i=0; i<ChartData.size2(); ++i) {
            if (ColumnLabels.size() == ChartData.size2())
                newSet = new QBarSet((ColumnLabels[i]));
            else
                newSet = new QBarSet("");
            for (unsigned int val=0; val<ChartData.size1(); ++val) {
                *newSet << ChartData(val,i);
            }
            series->append(newSet);
        }
        chart->addSeries(series);

    } else if (type == "Line") {

        // Load data into series and then add series to the chart
        QLineSeries *series;
        for (unsigned int line=0; line<ChartData.size2(); ++line) {
            series = new QLineSeries();
            for (unsigned int j=0; j<ChartData.size1(); ++j) {
                series->append(j+1,ChartData(j,line));
            }
            chart->addSeries(series);
            if (line < ColumnLabels.size())
                series->setName(ColumnLabels[line]);
        }

    } else if (type == "Scatter") {
        // Load data into series and then add series to the chart
        QScatterSeries *series;
        for (unsigned int line=0; line<ChartData.size2(); ++line) {
            series = new QScatterSeries();
            series->setMarkerSize(10);
            for (unsigned int j=0; j<ChartData.size1(); ++j) {
                series->append(j+1,ChartData(j,line));
            }
            chart->addSeries(series);
            if (line < ColumnLabels.size())
                series->setName(ColumnLabels[line]);
        }

    } else if (type == "Bar") {
        QBarSeries *series = new QBarSeries();

        // Load data into series and then add series to the chart
        for (unsigned int i=0; i<ChartData.size2(); ++i) {
            if (ColumnLabels.size() == ChartData.size2())
                newSet = new QBarSet((ColumnLabels[i]));
            else
                newSet = new QBarSet("");
            for (unsigned int j=0; j<ChartData.size1(); ++j) {
                *newSet << ChartData(j,i);
            }
            series->append(newSet);
        }
        chart->addSeries(series);
    }
    // Set main title
    QFont mainTitleFont = chart->titleFont();
    mainTitleFont.setPointSize(14);
    mainTitleFont.setWeight(QFont::Bold);
    chart->setTitleFont(mainTitleFont);
    chart->setTitle(QString::fromStdString(MainTitle));

    // Setup X and Y axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    if (RowLabels.size() > 0)
        axis->append(RowLabels);
    chart->createDefaultAxes();
    chart->setAxisX(axis, NULL);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QAbstractAxis *axisX = chart->axisX();
    QFont titleFont = axisX->titleFont();
    titleFont.setPointSize(12);
    titleFont.setWeight(QFont::Bold);
    axisX->setTitleFont(titleFont);
    axisX->setTitleText(QString::fromStdString(XTitle));
    if (RowLabels.count() > NumCategoriesForVerticalNotation)
        axis->setLabelsAngle(-90);
    else
        axis->setLabelsAngle(0);

    // Rescale vertical axis....0 to 1 in increments of 0.2
    if (type == "StackedBar") {
        QValueAxis *newAxisY = new QValueAxis();
        newAxisY->setRange(0,1.0);
        newAxisY->setTickCount(6);
        chart->setAxisY(newAxisY,series);
    }

    QValueAxis *currentAxisY = qobject_cast<QValueAxis*>(chart->axisY());
    currentAxisY->setTitleFont(titleFont);
    currentAxisY->setTitleText(QString::fromStdString(YTitle));
    currentAxisY->applyNiceNumbers();

    // Set grid line visibility
    chart->axisX()->setGridLineVisible(GridLines[0]);
    chart->axisY()->setGridLineVisible(GridLines[1]);
}

