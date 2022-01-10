#OBJS specifies which files to compile as part of the project
OBJS = pong.c

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = SDLMain

#This is the target that compiles our executable
all : $(OBJS)
	gcc $(OBJS) -IC:\Users\husse\Desktop\Development\SDL2-32bit\include -LC:\Users\husse\Desktop\Development\SDL2-32bit\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o $(OBJ_NAME)