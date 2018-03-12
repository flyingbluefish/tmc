##PATH="C:\Program%Files\GnuWin32\bin"
PATH="C:\Data_D\HSKOST\BisonTools\"

all: lex.tmclsp_.cpp TmcLspParser.tab.cpp TmcLspParser.tab.hpp 



TmcLspParser.tab.cpp TmcLspParser.tab.hpp: TmcLspParser.y
	bison -o TmcLspParser.tab.cpp -d -v TmcLspParser.y

lex.tmclsp_.cpp: TmcLspLexer.l TmcLspParser.tab.hpp
	flex -olex.tmclsp_.cpp  TmcLspLexer.l
