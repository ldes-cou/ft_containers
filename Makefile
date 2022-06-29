CXX					:= c++
ifeq ($(shell uname -s), Darwin)
	CXX				:= g++
endif

VECTOR_TARGET		:= _vector
STACK_TARGET		:= _stack
MAP_TARGET			:= _map

BUILD				:= release

include sources.mk

SRCDIR				:= srcs
INCDIR				:= includes
BUILDDIR			:= objs_
TARGETDIR			:= .
SRCEXT				:= cpp
DEPEXT				:= d
OBJEXT				:= o

VECTOR_OBJECTS		:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)$(VERSION)/%,$(VECTOR_SOURCES:.$(SRCEXT)=.$(OBJEXT)))
MAP_OBJECTS			:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)$(VERSION)/%,$(MAP_SOURCES:.$(SRCEXT)=.$(OBJEXT)))
STACK_OBJECTS		:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)$(VERSION)/%,$(STACK_SOURCES:.$(SRCEXT)=.$(OBJEXT)))

cflags.release		:= -Wall -Werror -Wextra
# cflags.valgrind		:= -Wall -Werror -Wextra -DDEBUG -lldb
cflags.debug		:= -Wall -Werror -Wextra -DDEBUG -g3 -fsanitize=address -fno-omit-frame-pointer
CFLAGS				:= $(cflags.$(BUILD))
CPPFLAGS			:= $(cflags.$(BUILD)) -DNS=$(VERSION) -std=c++98

lib.release			:=
lib.valgrind		:= $(lib.release)
lib.debug			:= $(lib.release) -fsanitize=address -fno-omit-frame-pointer
LIB					:= $(lib.$(BUILD))

INC					:= -I$(INCDIR) -I/usr/local/include
INCDEP				:= -I$(INCDIR)

# Colors
C_RESET				:= \033[0m
C_PENDING			:= \033[0;36m
C_SUCCESS			:= \033[0;32m

# Multi platforms
ECHO				:= echo

# Escape sequences (ANSI/VT100)
ES_ERASE			:= "\033[1A\033[2K\033[1A"
ERASE				:= $(ECHO) $(ES_ERASE)

all: vector.ft stack.ft vector.std stack.std map.ft   map.std 

vector.%:
	$(MAKE) VERSION=$* $(TARGETDIR)/$*$(VECTOR_TARGET)

map.%:
	$(MAKE) VERSION=$* $(TARGETDIR)/$*$(MAP_TARGET)

stack.%:
	$(MAKE) VERSION=$* $(TARGETDIR)/$*$(STACK_TARGET)

fclean: clean
	@$(RM) -f *.d *.o
	@$(RM) -rf $(BUILDDIR)ft
	@$(RM) -rf $(BUILDDIR)std

clean:
	@$(RM) -rf $(TARGETDIR)/ft$(VECTOR_TARGET)
	@$(RM) -rf $(TARGETDIR)/std$(VECTOR_TARGET)
	# @$(RM) -rf $(TARGETDIR)/ft$(MAP_TARGET)
	# @$(RM) -rf $(TARGETDIR)/std$(MAP_TARGET)
	# @$(RM) -rf $(TARGETDIR)/ft$(STACK_TARGET)
	# @$(RM) -rf $(TARGETDIR)/std$(STACK_TARGET)

re: fclean all
	@$(MAKE) all

-include $(VECTOR_OBJECTS:.$(OBJEXT)=.$(DEPEXT))
-include $(MAP_OBJECTS:.$(OBJEXT)=.$(DEPEXT))
-include $(STACK_OBJECTS:.$(OBJEXT)=.$(DEPEXT))

$(TARGETDIR)/%$(VECTOR_TARGET): $(VECTOR_OBJECTS)
	@mkdir -p $(TARGETDIR)
	$(CXX) -o $(TARGETDIR)/$(VERSION)$(VECTOR_TARGET) $^ $(LIB)

$(TARGETDIR)/%$(MAP_TARGET): $(MAP_OBJECTS)
	@mkdir -p $(TARGETDIR)
	$(CXX) -o $(TARGETDIR)/$(VERSION)$(MAP_TARGET) $^ $(LIB)

$(TARGETDIR)/%$(STACK_TARGET): $(STACK_OBJECTS)
	@mkdir -p $(TARGETDIR)
	$(CXX) -o $(TARGETDIR)/$(VERSION)$(STACK_TARGET) $^ $(LIB)

$(BUILDDIR)$(VERSION)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(ECHO) "$(TARGET)\t\t[$(C_PENDING)⏳$(C_RESET)]"
	$(CXX) $(CPPFLAGS) $(INC) -c -o $@ $<
	@$(CXX) $(CPPFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)$(VERSION)/$*.$(DEPEXT)
	@$(ERASE)
	@$(ERASE)
	@cp -f $(BUILDDIR)$(VERSION)/$*.$(DEPEXT) $(BUILDDIR)$(VERSION)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)$(VERSION)/$*.$(OBJEXT):|' < $(BUILDDIR)$(VERSION)/$*.$(DEPEXT).tmp > $(BUILDDIR)$(VERSION)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)$(VERSION)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)$(VERSION)/$*.$(DEPEXT)
	@rm -f $(VERSION)$(BUILDDIR)/$*.$(DEPEXT).tmp

# NAME        ?=    Containers_test

# MAKE        += --no-print-directory

# CXX            =    c++

# ifndef CXXFLAGS
# CXXFLAGS        =    -std=c++98 -Wall -Wextra -Werror
# CXXFLAGS        +=    -g
# CXXFLAGS        +=    -fsanitize=address
# endif

# SRC_DIR        =    srcs/
# INCDIR		   =	includes/
# OBJ_DIR        =    objs/

# include sources.mk

# INC_FLAGS    =    -iquote map/ -iquote set/ -iquote stack -iquote vector -iquote iterator/ -iquote .

# SRC_LIST    =    \
#                 main.cpp\

# SRC            =    $(addprefix $(OBJ_DIR), $(SRC_IST))
# OBJ            =    $(addprefix $(OBJ_DIR), $(SRC_LIST:.cpp=.o))
# DIR            =    $(sort $(dir $(OBJ)))

# all:
# 	$(MAKE) -j $(NAME)

# $(NAME):        $(OBJ) Makefile $(LIB_DIR)$(LIB_LIB)
# 	$(CXX) $(CXXFLAGS) -MMD $(OBJ) -o $@ $(INC_FLAGS)

# $(OBJ_DIR)%.o:    $(SRC_DIR)%.cpp Makefile | $(DIR)
# 	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@ $(INC_FLAGS)

# $(DIR):
# 	@mkdir -p $@

# clean:
# 	rm -rf $(OBJ_DIR)
# 	rm *output

# fclean: clean
# 	rm -rf $(NAME)
# 	rm mine std

# re: fclean
# 	@$(MAKE) all

# test:
# 	@$(MAKE) mine NAME="mine"
# 	@rm $(OBJ)
# 	@$(MAKE) std NAME="std" CXXFLAGS="-std=c++98 -Wall -Wextra -Werror -D STD -fsanitize=address"
# 	@rm $(OBJ)
# 	@./mine > mine_output
# 	@./std > std_output
# 	diff mine_output std_output