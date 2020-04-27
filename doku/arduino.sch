EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v2.x A?
U 1 1 5EA67077
P 5500 3650
F 0 "A?" H 5500 2561 50  0001 C CNN
F 1 "Arduino Nano" V 5500 3500 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 5500 3650 50  0001 C CIN
F 3 "https://www.arduino.cc/en/uploads/Main/ArduinoNanoManual23.pdf" H 5500 3650 50  0001 C CNN
	1    5500 3650
	1    0    0    -1  
$EndComp
$Comp
L Timer_RTC:DS1307+ U?
U 1 1 5EA68B45
P 7400 3950
F 0 "U?" H 7400 3369 50  0001 C CNN
F 1 "DS1307+" H 7650 3600 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 7400 3450 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/DS1307.pdf" H 7400 3750 50  0001 C CNN
	1    7400 3950
	1    0    0    1   
$EndComp
Wire Wire Line
	6000 4050 6900 4050
Wire Wire Line
	6900 4150 6000 4150
NoConn ~ 6900 3850
NoConn ~ 6900 3750
NoConn ~ 7400 4350
NoConn ~ 7900 3950
$Comp
L power:+5V #PWR?
U 1 1 5EA6BB08
P 7300 4350
F 0 "#PWR?" H 7300 4200 50  0001 C CNN
F 1 "+5V" H 7315 4523 50  0000 C CNN
F 2 "" H 7300 4350 50  0001 C CNN
F 3 "" H 7300 4350 50  0001 C CNN
	1    7300 4350
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EA6C029
P 7400 3550
F 0 "#PWR?" H 7400 3300 50  0001 C CNN
F 1 "GND" H 7405 3377 50  0000 C CNN
F 2 "" H 7400 3550 50  0001 C CNN
F 3 "" H 7400 3550 50  0001 C CNN
	1    7400 3550
	-1   0    0    1   
$EndComp
Text GLabel 5000 3350 0    50   Input ~ 0
SrLatch
Text GLabel 5000 3250 0    50   Input ~ 0
SrClock
Text GLabel 5000 3450 0    50   Input ~ 0
SrData
$Comp
L power:+5V #PWR?
U 1 1 5EA708BF
P 5400 2650
F 0 "#PWR?" H 5400 2500 50  0001 C CNN
F 1 "+5V" H 5415 2823 50  0000 C CNN
F 2 "" H 5400 2650 50  0001 C CNN
F 3 "" H 5400 2650 50  0001 C CNN
	1    5400 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EA7163E
P 5500 4650
F 0 "#PWR?" H 5500 4400 50  0001 C CNN
F 1 "GND" H 5505 4477 50  0000 C CNN
F 2 "" H 5500 4650 50  0001 C CNN
F 3 "" H 5500 4650 50  0001 C CNN
	1    5500 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 4650 5500 4650
Connection ~ 5500 4650
NoConn ~ 6000 3050
NoConn ~ 6000 3150
NoConn ~ 6000 3450
NoConn ~ 5600 2650
NoConn ~ 5700 2650
Text GLabel 5000 3550 0    50   Input ~ 0
ledDrei
Text GLabel 5000 3650 0    50   Input ~ 0
ledFuenf
Text GLabel 5000 3750 0    50   Input ~ 0
ledElf
Text GLabel 5000 4350 0    50   Input ~ 0
ledUhr
Text GLabel 5000 4050 0    50   Input ~ 0
sigmentLeft
Text GLabel 5000 4150 0    50   Input ~ 0
sigmentRight
Text GLabel 5000 3850 0    50   Input ~ 0
btn0
Text GLabel 5000 3950 0    50   Input ~ 0
btn1
NoConn ~ 5000 4250
NoConn ~ 5000 3150
NoConn ~ 5000 3050
NoConn ~ 6000 3650
NoConn ~ 6000 3750
NoConn ~ 6000 3850
NoConn ~ 6000 3950
NoConn ~ 6000 4250
NoConn ~ 6000 4350
$EndSCHEMATC
