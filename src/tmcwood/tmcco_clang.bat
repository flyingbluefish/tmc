see: wtmclsp.sln

set PATH=D:\Data_D\HSKOST\Tools\LLVM\bin;D:\Data_D\HSKOST\Tools\bison_flex\;
set INCLUDE=


rem C:\MinGW\bin;

rem -Wall -Wextra 

win_bison -o TmcParParser.tab.cpp -d -v TmcParParser.Y
win_flex -olex.tmcpar_.cpp  TmcParLexer.L
win_bison -o TmcLspParser.tab.cpp -d -v TmcLspParser.Y
win_flex -olex.tmclsp_.cpp  TmcLspLexer.L
clang  -D YY_NO_UNISTD_H -D LINUX_GPL  -D UNICODE -O0  -D BLD_RTL_FEATURE=1 -masm=intel -D GCC_BUILD=1 -o  ..\..\bin\tmccoC.exe  tmc_asmgen.cpp tmc_rtl.cpp tmc_string_hash.cpp  tmclsp_rtlgen.cpp tmclsp_tree.cpp tmc_mak_lc.cpp    lex.tmclsp_.cpp tmc_tree_debug.cpp tmclsp_matrix.cpp  tmcpar_env.cpp tmcpar_tree.cpp tmcpar_utils.cpp  TmcLspParser.tab.cpp tmc_sym_table.cpp  tmc_mak_ml.cpp TmcParParser.tab.cpp lex.tmcpar_.cpp -static  -lstdc++
rem 

pause
