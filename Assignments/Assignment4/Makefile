
er.out: emergencyRoomMain.o linked_list_hospital.o patient.o
	gcc emergencyRoomMain.o linked_list_hospital.o patient.o -o er.out

emergencyRoomMain.o : emergencyRoomMain.c
	gcc -c emergencyRoomMain.c 

linked_list_hospital.o: linked_list_hospital.c patient.h linked_list_hospital.h 
	gcc -c linked_list_hospital.c

patient.o: patient.h
	gcc -c patient.c

clean:
	rm -f *.o er.out

