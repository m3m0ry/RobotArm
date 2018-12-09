# Makefile for compiling arduino sketches with arduino-cli
# You need:
# - arduino-cli: https://github.com/arduino/arduino-cli
# - jq: https://stedolan.github.io/jq/


# Directory of project
PROJECT_DIR       = $(HOME)/git/RobotArm/ArmII
SKETCH						= $(shell basename $(PROJECT_DIR))
# Location of arduino-cli
ARDUINO_CLI				= arduino-cli
# Command line json parser
JQ								= jq
# Information about board. File is created with `make board-info`
BOARD_INFO				= board_info.txt

BOARD							= $(shell jq .serialBoards[0].fqbn $(BOARD_INFO))
PORT							= $(shell jq .serialBoards[0].port $(BOARD_INFO))
PROJECT						= $(SKETCH).$(BOARD)

.PHONY: build update clean upload board-info status

build:
	$(info ##### COMPILE $(SKETCH) in $(PROJECT_DIR))
	$(ARDUINO_CLI) compile --warnings all -v --fqbn $(BOARD) $(PROJECT_DIR) -o $(PROJECT)

status:
	$(info ##### STATUS)
	$(info - [PROJECT_DIR]		${PROJECT_DIR})
	$(info - [SKETCH]		${SKETCH})
	$(info - [ARDUINO_CLI]		${ARDUINO_CLI})
	$(info - [JQ]			${JQ})
	$(info - [BOARD_INFO]		${BOARD_INFO})
	$(info - [BOARD]		${BOARD})
	$(info - [PORT]		${PORT})

update:
	$(info ##### UPDATE index)
	$(ARDUINO_CLI) core update-index

clean:
	$(info ##### CLEAN)
	rm $(SKETCH).$(BOARD).elf $(SKETCH).$(BOARD).hex

upload:
	$(info ##### UPLOAD)
	$(ARDUINO_CLI) upload -v -p $(PORT) --fqbn $(BOARD) -i $(PROJECT)  $(PROJECT_DIR)

board-info:
	$(info ##### BOARD INFO)
	$(ARDUINO_CLI) board list --format json > $(BOARD_INFO)
