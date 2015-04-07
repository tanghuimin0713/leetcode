ROOT_LEETCODE = $(HOME)/leetcode
ROOT_LEETCODE_C = $(ROOT_LEETCODE)/leetcode_c

DIR_MODULE_SRC = $(shell pwd)
DIR_MODULE_OBJ = $(DIR_MODULE_SRC)/obj
DIR_LIB_SRC = $(ROOT_LEETCODE_C)/lib
DIR_LIB_OBJ = $(DIR_LIB_SRC)/obj
DIR_INC = $(ROOT_LEETCODE_C)/include

CC = gcc
CFLAGS += -Wall -O2 -g
CFLAGS += -I$(DIR_INC)
CFLAGS += -I$(DIR_LIB_SRC)

TARGET = $(DIR_MODULE_SRC)/main
MODULE_SRC = $(wildcard $(DIR_MODULE_SRC)/*.c)
LIB_SRC = $(wildcard $(DIR_LIB_SRC)/*.c)
MODULE_OBJS = $(patsubst %.c, $(DIR_MODULE_OBJ)/%.o, $(notdir $(MODULE_SRC)))
LIB_OBJS = $(patsubst %.c, $(DIR_LIB_OBJ)/%.o, $(notdir $(LIB_SRC)))
OBJS += $(MODULE_OBJS)
OBJS += $(LIB_OBJS)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

dir_guard = @mkdir -p $(@D) #"$(@D)" means the directory the current targets reside in
$(DIR_MODULE_OBJ)/%.o: $(DIR_MODULE_SRC)/%.c
	$(dir_guard)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_LIB_OBJ)/%.o: $(DIR_LIB_SRC)/%.c
	$(dir_guard)
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY: clean
clean:
	rm -rf $(DIR_LIB_OBJ) $(DIR_MODULE_OBJ) $(TARGET)
