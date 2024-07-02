CFLAGS = -Wall -std=c++17 -ILibs_Windows/glfw-3.4/include -ILibs_Windows/glew-2.1.0/include
LDFLAGS = -LLibs_Windows/glfw-3.4/lib-mingw-w64 -LLibs_Windows/glew-2.1.0/lib/Release/x64 -lglew32 -l:libglfw3dll.a -lopengl32

all: compile link clean

compile:
	g++ -c main.cpp Window/Window.cpp VertexBuffer/VertexBuffer.cpp $(CFLAGS)

link:
	g++ -o main main.o Window.o VertexBuffer.o $(LDFLAGS)

clean:
	del /Q *.o
