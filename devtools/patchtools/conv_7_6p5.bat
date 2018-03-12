set DST_RR=%2
set SRC_RR=%1

rem set DST_RR="D:\Data_D\HSKOST\TMC\OdedCompilation3x3"
rem set SRC_RR="D:\Data_D\MyProjects\AMRI\AMRI_prj_2016_08_03\AspectWiz\GaDemo\GaDemo\DftWizard_MatlabFiles\3X3"
rem @ECHO OFF

rem forfiles /p %SRC_DIR% /m *.m /c "patchone.bat @file @file"
rem set FILEIN=CasFDesignA.m
rem removetilda.exe   %SRC_DIR%\%FILEIN%   > %DST_DIR%\%FILEIN%
rem set FILEIN=ChooseFreqsAut1MAA.m
rem removetilda.exe   %SRC_DIR%\%FILEIN%   > %DST_DIR%\%FILEIN%

set SUBDIRR=Aspect\Design
set SRC_DIR=%SRC_RR%\%SUBDIRR%
set DST_DIR=%DST_RR%\%SUBDIRR%
for /R %SRC_DIR% %%G in (*.m) do removetilda.exe   %SRC_DIR%\%%~nG.m   > %DST_DIR%\%%~nG.m  

set SUBDIRR=Aspect\MIMO
set SRC_DIR=%SRC_RR%\%SUBDIRR%
set DST_DIR=%DST_RR%\%SUBDIRR%
for /R %SRC_DIR% %%G in (*.m) do removetilda.exe   %SRC_DIR%\%%~nG.m   > %DST_DIR%\%%~nG.m  

set SUBDIRR=SIMO
set SRC_DIR=%SRC_RR%\%SUBDIRR%
set DST_DIR=%DST_RR%\%SUBDIRR%
for /R %SRC_DIR% %%G in (*.m) do removetilda.exe   %SRC_DIR%\%%~nG.m   > %DST_DIR%\%%~nG.m  

set SUBDIRR=SIMO\qfdModel
set SRC_DIR=%SRC_RR%\%SUBDIRR%
set DST_DIR=%DST_RR%\%SUBDIRR%
for /R %SRC_DIR% %%G in (*.m) do removetilda.exe   %SRC_DIR%\%%~nG.m   > %DST_DIR%\%%~nG.m  

set SUBDIRR=SIMOMex
set SRC_DIR=%SRC_RR%\%SUBDIRR%
set DST_DIR=%DST_RR%\%SUBDIRR%
for /R %SRC_DIR% %%G in (*.m) do removetilda.exe   %SRC_DIR%\%%~nG.m   > %DST_DIR%\%%~nG.m  


pause

