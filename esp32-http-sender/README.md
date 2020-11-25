# Download Firmware on ESP32
This repository uses the ***Iot2Tangle C Core devices*** adapted for ***ESP32-FreeRTOS*** offered in the official *Espressif Toolchain ESP-IDF SDK*. Once the SDK is installed you will have all the tools to compile and download the program on your ESP32.


## 1) Install ESP-IDF SDK:
### Windows:
The easiest way to install ESP-IDF and their prerequisites is to download the ESP-IDF Tools installer from this URL:
<https://dl.espressif.com/dl/esp-idf-tools-setup-2.3.exe>

Just follow the steps and you will have the official *Espressif SDK Toolchain* installed on your computer.

To check other methods, the following page is suggested: 
<https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html>

### Linux and macOS:
Prerequisites of ESP-IDF SDK:
```
sudo apt update
sudo apt install git wget flex bison gperf python python-pip python-setuptools cmake ninja-build ccache libffi-dev libssl-dev
```
It is recommended to install the stable version: ESP-IDF v4.1, you can download it from here:
```
git clone -b v4.1 --recursive https://github.com/espressif/esp-idf.git
```
Now install the SDK, this may take a while:
```
cd ~/esp-idf
./install.sh
. ./export.sh
```
After doing this last step do not close the shell, as we will compile and flash from here. If you close the shell you will have to do the previous step again.

## 2) Clone the iot2tangle.lima repository and go to the 'esp32-http-sender' folder:
You can download the repository directly from Github, or from shell or Command Prompt with the following command:
```
git clone https://github.com/Agro-iot/iot2tangle.lima
cd iot2tangle.lima/esp32-http-sender
```
## 3) Edit the file config.h
The *config.h* file must be opened and modified, this file is in the directory *'ESP32/http-sender/main'* of the repository.

This step is very important if you want to make a connection to the gateway. Your *WiFi Credentials*, the *address* and *port* that will have the *I2T Streams HTTP Gateway* or *Keepy* running, the *Device Id*, and others configurations. The *Id Name Device* you define here must be between the devices you set in on the *Gateway configuration file*. 
```
const char* id_name = "ESP32-HTTP";

/* Network Configuration */
const char* ssid_WiFi = "YOUR-SSID";
const char* pass_WiFi = "YOUR-PASS";

/* HTTP Endpoint Configuration */
const char* address = "SERVER-IP-ADDRESS/sensor_data";    /* Endpoint address (HTTP), must NOT include 'http://xxx' or 'tcp://xxx' */
int port = 3002;

/* Enable Sensors */
bool isEnable_TemperatureIntern = true;
bool isEnable_TemperatureExtern = true;	   /* true: Enable  --  false: Disable */
bool isEnable_Humidity = true;
...

/* Interval of time */
long interval = 30;    /* Time in seconds between */
```
## 4) Compile and Download the Firmware:
Remembering to have the ***ESP-IDF Toolchain*** open, and you make sure you are at the root of the *http-sender* folder run the following command:
```
idf.py build
```
If the compilation was correct it should read: *Project build complete*.

Now make sure you have ESP32 connected to your computer, and know what COM port it is connected to. (You can see this in 'Device Manager'). 

Then run the following command that will start flashing the firmware. (You will probably have to press the reset button on your ESP32 development board, even several times for it to recognize the board.)
```
idf.py -p COM1 flash monitor  # COM1 is an Windows port example, you must put your port. In Linux /dev/ttyUSB0 is an example, and in macOS: '/dev/cu' 
```

Upon completion, the firmware is downloaded to your ESP32. If the *I2T Streams HTTP Gateway* and *Keepy* were configured correctly, ***now you should be sending data to Tangle via Streams***.

**DEMO**

![running_debugging_esp32_animation](https://user-images.githubusercontent.com/42292104/100288480-c38cd380-2f44-11eb-9e04-360201bb182b.gif)

# Debugging
If configured correctly, *ESP32* should be sending data to the gateway automatically. However, you may want to verify that it is running on *ESP32*.

The code continuously sends information out the **serial port**, so it can read the serial port to see what is happening and detect errors.

You can use the 'Arduino Serial Monitor' for this, but we recommend using the following software:
## Windows:
Open *Command Prompt*.

Configure the Baud Rate of the port to 115200 bps:
```
mode COM1: baud=115200
```
Read the serial port:
```
copy COM1: con:
```
## Linux and macOS:
Install *cu Monitor*. It is an excellent shell monitor and very useful.
```
sudo apt install cu
```
Run *cu Monitor*:
```
cu -l /dev/ttyUSB0 -s 115200
```

The following screenshot is a reading of the *Serial Port*, you should see something like this:

![esp32_Streams_Gateway](https://user-images.githubusercontent.com/42292104/100207093-28a8e080-2ed5-11eb-8b17-3f2fd41497ed.png)

### Knowing your Channel Id

You can know your Channel Id doing a request like this:
```
curl --location --request GET '0.0.0.0:8080/current_channel' \
--header 'Content-Type: application/json' \
--data-raw '{
    "device": "DEVICE_ID_1"
}'
```
Or using *Postman*:

![channel_id_postman](https://user-images.githubusercontent.com/42292104/100207705-e6cc6a00-2ed5-11eb-86a2-fede7d93ddaf.png)

### Reading messages from the Tangle

You can read the received messages directly from the **I2T Explorer**: https://explorer.iot2tangle.io/ using the Channel Id.   

![explorer_lima](https://user-images.githubusercontent.com/42292104/100208487-c650df80-2ed6-11eb-8084-daa7b3b6eac7.png)


*For inquiries, improvements or errors detected, please start an issue in this repository.*
