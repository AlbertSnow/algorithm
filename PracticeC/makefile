build: CppLang.cpp CLang.c
	gcc -c -o clang.o CLang.c
	g++ -c -o CppLang.o CppLang.cpp

install: clang.o CppLang.o CppCallC.cpp CCallCpp.c
	g++ -o Cpp_call_C_Program CppCallC.cpp clang.o
	# gcc -o C_call_Cpp_Program CCallCpp.c CppLang.o
	# gcc -c -o CallCpp.o CCallCpp.c
	# g++ -c -o CppCallC.o CppCallC.cpp

clean: 
	rm clang.o CallCpp.o CppLang.o CppCallC.o
