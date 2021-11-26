.POSIX:

SRC = main.cpp
PRG = AOC
PZL1 = PZL1
PZL2 = PZL2
CFLAGS = -Os -std=c++17;
CC = g++
INPUT = input.txt
#INPUT = test.txt
RUN = awk -f pipe.awk $(INPUT) | ./$(PRG)
RUN_PUZZLE1 = awk -f pipe.awk $(INPUT) | ./$(PZL1)
RUN_PUZZLE2 = awk -f pipe.awk $(INPUT) | ./$(PZL2)

run: build input
	@echo -----------
	$(RUN)

build:
	$(CC) -o $(PRG) $(SRC) $(CFLAGS)

run_puzzle:
	@$(CC) -o $(PZL1) puzzle1.cpp $(CFLAGS)
	@$(CC) -o $(PZL2) puzzle2.cpp $(CFLAGS)
	@echo "part 1"
	@$(RUN_PUZZLE1)
	@echo "part 2"
	@$(RUN_PUZZLE2)
	@rm -rf $(PZL1) $(PZL2)

save1: 
	cp main.cpp puzzle1.cpp

save2: 
	cp main.cpp puzzle2.cpp

input:
	touch $(INPUT)

clean:
	rm -rf $(PRG) input.txt test.txt .cache
