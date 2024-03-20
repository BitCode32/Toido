EXECUTABLE = App.exe
CODEDIR := .
INCDIR :=
LIBDIR :=

COMP = gcc
OPT = -O3
INCFLAG = -I$(INCDIR)
DEPFLAGS = -MMD
CFLAGS = $(INCFLAG) -g $(OPT) $(DEPFLAGS) -DWIN32

LIBS = -luser32 -lgdi32 -lws2_32

CFILES = $(wildcard $(CODEDIR)/*.c) $(wildcard $(CODEDIR)/*/*.c) $(wildcard $(CODEDIR)/*/*/*.c) $(wildcard $(CODEDIR)/*/*/*/*.c) $(wildcard $(CODEDIR)/*/*/*/*/*.c)
OBJDIR := Obj
OBJECTS := $(patsubst $(CODEDIR)/%.c,$(OBJDIR)/%.o,$(CFILES))
DEPFILES := $(patsubst $(CODEDIR)/%.c,$(OBJDIR)/%.d,$(CFILES))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(COMP) -o $@ $^ $(LIBS) 

$(OBJDIR)/%.o: $(CODEDIR)/%.c
	@mkdir -p $(@D)
	$(COMP) $(CFLAGS) -c -o $@ $<

-include $(DEPFILES)

clean:
	rm -rf $(EXECUTABLE) $(OBJDIR)

.PHONY: all clean
