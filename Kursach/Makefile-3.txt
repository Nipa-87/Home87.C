
# Имя исполняемого файла
TARGET = sensor

all: $(TARGET)

#объектники
OBJECTS = sensor.o temp_functions.o

$(TARGET): $(OBJECTS)
	gcc -o $(TARGET) $(OBJECTS)

$(OBJECTS): 

clean:
	del  *.o sensor.exe
