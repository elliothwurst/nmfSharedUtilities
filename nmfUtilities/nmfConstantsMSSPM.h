
/**
 * @file nmfConstantsMSSPM.h
 * @brief Definition for constants used in MSSPM tool
 * @date Jan 14, 2020
 *
 * This file defines constants used in the MSSPM application program.
 */

#ifndef NMFCONSTANTSMSSPM_H
#define NMFCONSTANTSMSSPM_H

#include <iostream>
#include <vector>

namespace nmfConstantsMSSPM
{
     const int    Start_Year            = 1900;

     const int    Column_SpeId          =  0;
     const int    Column_SpeName        =  1;
     const int    Column_GuildName      =  2;
     const int    Column_InitBiomass    =  3;
     const int    Column_SurveyQ        =  4;
     const int    Column_SpeciesK       =  5;
     const int    Column_SpeciesKCovarCoeff   = 6;
     const int    Column_GrowthRate           = 7;
     const int    Column_GrowthRateCovarCoeff = 8;
     const int    Column_Habitat        =  9;
     const int    Column_InitBiomassMin = 10;
     const int    Column_InitBiomassMax = 11;
     const int    Column_SurveyQMin     = 12;
     const int    Column_SurveyQMax     = 13;
     const int    Column_GrowthRateMin  = 14;
     const int    Column_GrowthRateMax  = 15;
     const int    Column_SpeciesKMin    = 16;
     const int    Column_SpeciesKMax    = 17;

     const bool   RotateLabels         = true;
     const bool   DontRotateLabels     = false;
     const int    MaxNumberLogFiles    =  50;
     const int    MinSliderValue       =   0;
     const int    MaxSliderValue       =  99;
     const int    MaxNumberSeasons     =   6;
     const int    MaxNumberYears       = 100;
     const int    MaxNumberSpecies     =  12;
     const int    MaxTotalSpecies      =  50;
     const bool   RearrangeTitle       = true;
     const bool   DontRearrangeTitle   = false;
     const bool   Clear                = true;
     const bool   DontClear            = false;
     const bool   ShowError            = true;
     const bool   DontShowError        = false;
     const bool   ShowFirstPoint       = true;
     const bool   HideFirstPoint       = false;
     const bool   RescaleData          = true;
     const bool   DontRescaleData      = false;
     const bool   LabelXAxisAsReals    = false;
     const bool   LabelXAxisAsInts     = true;
     const bool   UseDimmedColor       = true;
     const bool   DontUseDimmedColor   = false;
     const bool   VerboseOn            = true;
     const bool   VerboseOff           = false;
     const bool   ShowPopupError       = true;
     const bool   DontShowPopupError   = false;
     const bool   ShowDiagnosticsChart = true;
     const bool   DontShowDiagnosticsChart = false;
     const bool   ShowBlankFields      = true;
     const bool   LoadFirstRowOnly     = true;
     const bool   LoadAllRows          = false;
     const bool   ReadValidPointsOnly  = true;
     const bool   ReadAllPoints        = false;

     const std::string  HiddenDir                      = ".MSSPM";
     const std::string  HiddenDataDir                  = ".MSSPM/data";
     const std::string  HiddenLogDir                   = ".MSSPM/logs";
     const std::string  MSSPMProgressBarFile           = ".MSSPM/MSSPMProgress.dat";
     const std::string  MSSPMProgressChartFile         = ".MSSPM/MSSPMProgressChart.dat";
     const std::string  MSSPMProgressChartLabelFile    = ".MSSPM/MSSPMProgressChartLabel.dat";
     const std::string  MSSPMStopRunFile               = ".MSSPM/MSSPMStopRun.dat";
     const std::string  MSSPMCurrentLoopFile           = ".MSSPM/MSSPMCurrentLoop.dat";
     const std::string  SettingsDirWindows             = "C:\\.QtSettings";
     const std::string  LogDir                         = ".MSSPM/logs";
     const std::string  LogFilter                      = ".MSSPM/logs/*.log";
     const std::string  InputDataDir                   = "inputData";
     const std::string  OutputDataDir                  = "outputData";
     const std::string  OutputImagesDir                = "outputImages";

}


#endif
