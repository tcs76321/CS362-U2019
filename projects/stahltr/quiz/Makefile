testme:
	-gcc -o quiz testme.c -coverage -fpic -lm
	-./quiz >> quizResults.out
	-gcov testme.c -b >> quizResults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
