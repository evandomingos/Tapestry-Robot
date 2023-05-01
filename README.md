# Tapestry-Robot
Arduino C++ code for a matrix printing robort. RNG matrix generator arduino board is initialized by a press-button. 
This generates a 9x9 symmetric matrix with color values (0-8)for entries. Matrix is converted to G-Code instructions for the recieving GRBL arduino.
Reciever arduino attached via software serial is GRBL configured. Loop on generator is configured to wait for reciever to finish last instruction before sending next instruction. 
