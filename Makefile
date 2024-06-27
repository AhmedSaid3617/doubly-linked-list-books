SRC_DIR = src
OBJS_DIR = build
INC_DIR = inc

vpath %.c $(SRC_DIR)
vpath %.o $(OBJS_DIR)

PROJECT_NAME = final_project
CC = 
CFLAGS = -g
INCS = -I $(INC_DIR)
LIBS = 
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(subst $(SRC_DIR)/, $(OBJS_DIR)/, $(SRC:.c=.o))
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

.PHONY: build
build: build_dir $(PROJECT_NAME).exe

$(OBJS_DIR)/%.o: %.c
	$(CC)gcc $< -c $(INCS) -o $@   $(CFLAGS)

$(OBJS_DIR)/%.o: %.s
	$(CC)as $< -o $@ $(CFLAGS)

$(PROJECT_NAME).exe: $(OBJ) $(AsOBJ)
	$(CC)gcc -o $(PROJECT_NAME).exe $(AsOBJ) $(OBJ)

clean:
	rm *.exe -f
	rm build/*.o -f

.PHONY: rebuild
rebuild: clean build

.PHONY: build_dir
build_dir:
	mkdir -p $(OBJS_DIR)
