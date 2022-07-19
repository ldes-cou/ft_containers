
FT_NAME			=	ft_containers
STD_NAME		=	std_containers

SOURCES_DIR		=	srcs/

INCLUDES		= 	-I include -I .

DEFINE_STD		=	-D NAMESPACE="std"

DEFINE_FT		=	-D NAMESPACE="ft"

SOURCES_NAME	= 	\
					srcs/main		\
					srcs/test_map		\
					srcs/test_stack		\
					srcs/test_vector	\


# Add SRCS_DIR name before filename and cpp at the end
SOURCES			= $(patsubst %, %.cpp, $(SOURCES_NAME))

# Copy SOURCES but replace .cpp by .o
FT_OBJECTS			= 	$(SOURCES:%.cpp=ft/%.o)
STD_OBJECTS			= 	$(SOURCES:%.cpp=std/%.o)

# Copy SOURCES but replace .cpp by .d
FT_DEPEND			=	$(SOURCES:.cpp=.d)
STD_DEPEND			=	$(SOURCES:.cpp=.d)

# Compiler
CPP				=	c++

#SANITIZE = -fsanitize=address
DEBUG		=	-g3 $(SANITIZE)
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98 -MMD -MP $(DEBUG) $(INCLUDES)
$(FT_NAME): CPPFLAGS += $(DEFINE_FT)
$(STD_NAME): CPPFLAGS += $(DEFINE_STD)


-include $(FT_DEPEND)
-include $(STD_DEPEND)

#	AUTOMATIC VARIABLES
#	$@	=	Name of the rules
#	$<	=	Name of the first dependances
#	$^	=	every dependances

std/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(INC) -c -o $@ $<

ft/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(INC) -c -o $@ $<


all:			$(FT_NAME) $(STD_NAME)

$(STD_NAME):	$(STD_OBJECTS)
	$(CPP) $(CPPFLAGS) $^ -o $@

$(FT_NAME):		$(FT_OBJECTS)
	$(CPP) $(CPPFLAGS) $^ -o $@

clean:			
	rm -rf ft
	rm -rf std

fclean:			clean
	rm -f $(FT_NAME)
	rm -f $(STD_NAME)

re:				fclean all



.PHONY:			all clean fclean re
	# Delete the default suffixes
	.SUFFIXES:            		
	# Define my suffix list
	.SUFFIXES:		.cpp .o .h
	# Default target
	.DEFAULT_GOAL 	:= all