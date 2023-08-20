
# Building an Open-Source Inventory Management and Monitoring System for Efficient Operations 📦🔍🌐

Introduction:
Managing inventories efficiently is crucial for businesses of all sizes. To streamline this process, we have developed an innovative Inventory Management and Monitoring System as part of our Engineering Design and Innovation Project. This system incorporates open-source technologies and a user-friendly approach to help businesses effectively manage their inventory, optimize operations, and enhance overall productivity. 🚀💼🔧

## 1. Inventory Management System with Raspberry Pi 🍓🥧

Our system leverages the power of Raspberry Pi, a popular single-board computer, to create a robust and versatile inventory management solution. Here's how it works: 🖥️📊🤖

### a. Hardware Setup 🛠️
We utilize Raspberry Pi 4B and connect it to three ultrasonic sensors, one for each rack. These sensors measure the distance within the racks, continuously monitoring inventory levels.

### b. Software Setup 💻🔌
We set up the Raspberry Pi with the Raspbian operating system, an open-source OS specifically designed for Raspberry Pi. Additionally, we install essential Python libraries like RPi.GPIO and smtplib for sensor interfacing and email communication.

### c. Sensor Measurement and Billing 📏💰
Using Python code, we measure the distance from the ultrasonic sensors and calculate the bill based on the reduced distance when an item is removed from the rack. The bill is stored in a .txt file in the Raspberry Pi's file system. We utilize the smtplib library to send the bill to the customer via email, ensuring prompt and accurate updates. 📧💳📝

### The Functional Representation :
![image](https://github.com/Auriel3003/samael/assets/103866475/bafc347b-d338-4bc5-b52a-4803a9fc6258)




## 2. Inventory Management System with NodeMCU ESP8266 📲🌐📉

Expanding the system's capabilities, we incorporate the NodeMCU ESP8266 board to enable real-time inventory monitoring and alerting. Here's an overview: 

### a. Hardware Setup 🛠️
We connect the NodeMCU ESP8266 board to two ultrasonic sensors, which are housed in racks containing perishable goods. This configuration allows us to continuously monitor the inventory levels in these racks.

### b. Software Setup 💻🔌
We install the necessary libraries such as ESP8266WiFi and ThingSpeak in the Arduino IDE, an open-source integrated development environment for programming microcontrollers.

### c. ThingSpeak Integration and Alert System 📊📮🚨
By leveraging the ThingSpeak cloud platform and its write API, we update inventory data every minute. This information is then relayed to the IFTTT API, which triggers an email notification to the inventory manager when certain goods reach minimal supply levels. This real-time alert system enables proactive inventory management and timely replenishment. 🌩️📩📉

### The Functional Representation :
![image](https://github.com/Auriel3003/samael/assets/103866475/8191a17b-188e-4736-a574-2823c97bd48f)


## 3. Inventory Monitoring System with Arduino UNO ⚠️💡🌡️

To ensure the safety and integrity of inventories, we incorporate an Arduino UNO board with various sensors. Here's how it works: 

### a. Hardware Setup 🛠️
We connect a DHT11 sensor for temperature and humidity measurement, as well as an MQ135 sensor for smoke detection. These sensors enable real-time monitoring of environmental conditions.

### b. Software Setup 💻🔌
We utilize the Arduino IDE and install relevant libraries to facilitate LCD display interaction and sensor readings.

### c. Safety Measures and Display 📊🌡️🔴
When abnormal readings are detected, such as high temperatures or smoke presence, the LCD display shows a "Danger" message, the Arduino triggers a fan, a buzzer sounds, and red LEDs light up. These safety measures help prevent inventory damage and ensure the well-being of personnel. ⚠️🌡️🔴🔒

### The Functional Representation :
![image](https://github.com/Auriel3003/samael/assets/103866475/3acc22cb-1dd5-4f94-a741-34fa69e59658)




## Advantages and Applications 🌟📈💼

Our Inventory Management and Monitoring System offers numerous benefits and applications:

1. Real-time inventory monitoring allows for efficient management and proactive decision-making.
2. Temperature and humidity monitoring ensures optimal storage conditions, preventing spoilage and maintaining quality.
3. Gas level monitoring enhances safety by detecting potential hazards in the inventory environment.
4. Open-source nature encourages transparency, affordability, and community collaboration.
5. Customizable and modular design enables adaptation to different business sizes and needs.
6. On-the-spot billing system improves customer experience and reduces waiting times.
7. Data collection facilitates analysis for demand patterns, inventory optimization, and informed decision-making.

## Conclusion:
Our Inventory Management and Monitoring System, driven by open-source technologies, empowers businesses to effectively monitor inventories, automate billing processes, implement proactive alerts, and maintain optimal storage conditions. With its user-friendly approach and customizable features, this system offers an innovative solution for businesses of all sizes. Embrace the power of open-source and revolutionize your inventory management practices today! 🚀📦🌐

