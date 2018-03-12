##PATH="C:\Program%Files\GnuWin32\bin"
PATH="C:\Data_D\HSKOST\BisonTools\"

all: lex.tmcpar_.cpp TmcParParser.tab.cpp TmcParParser.tab.hpp

#tmc_kw.h  

#tmc_kw.h : tmc_kw.gperf
#	gperf --output-file tmc_kw.h  -t -C -D -G -L C++ -Z octave_kw_hash  tmc_kw.gperf

TmcParParser.tab.cpp TmcParParser.tab.hpp: TmcParParser.y
	bison -o TmcParParser.tab.cpp -d -v TmcParParser.y

lex.tmcpar_.cpp: TmcParLexer.l TmcParParser.tab.hpp
	flex -olex.tmcpar_.cpp  TmcParLexer.l

