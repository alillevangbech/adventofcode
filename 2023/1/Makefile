.POSIX:
 
SRC = main.cpp
PRG = AOC
PZL1 = PZL1
PZL2 = PZL2
INPUT = input.txt
#INPUT = test.txt
RUN = awk -f pipe.awk $(INPUT) | python main.py
RUN_PUZZLE1 = awk -f pipe1.awk $(INPUT) | ./$(PZL1)
RUN_PUZZLE2 = awk -f pipe2.awk $(INPUT) | ./$(PZL2)

run: input
	$(RUN)

save1: 
	cp main.py puzzle1.py
	cp pipe.awk pipe1.awk

save2: 
	cp main.py puzzle2.py
	cp pipe.awk pipe2.awk

awkinput:
	awk -f pipe.awk $(INPUT)

input:
	@touch $(INPUT)

clean:
	rm -rf $(PRG) input.txt test.txt .cache

cleanall: clean
	rm -rf main.cpp pipe.awk
