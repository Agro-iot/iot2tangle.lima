![lima_iot2tangle_banner](https://user-images.githubusercontent.com/42292104/100166018-b7900b80-2e89-11eb-9e6e-031cb2113a56.png)

## Subject
Lima is a Secure Body Temperature Monitoring System which integrates a MLX90614 sensor, an ESP32 board and the project version of the [iot2tangle stack](https://github.com/iot2tangle).

For full instructions, visit the [Wiki page](https://github.com/Agro-iot/iot2tangle.lima/wiki).

## Overview and Background
The MLX90614 sensor is an infrared thermometer for non-contact temperature measurements. This sensor is connected to an ESP-32 board which sends the data to the [IOTA Tangle](https://blog.iota.org/the-tangle-an-illustrated-introduction-4d5eae6fe8d4!) using Wi-Fi connectivity. The developed system can be use to detect a common symptom like fever caused by many diseases (flu, pneumonia, COVID-19...) and prevent health complications. This project achieves two major challenges: connectivity and security, the first one allows users and doctors have the data remotely and in the right time. The second one gives confidence to adopt this type of technology without worrying about typical centralized system vulnerabilities. 

## Standards
This project is based on [IOTA Streams Framework](https://www.iota.org/solutions/streams) and [ESP-IDF Standard](https://docs.espressif.com/projects/esp-idf/en/stable/get-started/).

## Potential
The same principle applies to wearable technologies (i.e. smartwatches or wristbands) adding other sensors such as GPS or oximeters to have the full picture of the end user's physical activity. Thanks to IOTA Streams Framework, the user is always in control of its own data and decides who and when can access it.

## Future Steps
Make a PCB board and a 3D-printed enclosure prototype for portable funcionality. Also integrate other types of connectivity like LPWAN to expand the use case scenarios.

## Video Presentation
[![video_ppt](https://user-images.githubusercontent.com/42292104/100272260-cbd71580-2f28-11eb-8634-a995412d1148.png)](https://www.youtube.com/watch?v=VQvI5fAxg1s)
