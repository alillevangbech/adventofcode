.POSIX:

SRC = main.cpp
PRG = AOC
PZL1 = PZL1
PZL2 = PZL2
CFLAGS = -Os -std=c++17;
CC = g++
INPUT = input.txt
# INPUT = test.txt
RUN = awk -f pipe.awk $(INPUT) | ./$(PRG) | ../out
RUN_PUZZLE1 = awk -f pipe1.awk $(INPUT) | ./$(PZL1)
RUN_PUZZLE2 = awk -f pipe2.awk $(INPUT) | ./$(PZL2)

run: build input
	$(RUN)

build:
	$(CC) -o $(PRG) $(SRC) $(CFLAGS)

puzzle:
	@$(CC) -o $(PZL1) puzzle1.cpp $(CFLAGS)
	@$(CC) -o $(PZL2) puzzle2.cpp $(CFLAGS)
	@echo "part 1"
	@$(RUN_PUZZLE1)
	@echo -e "\npart 2"
	@$(RUN_PUZZLE2)
	@rm -rf $(PZL1) $(PZL2)

save1: 
	cp main.cpp puzzle1.cpp
	cp pipe.awk pipe1.awk

save2: 
	cp main.cpp puzzle2.cpp
	cp pipe.awk pipe2.awk

awkinput:
	awk -f pipe.awk $(INPUT)


input:
	@touch $(INPUT)

clean:
	rm -rf $(PRG) input.txt test.txt .cache compile_commands.json 

cleanall: clean
	rm -rf main.cpp pipe.awk
