CC:=gcc
AR:=ar
CFLAGS:=-std=c99 -Wall -MMD -MP -nostdlib
LFLAGS:=

BIN        := cimproved.a
BUILD      := build
BUILD_TYPE := Debug

SOURCES_C   := src/main.c

OBJECTS    := $(SOURCES_C:.c=.c.o)
OBJECTS    := $(patsubst %,$(BUILD)/%,$(OBJECTS))
DEPENDS    := $(OBJECTS:.o=.d)

ifeq ($(BUILD_TYPE),Debug)
	CFLAGS+=-O0 -g
else
	ifeq ($(BUILD_TYPE),Release)
		CFLAGS+=-O3
	else
$(error Unknown Build Type "$(BUILD_TYPE)")
	endif
endif

-include $(DEPENDS)

all: $(BIN)

$(BUILD)/%.c.o: %.c
	@echo "CC  -" $<
	@mkdir -p "$$(dirname "$@")"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJECTS)
	@echo Linking Library $@
	@$(AR) rcs $@ $(OBJECTS)

.PHONY: run
.PHONY: clean

run: $(all)
	./$(BIN)

clean:
	$(RM) -rv $(BIN) $(BUILD)

